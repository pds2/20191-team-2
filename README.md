# Tema
O tema escolhido para o trabalho final da disciplina será um jogo, visando ser um clone de Bomberman. O projeto utilizará os conceitos de modelagem de projeto, programação orientada a objetos e de testes unitários. O tema escolhido tem o propósito de por em prática os conceitos introduzidos na matéria

## Dependencias

- [Git][]
- C Compiler (gcc, ...)
- [CMake][]
- [SDL2][SDL] library
- [SDL2_image][] library

**On Debian/Ubuntu based distributions, use the following command:**

```sh
sudo apt install cmake libsdl2-dev libsdl2-image-dev
```

## Build instructions

```sh
# Clone this repo
https://github.com/pds2/20191-team-2
cd /path/to/folder

# Create a build folder
mkdir build
cd build

# Build
cmake ..
make

# Run
./BombermanC++
```

## User Stories
  - Como jogador preciso de um menu para sair, entrar e interagir com as opções de jogo, para facilitar a interação jogo-usuário.
     - Ter uma opção de começar e sair do jogo.
     - Ter uma opção para pausar o jogo e sair dele.
     
  - Como jogador preciso poder interagir com o personagem e a fase, podendo fazer ações como atacar, mover, em prol da verossimilhança com o jogo original.
    - Definir um espaço(fase) para o jogo.
    - Criar a movimentação do personagem no espaço de jogo.
    - Criar o ataque do personagem nesse espaço.
    
  - Como jogador preciso ter um feedback das ações dos personagens, para facilitar a interação com o software.
    - Fazer uma interface para as tarefas anteriores.
    
  - Como jogador preciso de inimigos para competirem no jogo, em prol da verossimilhança com o jogo original.
    - Fazer um tipo de movimentação para o adversário.
    - Fazer um tipo de ataque para o adversário.
    
  - Como jogador preciso de um critério de sucesso e um de fracasso ao jogar, ou seja, o jogo precisa conter uma forma de ganhar e de perder.
    - Definir e implementar um critério para ganhar, por exemplo: O jogador matou o inimigo na fase.
    - Definir e implementar um critério para perder, por exemplo: O jogador morreu antes de concluir a fase.
  - Como desenvolvedor quero permitir e criar algum tipo de variação da fase ou do personagem, para exemplificar os conceitos de programação orientada a objetos utilizados no projeto
