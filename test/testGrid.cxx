#include "ndgrid.hxx"
#include<iostream>

int main() {
    // NdGrid<3, double> ndGrid{1, 2, 3};
    NdGrid<2, double> ndGrid{4, 5};

    /*
    const std::vector<std::size_t> v = ndGrid.shape();

    for (auto it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;
    */
}