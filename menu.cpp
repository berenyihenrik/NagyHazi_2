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
        "4.: Vonat felvetele\n" <<
        "5.: Vonat torlese\n" <<
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
                cout << "Ilyen azonosito nem letezik, kerlek ird be ujra!" << endl;
                cin >> azonosito;
            }

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
        }

        /* Jegy törlése menüpont */
        else if(menupont == 3) {
            cout << "Milyen néven van a foglalás?";
            String nev;
            cin >> nev;

            je.remove(nev.c_str());

            cout << je;
        }

        /* Vonat felvetele manupont */
        else if(menupont == 4) {
            cout << "Mi legyen a vonat azonositoja?";
            String azonosito;
            cin >> azonosito;
            while(ja.checkID(azonosito)) {
                cout << "Ilyen azonosito mar letezik, kerlek ird be ujra!" << endl;
                cin >> azonosito;
            }

            cout << "Mi legyen a vonat kiindulasi allomasa?";
            String ind_all;
            cin >> ind_all;

            cout << "Mi legyen a vonat indulasi datuma?" << endl;
            Datum ind;
            cin >> ind;

            cout << "Mi legyen a vonat vegallomasa?";
            String erk_all;
            cin >> erk_all;

            cout << "Mi legyen a vonat erkezesi datuma" << endl;
            Datum erk;
            cin >> erk;
            while(erk < ind) {
                cout << "A vonatnak kesobbi idopontban kell megerkeznie, mint az indulasi datum, kerlek ird be ujra!" << endl;
                cin >> erk;
            }

            Vonat v(azonosito, ind_all, ind, erk_all, erk);
            ja.add(v);
        }

        /* Vonat torlese menupont */
        else if(menupont == 5) {
            cout << "Adja meg annak a vonatnak az azonositojat, amelyiket torolni szeretne.";
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
