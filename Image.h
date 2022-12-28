/*
 * Image.h
 *
 *  Created on: Dec 15, 2022
 *      Author: Nathan
 */
#ifndef IMAGE_H_
#define IMAGE_H_

#include "Color.h"

namespace priori{
	struct Image{
		const int width, height;
		Color** pixels;

		Image(int w, int h) : width(w), height(h), pixels(new Color*[width]) {
			for(int i = 0; i < width; i++)
				pixels[i] = new Color[height];
		};

		~Image() {
			for(int i = 0; i < width; i++)
				delete[] pixels[i];
			delete[] pixels;
		};
	};
}

#endif /* IMAGE_H_ */
