#include <iostream>
#include <fstream>
#include <string>

#include "datum.hpp"
#include "vonat.hpp"
#include "string.hpp"
#include "jegy.hpp"
#include "menu.hpp"
using namespace std;

int main() {
    Jaratok ja;
    beolvas(ja, "vonatok.txt");
    Jegyek je;
    beolvas(ja, je, "jegyek.txt");

    /*cout << endl << ja << endl;

    Datum d1(2021, 04, 20, 1130);
    Datum d2(2021,04,20, 1140);

    keres(ja, "Buda", "New", d1, d2);*/


    menu(ja ,je);

    return 0;
}
