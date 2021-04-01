#include <iostream>
#include <fstream>
#include <string>

#include "datum.h"
#include "vonat.h"
#include "string.h"
using namespace std;

int main() {


    Jaratok j;
    beolvas(j, "vonatok.txt");

    cout << j;

    ofstream f;
    f.open("asd.txt");
    f << j;


    return 0;
}
