#include "Particle.h"


Particle::Particle(const ci::Vec2f& position, float radius, float
	mass, float drag){
	this->position = position;
	this->radius = radius;
	this->mass = mass;
	this->drag = drag;
	prevPosition = position;
	forces = ci::Vec2f::zero();
}

void Particle::update()
{
	ci::Vec2f temp = position;
	ci::Vec2f vel = (position - prevPosition) * drag;
	position += vel + forces / mass;
	prevPosition = temp;
	forces = ci::Vec2f::zero();
}

void Particle::draw(){
	ci::gl::drawSolidRect(ci::Rectf(position.x - radius, position.y - radius,
		position.x + radius, position.y + radius));
}