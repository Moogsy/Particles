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
    std::uniform_real_distribution<double> dist(-40.0, 40.0);
    std::uniform_real_distribution<double> dist2(-10.0, 10.0);

    for (std::size_t i = 0; i < pCount; ++i) {
        Particle<N> p;
        for (std::size_t j = 0; j < N-1; ++j) {
            p.getPositionMut()[j] = dist(mt);
            p.getPositionMut()[2] = dist2(mt);
            p.getMass() = dist(mt);
            p.getSpeedMut()[j] = 0;
        }
        
        p.identifier = std::to_string(i);
        parts.push_back(p);
    }
}

int main() {

    Univers3D uni(
        100,
        40,
        1,
        1,
        1e-2
   );

    for (int i = 0; i < 10000; ++i) {
        uni.step(); 
        uni.output3D();
    }

    return 0;
}

