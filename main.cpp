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

    cout << j << endl;


    try {
        j.remove("BBB001");
    }
    catch(const char* c){
        cout << c;
    }

    cout << j;

    ofstream f;
    f.open("asd.txt");
    f << j;


    return 0;
}
