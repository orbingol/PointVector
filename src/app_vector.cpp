/**
 * PointVector -- n-dimensional point and vector implementations
 * Copyright (c) 2018 Onur Rauf Bingol
 *
 * Licensed under the MIT License
 *
 *
 * Vector class demonstration
 */

#include <iostream>
#include "Vector.hxx"

// Define Vector3
#define Vector3 geomdl::Vector<double, 3>


int main(int argc, char **argv) {
    // Test Vector.hxx
    std::cout << "Testing Example 1..." << std::endl;

    // Test array constructor
    double *data = new double[4];
    data[0] = 1;
    data[1] = 2;
    data[2] = 3;
    data[3] = 4;

    Vector3 vec1(data);

    delete[] data;

    // Test subscript operator
    for (int i = 0; i < 3; ++i)
        std::cout << vec1[i] << std::endl;

    std::cout << "\n" << std::endl;
    std::cout << "Testing Example 2..." << std::endl;

    // Test initializer list constructor
    Vector3 vec2 = {5, 6, 7};

    // Test extraction operator
    std::cout << vec2 << std::endl;

    std::cout << "\n" << std::endl;
    std::cout << "Testing Example 3..." << std::endl;

    // Test copy constructor
    Vector3 vec3(vec2);

    // Test begin() and end()
    for (auto v : vec3)
        std::cout << v << std::endl;

    std::cout << "\n" << std::endl;
    std::cout << "Testing Example 4..." << std::endl;

    // Test addition operator
    Vector3 vec4 = vec1 + vec2;

    // Test extraction operator
    std::cout << vec4 << std::endl;

    std::cout << "\n" << std::endl;
    std::cout << "Testing Example 5..." << std::endl;

    // Test subtraction operator
    Vector3 vec5 = vec2 - vec1;

    // Test data() method
    double *vec5_data = vec5.data();

    for (int i = 0; i < 3; ++i)
        std::cout << vec5_data[i] << std::endl;

    std::cout << "\n" << std::endl;
    std::cout << "Testing Example 6..." << std::endl;

    // Test dot product
    double vec1dot = vec1 * vec1;

    std::cout << vec1dot << std::endl;

//    // Test insertion operator
//    Vector3 vec5;
//    std::cin >> vec5;

    return EXIT_SUCCESS;
}