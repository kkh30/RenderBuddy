#pragma once
#include "image.h"
#include "vector3.h"

struct Film
{
	Image image = {};
	Vec3f center = {};
	int width = 0;
	int height = 0;

	Film(Vec3f p_center,int width,int height) : center(p_center),width(width),height(height),image(width,height){
		image.Clear();
	}


};






