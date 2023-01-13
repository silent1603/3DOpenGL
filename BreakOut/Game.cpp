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
    //GAME_TRACE("Vendor: {0}", glGetString(GL_VENDOR));
    ///GAME_TRACE("Renderer: {0}", glGetString(GL_RENDERER));
    //GAME_TRACE("Version: {0}", glGetString(GL_VERSION));

    SDL_GL_SetSwapInterval(1);
    glViewport(0, 0, m_iWidth, m_iHeight);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    m_canRunning = true;
}

void Game::Running()
{
    m_nowFrame =    SDL_GetPerformanceCounter();
    m_lastFrame = 0;
    double deltaTime = 0;

    while (m_canRunning)
    {
        m_lastFrame = m_nowFrame;
        m_nowFrame = SDL_GetPerformanceCounter();
        deltaTime = (double)((m_nowFrame - m_lastFrame) * 1000 / (double)SDL_GetPerformanceFrequency());
        ProcessInput(deltaTime);
        Update(deltaTime);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        SDL_GL_SwapWindow(m_pWindow);
    }
    Shutdown();
}

void Game::Update(double dt)
{
   
}

void Game::ProcessInput(double dt)
{
    while (SDL_PollEvent(&m_Event))
    {
        switch (m_Event.type)
        {
        case SDL_QUIT:
            m_canRunning = false;
        default:
            break;
        }
    }
}

void Game::Render()
{

}

void Game::Shutdown()
{
    SDL_GL_DeleteContext(m_GLContext);
    SDL_DestroyWindow(m_pWindow);
    SDL_Quit();
}

bool Game::IsRunning()
{
    return m_canRunning;
}
