#include "points.h"
#include <cstdlib>

Particle::Particle(float x, float y) {
	this->x = x;
	this->y = y;
	dx=dy=0;
	// printf("Particle(%3.1f, %3.1f)\n", x, y);
	// dx = rand() / (float) RAND_MAX * 40.0 - 20.0;
	// dy = rand() / (float) RAND_MAX * 40.0 - 20.0;
}

PointSim::PointSim(int num, float xrangeo, float yrangeo) {
	numParticles = num;
	curScale = 1.0;
	srand(0);
	float xrange = (float) RAND_MAX / xrangeo;
	float yrange =  (float) RAND_MAX / yrangeo;
	for(; num > 0; num--) {
		particles.push_front(Particle(rand() / xrange - xrangeo/2.0, rand() / yrange - yrangeo/2.0));
	}
}

void PointSim::scale(float f) {
	curScale*=(1.0+f);
	if(f<=0) f = 0.001;
}

float PointSim::getScale() {
	return curScale;
}

void PointSim::render(GameWindow& window) {
	auto part = particles.begin();
	window.setColor(color(0,30,255,5));
	float x,y,angle,f;
	for(int i = 0; i++ < numParticles; part++) {
		if(part->x > window.width/2.0-1) {
			part->x = window.width/2.0-1;
			part->dx = part->dy = 0;
		}
		else if(part->x < -window.width/2.0) {
			part->x = -window.width/2.0;
			part->dx = part->dy = 0;
		}
		if(part->y > window.height/2.0-1) {
			part->y = window.height/2.0-1;
			part->dx = part->dy = 0;
		}
		else if(part->y < -window.height/2.0) {
			part->y = -window.height/2.0;
			part->dx = part->dy = 0;
		}

		//error and waayyyy too slow

		auto other = particles.begin();
		for(int j = 0; j++ < numParticles; other++) {
			if(other == part) continue;
			x = other->x - part->x;
			y = other->y - part->y;

			angle = atan2(y, x);
			f = 200.0 / (x*x + y*y);
			part->dx += f*cos(angle);
			part->dy += f*sin(angle);
			// printf("ang:%f\n", angle);
		}

		x = -part->x;
		y = -part->y;

		angle = atan2(y, x);
		f = 1000.0 / (x*x + y*y);
		part->dx += f*SDL_cosf(angle);
		part->dy += f*SDL_sinf(angle);

		// printf("dx:%f, dy: %f\n", part->dx, part->dy);
		window.pixel(((part->x+=part->dx)/curScale)+window.width/2, ((part->y+=part->dy)/curScale)+window.height/2);
	}

	window.setColor(color(0,255,0,255));
	x = 0;
	y = 0;
	for(int i = -1; i <= 1; i++) {
		for(int j = -1; j <= 1; j++) {
			window.pixel((x+i)+window.width/2, (y+j)+window.height/2);
		}
	}


	window.pixel((x+2)+window.width/2, y+window.height/2);
	window.pixel((x-2)+window.width/2, y+window.height/2);
	window.pixel(x+window.width/2, (y+2)+window.height/2);
	window.pixel(x+window.width/2, (y-2)+window.height/2);


}
