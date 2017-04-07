#include "points.h"
#include <cstdlib>

Particle::Particle(float x, float y) {
	this->x = x;
	this->y = y;
	dx = rand() / (float) RAND_MAX * 2.0 - 1.0;
	dy = rand() / (float) RAND_MAX * 2.0 - 1.0;
}

PointSim::PointSim(int num, float xrange, float yrange) {
	numParticles = num;
	scale = 1.0;
	srand(0);
	xrange = xrange / RAND_MAX;
	yrange = yrange / RAND_MAX;
	for(; num > 0; num--) {
		particles.push_front(Particle(rand() * xrange, rand()*yrange));
	}
}

void PointSim::render(GameWindow& window) {
	auto part = particles.begin();
	window.setColor(color(0,30,255,5));
	for(int i = 0; i++ < numParticles; part++) {
		// if(part->x > window.width-1) {
		// 	part->x = window.width-1;
		// 	part->dx = -part->dx;
		// }
		// else if(part->x < 0) {
		// 	part->x = 0;
		// 	part->dx = -part->dx;
		// }
		// if(part->y > window.height-1) {
		// 	part->y = window.height-1;
		// 	part->dy = -part->dy;
		// }
		// else if(part->y < 0) {
		// 	part->y = 0;
		// 	part->dy = -part->dy;
		// }
		auto other = particles.begin();
		for(int j = 0; j++ < numParticles; other++) {
			float f = 1.0 / fabs((other->x - part->x)*(other->x - part->x)+((other->y - part->y)*(other->y - part->y)));

		}
		window.pixel(part->x+=part->dx, part->y+=part->dy);
	}
}
