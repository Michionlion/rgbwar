#include <iostream>
#include <SDL2/SDL.h>
#include "fps.h"
#include "points.h"
#define MSP 0.16
#define FRC 0.85

int main(int argc, char const *argv[]) {
	bool ready;
	Game game(ready);
	if(!ready) return -1;

	GameWindow window(640,400, color(0,0,0,255), false);
	FPSCounter fps;

	fps.startFrame();
	window.clear();
	window.refresh();
	fps.endFrame();

	PointSim points(200, window.width, window.height);

	bool running = true, debug = true;
	const Uint8* keys = SDL_GetKeyboardState(NULL);
	while (running) {
		fps.startFrame();
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT || e.key.keysym.scancode == SDL_SCANCODE_ESCAPE || (e.key.keysym.scancode == SDL_SCANCODE_C && e.key.keysym.mod == /*'&' if only want to see if it is down, don't care about others*/ KMOD_LCTRL)) {
                running = false;
            } else if(e.key.repeat == false && e.key.keysym.scancode == SDL_SCANCODE_V && e.type == SDL_KEYDOWN) {
				window.setOption(VSYNC, window.vsync ? OFF : ON);
				printf("VSYNC: %s\n", window.vsync ? "ON" : "OFF");
			} else if(e.key.repeat == false && e.key.keysym.scancode == SDL_SCANCODE_GRAVE && e.type == SDL_KEYDOWN) {
				debug = !debug;
			}
        }

		if(keys[SDL_SCANCODE_UP]) {
			points.scale(-0.05);
			printf("Scale: %f\n", points.getScale());
		} else if(keys[SDL_SCANCODE_DOWN]) {
			points.scale(0.05);
			printf("Scale: %f\n", points.getScale());
		}

		if(debug) printf("Rendertime: %0.02fms, %0.1f FPS\n", fps.toMillis(fps.getFRT()), fps.getFPS());

		window.clear();
		points.render(window);
		window.refresh();
		fps.endFrame();

		if(!window.vsync) {
			float t = fps.getSleepTimeFor(30);

			if(t > 0) {
				SDL_Delay((Uint32) t);
				if(debug) printf("sleeping %f\n", t);
			}
		}
    }

	//cleanup
	window.destroy();
	SDL_Quit();
	return 0;
}
