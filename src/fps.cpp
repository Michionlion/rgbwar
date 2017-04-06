#include "fps.h"
#include <SDL2/SDL_timer.h>

FPSCounter::FPSCounter() {
	last = SDL_GetPerformanceCounter();
	fps = 0;
}

float FPSCounter::getFPS() {
	return fps;
}

Uint64 FPSCounter::getFRT() {
	return frametime;
}

float FPSCounter::toMillis(Uint64 t) {
	return toMillis((float) t);
}

float FPSCounter::toMillis(float t) {
	return t / SDL_GetPerformanceFrequency() * 1000;
}

void FPSCounter::startFrame() {
	start = SDL_GetPerformanceCounter();
	fps = (float) SDL_GetPerformanceFrequency() / (float) (start - last);
	last = start;
}

void FPSCounter::endFrame() {
	Uint64 now = SDL_GetPerformanceCounter();
	frametime = now - start;
	// int i;
	// for(i = 0; i < size; i++) {
	// 	printf("%ld, ", frametimes[i]);
	// }
}

float FPSCounter::getSleepTimeFor(float desiredFPS) {
	return toMillis((SDL_GetPerformanceFrequency() / desiredFPS) - getFRT());
}
