#include "particle.hxx"
#include "vector.hxx"
#include "univers.hxx"
#include <random>
#include <vector>
#include <cmath>

template <std::size_t N>
void randomParts(std::vector<Particle<N>> & parts, std::size_t pCount) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(8.0, 10.0);

    for (std::size_t i = 0; i < pCount; ++i) {
        Particle<N> p;
        for (std::size_t j = 0; j < N; ++j) {
            p.getPositionMut()[j] = dist(mt);
            p.getMass() = 1e-8;
            p.getSpeedMut()[j] = -1;
        }
        
        p.identifier = std::to_string(i);
        parts.push_back(p);
    }
}

int main() {
    /*
    std::vector<Particle2D> particles {
        Particle2D("Sun", "star", Vector2D(), Vector2D(), 1.0),
        Particle2D("Earth", "planet", Vector2D{0, 1}, Vector2D{-1, 0}, 3e-6),
        Particle2D("Mars", "planet", Vector2D{0, 1.524}, Vector2D{-0.72, 0}, 3.3e-7),
        Particle2D("Jupiter", "planet", Vector2D{0, 5.36}, Vector2D{-0.425, 0}, 1e-3),
        Particle2D("Haley", "comet", Vector2D{34.75, 0}, Vector2D{0, 0.0296}, 1e-14),
        Particle2D("Saturn", "planet", Vector2D{8.58, 0}, Vector2D{0, 0.2}, 2.75e-3),
        Particle2D("Uranus", "planet", Vector2D{16.22, 0}, Vector2D{0, 0.3}, 4.4e-4),
        Particle2D("Neptune", "planet", Vector2D{25.05, 0}, Vector2D{0, 0.4}, 5.15e-5),
    };

    // randomParts(particles, 50);
    Univers2D universe(particles, 1e-3);
    universe.init();
    */

   Univers2D uni(
        100,
        40,
        1,
        1,
        1e-2
   );

    for (int i = 0; i < 10000; ++i) {
        uni.step(); 
        uni.output2D();
    }

    return 0;
}


