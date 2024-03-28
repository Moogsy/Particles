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

   double calculatePotential(Particle<N> & other){
        Vector<N> dist_vec = readPosition - other.readPosition;
        double norm = dist_vec.euclidianNorm();
        double inversed_norm =(1/norm)**6;
        return 4*inversed_norm*(inversed_norm-1)
    }

   
    /* Operations */
    const bool operator==(const Particle<N> & p) const {
        return (
            this->identifier == p.identifier &&
            this->category == p.category
        );
    }

    friend std::ostream& operator<<(std::ostream &os, const Particle & p) {
        os << "Particule{";
        os << "position=" << p.position;
        os << ", " << "vitesse=" << p.speed;
        os << ", " << "force=" << p.force;
        os << ", " << "masse=" << p.mass;
        os << ", " << "identifiant=" << p.identifier; 
        os << "}";
        return os; 
    }
};

typedef Particle<2> Particle2D;
typedef Particle<3> Particle3D;