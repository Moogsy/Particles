#pragma once

#include <iostream>
#include <vector>
#include <random>
#include "particle.hxx"

template <std::size_t N>
class Univers {

private:
    std::vector<Particle<N>> particles;
    std::vector<Vector<N>> oldForces;
    std::vector<double> speeds;
    std::vector<double> dimensions;

    double t;
    double deltaT;
    Vector<N> charactesticLength;
    double cuttingRadius;
    // 2D only 
    std::vector<std::vector<Particle<2>>> cellsList;


public:
    Univers(
        std::vector<Particle<N>> particles,
        double deltaT,
        double charLength,
        double cuttingRadius
    ) {
        this->particles = particles;
        this->oldForces = std::vector<Vector<N>>();
        for (auto _: particles) {
            this->oldForces.push_back(Vector<N>());
        }

        this->t = 0.0;
        this->deltaT = deltaT;
        for (std::size_t i = 0; i < 2; ++i){
        // size_t numberCells =  floor(characteristicLength[i]/cuttingRadius);

        }

    }

    Univers(
        std::size_t pCount,
        double maxPos,
        double maxSpeed,
        double commonMass,
        double deltaT
    ) {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_real_distribution<double> dist(-1.0, 1.0);
        std::uniform_real_distribution<double> normDist(0.0, 1.0);

        for (std::size_t i = 0; i < pCount; ++i) {
            Particle<N> p;
            p.identifier = std::to_string(i);
            for (std::size_t j = 0; j < N; ++j) {
                p.getPositionMut()[j] = dist(mt);
                p.getSpeedMut()[j] = dist(mt);
                p.getMass() = commonMass;
            }

            p.getPositionMut().normalizeOrZero();
            p.getPositionMut() *= normDist(mt) * maxPos;

            p.getForceMut().normalizeOrZero();
            p.getPositionMut() *= normDist(mt) * maxSpeed;

            this->particles.push_back(p);
            this->oldForces.push_back(Vector<N>());
            this->speeds.push_back(0);
        }
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
        std::vector<std::vector<Vector<N>>> v = std::vector<std::vector<Vector<N>>>(
            this->particles.size(), 
            std::vector<Vector<N>>(
                this->particles.size()
            )
        );

        for (size_t i = 0; i < this->particles.size(); i++) {
            Particle<N> &curr = this->particles[i];
            curr.getForceMut().zero();
            for (size_t j = 0; j < this->particles.size(); j++) {
                if (i == j) {
                    continue;
                }
                Particle<N> &other = this->particles[j];

                if (v[i][j].isZero()) {
                    Vector<N> f = other.readPosition() - curr.readPosition();
                    double normSquared = f.euclidianNormSquared();
                    double norm = sqrt(normSquared);

                    f *= (curr.getMass() * other.getMass()) / (normSquared * norm);

                    v[i][j] = f;
                    v[j][i] = -f;

                    curr.getForceMut() += f;
                } else {
                    curr.getForceMut() += v[i][j];
                }
            }
        }
    }

   

    void step() {
        this->t += this->deltaT;
        for (std::size_t i = 0; i < particles.size(); ++i) {
            Particle<N> &p = particles[i];

            Vector<N> deltaPos = (0.5 / p.readMass()) * deltaT * p.readForce();
            deltaPos += p.readSpeed();

            Vector<N> oldPosition = p.readPosition().copy();

            p.getPositionMut() += deltaT * deltaPos;

            this->speeds[i] = (p.readPosition() - oldPosition).euclidianNormSquared();
            this->oldForces[i] = p.readForce();
        }
        this->init();

        for (std::size_t i = 0; i < particles.size(); ++i) {
            Particle<N> &p = particles[i];
            p.getSpeedMut() += deltaT * (0.5 / p.readMass()) * (p.readForce() + this->oldForces[i]);
        }
    }

    void output2D() {
        std::cout << "# t = " << t << "\n";
        for (const Particle<N> &p: particles) {
            const Vector<N> &v = p.readPosition();
            std::cout << v[0] << " " << v[1] << "\n";
        
        }
        std::cout << "\n";
        std::cout << std::endl;

}


    void output3D() {
        std::cout << "# t = " << t << "\n";
        for (const Particle<N> &p: particles) {
            const Vector<N> &v = p.readPosition();
            std::cout << v[0] << " " << v[1] << " " << v[2] << " " << p.identifier <<"\n";
        
        }
        std::cout << "\n";
        std::cout << std::endl;

}
};


// template <std::size_t N>
// std::vector<Particle<N>> Univers<N>::particles; 

typedef Univers<2> Univers2D;
typedef Univers<3> Univers3D;