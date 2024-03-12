#include <list>
#include "particule.hxx"
#include "vecteur.hxx"

int main() {

}

void stromerVerlet(
    std::list<Particule> particules,
    std::list<Vecteur> forces,
    double timeStep, 
    double timeEnd
) {
    double t = 0.0;

    while (t < timeEnd) {
        t += timeEnd;

        for (auto p: particules) {
            Vecteur rhs = p.getForce() * (0.5 / p.getMasse()) * timeStep;
            p.getPosition() += (p.getVitesse() + rhs) * timeStep;
        }
    }

}