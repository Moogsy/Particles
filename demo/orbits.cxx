#include <vector>
#include <stdio.h>

#include "particle.hxx"
#include "vector.hxx"

template<std::size_t N>
Vector<N> attractionForce(const Particle<N> & current, const Particle<N> & other) {
    Vector<N> ltr = other - current;
    double distSquared = ltr.euclidianDistanceSquared();

    ltr.normalize();

    ltr *= current.getMass() * other.getMass() / distSquared;

    return ltr;
}

template<std::size_t N>
void stromerVerletInit(std::vector<Particle<N>> particles) {

    for (auto current: particles) {
        Vector<N> & force = current.getForce();
        force.zero();

        for (auto other: particles) {
            if (current == other) {
                continue;
            }
            force += attractionForce(current, other);
        }
    }
}

template<std::size_t N>
void stromerVerlet(
    std::vector<Particle<N>> particles,
    std::vector<Vector<N>> oldForces
) {
    stromerVerletInit(particles);
}

int main() {
    std::vector<Particle2D> particles {
        Particle2D(
            std::string("Sun"),
            std::string("star"),
            Vector2D(),
            Vector2D(),
            1.0
        ),
        Particle2D(
            std::string("Earth"),
            std::string("planet"),
            Vector2D{0, 1},
            Vector2D{-1, 0},
            3e-6
        ),
        Particle2D(
            std::string("Jupiter"),
            std::string("planet"),
            Vector2D{0, 5.36},
            Vector2D{-0.425, 0},
            9.55e-4
        ),
        Particle2D(
            std::string("Haley"),
            std::string("comet"),
            Vector2D{34.75, 0},
            Vector2D{0, 0.0296},
            1e-14
        )
    };

    std::cout << particles[1].getPosition().euclidianNormSquared() << std::endl;
}