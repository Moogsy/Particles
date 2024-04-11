#pragma once 

#include <iostream>
#include <vector>
#include "particle.hxx"
#include "vector.hxx"

template<std::size_t N>
class Grid {

private:
    Vector<N> dimensions;
    // Généraliser ceci à N dimensions
    std::vector<std::vector<Particle2D>> cellLists;
}



public:
    Grid(
        Vector<N> characteristicLength;
        double cuttingRadius;
    )
    {
        for (std::size_t i = 0; i < N; ++i){
            size_t numberCells =  floor(characteristicLength[i]/cuttingRadius);
            dimensions.push_back(numberCells);
        }        
    }


    void fill(std::vector<Particle<N>> & particles, Vector<N> & characteristicLength){
        // here we fill the cellLists with our particles
        for (const Particle<N> &p: particles){
            
        }



        for (std::size_t i = 0; i < N; ++i){
            double subSize =  characteristicLength/cellLists[i].size();
        }
    };

typedef Grid<2> Grid2D;
typedef Grid<3> Grid3D;


