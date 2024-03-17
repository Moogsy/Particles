#pragma once
#include "vector.hxx"

template <std::size_t N>
class Particle {
private:
    Vector<N> position;
    Vector<N> speed;
    Vector<N> force;
    double mass;
    std::string category;
public:
    std::string identifier;

    Particle() = default;

    Particle(
        std::string identifier,
        std::string category,
        Vector<N> position,
        Vector<N> speed,
        double mass
    ) {
        this->identifier = identifier;
        this->category = category;
        this->position = position;
        this->speed = speed;
        this->mass = mass;
        this->force = Vector<N>();
    };
    
    /* Getters */

    const Vector<N> & readPosition() const {
        return this->position;
    }
    Vector<N> & getPositionMut() {
        return this->position;
    }

    const Vector<N> & readSpeed() const {
        return this->speed;
    }

    Vector<N> & getSpeedMut() {
        return this->speed;
    }

    const Vector<N> & readForce() const {
        return this->force;
    }

    Vector<N> & getForceMut() {
        return this->force;
    }

    const double readMass() const {
        return this->mass;
    }

    double & getMass() {
        return this->mass;
    }


    /* Operations */
    const bool operator==(const Particle<N> & p) const {
        return (
            this->position == p.position &&
            this->speed == p.speed &&
            this->force == p.force &&
            this->mass == p.mass &&
            this->identifier == p.identifier &&
            this->category == p.category
        );
    }
};

typedef Particle<2> Particle2D;
typedef Particle<3> Particle3D;