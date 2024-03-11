#include "vector.hxx"

template <std::size_t N>
class Particle {
private:
    Vector<N> position;
    Vector<N> speed;
    Vector<N> force;
    double mass;
    std::string identifier;
    std::string category;

public:
    Particle(
        Vector<N> position, 
        std::string identifier, 
        std::string category,
        double mass,
    ) {

    }
};