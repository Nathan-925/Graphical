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
		uint8_t r, g, b, a;

		Color(uint32_t c=0);
		Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a=0xFF);

		Color operator*(const Color &other) const;
		Color operator/(const Color &other) const;
		Color operator+(const Color &other) const;
		Color operator-(const Color &other) const;

		Color operator*(const double &d) const;
		Color operator/(const double &d) const;

		Color operator+=(const Color &other);
		Color operator-=(const Color &other);
		Color operator*=(const Color &other);
		Color operator/=(const Color &other);

		Color operator*=(const double &d);
		Color operator/=(const double &d);

		bool operator==(const Color &other);
		bool operator!=(const Color &other);

		explicit operator uint32_t() const;
	};

	Color average(Color c1, Color c2);
}

#endif /* COLOR_H_ */
