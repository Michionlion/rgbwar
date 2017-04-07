#include <SDL2/SDL.h>

enum Window_Option_t { VSYNC, BACKGROUND_COLOR };
enum Window_Option_Value_t { ON, OFF };

class GameWindow {
public:
	int width;
	int height;
	SDL_Color background;
	bool vsync;
	GameWindow(int,int, SDL_Color, bool);
	void setColor(const SDL_Color);
	void render(const SDL_Rect, const SDL_Color);
	void pixel(int,int);
	void refresh(void);
	void clear(void);
	void destroy(void);
	void setOption(Window_Option_t, const void*);
	void setOption(Window_Option_t, Window_Option_Value_t);
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
SDL_Point point(int,int);
