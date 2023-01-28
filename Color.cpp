/*
 * Color.cpp
 *
 *  Created on: Jan 19, 2023
 *      Author: Nathan
 */
#include <cmath>

#include "Color.h"

namespace priori{

	Color::Color(uint32_t c) : a(c>>24), r(c>>16), g(c>>8), b(c) {};
	Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) : a(a), r(r), g(g), b(b) {};

	Color Color::operator*(const Color &other){
		return Color(255*(r/255.0)*(other.r/255.0),
					 255*(g/255.0)*(other.g/255.0),
					 255*(b/255.0)*(other.b/255.0));
	}

	Color Color::operator/(const Color &other){
		return Color(255*(r/255.0)/(other.r/255.0),
					 255*(g/255.0)/(other.g/255.0),
					 255*(b/255.0)/(other.b/255.0));
	}

	Color Color::operator+(const Color &other){
		return Color(std::min(255, r+other.r),
					 std::min(255, g+other.g),
					 std::min(255, b+other.b));
	}

	Color Color::operator-(const Color &other){
		return Color(std::max(0, r-other.r),
					 std::max(0, g-other.g),
					 std::max(0, b-other.b));
	}

	Color Color::operator*(const double &other){
		return Color(std::min(255, std::max(0, (int)(r*other))),
					 std::min(255, std::max(0, (int)(g*other))),
					 std::min(255, std::max(0, (int)(b*other))));
	}

	Color Color::operator/(const double &other){
		return Color(std::min(255, std::max(0, (int)(r/other))),
					 std::min(255, std::max(0, (int)(g/other))),
					 std::min(255, std::max(0, (int)(b/other))));
	}

	Color Color::operator+=(const Color &other){
		*this = *this+other;
		return *this;
	}

	Color Color::operator-=(const Color &other){
		*this = *this-other;
		return *this;
	}

	Color Color::operator*=(const Color &other){
		*this = *this*other;
		return *this;
	}

	Color Color::operator/=(const Color &other){
		*this = *this/other;
		return *this;
	}

	Color Color::operator*=(const double &other){
		*this = *this*other;
		return *this;
	}

	Color Color::operator/=(const double &other){
		*this = *this/other;
		return *this;
	}

	Color::operator uint32_t() const{
		return (a<<24) |
			   (r<<16) |
			   (g<<8)  |
			   b;
	}
}
