/*
 * Color.h
 *
 *  Created on: Dec 9, 2022
 *      Author: Nathan
 */

#ifndef COLOR_H_
#define COLOR_H_

#include <cstdint>
#include <cmath>

union Color{
	uint32_t c;
	struct{
		uint8_t b;
		uint8_t g;
		uint8_t r;
		uint8_t a;
	};

	Color() : c(0) {};
	Color(int c) : c(c) {};
	Color(int r, int g, int b) : b(b), g(g), r(r), a(0) {};

	Color operator*(const Color &other){
		return Color(255*(r/255.0)*(other.r/255.0),
					 255*(g/255.0)*(other.g/255.0),
					 255*(b/255.0)*(other.b/255.0));
	}

	Color operator/(const Color &other){
		return Color(255*(r/255.0)/(other.r/255.0),
					 255*(g/255.0)/(other.g/255.0),
					 255*(b/255.0)/(other.b/255.0));
	}

	Color operator+(const Color &other){
		return Color(std::min(255, r+other.r),
					 std::min(255, g+other.g),
					 std::min(255, b+other.b));
	}

	Color operator-(const Color &other){
		return Color(std::max(0, r-other.r),
					 std::max(0, g-other.g),
					 std::max(0, b-other.b));
	}

	Color operator*(const double &other){
		return Color((uint8_t)(r*other),
					 (uint8_t)(g*other),
					 (uint8_t)(b*other));
	}

	Color operator/(const double &other){
		return Color((uint8_t)(r/other),
					 (uint8_t)(g/other),
					 (uint8_t)(b/other));
	}

	Color operator+=(const Color &other){
		r = std::min(255, r+other.r);
		g = std::min(255, g+other.g);
		b = std::min(255, b+other.b);
		return *this;
	}

	Color operator-=(const Color &other){
		r = std::max(255, r-other.r);
		g = std::max(255, g-other.g);
		b = std::max(255, b-other.b);
		return *this;
	}

	Color operator*=(const double &other){
		r = std::min(255.0, r*other);
		g = std::min(255.0, g*other);
		b = std::min(255.0, b*other);
		return *this;
	}
};



#endif /* COLOR_H_ */
