/*
 * Rasterizer.cpp
 *
 *  Created on: Dec 4, 2022
 *      Author: Nathan
 */
#include <cmath>
#include <algorithm>

#include "Rasterizer.h"

using namespace std;

namespace priori{
	void drawLine(Image &target, Color color, Point p1, Point p2){
		int dx = abs(p2.x-p1.x);
		int dy = abs(p2.y-p1.y);
		if(dx > dy){
			if(p1.x > p2.x)
				swap(p1, p2);
			double* line = lerp<double>(p1.x, p1.y, p2.x, p2.y);
			for(int i = 0; i <= dx; i++)
				target[i+(int)p1.x][(int)line[i]] = color;
			delete[] line;
		}
		else{
			if(p1.y > p2.y)
				swap(p1, p2);
			double* line = lerp<double>(p1.y, p1.x, p2.y, p2.x);
			for(int i = 0; i <= dy; i++)
				target[(int)line[i]][i+(int)p1.y] = color;
			delete[] line;
		}
	}

	void drawTriangle(Image &target, Color color, Point p1, Point p2, Point p3){
		drawLine(target, color, p1, p2);
		drawLine(target, color, p1, p3);
		drawLine(target, color, p2, p3);
	}

	void fillTriangle(Image &target, Color color, Point p1, Point p2, Point p3){
		if(p2.y < p1.y){
			Point temp = p1;
			p1 = p2;
			p2 = temp;
		}
		if(p3.y < p1.y){
			Point temp = p1;
			p1 = p3;
			p3 = temp;
		}
		if(p3.y < p2.y){
			Point temp = p2;
			p2 = p3;
			p3 = temp;
		}

		int dy01 = abs(p2.y-p1.y);
		int dy02 = abs(p3.y-p1.y);

		double* x01 = priori::lerp<double>(p1.y, p1.x, p2.y, p2.x);
		double* x02 = priori::lerp<double>(p1.y, p1.x, p3.y, p3.x);
		double* x12 = priori::lerp<double>(p2.y, p2.x, p3.y, p3.x);

		for(int i = 0; i <= dy02; i++){
			int n0 = (int)x02[i];
			int n1 = (int)(i < dy01 ? x01[i] : x12[i-dy01]);
			int n = min(n0, n1);
			for(int j = 0; j < abs(n1-n0); j++)
				target.pixels[j+n][i+(int)p1.y] = color;
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
