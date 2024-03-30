#include <iostream>
#include "kr1_05.h"

int main() {
    kr1_05 unit("data.txt");
    std::cout << unit << std::endl;
    std::vector <student> result = unit.search(4);
    for (student u: result) {
        unit.pushBack(u);
    }
    std::cout << unit << std::endl;
    std::cout << unit.calculate("programming") << std::endl;
    unit.removeItems(4);
    std::cout << unit << std::endl;
    return 0;
}
