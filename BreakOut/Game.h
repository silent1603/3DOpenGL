#pragma once
#include <SDL2/SDL.h>
#include <glad/glad.h>
enum GameState {
	GAME_ACTIVE,
	GAME_MENU, 
	GAME_WIN
};
class Game
{
public:
	Game(unsigned int width, unsigned int height);
	~Game();
	void Init();
	void Running();
	void ProcessInput(double dt);
	void Update(double dt);
	void Shutdown();
	void Render();
	bool IsRunning();
private:
	GameState State;
	bool Keys[1024];
	unsigned int m_iWidth, m_iHeight;
	bool m_canRunning = false;
	SDL_Window* m_pWindow;
	SDL_GLContext m_GLContext;
	SDL_Event m_Event;
	UINT64 m_lastFrame ;
	UINT64 m_nowFrame ;
	double m_delataTime ;
};

