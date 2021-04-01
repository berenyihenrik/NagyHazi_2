#include <iostream>
#include <fstream>
#include <string>

#include "datum.h"
#include "vonat.h"
#include "string.h"
using namespace std;

int main() {


    string test;



    //Jaratok j;
    //beolvas(j, "vonatok.txt");

    //cout << j;



    String tester;
    String tester2;
    //tester +=  'C';
    //cout<< tester;
    ifstream fpp;
    fpp.open("vonatok.txt");
    if(!fpp) {
        printf("KIVETEL\n");
        throw "QP4TVJ";
    }

    //getline(fpp, tester, '#');

    //cout << tester;

    Jaratok j;
    beolvas(j, "vonatok.txt");

    cout << j;


    return 0;
}
