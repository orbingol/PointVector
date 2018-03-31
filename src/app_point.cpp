/**
 * PointVector -- n-dimensional point and vector implementations
 * Copyright (c) 2018 Onur Rauf Bingol
 *
 * Licensed under the MIT License
 *
 *
 * Point class demonstration
 */

#include <iostream>
#include "Point.hxx"

// Define Point3
#define Point3 geomdl::Point<double, 3>


int main(int argc, char **argv) {
    // Test Point.hxx

    // Test array constructor
    double *data = new double[4];
    data[0] = 1;
    data[1] = 2;
    data[2] = 3;
    data[3] = 4;
    Point3 pt1(data);
    delete[] data;

    // Test subscript operator
    for (int i = 0; i < 3; ++i)
        std::cout << pt1[i] << std::endl;

    // Test initializer list constructor
    Point3 pt2 = {5, 6, 7};

    // Test copy constructor
    Point3 pt3(pt2);

    // Test begin() and end()
    for (auto p : pt3)
        std::cout << p << std::endl;

    // Test addition operator
    Point3 pt4 = pt1 + pt2;

    // Test extraction operator
    std::cout << pt4 << std::endl;

//    // Test insertion operator
//    Point3 pt5;
//    std::cin >> pt5;

    // Return success
    return EXIT_SUCCESS;
}