#pragma once
#include<vector>

template <std::size_t N, typename T> 
class NdGrid {

public:
    using type = std::vector<typename NdGrid<N - 1, T>::type>;

    NdGrid(std::initializer_list<std::size_t> init) {
        std::initializer_list<std::size_t>::iterator curr = init.begin();
        std::initializer_list<std::size_t>::const_iterator end = init.end();

        for (std::size_t i = 0; i < *curr++; ++i) {
        }


    }

private:
    std::vector<type> data;

    NdGrid(
        std::initializer_list<std::size_t>::iterator curr,
        std::initializer_list<std::size_t>::const_iterator end,
    ) {
        std::initializer_list<std::size_t>::iterator curr = init.begin();
        std::initializer_list<std::size_t>::const_iterator end = init.end();

        for (std::size_t i = 0; i < *curr; ++i) {
        }

        this->data.resize(*curr);
    }

};

template <typename T> 
class NdGrid<1,  T> {
public:
    using type = std::vector<T>;

    NdGrid() {}

    NdGrid(std::size_t length) {
        this->data.resize(length);
    }

    const std::vector<T>& readData() const {
        return this->data;
    }

private:
    std::vector<T> data;

};