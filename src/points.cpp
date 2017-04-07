#include "points.h"
#include <cstdlib>

PointSim::PointSim(int num, float xrange, float yrange) {
	numParticles = num;
	xrange = xrange / RAND_MAX;
	yrange = yrange / RAND_MAX;
	for(; num > 0; num--) {
		particles.push_front(Particle(rand() * xrange, rand()*yrange));
	}
}

void PointSim::render(GameWindow& window) {
	auto it = particles.begin();
	window.setColor(color(255,255,255,255));
	for(int i = 0; i < numParticles; i++) {
		window.pixel(it->x, it->y);
	}
}
