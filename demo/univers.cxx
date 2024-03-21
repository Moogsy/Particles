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
    std::uniform_real_distribution<double> dist(0.0, 1.0);

    for (std::size_t i = 0; i < pCount; ++i) {
        Particle<N> p;
        for (std::size_t j = 0; j < N; ++j) {
            p.getPositionMut()[j] = dist(mt);
        }

        p.getMass() = dist(mt);
        p.identifier = std::to_string(i);
        parts.push_back(p);
    }
}

int main() {
    std::vector<Particle3D> particles;
    const std::size_t totalNumberParticules = 50;
    randomParts(particles,totalNumberParticules);
    Univers3D universe(particles,2000,30);
    universe.init();
    //universe.step(); 
    std::cout << universe << std::endl;    
    return 0;
}

