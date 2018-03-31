/**
 * PointVector -- n-dimensional point and vector implementations
 * Copyright (c) 2018 Onur Rauf Bingol
 *
 * Licensed under the MIT License
 *
 * Point class
 */

#ifndef GPV_POINT_HXX
#define GPV_POINT_HXX

#include <iostream>
#include <memory>
#include <initializer_list>
#include <stdexcept>

#ifndef GPV_POINTVECTOR_EVAL_TOL
#define GPV_POINTVECTOR_EVAL_TOL 10e-5
#endif

namespace geomdl {

    /**
     * @brief Represents n-dimensional points.
     * @tparam T type of the values contained, e.g. float, double
     * @tparam S dimension
     */
    template<typename T, std::size_t S>
    class Point {
    public:
        using value_type = T; ///< value type, first keyword, expected to be a primitive type.
        using size_type = std::size_t; ///< size type, second keyword, expected to be a positive number.
        using iterator = T *; ///< iterator type.

        /**
         * @brief Default constructor.
         */
        Point() : coord{0}, dim(S) {};

        /**
         * @brief Copy constructor.
         * @param rhs object on the right hand side
         */
        Point(const Point<value_type, S> &rhs) {
            std::copy(rhs.coord, rhs.coord + rhs.dim, this->coord);
            this->dim = rhs.dim;
        }

        /**
         * @brief Aggregate constructor from a brace-init-list.
         * @param values brace-init-list
         */
        Point(std::initializer_list<value_type> values) : Point() {
            if (this->dim != values.size())
                throw std::range_error("Size of the array is not equal to the dimension of the object");
            std::copy(values.begin(), values.end(), this->coord);
        };

        /**
         * @brief Initializes the point from an array.
         * @param values array containing the initial values
         */
        explicit Point(T *values) : Point() {
            for (size_type i = 0; i < this->dim; ++i)
                this->coord[i] = values[i];
        };

        /**
         * @brief Initializes all components of the point to the same value.
         * @param value initial value
         */
        explicit Point(T value) : Point() {
            for (size_type i = 0; i < this->dim; ++i)
                this->coord[i] = value;
        }

        /**
         * @brief Copy assignment operator.
         * @param rhs object to be copied
         * @return point
         */
        Point<value_type, S> &operator=(const Point<value_type, S> &rhs) {
            std::copy(rhs.coord, rhs.coord + rhs.dim, this->coord);
            this->dim = rhs.dim;
            return *this;
        }

        /**
         * @brief Move assignment operator.
         * @param rhs object to be moved
         * @return point
         */
        Point<value_type, S> &operator=(Point<value_type, S> &&rhs) {
            std::copy(rhs.coord, rhs.coord + rhs.dim, this->coord);
            this->dim = rhs.dim;
            for (size_type i = 0; i < rhs.dim; ++i)
                rhs.coord[i] = T(0);
            return *this;
        }

        /**
         * @brief Compound assignment operator (complex addition).
         * @param rhs object to be added
         * @return current object after operation
         */
        Point<value_type, S> &operator+=(const Point<value_type, S> &rhs) {
            for (size_type i = 0; i < this->dim; ++i)
                this->coord[i] += rhs.coord[i];
            return *this;
        }

        /**
         * @brief Compound assignment operator (complex subtraction).
         * @param rhs object to be subtracted
         * @return current object after operation
         */
        Point<value_type, S> &operator-=(const Point<value_type, S> &rhs) {
            for (size_type i = 0; i < this->dim; ++i)
                this->coord[i] -= rhs.coord[i];
            return *this;
        }

        /**
         * @brief Compound assignment operator (primitive addition).
         * @param rhs object to be added
         * @return current object after operation
         */
        Point<value_type, S> &operator+=(const T &rhs) {
            for (size_type i = 0; i < this->dim; ++i)
                this->coord[i] += rhs;
            return *this;
        }

        /**
         * @brief Compound assignment operator (primitive subtraction).
         * @param rhs object to be subtracted
         * @return current object after operation
         */
        Point<value_type, S> &operator-=(const T &rhs) {
            for (size_type i = 0; i < this->dim; ++i)
                this->coord[i] -= rhs;
            return *this;
        }

        /**
         * @brief Compound assignment operator (primitive multiplication).
         * @param rhs object to be multiplicated
         * @return current object after operation
         */
        Point<value_type, S> &operator*=(const T &rhs) {
            for (size_type i = 0; i < this->dim; ++i)
                this->coord[i] *= rhs;
            return *this;
        }

        /**
         * @brief Compound assignment operator (primitive division).
         * @param rhs object to be divided
         * @return current object after operation
         */
        Point<value_type, S> &operator/=(const T &rhs) {
            for (size_type i = 0; i < this->dim; ++i)
                this->coord[i] /= rhs;
            return *this;
        }

