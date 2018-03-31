/**
 * PointVector -- n-dimensional point and vector implementations
 * Copyright (c) 2018 Onur Rauf Bingol
 *
 * Licensed under the MIT License
 *
 * Vector class
 */

#ifndef GPV_VECTOR_HXX
#define GPV_VECTOR_HXX

#include <iostream>
#include <memory>
#include <initializer_list>
#include <stdexcept>

#ifndef GPV_POINTVECTOR_EVAL_TOL
#define GPV_POINTVECTOR_EVAL_TOL 10e-5
#endif

namespace geomdl {

    /**
     * @brief Represents n-dimensional vectors.
     * @tparam T type of the values contained, e.g. float, double
     * @tparam S dimension
     */
    template<typename T, std::size_t S>
    class Vector {
    public:
        using value_type = T; ///< value type, first keyword, expected to be a primitive type.
        using size_type = std::size_t; ///< size type, second keyword, expected to be a positive number.
        using iterator = T *; ///< iterator type.

        /**
         * @brief Default constructor.
         */
        Vector() : comp{0}, dim(S) {};

        /**
         * @brief Copy constructor.
         * @param rhs object on the right hand side
         */
        Vector(const Vector<value_type, S> &rhs) {
            std::copy(rhs.comp, rhs.comp + rhs.dim, this->comp);
            this->dim = rhs.dim;
        }

        /**
         * @brief Aggregate constructor from a brace-init-list.
         * @param values brace-init-list
         */
        Vector(std::initializer_list<value_type> values) : Vector() {
            if (this->dim != values.size())
                throw std::range_error("Size of the array is not equal to the dimension of the object");
            std::copy(values.begin(), values.end(), this->comp);
        };

        /**
         * @brief Initializes the vector from an array.
         * @param values array containing the initial values
         */
        explicit Vector(T *values) : Vector() {
            for (size_type i = 0; i < this->dim; ++i)
                this->comp[i] = values[i];
        };

        /**
         * @brief Initializes all components of the vector to the same value.
         * @param value initial value
         */
        explicit Vector(T value) : Vector() {
            for (size_type i = 0; i < this->dim; ++i)
                this->comp[i] = value;
        }

        /**
         * @brief Copy assignment operator.
         * @param rhs object to be copied
         * @return vector
         */
        Vector<value_type, S> &operator=(const Vector<value_type, S> &rhs) {
            std::copy(rhs.comp, rhs.comp + rhs.dim, this->comp);
            this->dim = rhs.dim;
            return *this;
        }

        /**
         * @brief Move assignment operator.
         * @param rhs object to be moved
         * @return vector
         */
        Vector<value_type, S> &operator=(Vector<value_type, S> &&rhs) {
            std::copy(rhs.comp, rhs.comp + rhs.dim, this->comp);
            this->dim = rhs.dim;
            for (size_type i = 0; i < rhs.dim; ++i)
                rhs.comp[i] = T(0);
            return *this;
        }

        /**
         * @brief Vector addition.
         * @param rhs object on the right hand side
         * @return object after operation
         */
        Vector<value_type, S> &operator+=(const Vector<value_type, S> &rhs) {
            for (size_type i = 0; i < this->dim; ++i)
                this->comp[i] += rhs.comp[i];
            return *this;
        }

        /**
         * @brief Vector subtraction.
         * @param rhs object on the right hand side
         * @return object after operation
         */
        Vector<value_type, S> &operator-=(const Vector<value_type, S> &rhs) {
            for (size_type i = 0; i < this->dim; ++i)
                this->comp[i] -= rhs.comp[i];
            return *this;
        }

        /**
         * @brief Scales up this vector by a multiplying it with a number.
         * @param rhs scaling factor
         * @return current vector scaled up
         */
        Vector<value_type, S> &operator*=(const T &rhs) {
            for (size_type i = 0; i < this->dim; ++i)
                this->comp[i] *= rhs;
            return *this;
        }

        /**
         * @brief Scales down this vector by a diving it by a number.
         * @param rhs scaling factor
         * @return current vector scaled down
         */
        Vector<value_type, S> &operator/=(const T &rhs) {
            for (size_type i = 0; i < this->dim; ++i)
                this->comp[i] /= rhs;
            return *this;
        }

        /**
         * @brief Vector addition.
         * @param lhs object on the left hand side
         * @param rhs object on the right hand side
         * @return object after operation
         */
        friend Vector<value_type, S> operator+(Vector<value_type, S> lhs, const Vector<value_type, S> &rhs) {
            lhs += rhs;
            return lhs;
        }

