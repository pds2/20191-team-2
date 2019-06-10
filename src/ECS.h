//
// Created by giow on 10/06/19.
//

#ifndef BOMBERMANC_SRC_ECS_H_
#define BOMBERMANC_SRC_ECS_H_
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

class Component;
class Entity;

using ComponentID = std::size_t;

// Put into place whenever called like a header, inlines are LoL
// Generate a component id whenever called
inline ComponentID GetComponentTypeId()
{
    static ComponentID last_id = 0;
    return last_id++;
}

template <typename T> inline ComponentID GetComponentTypeId() noexcept
{
    static ComponentID type_id = GetComponentTypeId();
    return type_id;
}

// maximum number of components C++ is able to hold
constexpr  std::size_t MAX_COMPONENTS = 32;

/*If we need to find if an entity has a component*/
using ComponentBitSet = std::bitset< MAX_COMPONENTS>;

/*Array of component pointers*/
using ComponentArray = std::array<Component*, MAX_COMPONENTS>;

class Component
{
 public:
    Entity* entity_;
    virtual void init();
    virtual void update();
    virtual void draw();
    virtual ~Component();
};

class Entity
{
 private:
    bool active = true;
    std::vector<std::unique_ptr<Component>> components;
    ComponentArray component_array_;
    ComponentBitSet component_bit_set_;

 public:
    void update()
    {
        for(auto &c : components)
        {
            c->update();
        }
        for(auto &c : components)
        {
            c->draw();
        }
    }

    void draw(){}

    bool is_active(){
        return active;
    }
    void destroy(){
        active = false;
    }

    template <typename T> bool has_component() const {
        return component_bit_set_[GetComponentTypeId<T>];
    }

    template<typename T, typename ... TArgs>

    T& add_component(TArgs &&... mArgs)
    {
        T* c(new T(std::forward<TArgs>(mArgs)...));
        c->entity = this;
        std::unique_ptr<Component> uPtr{ c };
        components.emplace_back((std::move(uPtr)));

        component_array_[GetComponentTypeId<T>()] = c;
        component_bit_set_[GetComponentTypeId<T>()] = true;

        c->init();
        return *c;
    }

    template<typename  T> T& get_component() const {
        auto ptr(component_array_[GetComponentTypeId()]);
        return *static_cast<T*>(ptr);
    }
    
};


#endif //BOMBERMANC_SRC_ECS_H_
