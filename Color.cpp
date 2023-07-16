/*
 * Color.cpp
 *
 *  Created on: Jan 19, 2023
 *      Author: Nathan
 */
#include <algorithm>

#include "Color.h"

namespace priori{

	Color::Color(uint32_t c) : r((c>>16)%0x100), g((c>>8)%0x100), b(c%0x100), a(c>>24) {};
	Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) : r(r), g(g), b(b), a(a) {};

	Color Color::operator*(const Color &other) const{
		return Color(255*(r/255.0)*(other.r/255.0),
					 255*(g/255.0)*(other.g/255.0),
					 255*(b/255.0)*(other.b/255.0));
	}

	Color Color::operator/(const Color &other) const{
		return Color(255*(r/255.0)/(other.r/255.0),
					 255*(g/255.0)/(other.g/255.0),
					 255*(b/255.0)/(other.b/255.0));
	}

	Color Color::operator+(const Color &other) const{
		return Color(std::min(255, r+other.r),
					 std::min(255, g+other.g),
					 std::min(255, b+other.b));
	}

	Color Color::operator-(const Color &other) const{
		return Color(std::max(0, r-other.r),
					 std::max(0, g-other.g),
					 std::max(0, b-other.b));
	}

	Color Color::operator*(const double &d) const{
		return Color(std::min(255, std::max(0, (int)(r*d))),
					 std::min(255, std::max(0, (int)(g*d))),
					 std::min(255, std::max(0, (int)(b*d))));
	}

	Color Color::operator/(const double &d) const{
		return Color(std::min(255, std::max(0, (int)(r/d))),
					 std::min(255, std::max(0, (int)(g/d))),
					 std::min(255, std::max(0, (int)(b/d))));
	}

	Color Color::operator+=(const Color &other){
		r = std::min(255, r+other.r);
		g = std::min(255, g+other.g);
		b = std::min(255, b+other.b);
		return *this;
	}

	Color Color::operator-=(const Color &other){
		r = std::max(0, r-other.r);
		g = std::max(0, g-other.g);
		b = std::max(0, b-other.b);
		return *this;
	}

	Color Color::operator*=(const Color &other){
		r = 255*(r/255.0)*(other.r/255.0);
		g = 255*(g/255.0)*(other.g/255.0);
		b = 255*(b/255.0)*(other.b/255.0);
		return *this;
	}

	Color Color::operator/=(const Color &other){
		r = 255*(r/255.0)/(other.r/255.0);
		g = 255*(g/255.0)/(other.g/255.0);
		b = 255*(b/255.0)/(other.b/255.0);
		return *this;
	}

	Color Color::operator*=(const double &d){
		r = std::min(255, std::max(0, (int)(r*d)));
		g = std::min(255, std::max(0, (int)(g*d)));
		b = std::min(255, std::max(0, (int)(b*d)));
		return *this;
	}

	Color Color::operator/=(const double &d){
		r = std::min(255, std::max(0, (int)(r/d)));
		g = std::min(255, std::max(0, (int)(g/d)));
		b = std::min(255, std::max(0, (int)(b/d)));
		return *this;
	}

	bool Color::operator==(const Color &other){
		return r == other.r && g == other.g && b == other.b;
	}

	bool Color::operator!=(const Color &other){
		return r != other.r && g != other.g && b != other.b;
	}

	Color::operator uint32_t() const{
		return ((uint32_t)a<<24) |
			   ((uint32_t)r<<16) |
			   ((uint32_t)g<<8)  |
			   b;
	}

	Color average(Color c1, Color c2){
		return Color((c1.r+c2.r)/2, (c1.g+c2.g)/2, (c1.b+c2.b)/2);
	}
}
