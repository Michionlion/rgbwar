#include "particles.h"

Particle::Particle(float x, float y) {
	this->x = x;
	this->y = y;
}

void Particle::move() {
	x+=dx;
	y+=dy;
}
