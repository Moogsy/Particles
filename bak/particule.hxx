#pragma once

#include "vecteur.hxx"

enum CategorieParticule {
    STANDARD
};

class Particule {

    private:
    Vecteur position;
    Vecteur vitesse;
    Vecteur force;

    double masse;
    unsigned long identifiant; 
    CategorieParticule categorie;

    public:
    Particule(Vecteur & position, double masse);
    Vecteur & getPosition();
    Vecteur & getVitesse();
    Vecteur & getForce();
    double getMasse();
    friend std::ostream& operator<<(std::ostream &os, const Particule & p);
};