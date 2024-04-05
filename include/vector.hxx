#pragma once

#include <array>
#include <cmath>
#include <iostream>

template <std::size_t N>
class Vector {
private:
    std::array<double, N> coords;
public:
    /// @brief Creates a new zero vector of size N
    Vector() {
        this->coords = std::array<double, N>();
    };

    /// @brief Creates a new vector from the provided initializer
    /// @warning If the amount of provided arguments doesn't match the vector's size
    /// then: 
    /// - Extra arguments will be discarded
    /// - Non initialized ones will be zero-initialized
    /// @param args 
    Vector(const std::initializer_list<double> args) {
        this->coords = std::array<double, N>();

        auto provided = args.begin();
        auto coord = this->coords.begin();

        while (provided != args.end() && coord != this->coords.end()) {
            *coord = *provided;
            ++provided;
            ++coord;
        }
    }

    /// @brief Squared euclidian norm of the current vector
    double euclidianNormSquared() {
        double dist = 0.0;
        for (auto coord: this->coords) {
            dist += coord * coord;
        }
        return dist;
    };

    /// @brief Euclidian norm of the current vector
    inline double euclidianNorm() {
        return std::sqrt(this->euclidianNormSquared());
    }

    /// @brief Squared Euclidian distance between two vectors
    double euclidianDistanceSquared(const Vector<N> & v) const {
        return (*this - v).euclidianNormSquared();
    }

    /// @brief Euclidian distance between this vector and another one
    inline double euclidianDistance(const Vector<N> & v) const {
        return std::sqrt(this->euclidianDistanceSquared(v));
    }
    
    /// @brief Normalizes this vector if it is not zero
    void normalizeOrZero() {
        double norm = this->euclidianNorm();
        if (norm != 0.0) {
            *this /= this->euclidianNorm();
        }
        
    } 

    /// @brief Sets all of this vector's coordinates to 0
    void zero() {
        for (auto &coord: this->coords) {
            coord = 0;
        }

    }

    /// @brief Copies another vector's value into ours
    Vector<N> copy() const {
        Vector<N> ret;
        auto ours = this->coords.begin();
        auto other = ret.coords.begin();

        while (ours != this->coords.end()) {
            *other = *ours;
            ++ours;
            ++other;
        }

        return ret;
    }

    /* Comparison operations */
    bool operator==(const Vector<N> & v) const {
        return this->coords == v.coords;
    }

    /// @return The size of the vector
    constexpr std::size_t getSize() const {
        return N;
    };

    /* Read / Write operations */

    /// @brief Gets a specified component from the vector
    /// @param index The index of the component to get
    /// @return The corresponding vector value
    double & operator[](std::size_t index) {
        if (index < 0 || index >= N) {
            throw std::out_of_range("Index out of range");
        }
        return this->coords[index];
    }

    double operator[](std::size_t index) const {
        if (index < 0 || index >= N) {
            throw std::out_of_range("Index out of range");
        }
        return this->coords[index];
    }

    /* Arithmetic operations*/

    /// @brief In place addition of two same sized vectors
    /// @param v The vector to add this one with.
    void operator+=(const Vector<N> & v) {
        auto ours = this->coords.begin();
        auto others = v.coords.begin();

        while (ours != this->coords.end())
        {
            *ours += *others;
            ++ours;
            ++others;
        }
    }

    /// @brief Addition of two same sized vectors 
    /// @param v The vector to add that one with
    Vector<N> operator+(const Vector<N> & v) const {
        auto ret = Vector(*this);
        ret += v;
        return ret;
    }

    /// @brief In place substraction of two same sized vectors
    /// @param v  The vector to sub that one with
    void operator-=(const Vector<N> & v) {
        auto ours = this->coords.begin();
        auto others = v.coords.begin();

        while (ours != this->coords.end())
        {
            *ours -= *others;
            ++ours;
            ++others;
        }
    }

    bool isZero() const {
        for (auto &coord: this->coords) {
            if (coord != 0) {
                return false;
            }
        }
        return true;
    }

    Vector<N> operator-() const {
        return Vector<N>() - *this;
    }

    Vector<N> operator-(const Vector<N> & v) const {
        Vector<N> ret(*this);
        ret -= v;
        return ret;
    }

    /// @brief Inplace multiplication of a vector by a scalar
    /// @param x The scalar to multiply this vector with
    void operator*=(const double x) {
        for (auto &coord: this->coords) {
            coord *= x;
        }
    }

    /// @brief Multiplication of a vector by a scalar
    /// @param x The scalar to multiply the resulting vector with
    Vector<N> operator*(const double x) const {
        Vector<N> v(*this);
        v *= x;
        return v;
    }

    /// @brief Multiplication of a scalar by a vector
    friend Vector<N> operator*(double x, const Vector<N> &v) {
        return v * x;
    }

    void operator/=(double x) {
        for (auto &coord: this->coords) {
            coord /= x;
        }
    }

    Vector<N> operator/(double x) {
        Vector<N> v(*this);
        v /= x;
        return v;
    }

    /// @brief Outputs the vector to the provided stream
    /// @param os The stream to output the vector to 
    /// @param v The vector to output
    /// @return The provided stream
    friend std::ostream& operator<<(std::ostream &os, const Vector<N> &v) {
        os << "Vector{";

        auto coord = v.coords.begin();
        while (coord + 1 != v.coords.end()) {
            os << *coord << ", ";
            ++coord;
        }
        os << *coord << "}";

        return os;
    };
};

typedef Vector<2> Vector2D;
typedef Vector<3> Vector3D;