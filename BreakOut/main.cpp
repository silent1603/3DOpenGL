#include "Core.h"
#include "Game.h"
int main(int argc , char** argv)
{
    Core::Log::Init();
    Game game(600,300);
    game.Init();
    game.Running();
    return 0;
}