#include "vonat.hpp"
#include "jegy.hpp"
#include "menu.hpp"

using namespace std;

int main() {
    Jaratok ja;
    beolvas(ja, "vonatok.txt");
    Jegyek je;
    beolvas(ja, je, "jegyek.txt");


    menu(ja ,je);

    return 0;
}
