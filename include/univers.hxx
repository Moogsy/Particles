#pragma once

#include <iostream>
#include <vector>
#include "particle.hxx"

template <std::size_t N>
class Univers {

private:
    std::vector<Particle<N>> particles;
    std::vector<Vector<N>> oldForces;
    std::size_t totalParticles;
    double t;
    double deltaT;
public:
    Univers(
        std::vector<Particle<N>> particles,
        double deltaT
    ) {
        this->totalParticles = particles.size();
        this->particles = particles;
        this->oldForces = std::vector<Vector<N>>();
        for (auto _: particles) {
            this->oldForces.push_back(Vector<N>());
        }

        this->t = 0.0;
        this->deltaT = deltaT;
    }

    friend std::ostream& operator<<(std::ostream &os, const Univers<N> &u) {
        std::size_t last = u.particles.size() - 1;
        for (std::size_t i = 0; i < last; ++i) {
            os << u.particles[i] << ", ";
        }
        os << u.particles[last] << "}";

        return os;
    }

    void init() {
        for (Particle<N> &curr: this->particles) {
            curr.getForceMut().zero();

            for (Particle<N> &other: particles) {
                if (curr == other) {
                    continue;
                }
                Vector<N> f = other.readPosition() - curr.readPosition();
                double norm = f.euclidianNorm();
                f *= curr.getMass() * other.getMass() / (norm * norm * norm);
                curr.getForceMut() += f;
            }
        }
    }

    void step() {
        this->t += this->deltaT;
        for (std::size_t i = 0; i < particles.size(); ++i) {
            Particle<N> &p = particles[i];

            Vector<N> deltaPos = (0.5 / p.readMass()) * deltaT * p.readForce();
            deltaPos += p.readSpeed();

            p.getPositionMut() += deltaT * deltaPos;
            this->oldForces[i] = p.readForce();
        }
        this->init();

        for (std::size_t i = 0; i < particles.size(); ++i) {
            Particle<N> &p = particles[i];
            p.getSpeedMut() += deltaT * (0.5 / p.readMass()) * (p.readForce() + this->oldForces[i]);
        }
    }

    void output() {
        std::cout << "# t = " << t << "\n";
        for (const Particle<N> &p: particles) {
            const Vector<N> &v = p.readPosition();
            std::cout << v[0] << " " << v[1] << " " << p.identifier<< "\n";
        
        }
        std::cout << "\n";
        std::cout << std::endl;

}
};

// template <std::size_t N>
// std::vector<Particle<N>> Univers<N>::particles; 

typedef Univers<2> Univers2D;
typedef Univers<3> Univers3D;