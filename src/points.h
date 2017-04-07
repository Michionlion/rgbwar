#include <SDL2/SDL.h>
#include <forward_list>
#include "game.h"
#include "particles.h"

class PointSim {
public:
	PointSim(int,float,float);
	void render(GameWindow&);
private:
	std::forward_list<Particle> particles;
	int numParticles;
};
