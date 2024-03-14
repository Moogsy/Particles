#include "univers.hxx"
#include "particle.hxx"
#include "vector.hxx"
#include <random>
#include <vector>

template <std::size_t N>
void randomParts(std::vector<Particle<N>> & parts, std::size_t pCount) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(0.0, 1.0);

    for (std::size_t i = 0; i < pCount; ++i) {
        Vector<N> pos;
        for (std::size_t i = 0; i < N; ++i) {
            pos[i] = dist(mt);
        }

        Particle<N> p(
            pos,
            Vector<N>(),
            Vector<N>(),
            dist(mt),
            std::string((char)i),
            std::string((char)i)
        );
    }
}

int main() {
    std::vector<Particle2D> parts;
    randomParts(parts, 1000);

    Univers2D u(
        parts,
        468.5,
        0.015
    );

    u.step();

    return 0;
}