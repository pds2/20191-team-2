
#ifndef BOMBERMANC_SRC_BLOCK_H_
#define BOMBERMANC_SRC_BLOCK_H_

#include "GameObjectSDL.h"
class Block : public GameObjectSDL
{
 private:
    bool destroyed_;
 public:
    bool is_destroyed() const;
    void set_destroyed(bool destroyed);
 public:
    Block(const char *texture_sheet, const Pos &pos);
    void render() override;
    void destroy() override;
    void update() override;
};
#endif //BOMBERMANC_SRC_BLOCK_H_
