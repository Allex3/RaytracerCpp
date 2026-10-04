#include <iostream>

#include "vec3.h"
#include "color.h"

int main() {
	float aspect_ratio = 16.0/9.0;

	int image_width = 400;
	int image_height = static_cast<int>(float(image_width)/aspect_ratio);
	image_height = image_height < 1 ? 1 : image_height; // make the image be at minimum 1 pixel long

	// Viewport widths less than one are ok since they are real valued. (why?)
	float viewport_height = 2.0;
	// do not use the aspect_ratio because that's perfect, but our ratio is not
	//	since image_height is rounded down to the nearest integer based on the ideal aspect ratio
	float viewport_width = viewport_height * (float(image_width)/float(image_height));

	// start the .ppm file
	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	for (int j = 0; j < image_height; j++) {
		// progress indicator:
		std::clog << "\rScan-lines remaining: " << (image_height - j) << ' ' << std::flush;
		for (int i = 0; i < image_width; i++) {
			write_color(std::cout,
				color(float(i)/(float(image_width)-1), float(j)/(float(image_height)-1), 0));
		}
	}

	std::clog << "\rDone.\n";
	return 0;
}