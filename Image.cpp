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
	}

	Image::Image(const Image &other) : width(other.width), height(other.height), pixels(new Color*[width]) {
		for(int i = 0; i < width; i++){
			pixels[i] = new Color[height];
			for(int j = 0; j < height; j++)
				pixels[i][j] = other[i][j];
		}
	}

	Image::~Image() {
		for(int i = 0; i < width; i++)
			delete[] pixels[i];
		delete[] pixels;
	}

	Color*& Image::operator[](int n){
		return pixels[n];
	}

	const Color*& Image::operator[](int n) const{
		return (const Color*&)(pixels[n]);
	}

	Image trim(const Image &image, int x0, int y0, int x1, int y1){
		Image out(x1-x0, y1-y0);
		for(int i = 0; i < out.width; i++)
			for(int j = 0; j < out.height; j++)
				out[i][j] = image[i+x0][j+y0];
		return out;
	}
}
