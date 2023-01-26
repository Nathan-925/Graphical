/*
 * Rasterizer.cpp
 *
 *  Created on: Dec 4, 2022
 *      Author: Nathan
 */
#include <cmath>
#include <algorithm>
#include <forward_list>

#include "Rasterizer.h"

using namespace std;

namespace priori{
	void drawLine(Image &target, Color color, Point p1, Point p2){
		double d = max(abs(p2.x-p1.x), abs(p2.y-p1.y));
		forward_list<Point> list = lerp(0, p1, d, p2);
		for(auto it = list.begin(); it != list.end(); it++)
			target[(int)round((*it).x)][(int)round((*it).y)] = color;
	}

	void drawTriangle(Image &target, Color color, Point p1, Point p2, Point p3){
		drawLine(target, color, p1, p2);
		drawLine(target, color, p1, p3);
		drawLine(target, color, p2, p3);
	}

	void fillTriangle(Image &target, Color color, Point p1, Point p2, Point p3){
		if(p2.y < p1.y)
			swap(p1, p2);
		if(p3.y < p1.y)
			swap(p1, p3);
		if(p3.y < p2.y)
			swap(p2, p3);

		int dy01 = abs(p2.y-p1.y);
		int dy02 = abs(p3.y-p1.y);
		int dy12 = abs(p3.y-p2.y);

		forward_list<double> x01 = priori::lerp<double>(0, p1.x, dy01, p2.x);
		forward_list<double> x02 = priori::lerp<double>(0, p1.x, dy02, p3.x);
		forward_list<double> x12 = priori::lerp<double>(0, p2.x, dy12, p3.x);
		x12.pop_front();

		for(int i = 0; i < dy02; i++){
			double x0 = x02.front();
			double x1 = x01.empty() ? x12.front() : x01.front();
			if(x0 > x1)
				swap(x0, x1);

			for(int j = round(x0); j < round(x1); j++)
				target[j][(int)round(p1.y)+i] = color;

			x02.pop_front();
			if(x01.empty())
				x12.pop_front();
			else
				x01.pop_front();
		}
	}

	void drawPolygon(Image &target, Color color, Polygon polygon){
		Point prev = *polygon.begin();
		for(auto it = ++polygon.begin(); it != polygon.end(); it++){
			drawLine(target, color, prev, *it);
			prev = *it;
		}
		drawLine(target, color, *polygon.begin(), prev);
	}

	void drawCircle(Image &target, Color color, Point center, double radius){
		for(int i = 0; i <= radius; i++){
			target[(int)center.x-i][(int)round(center.y+sqrt(radius*radius-i*i))] = color;
			target[(int)center.x+i][(int)round(center.y+sqrt(radius*radius-i*i))] = color;
			target[(int)center.x-i][(int)round(center.y-sqrt(radius*radius-i*i))] = color;
			target[(int)center.x+i][(int)round(center.y-sqrt(radius*radius-i*i))] = color;

			target[(int)round(center.y+sqrt(radius*radius-i*i))][(int)center.y-i] = color;
			target[(int)round(center.y+sqrt(radius*radius-i*i))][(int)center.y+i] = color;
			target[(int)round(center.y-sqrt(radius*radius-i*i))][(int)center.y-i] = color;
			target[(int)round(center.y-sqrt(radius*radius-i*i))][(int)center.y+i] = color;
		}
	}
}
