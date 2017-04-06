#include <SDL2/SDL_timer.h>

class FPSCounter {
public:
	FPSCounter();
	float getFPS(void);
	Uint64 getFRT(void);
	float toMillis(Uint64);
	float toMillis(float);
	void startFrame(void);
	void endFrame(void);
	float getSleepTimeFor(float);
private:
	Uint64 frametime;
	Uint64 start;
	Uint64 last;
	float fps;
};
