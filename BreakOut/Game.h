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
	void ProcessInput(float dt);
	void Update(float dt);
	void Render();
private:
	GameState State;
	bool Keys[1024];
	unsigned int m_iWidth, m_iHeight;
	bool quit = false;
	SDL_Window* m_pWindow;
	SDL_GLContext m_GLContext;
	SDL_Event m_Event;
};

