#include "menu.hpp"
#include "vonat.hpp"


void menu(Jaratok& ja, Jegyek& je) {
    int menupont = 0;
    while(menupont != 5) {
        cout <<
        "Válassz egyet az alábbi menüpontok közül:\n" <<
        "1.: Járat keresése\n" <<
        "2.: Repülőjegy foglalása\n" <<
        "3.: Foglalás törlése\n" <<
        "4.: Összesítés\n" <<
        "5.: Kilépés\n";

        cin >> menupont;

        /* Járat keresése menüpont */
        if(menupont == 1) {
            /* Úticélok beolvasása */
            cout << "Honnan kíván utazni?";
            String honnan;
            cin >> honnan;

            String hova;
            cout << "Hova kíván utazni?";
            cin >> hova;

            /* Dátumok beolvasása */
            cout << "Mi legyen az indulási dátum?" << endl;
            Datum kezdo;
            cin >> kezdo;

            cout << "Mi legyen a végső dátum?" << endl;
            Datum vegso;
            cin >> vegso;

            /* Járat keresése */
            keres(ja, honnan, hova, kezdo, vegso);
            }


        }


    }
