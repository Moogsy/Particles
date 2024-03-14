#include <vector>

#include "particle.hxx"
#include "vector.hxx"

#define T_END 468.5
#define DELTA_T 0.015

template<std::size_t N>
void stromerVerletInit(std::vector<Particle<N>> &particles) {

    for (Particle<N> &curr: particles) {
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

template <std::size_t N>
void stromerVerletOutput(std::vector<Particle<N>> particles, double t) {
        std::cout << "# t = " << t << "\n";
        for (const Particle<N> &p: particles) {
            const Vector<N> &v = p.readPosition();
            std::cout << v[0] << " " << v[1] << "\n";
        }
        std::cout << "\n";
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
            p.getPositionMut() += deltaT * (p.readSpeed() + (0.5 / p.readMass()) * deltaT * p.readForce());
            oldForces[i] = p.readForce();
        }
        stromerVerletInit(particles);

        for (std::size_t i = 0; i < particles.size(); ++i) {
            Particle<N> &p = particles[i];
            p.getSpeedMut() += deltaT * (0.5 / p.readMass()) * (p.readForce() + oldForces[i]);
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
