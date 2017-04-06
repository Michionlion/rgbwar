#include <iostream>
#include <SDL2/SDL.h>
#include "game.h"
#include "fps.h"
#define MSP 0.16
#define FRC 0.85

int main(int argc, char const *argv[]) {
	bool ready;
	Game game(ready);
	if(!ready) return -1;

	GameWindow window(400,200, color(0,0,0,255), false);
	FPSCounter fps;



	float dx = 5.5, dy = 0, x = 0, y = window.height/2 - 25;
	bool running = true;
	const Uint8* keys = SDL_GetKeyboardState(NULL);
	while (running) {
		fps.startFrame();
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT || e.key.keysym.scancode == SDL_SCANCODE_ESCAPE || (e.key.keysym.scancode == SDL_SCANCODE_C && e.key.keysym.mod == /*'&' if only want to see if it is down, don't care about others*/ KMOD_LCTRL)) {
                running = false;
            } else if(e.key.repeat == false && e.key.keysym.scancode == SDL_SCANCODE_V && e.type == SDL_KEYDOWN) {
				window.setOption(VSYNC, window.vsync ? OFF : ON);
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

		// int i;
		// for(i=0; i < 100; i++) {
		// 	int j = i*10/(float)400;
		// }


		window.clear();
		window.render(rect((int)x,(int)y,50,50), color(255,255,255,100));
		window.refresh();
		fps.endFrame();

		printf("Rendertime: %0.02fms, %0.02f FPS\n", fps.toMillis(fps.getFRT()), fps.getFPS());

		if(!window.vsync) {
			float t = fps.getSleepTimeFor(60);
			printf("sleeping %f\n", t);
			if(t > 0) SDL_Delay((Uint32) t);
		}
    }

	//cleanup
	window.destroy();
	SDL_Quit();
	return 0;
}
