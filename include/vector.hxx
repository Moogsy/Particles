#include <array>
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
    void operator+(const Vector<N> & v) const {
        auto ret = Vector(*this);
        ret += v;
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
        auto v = Vector(*this);
        v *= x;
        return v;
    }

    /// @brief Multiplication of a scalar by a vector
    friend Vector<N> operator*(double x, const Vector<N> &v) {
        return v * x;
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