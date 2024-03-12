#pragma once

#include "vecteur.hxx"

enum CategorieParticule {
    STANDARD
};

class Particule {

    private:
    Vecteur<2> position;
    Vecteur<2> vitesse;
    Vecteur<2> force;

    double masse;
    unsigned long identifiant; 
    CategorieParticule categorie;

    public:
    Particule(Vecteur<2> & position, double masse);
    Vecteur<2> & getPosition();
    Vecteur<2> & getVitesse();
    Vecteur<2> & getForce();
    double getMasse();
    friend std::ostream& operator<<(std::ostream &os, const Particule & p);
};