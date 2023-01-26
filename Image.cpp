/*
 * Image.cpp
 *
 *  Created on: Jan 19, 2023
 *      Author: Nathan
 */
#include "Image.h"

namespace priori{
	Image::Image(int w, int h) : width(w), height(h), pixels(new Color*[width]) {
		for(int i = 0; i < width; i++)
			pixels[i] = new Color[height];
	};

	Image::~Image() {
		for(int i = 0; i < width; i++)
			delete[] pixels[i];
		delete[] pixels;
	};

	Color* Image::operator[](int n){
		return pixels[n];
	}
}
