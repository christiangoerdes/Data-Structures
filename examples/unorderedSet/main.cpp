#include "../../include/Container/unorderedSet/unorderedSet.hpp"

#include <iostream>

int main() {
    UnorderedSet<int> x;

    std::cout << x.get_size() << std::endl;

    x.insert(5);
    x.insert(82);
    x.remove(5);

    std::cout << x.get_size() << std::endl;

}
