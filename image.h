#pragma once
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include <array>
#include <stdint.h>
#include <vector>
class Image
{
public:

	Image() {}

	Image(int width,int height):width(width),height(height)
	{
		data.resize(width);
		for (auto& row : data) {
			row.resize(height);
			for (auto& pixel : row) {
				pixel.resize(4);
			}
		}
	}
	~Image()
	{
	}
	
	void WriteToDisk() {

		std::vector<uint8_t> raw_data;

		for (auto& row : data) {
			for (auto& col : row) {
				for (auto& channel : col) {
					raw_data.push_back(channel);
				}
			}
		}


		stbi_write_bmp("res.bmp", width, height, 4, raw_data.data());
	}

	void Clear() {
		for (auto& row : data) {
			for (auto& col : row) {
				col[0] = 120;
				col[1] = 120;
				col[2] = 120;
				col[3] = 255;
			}
		}
	}
public:
	std::vector<std::vector<std::vector<uint8_t>>> data = {};
	int width = 0;
	int height = 0;

};




