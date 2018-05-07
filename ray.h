#pragma once
#include "vector3.h"


class Ray
{
public:
	Ray::Ray()
	{
	}

	Ray::Ray(const Vec3f& p_origin,const Vec3f p_target):origin(p_origin),target(p_target)
	{

	}

	Ray::~Ray()
	{

	}

	Vec3f RayAtT(const float T) {
		return origin + target * T;
	};
public:
	Vec3f origin = {};
	Vec3f target = {};
};

