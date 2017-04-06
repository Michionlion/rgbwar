#include "points.h"

PointSim::PointSim(int num) {
	numParticles = num;
	particles = new Particle[num];
}
Particle::Particle(float x, float y) {
	this->x = x;
	this->y = y;
}
void Particle::move() {
	x+=dx;
	y+=dy;
}

PointSim::~PointSim() {
	delete particles;
}

void PointSim::render(GameWindow& window) {
	int i;
	for(i=0; i < numParticles; i++) {
		// window.renderer
	}
}
