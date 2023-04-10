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
		Color** const pixels;

		Image(int w, int h);
		Image(const Image &other);
		~Image();

		Color*& operator[](int n);
		const Color*& operator[](int n) const;
	};

	Image trim(const Image &image, int x0, int y0, int x1, int y1);
}

#endif /* IMAGE_H_ */
