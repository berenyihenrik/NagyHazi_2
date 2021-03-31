#include <iostream>
#include <fstream>
#include <string>

#include "datum.h"
#include "vonat.h"
using namespace std;

int main() {


    string test;



    Jaratok j;
    beolvas(j, "vonatok.txt");

    cout << j;



    return 0;
}
