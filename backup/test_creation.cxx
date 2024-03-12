#include <random>
#include <iostream>

#include <list>
#include "particule.hxx"

int main() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(0.0, 1.0);


    std::list<Particule> particules;

    for (int i = 0; i < 10; i++) {
        Vecteur position(dist(mt), dist(mt), dist(mt));
        double masse = dist(mt);
        Particule p(position, masse);

        particules.push_back(p);
    }

    for (auto p: particules) {
        std::cout << p << "\n";
    }
    std::cout << std::flush;

}