#include "Game.h"


Game::Game(unsigned int width, unsigned int height)
    : State(GAME_ACTIVE), Keys(), m_iWidth(width), m_iHeight(height)
{

}

Game::~Game()
{

}

void Game::Init()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        GAME_ERROR("SDL could not be initialized : {0}", SDL_GetError());
    }
    GAME_INFO("SDL init everthing success !!!");

    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    m_pWindow = SDL_CreateWindow("BreakOut", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_iWidth, m_iHeight,SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

    m_GLContext = SDL_GL_CreateContext(m_pWindow);
    if (m_GLContext == nullptr)
    {
        GAME_ERROR("SDL Error {0}", SDL_GetError());
    }
    gladLoadGLLoader(SDL_GL_GetProcAddress);
}

void Game::Update(float dt)
{

}

void Game::ProcessInput(float dt)
{

}

void Game::Render()
{

}