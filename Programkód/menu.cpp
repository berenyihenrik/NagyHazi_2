#include "menu.hpp"
#include "vonat.hpp"


void menu(Jaratok& ja, Jegyek& je) {
    int menupont = 0;
    while(menupont != 6) {
        cout <<
        "Válassz egyet az alábbi menüpontok közül:\n" <<
        "1.: Járat keresése\n" <<
        "2.: Jegy foglalása\n" <<
        "3.: Foglalás törlése\n" <<
        "4.: Vonat felvétele\n" <<
        "5.: Vonat törlése\n" <<
        "6.: Kilépés\n";

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
            while(!ja.checkID(azonosito)) {
                cout << "Ilyen azonosító nem letezik, kérlek írd be újra!" << endl;
                cin >> azonosito;
            }

            cout << "Milyen névre legyen a foglalás?";
            String nev;
            cin >> nev;

            cout << "Kérlek válassz kocsit!";
            int kocsiszam;
            cin >> kocsiszam;

            cout << "Kérlek válassz ülőhelyet!";
            int ulohely;
            cin >> ulohely;
            while(je.checkSeat(azonosito, kocsiszam, ulohely)) {
                cout << "Ez az ülőhely már foglalt, kérlek válassz másikat!" << endl;
                cout << "Kérlek válassz kocsit!";
                cin >> kocsiszam;
                cout << "Kérlek válassz ülőhelyet!";
                cin >> ulohely;
            }

            Jegy j(nev, kocsiszam, ulohely, azonosito, ja);
            je.add(j);
        }

        /* Jegy törlése menüpont */
        else if(menupont == 3) {
            cout << "Milyen néven van a foglalás?";
            String nev;
            cin >> nev;

            je.remove(nev.c_str());

            cout << je;
        }

        /* Vonat felvétele menüpont */
        else if(menupont == 4) {
            cout << "Mi legyen a vonat azonosítója?";
            String azonosito;
            cin >> azonosito;
            while(ja.checkID(azonosito)) {
                cout << "Ilyen azonosító már létezik, kérlek írd be újra!" << endl;
                cin >> azonosito;
            }

            cout << "Mi legyen a vonat kiindulási állomása?";
            String ind_all;
            cin >> ind_all;

            cout << "Mi legyen a vonat indulási dátuma?" << endl;
            Datum ind;
            cin >> ind;

            cout << "Mi legyen a vonat végállomása?";
            String erk_all;
            cin >> erk_all;

            cout << "Mi legyen a vonat érkezési dátuma" << endl;
            Datum erk;
            cin >> erk;
            while(erk <= ind) {
                cout << "A vonatnak későbbi időpontban kell megérkeznie, mint az indulási dátum, kérlek írd be újra!" << endl;
                cin >> erk;
            }

            Vonat v(azonosito, ind_all, ind, erk_all, erk);
            ja.add(v);
        }

        /* Vonat törlése menüpont */
        else if(menupont == 5) {
            cout << "Adja meg annak a vonatnak az azonosítóját, amelyiket törölni szeretné.";
            String azonosito;
            cin >> azonosito;

            try {
                ja.remove(azonosito.c_str());
            }
            catch(const char* c) {
                cout << c;
            }
        }




        /* Minden más érték az 6-ot kivéve => nem létező menüpont */
        else if(menupont != 6) {
            printf("Nem létező menüpont.\n");
        }

    }
}
