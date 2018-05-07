
#include "image.h"
#include "vector3.h"
#include "ray.h"
#include "sephere.h"
#include "camera.h"
#include "film.h"

bool hit_sphere(const Vec3f& sephere_center,float radius,const Ray& ray) {
	Vec3f oc = ray.origin - sephere_center;
	auto a = Vec3f::dot(ray.target, ray.target);
	auto b = 2.0f * Vec3f::dot(oc, ray.target);
	auto c = Vec3f::dot(oc, oc) - radius * radius;
	return (b * b - 4 * a * c) > 0;
}


int main() {

	Film l_film(Vec3f(0.0f,0.0f,-1.0f),800,800);
	auto camera = Camera(0.0f);

	Sephere sepheres[4] = {
		{ { 1.0f,  0.0f, -4.0f },0.2f  ,{ 1.0f,0.0f,0.0f }},
		{ { 0.0f,  1.0f, -4.0f },0.4f  ,{ 0.0f,1.0f,0.0f }},
		{ { -1.0f,-1.0f, -4.0f },0.1f  ,{ 0.0f,0.0f,1.0f }},
		{ { 0.0f,  0.0f, -4.0f },0.35f ,{ 1.0f,1.0f,0.0f }},

	};


	for (auto i = 0; i < l_film.width;++i) {
		for (auto j = 0; j < l_film.height; ++j) {
			
			auto ray = Ray(camera.pos,Vec3f(float(i - l_film.width/2)/ l_film.width,float(j - l_film.height /2)/l_film.height,l_film.center.z));


			for (const auto& l_sephere: sepheres) {
				if (hit_sphere(l_sephere.center, l_sephere.r, ray)) {
					l_film.image.data[i][j][0] = uint8_t(255.0 * l_sephere.color.x);
					l_film.image.data[i][j][1] = uint8_t(255.0 * l_sephere.color.y);
					l_film.image.data[i][j][2] = uint8_t(255.0 * l_sephere.color.z);
				}
					

			}

			
		}
	}

	l_film.image.WriteToDisk();

	return 0;
}