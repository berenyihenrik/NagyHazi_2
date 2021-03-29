#include <iostream>

#include "datum.h"

int main() {
    std::cout << "NagyHazi_2" << std::endl;


    Datum datum1(2021,11,28);
    Datum datum2(2021, 11,28);
    std::cout << (datum1 > datum2) << std::endl;


    return 0;
}
