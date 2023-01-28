/*
 * Color.h
 *
 *  Created on: Dec 9, 2022
 *      Author: Nathan
 */

#ifndef COLOR_H_
#define COLOR_H_

#include <cstdint>

namespace priori{
	struct Color{
		uint8_t a, r, g, b;

		Color(uint32_t c=0);
		Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a=0xFF);

		Color operator*(const Color &other);
		Color operator/(const Color &other);
		Color operator+(const Color &other);
		Color operator-(const Color &other);

		Color operator*(const double &other);
		Color operator/(const double &other);

		Color operator+=(const Color &other);
		Color operator-=(const Color &other);
		Color operator*=(const Color &other);
		Color operator/=(const Color &other);

		Color operator*=(const double &other);
		Color operator/=(const double &other);

		operator uint32_t() const;
	};
}

#endif /* COLOR_H_ */
