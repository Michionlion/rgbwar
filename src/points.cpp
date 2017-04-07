#include "points.h"
#include <cstdlib>

Particle::Particle(float x, float y) {
	this->x = x;
	this->y = y;
	dx=dy=0;
	// dx = rand() / (float) RAND_MAX * 2.0 - 1.0;
	// dy = rand() / (float) RAND_MAX * 2.0 - 1.0;
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
	float x,y,angle,f;
	for(int i = 0; i++ < numParticles; part++) {
		if(part->x > window.width-1) {
			part->x = window.width-1;
			// part->dx = -part->dx;
		}
		else if(part->x < 0) {
			part->x = 0;
			// part->dx = -part->dx;
		}
		if(part->y > window.height-1) {
			part->y = window.height-1;
			// part->dy = -part->dy;
		}
		else if(part->y < 0) {
			part->y = 0;
			// part->dy = -part->dy;
		}

		//error and waayyyy too slow

		auto other = particles.begin();
		for(int j = 0; j++ < numParticles; other++) {
			x = other->x - part->x;
			y = other->y - part->y;
			if(x==y && y==0) continue;
			angle = atan2(y, x);
			f = 1.0 / (x*x + y*y);
			part->dx += f*cos(angle);
			part->dx += f*sin(angle);
			// printf("ang:%f\n", angle);
		}
		// printf("dx:%f, dy: %f\n", part->dx, part->dy);
		window.pixel((part->x+=part->dx)/scale, (part->y+=part->dy)/scale);
	}
}
