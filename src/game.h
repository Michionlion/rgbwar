#include <SDL2/SDL.h>

class GameWindow {
public:
	int width;
	int height;
	SDL_Color background;
	GameWindow(int,int, SDL_Color);
	void setColor(const SDL_Color);
	void render(const SDL_Rect, const SDL_Color);
	void refresh(void);
	void clear(void);
	void destroy(void);
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Surface* surf;
};

// enum logtype_t {ERROR, NORMAL};

class Game {
public:
	Game(bool&);
};



SDL_Rect rect(int, int, int, int);
SDL_Color color(Uint8, Uint8, Uint8, Uint8);
