#pragma once
#include "vector.hxx"

template <std::size_t N>
class Particle {
public:
    Vector<N> position;
    Vector<N> speed;
    Vector<N> force;
    double mass;
    std::string identifier;
    std::string category;

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

    Vector<N> & getSpeed() {
        return this->speed;
    }

    double & getMass() {
        return this->mass;
    }

    /* Operations */
    const bool operator==(const Particle<N> & p) const {
        return (this->identifier == p.identifier && this->category == p.category);
    }

    friend std::ostream& operator<<(std::ostream &os, const Particle<N> &p) {
        os << "Particle{";
        os << "identifier=" << p.identifier;
        os << ", " << "category=" << p.category;
        os << ", " << "position=" << p.position;
        os << ", " << "speed=" << p.speed;
        os << ", " << "force=" << p.force;
        os << ", " << "mass=" << p.mass;
        os << "}";
        return os;
    }

};

typedef Particle<2> Particle2D;
typedef Particle<3> Particle3D;