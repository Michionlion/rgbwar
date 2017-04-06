#include <iostream>
#include "game.h"
#define MSP 0.16
#define FRC 0.7

int main(int argc, char const *argv[]) {
	bool ready;
	Game game(ready);
	if(!ready) return -1;

	GameWindow window(400,200, color(0,0,0,255));
	float dx = 0, dy = 0, x = 0, y = 0;
	bool running = true;
	const Uint8* keys = SDL_GetKeyboardState(NULL);
	while (running) {
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT || e.key.keysym.scancode == SDL_SCANCODE_ESCAPE || (e.key.keysym.scancode == SDL_SCANCODE_C && e.key.keysym.mod == /*'&' if only want to see if it is down, don't care about others*/ KMOD_LCTRL)) {
                running = false;
            }
        }

		if(keys[SDL_SCANCODE_DOWN]) dy+=MSP;
		if(keys[SDL_SCANCODE_UP]) dy-=MSP;
		if(keys[SDL_SCANCODE_RIGHT]) dx+=MSP;
		if(keys[SDL_SCANCODE_LEFT]) dx-=MSP;

		x += dx;
		y += dy;

		if(x < 0) {
			x = 0;
			dx = -dx*FRC;
		}
		else if(x > window.width - 50) {
			x = window.width-50;
			dx = -dx*FRC;
		}
		if(y < 0) {
			y = 0;
			dy = -dy*FRC;
		}
		else if(y > window.height - 50) {
			y = window.height-50;
			dy = -dy*FRC;
		}

		window.clear();
		window.render(rect((int)x,(int)y,50,50), color(255,255,255,100));
		window.refresh();
		SDL_Delay(16);
    }

	//cleanup
	window.destroy();
	SDL_Quit();
	return 0;
}
