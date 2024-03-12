#include "particule.hxx"

Particule::Particule(Vecteur & position, double masse) {
    this->position = position; 
    this->vitesse = Vecteur();
    this->force = Vecteur();
    this->masse = masse;
}

Vecteur & Particule::getPosition() {
    return this->position;
}

Vecteur & Particule::getVitesse() {
    return this->vitesse;
}

Vecteur & Particule::getForce() {
    return this->force;
}

double Particule::getMasse() {
    return this->masse;
}

std::ostream& operator<<(std::ostream &os, const Particule & p) {
    os << "Particule{";
    os << "position=" << p.position;
    os << ", " << "vitesse=" << p.vitesse;
    os << ", " << "force=" << p.force;
    os << ", " << "masse=" << p.masse;
    os << ", " << "identifiant=" << p.identifiant; 
    os << "}";

    return os; 
}