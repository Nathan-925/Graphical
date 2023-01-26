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

		Image(int w, int h);

		~Image();

		Color* operator[](int n);
	};
}

#endif /* IMAGE_H_ */
