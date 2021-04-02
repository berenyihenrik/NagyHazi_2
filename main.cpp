#include <iostream>
#include <fstream>
#include <string>

#include "datum.hpp"
#include "vonat.hpp"
#include "string.hpp"
#include "jegy.hpp"
using namespace std;

int main() {
    Jaratok j;
    beolvas(j, "vonatok.txt");

    cout << j << endl;

    //cout << j;

    ofstream f;
    f.open("asd.txt");
    f << j;

    Jegyek je;
    beolvas(j, je, "jegyek.txt");

    cout << endl << je << endl;



    return 0;
}
