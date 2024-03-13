#include <vector>

#include "particle.hxx"
#include "vector.hxx"

#define T_END 468.5
#define DELTA_T 0.015

template<std::size_t N>
void stromerVerletInit(std::vector<Particle<N>> &particles) {

    for (Particle<N> &curr: particles) {
        curr.force.zero();

        for (Particle<N> &other: particles) {
            if (curr == other) {
                continue;
            }
            Vector<N> f = other.position - curr.position;
            double norm = f.euclidianNorm();
            f *= curr.mass * other.mass / (norm * norm * norm);
            curr.force += f;
        }
    }
}

template <std::size_t N>
void stromerVerletOutput(std::vector<Particle<N>> particles, double t) {
        std::cout << "# t = " << t << std::endl;
        for (Particle<N> &p: particles) {
            Vector<N> &v = p.position;
            std::cout << v[0] << " " << v[1] << std::endl;
        }
        std::cout << std::endl;
        std::cout << std::endl;

}

template<std::size_t N>
void stromerVerlet(
    std::vector<Particle<N>> particles,
    std::vector<Vector<N>> oldForces,
    double deltaT,
    double tEnd
) {
    stromerVerletInit(particles);
    for (double t = 0.0; t < tEnd; t += deltaT) {

        for (std::size_t i = 0; i < particles.size(); ++i) {
            Particle<N> &p = particles[i];
            p.position += deltaT * (p.speed + (0.5 / p.mass) * deltaT * p.force);
            oldForces[i] = p.force;
        }
        stromerVerletInit(particles);

        for (std::size_t i = 0; i < particles.size(); ++i) {
            Particle<N> &p = particles[i];
            p.speed += deltaT * (0.5 / p.mass) * (p.force + oldForces[i]);
        }

        stromerVerletOutput(particles, t);

    }
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

    std::vector<Vector2D> oldForces;
    for (std::size_t i = 0; i < particles.size(); ++i) {
        oldForces.push_back(Vector2D());
    }

    stromerVerlet(particles, oldForces, DELTA_T, T_END);
}
