#pragma once
#include "vector3.h"

struct Sephere
{
	Vec3f center = {};
	Vec3f color = {};

	float r = 0.0f;

	Sephere() {
	
	}
	Sephere(Vec3f center,float r, Vec3f color):center(center),r(r),color(color) {

	}

};