        /**
         * @brief Arithmetic operator (complex addition).
         * @param lhs object on the left hand side
         * @param rhs object on the right hand side
         * @return object after operation
         */
        friend Point<value_type, S> operator+(Point<value_type, S> lhs, const Point<value_type, S> &rhs) {
            lhs += rhs;
            return lhs;
        }

        /**
         * @brief Arithmetic operator (complex subtraction).
         * @param lhs object on the left hand side
         * @param rhs object on the right hand side
         * @return object after operation
         */
        friend Point<value_type, S> operator-(Point<value_type, S> lhs, const Point<value_type, S> &rhs) {
            lhs -= rhs;
            return lhs;
        }

        /**
         * @brief Arithmetic operator (primitive addition).
         * @param lhs object on the left hand side
         * @param rhs object on the right hand side
         * @return object after operation
         */
        friend Point<value_type, S> operator+(Point<value_type, S> lhs, const T &rhs) {
            lhs += rhs;
            return lhs;
        }

        /**
         * @brief Arithmetic operator (primitive subtraction).
         * @param lhs object on the left hand side
         * @param rhs object on the right hand side
         * @return object after operation
         */
        friend Point<value_type, S> operator-(Point<value_type, S> lhs, const T &rhs) {
            lhs -= rhs;
            return lhs;
        }

        /**
         * @brief Arithmetic operator (primitive multiplication).
         * @param lhs object on the left hand side
         * @param rhs object on the right hand side
         * @return object after operation
         */
        friend Point<value_type, S> operator*(Point<value_type, S> lhs, const T &rhs) {
            lhs *= rhs;
            return lhs;
        }

        /**
         * @brief Arithmetic operator (primitive division).
         * @param lhs object on the left hand side
         * @param rhs object on the right hand side
         * @return object after operation
         */
        friend Point<value_type, S> operator/(Point<value_type, S> lhs, const T &rhs) {
            lhs /= rhs;
            return lhs;
        }

        /**
         * @brief Array subscript operator.
         * @param idx array index
         * @return value corresponding to the index
         */
        value_type &operator[](size_type idx) {
            return this->coord[idx];
        }

        /**
         * @brief Array subscript operator (const).
         * @param idx array index
         * @return value corresponding to the index
         */
        const value_type &operator[](size_type idx) const {
            return this->coord[idx];
        }

        /**
         * @brief Equality operator.
         * @param lhs object on the left hand side
         * @param rhs object on the right hand side
         * @return object after operation
         */
        friend bool operator==(const Point<value_type, S> &lhs, const Point<value_type, S> &rhs) {
            bool retval = true;
            for (size_type i = 0; i < lhs.dim; ++i) {
                if (std::abs(lhs.coord[i] - rhs.coord[i]) > GPV_POINTVECTOR_EVAL_TOL)
                    retval = false;
            }
            return retval;
        }

        /**
         * @brief Inequality operator.
         * @param lhs object on the left hand side
         * @param rhs object on the right hand side
         * @return object after operation
         */
        friend bool operator!=(const Point<value_type, S> &lhs, const Point<value_type, S> &rhs) {
            return !(lhs == rhs);
        }

        /**
         * @brief Stream extraction operator.
         * @param lhs object on the left hand side
         * @param rhs object on the right hand side
         * @return object after operation
         */
        friend std::ostream &operator<<(std::ostream &lhs, Point<value_type, S> &rhs) {
            lhs << "(";
            for (size_type i = 0; i < rhs.dim; ++i) {
                lhs << rhs.coord[i];
                lhs << ((i != rhs.dim - 1) ? ", " : ")");
            }
            return lhs;
        }

        /**
         * @brief Stream insertion operator.
         * @param lhs object on the left hand side
         * @param rhs object on the right hand side
         * @return object after operation
         */
        friend std::istream &operator>>(std::istream &lhs, Point<value_type, S> &rhs) {
            for (size_type i = 0; i < rhs.dim; ++i) {
                lhs >> rhs.coord[i];
            }
            return lhs;
        }

        /**
         * @brief Iterator begin.
         * @return iterator
         */
        iterator begin() {
            return &this->coord[0];
        }

        /**
         * @brief Iterator end.
         * @return iterator
         */
        iterator end() {
            return &this->coord[this->dim];
        }

        /**
         * @brief Access data.
         *
         * Returns the direct pointer to the array used internally.
         * @return pointer to the array
         */
        value_type *data() {
            return &this->coord[0];
        }

    private:
        std::size_t dim; ///< dimension of the object
        T coord[S]; ///< array storing the elements
    };
}

#endif //GPV_POINT_HXX