        /**
         * @brief Vector subtraction.
         * @param lhs object on the left hand side
         * @param rhs object on the right hand side
         * @return object after operation
         */
        friend Vector<value_type, S> operator-(Vector<value_type, S> lhs, const Vector<value_type, S> &rhs) {
            lhs -= rhs;
            return lhs;
        }

        /**
         * @brief Vector dot product.
         * @param lhs vector on the left hand side
         * @param rhs vector on the right hand side
         * @return result of the operation
         */
        friend value_type operator*(Vector<value_type, S> lhs, const Vector<value_type, S> &rhs) {
            value_type sum = 0;
            for (size_type i = 0; i < lhs.dim; ++i)
                sum += lhs.comp[i] * rhs.comp[i];
            return sum;
        }

        /**
         * @brief Scales up the vector by a multiplying it with a number.
         * @param lhs vector to be scaled up
         * @param rhs scaling factor
         * @return the scaled vector
         */
        friend Vector<value_type, S> operator*(Vector<value_type, S> lhs, const T &rhs) {
            lhs *= rhs;
            return lhs;
        }

        /**
         * @brief Scales down the vector by diving it by a number.
         * @param lhs vector to be scaled down
         * @param rhs scaling factor
         * @return the scaled vector
         */
        friend Vector<value_type, S> operator/(Vector<value_type, S> lhs, const T &rhs) {
            lhs /= rhs;
            return lhs;
        }

        /**
         * @brief Array subscript operator.
         * @param idx array index
         * @return value corresponding to the index
         */
        value_type &operator[](size_type idx) {
            return this->comp[idx];
        }

        /**
         * @brief Array subscript operator (const).
         * @param idx array index
         * @return value corresponding to the index
         */
        const value_type &operator[](size_type idx) const {
            return this->comp[idx];
        }

        /**
         * @brief Equality operator.
         * @param lhs object on the left hand side
         * @param rhs object on the right hand side
         * @return object after operation
         */
        friend bool operator==(const Vector<value_type, S> &lhs, const Vector<value_type, S> &rhs) {
            bool retval = true;
            for (size_type i = 0; i < lhs.dim; ++i) {
                if (std::abs(lhs.comp[i] - rhs.comp[i]) > GPV_POINTVECTOR_EVAL_TOL)
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
        friend bool operator!=(const Vector<value_type, S> &lhs, const Vector<value_type, S> &rhs) {
            return !(lhs == rhs);
        }

        /**
         * @brief Stream extraction operator.
         * @param lhs object on the left hand side
         * @param rhs object on the right hand side
         * @return object after operation
         */
        friend std::ostream &operator<<(std::ostream &lhs, Vector<value_type, S> &rhs) {
            lhs << "(";
            for (size_type i = 0; i < rhs.dim; ++i) {
                lhs << rhs.comp[i];
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
        friend std::istream &operator>>(std::istream &lhs, Vector<value_type, S> &rhs) {
            for (size_type i = 0; i < rhs.dim; ++i) {
                lhs >> rhs.comp[i];
            }
            return lhs;
        }

        /**
         * @brief Vector cross product.
         * @param rhs 3 dimensional vector on the right hand side of the cross product
         * @return a new vector object as a result of the operation
         */
        Vector<value_type, S> cross(const Vector<value_type, S> &rhs) {
            Vector<value_type, S> retval;
            if (this->dim != 3 || rhs.dim != 3) {
                throw std::runtime_error("Cross product can only work with certain dimensions");
            } else {
                retval[0] = (this->comp[1] * rhs.comp[2]) - (this->comp[2] * rhs.comp[1]);
                retval[1] = (this->comp[2] * rhs.comp[0]) - (this->comp[0] * rhs.comp[2]);
                retval[2] = (this->comp[0] * rhs.comp[1]) - (this->comp[1] * rhs.comp[0]);
            }
            return retval;
        }

        /**
         * @brief Iterator begin.
         * @return iterator
         */
        iterator begin() {
            return &this->comp[0];
        }

        /**
         * @brief Iterator end.
         * @return iterator
         */
        iterator end() {
            return &this->comp[this->dim];
        }

        /**
         * @brief Access data.
         *
         * Returns the direct pointer to the array used internally.
         * @return pointer to the array
         */
        value_type *data() {
            return &this->comp[0];
        }

    private:
        std::size_t dim; ///< dimension of the object
        T comp[S]; ///< array storing the elements
    };
}

#endif //GPV_VECTOR_HXX
