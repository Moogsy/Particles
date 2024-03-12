#include "particule.hxx"

Particule::Particule(Vecteur<2> & position, double masse) {
    this->position = position; 
    this->vitesse = Vecteur<2>();
    this->force = Vecteur<2>();
    this->masse = masse;
}

Vecteur<2> & Particule::getPosition() {
    return this->position;
}

Vecteur<2> & Particule::getVitesse() {
    return this->vitesse;
}

Vecteur<2> & Particule::getForce() {
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