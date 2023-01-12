#include "Core.h"
#include "Game.h"
int main(int argc , char** argv)
{
    Core::Log::Init();
    Game game(600,300);
    game.Init();
    GAME_INFO("Hello World");
    return 0;
}