#include "menu.hpp"
#include "vonat.hpp"


void menu(Jaratok& ja, Jegyek& je) {
    int menupont = 0;
    while(menupont != 5) {
        cout <<
        "Válassz egyet az alábbi menüpontok közül:\n" <<
        "1.: Járat keresése\n" <<
        "2.: Jegy foglalása\n" <<
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

        /* Jegy foglalása menüpont */
        else if(menupont == 2) {
            cout << "Mi a járat azonosítója?";
            String azonosito;
            cin >> azonosito;

            cout << "Milyen névre legyen a foglalás?";
            String nev;
            cin >> nev;

            cout << "Kerlek valassz kocsit!";
            int kocsiszam;
            cin >> kocsiszam;

            cout << "Kérlek válassz ülőhelyet!";
            int ulohely;
            cin >> ulohely;

            Jegy j(nev, kocsiszam, ulohely, azonosito, ja);
            je.add(j);

            //cout << je;
        }

        /* Jegy törlése menüpont */
        else if(menupont == 3) {
            cout << "Milyen néven van a foglalás?";
            String nev;
            cin >> nev;


            je.remove(nev.c_str());

            cout << je;
        }












        /* Minden más érték az 5-öt kivéve => nem létező menüpont */
        else if(menupont != 5) {
            printf("Nem létező menüpont.\n");
        }

    }


}
