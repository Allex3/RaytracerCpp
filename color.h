//
// Created by Alex on 04.10.2026.
//

#ifndef RAYTRACER_IN_ONE_WEEKEND_COLOR_H
#define RAYTRACER_IN_ONE_WEEKEND_COLOR_H

#include "vec3.h"
#include <iostream>

using color = vec3;

void write_color(std::ostream& out, const color& pixel_color) {
	// translate the normalized [0, 1] values into [0, 255] integers
	int rbyte = static_cast<int>(255.0 * pixel_color.x()); // x is r, y is g, z is b normalized
	int gbyte = static_cast<int>(255.0 * pixel_color.y());
	int bbyte = static_cast<int>(255.0 * pixel_color.z());

	// write the color components to the stream
	out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}

#endif //RAYTRACER_IN_ONE_WEEKEND_COLOR_H
