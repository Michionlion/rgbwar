#include "game.h"

Game::Game(bool& ready) {

	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
		ready = false;
	} else ready = true;
}

SDL_Color color(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
	SDL_Color col;
	col.a = a;
	col.r = r;
	col.g = g;
	col.b = b;

	return col;
}

SDL_Rect rect(int x, int y, int w, int h) {
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;

	return rect;
}

SDL_Point point(int x, int y) {
	SDL_Point p;
	p.x = x;
	p.y = y;

	return p;
}

GameWindow::GameWindow(int w,int h, SDL_Color bg, bool waitForSync) {
	width = w;
	height = h;
	background = bg;
	vsync = waitForSync;
	SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_OPENGL, &window, &renderer);
	surf = SDL_GetWindowSurface(window);

	//set vsync
	if(waitForSync && SDL_GL_SetSwapInterval(-1) < 0) SDL_GL_SetSwapInterval(1);

}

void GameWindow::setOption(Window_Option_t option, Window_Option_Value_t value) {
	if(option == VSYNC) {
		if(value == ON) {
			if(SDL_GL_SetSwapInterval(-1) < 0) SDL_GL_SetSwapInterval(1);
			vsync = true;
		} else if(value == OFF) {
			SDL_GL_SetSwapInterval(0);
			vsync = false;
		}
	}
}

void GameWindow::setOption(Window_Option_t option, const void* value) {
	if(option == BACKGROUND_COLOR) {
		background = *((SDL_Color*) value);
	}
}

void GameWindow::setColor(SDL_Color col) {
	SDL_SetRenderDrawColor(renderer, col.r, col.g, col.b, col.a);
}

void GameWindow::render(SDL_Rect rect, SDL_Color col) {
	setColor(col);
	SDL_RenderFillRect(renderer, &rect);
}

void GameWindow::pixel(int x, int y) {
	SDL_RenderDrawPoint(renderer, x, y);
}

void GameWindow::refresh() {
	SDL_RenderPresent(renderer);
}

void GameWindow::clear() {
	setColor(background);
	SDL_RenderClear(renderer);
}

void GameWindow::destroy() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
}
