/*
 * Rasterizer.h
 *
 *  Created on: Dec 7, 2022
 *      Author: Nathan
 */

#ifndef RASTERIZER_H_
#define RASTERIZER_H_

#include <forward_list>

#include "Image.h"
#include "Color.h"

#include "priori/Math.h"

namespace priori{
	void drawLine(Image &target, Color color, int x1, int y1, int x2, int y2);
	void drawTriangle(Image &target, Color color, Vector p1, Vector p2, Vector p3);
	void fillTriangle(Image &target, Color color, Vector p1, Vector p2, Vector p3);
	void drawPolygon(Image &target, Color color, Polygon polygon);
	void drawCircle(Image &target, Color color, Vector center, double radius);
}

#endif /* RASTERIZER_H_ */
