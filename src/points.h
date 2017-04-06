#include <SDL2/SDL.h>
#include "game.h"

struct Particle {
	float x,y,dx,dy;
	Particle(void);
	Particle(float,float);
	void move(void);
};

class PointSim {
public:
	PointSim(int);
	~PointSim(void);
	void render(GameWindow&);
private:
	Particle* particles;
	int numParticles;
};
