/**
 * PointVector -- n-dimensional point and vector implementations
 * Copyright (c) 2018 Onur Rauf Bingol
 *
 * Licensed under the MIT License
 * Catch2 is licensed under the Boost Software Licence 1.0 -- https://github.com/catchorg/Catch2
 *
 *
 * Unit testing of Vector class using Catch Framework
 */

#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "Vector.hxx"

#define Vector3 geomdl::Vector<float, 3>
#define GPV_TEST_EQTOL 10e-5


TEST_CASE("Test Vector Template Class", "[vector]") {

    SECTION("Default constructor") {

        Vector3 pt;

        REQUIRE(abs(pt[0] - 0) < GPV_TEST_EQTOL);
        REQUIRE(abs(pt[1] - 0) < GPV_TEST_EQTOL);
        REQUIRE(abs(pt[2] - 0) < GPV_TEST_EQTOL);
    }

    SECTION("Initializer list constructor") {

        Vector3 pt = {1, 2, 3};

        REQUIRE(abs(pt[0] - 1) < GPV_TEST_EQTOL);
        REQUIRE(abs(pt[1] - 2) < GPV_TEST_EQTOL);
        REQUIRE(abs(pt[2] - 3) < GPV_TEST_EQTOL);
    }

    SECTION("Pointer constructor") {

        float *dataptr = new float[3];
        dataptr[0] = 1;
        dataptr[1] = 2;
        dataptr[2] = 3;

        Vector3 pt(dataptr);

        delete[] dataptr;

        REQUIRE(abs(pt[0] - 1) < GPV_TEST_EQTOL);
        REQUIRE(abs(pt[1] - 2) < GPV_TEST_EQTOL);
        REQUIRE(abs(pt[2] - 3) < GPV_TEST_EQTOL);
    }

    SECTION("Single value constructor") {

        Vector3 pt(10);

        REQUIRE(abs(pt[0] - 10) < GPV_TEST_EQTOL);
        REQUIRE(abs(pt[1] - 10) < GPV_TEST_EQTOL);
        REQUIRE(abs(pt[2] - 10) < GPV_TEST_EQTOL);
    }

    SECTION("Copy constructor") {

        Vector3 pt2 = {2, 5, 7};
        Vector3 pt(pt2);

        REQUIRE(abs(pt[0] - 2) < GPV_TEST_EQTOL);
        REQUIRE(abs(pt[1] - 5) < GPV_TEST_EQTOL);
        REQUIRE(abs(pt[2] - 7) < GPV_TEST_EQTOL);
    }

    SECTION("Copy assignment operator") {

        Vector3 pt = {20, 50, 70};
        Vector3 pt2 = {2, 5, 7};
        pt = pt2;

        REQUIRE(abs(pt[0] - 2) < GPV_TEST_EQTOL);
        REQUIRE(abs(pt[1] - 5) < GPV_TEST_EQTOL);
        REQUIRE(abs(pt[2] - 7) < GPV_TEST_EQTOL);
    }

    SECTION("Vector addition operator") {

        Vector3 pt;
        Vector3 pt1 = {6, 5, 4};
        Vector3 pt2 = {1, 2, 3};
        pt = pt1 + pt2;

        REQUIRE(abs(pt[0] - 7) < GPV_TEST_EQTOL);
        REQUIRE(abs(pt[1] - 7) < GPV_TEST_EQTOL);
        REQUIRE(abs(pt[2] - 7) < GPV_TEST_EQTOL);
    }

    SECTION("Vector subtraction operator") {

        Vector3 pt;
        Vector3 pt1 = {6, 5, 4};
        Vector3 pt2 = {1, 2, 3};
        pt = pt1 - pt2;

        REQUIRE(abs(pt[0] - 5) < GPV_TEST_EQTOL);
        REQUIRE(abs(pt[1] - 3) < GPV_TEST_EQTOL);
        REQUIRE(abs(pt[2] - 1) < GPV_TEST_EQTOL);
    }


    SECTION("Value multiplication operator") {

        Vector3 pt;
        Vector3 pt1 = {6, 5, 4};
        float val = 2;
        pt = pt1 * val;

        REQUIRE(abs(pt[0] - 12) < GPV_TEST_EQTOL);
        REQUIRE(abs(pt[1] - 10) < GPV_TEST_EQTOL);
        REQUIRE(abs(pt[2] - 8) < GPV_TEST_EQTOL);
    }

    SECTION("Value division operator") {

        Vector3 pt;
        Vector3 pt1 = {6, 5, 1};
        float val = 2;
        pt = pt1 / val;

        REQUIRE(abs(pt[0] - 3) < GPV_TEST_EQTOL);
        REQUIRE(abs(pt[1] - 2.5) < GPV_TEST_EQTOL);
        REQUIRE(abs(pt[2] - 0.5) < GPV_TEST_EQTOL);
    }

    SECTION("Equality operator") {

        Vector3 pt1 = {2.7f, 3.11f, 6.65f};
        Vector3 pt2 = {2.7f, 3.11f, 6.65f};

        REQUIRE((pt1 == pt2) == true);
    }

    SECTION("Inequality operator") {

        Vector3 pt1 = {2.7f, 3.11f, 6.65f};
        Vector3 pt2 = {2.7f, 3.12f, 6.67f};

        REQUIRE((pt1 != pt2) == true);
    }

    SECTION("Stream extraction operator") {

        Vector3 pt = {10, 20, 30};
        std::stringstream out;
        out << pt;

        REQUIRE((out.str() == "(10, 20, 30)") == true);
    }

    SECTION("Stream insertion & extraction operator") {

        Vector3 pt;
        std::stringstream in;
        in.str("100 200 356");
        in >> pt;
        std::stringstream out;
        out << pt;

        REQUIRE((out.str() == "(100, 200, 356)") == true);
    }

    SECTION("Stream insertion operator") {

        Vector3 pt;
        std::stringstream in;
        in.str("1.1 2.71 3.9234");
        in >> pt;

        REQUIRE(abs(pt[0] - 1.1) < GPV_TEST_EQTOL);
        REQUIRE(abs(pt[1] - 2.71) < GPV_TEST_EQTOL);
        REQUIRE(abs(pt[2] - 3.9234) < GPV_TEST_EQTOL);
    }

    SECTION("Stream insertion & data() method") {

        Vector3 pt;
        std::stringstream in;
        in.str("1.1 2.71 3.9234");
        in >> pt;

        float *data = pt.data();

        REQUIRE(abs(data[0] - 1.1) < GPV_TEST_EQTOL);
        REQUIRE(abs(data[1] - 2.71) < GPV_TEST_EQTOL);
        REQUIRE(abs(data[2] - 3.9234) < GPV_TEST_EQTOL);
    }

    SECTION("Dot product") {

        Vector3 pt1 = {1, 2, 3};
        Vector3 pt2 = {1, 2, 3};
        float dotprod = pt1 * pt2;

        REQUIRE(abs(dotprod - 14) < GPV_TEST_EQTOL);
    }

    SECTION("Cross product #1") {

        Vector3 pt1 = {1, 2, 3};
        Vector3 pt2 = {4, 5, 6};
        Vector3 res = {-3, 6, -3};
        Vector3 pt = pt1.cross(pt2);

        REQUIRE((pt == res) == true);
    }

    SECTION("Cross product #2") {

        Vector3 pt1 = {-7.0f, 3.2f, 1.47f};
        Vector3 pt2 = {3.0f, -1.69f, 0.0f};
        Vector3 res = {2.4843f, 4.41f, 2.23f};
        Vector3 pt = pt1.cross(pt2);

        REQUIRE((pt == res) == true);
    }

}
