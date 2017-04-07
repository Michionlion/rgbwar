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

	GameWindow window(640,400, color(0,0,0,255), true);
	FPSCounter fps;
	PointSim points(20, 640, 400);

	bool running = true;
	// const Uint8* keys = SDL_GetKeyboardState(NULL);
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




		window.clear();
		points.render(window);
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
