#pragma once
#include "vector.hxx"

template <std::size_t N>
class Particle {
private:
    Vector<N> position;
    Vector<N> speed;
    Vector<N> force;
    double mass;
    std::string identifier;
    std::string category;
public:
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
    Vector<N> & getPosition() {
        return this->position;
    }

    Vector<N> & getForce() {
        return this->force;
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