/*
 * Rasterizer.cpp
 *
 *  Created on: Dec 4, 2022
 *      Author: Nathan
 */
#include <cmath>
#include <iostream>

#include "Rasterizer.h"

using namespace std;

namespace priori{
	void drawLine(Image target, Color color, Point p1, Point p2){
		int dx = abs(p2.x-p1.x);
		int dy = abs(p2.y-p1.y);
		if(dx > dy){
			double* line = lerp<double>(p1.x, p1.y, p2.x, p2.y);
			for(int i = 0; i <= dx; i++)
				target.pixels[i+(int)p1.x][(int)round(line[i])] = color;
		}
		else{
			double* line = lerp<double>(p1.y, p1.x, p2.y, p2.x);
			for(int i = 0; i <= dy; i++)
				target.pixels[(int)round(line[i])][i+(int)p1.y] = color;
		}
	}

	void drawTriangle(Image target, Color color, Point p1, Point p2, Point p3){
		drawLine(target, color, p1, p2);
		drawLine(target, color, p1, p3);
		drawLine(target, color, p2, p3);
	}

	void fillTriangle(Image target, Color color, Point p1, Point p2, Point p3){
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

	void drawPolygon(Image target, Color color, Polygon polygon){
		cout << "in function" << endl;
		Point prev = *polygon.begin();
		cout << "loop" << endl;
		for(auto it = ++polygon.begin(); it != polygon.end(); it++){
			cout << prev.x << " " << prev.y << " " << (*it).x << " " << (*it).y << endl;
			cout << distance(it, polygon.end()) << endl;
			cout << (it == polygon.end()) << endl;
			drawLine(target, color, prev, *it);
			cout << "line" << endl;
			prev = *it;
		}
		cout << "final line" << endl;
		drawLine(target, color, *polygon.begin(), *polygon.end());
		cout << "end function" << endl;
	}
}
