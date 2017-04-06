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

GameWindow::GameWindow(int w,int h, SDL_Color bg) {
	width = w;
	height = h;
	background = bg;
	SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_OPENGL, &window, &renderer);
	surf = SDL_GetWindowSurface(window);

}

void GameWindow::setColor(SDL_Color col) {
	SDL_SetRenderDrawColor(renderer, col.r, col.g, col.b, col.a);
}

void GameWindow::render(SDL_Rect rect, SDL_Color col) {
	setColor(col);
	SDL_RenderFillRect(renderer, &rect);
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
