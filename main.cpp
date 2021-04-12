#include "vonat.hpp"
#include "jegy.hpp"
#include "menu.hpp"

#include "gtest_lite.h"

using namespace std;

int main() {
    /*
    Jaratok ja;
    beolvas(ja, "vonatok.txt");
    Jegyek je;
    beolvas(ja, je, "jegyek.txt");

    menu(ja ,je);
    Végleges programhoz tartozó rész, illetve felhasználói menü meghívása */




    /*
    Az alábbi tesztek a jelenlegi programban lévő összes függvényt tesztelik a fájlkezeléssel együtt
    */

    ///TESZTEK

    //Datum osztaly tesztje
    TEST(Datum, kiir) {
        Datum d1(2021, 05, 06, 1140);
        stringstream ss;
        ss << d1;
        EXPECT_STREQ("2021#5#6#19#00", ss.str().c_str());
    } ENDM

    TEST(Datum, beolvas) {
        stringstream ss;
        ss << "2021\n12\n10\n15\n30";
        Datum d1;
        ss >> d1;
        Datum d2(2021, 12, 10, 930);
        EXPECT_EQ(d1, d2);
    } ENDM

    TEST(Datum, nagyobb/kisebb) {
        Datum d1(2021, 05, 06, 1140);
        Datum d2(2021, 06, 01, 1100);
        EXPECT_GT(d2, d1);
        EXPECT_LT(d1, d2);
    } ENDM

    TEST(Datum, ertekadas) {
        Datum d1(2021, 05, 06, 1140);
        Datum d2(2021, 06, 01, 1100);
        d1 = d2;
        EXPECT_EQ(d1, d2);
    } ENDM


    //Vonat osztaly tesztje
    String azonosito = "AAA111";
    String ind = "Budapest";
    String erk = "Debrecen";
    Datum d1(2021, 05, 06, 1140);
    Datum d2(2021, 06, 01, 1100);
    Vonat v(azonosito, ind, d1, erk, d2);

    TEST(Vonat, kiir) {
        stringstream ss;
        ss << v;
        EXPECT_STREQ("AAA111#2021#5#6#19#00#2021#6#1#18#20#Budapest#Debrecen\n",ss.str().c_str());
    } ENDM

    TEST(Vonat, getterek) {
        EXPECT_STREQ("AAA111",v.get_vsz().c_str());
        EXPECT_EQ(d1, v.get_ind_dt());
        EXPECT_EQ(d2, v.get_erkez_dt());
        EXPECT_STREQ("Budapest", v.get_ind_all().c_str());
        EXPECT_STREQ("Debrecen", v.get_erkez_all().c_str());
    } ENDM

    //Jegy osztaly tesztje
    Jegy j("Berenyi Henrik Daniel", 10, 5, v);

    TEST(Jegy, kiir) {
        stringstream ss;
        ss << j;
       EXPECT_STREQ("Berenyi Henrik Daniel#10#5#AAA111\n",ss.str().c_str()) ;
    } ENDM

    TEST(Jegy, getterek) {
        EXPECT_STREQ("Berenyi Henrik Daniel", j.get_nev().c_str());
        EXPECT_STREQ("AAA111", j.get_vsz().c_str());
        EXPECT_EQ(10, j.get_ksz());
        EXPECT_EQ(5, j.get_hely());
        EXPECT_STREQ("Budapest", j.get_ind_all().c_str());
        EXPECT_STREQ("Debrecen", j.get_erkez_all().c_str());
        EXPECT_EQ(d1, j.get_ind_dt());
        EXPECT_EQ(d2, j.get_erkez_dt());
        EXPECT_EQ(v,j.get_vonat());
    }ENDM

    TEST(Jegy, ertekadas) {
       Jegy j1(j);
       Jegy j2("Kovacs Endre", 13,2, v);
       j1 = j2;
       EXPECT_EQ(j1, j2);
    } ENDM
    
    //Jaratok es Jegyek tesztjei
    Jaratok ja;
    EXPECT_THROW(beolvas(ja, "ilyen_nincs.txt"), const char*); //ismeretlen fájl esetén kivétel
    EXPECT_NO_THROW(beolvas(ja, "vonatok.txt")); //sikeres beolvasás

    Jegyek je;
    EXPECT_THROW(beolvas(ja, je, "ilyen_nincs.txt"), const char*); //ismeretlen fájl esetén kivétel
    EXPECT_NO_THROW(beolvas(ja, je, "jegyek.txt")); //sikeres beolvasás

    TEST(Jaratok, kiir) {
        stringstream ss;
        ss << ja;
        EXPECT_STREQ("ABB001#2021#4#20#18#50#2021#4#20#19#00#Budapest#Sopron\n"
                     "ZBB002#2021#4#20#18#50#2021#4#20#19#00#Budapest#Debrecen\n"
                     "ZBB003#2021#4#20#18#50#2021#4#20#19#00#Budapest#Berlin\n", ss.str().c_str());
    } ENDM

    TEST(Jaratok, add/remove) {
        ja.add(v);
        EXPECT_EQ(v, ja[3]);
        EXPECT_EQ(4, ja.size());

        EXPECT_THROW(ja.remove("AAA222"), const char*);
        EXPECT_NO_THROW(ja.remove("AAA111"));
    } ENDM

    TEST(Jaratok, index) {
        stringstream ss;
        ss << ja[0];
        EXPECT_STREQ("ABB001#2021#4#20#18#50#2021#4#20#19#00#Budapest#Sopron\n", ss.str().c_str());
    } ENDM

    TEST(Jaratok, tovabbi_fuggvenyek) {
        EXPECT_EQ(3, ja.size());
        EXPECT_TRUE(ja.checkID("ABB001"));
        EXPECT_FALSE(ja.checkID("AAA222"));
    } ENDM

    TEST(Jegyek, kiir) {
       stringstream ss;
       ss << je;
       EXPECT_STREQ("Berenyi Henrik#12#8#ABB001\n"
                    "Kiss Gabor#21#9#ZBB002\n",ss.str().c_str());
    } ENDM

    TEST(Jegyek, add/remove) {
       je.add(j);
       EXPECT_EQ(j, je[2]);
       EXPECT_EQ(3, je.size());

       EXPECT_THROW(je.remove("nincs ilyen nev"), const char*);
       EXPECT_NO_THROW(je.remove("Berenyi Henrik Daniel"));
    } ENDM

    TEST(Jegyek, index) {
       stringstream ss;
       ss << je[0];
       EXPECT_STREQ("Berenyi Henrik#12#8#ABB001\n", ss.str().c_str());
    } ENDM

    TEST(Jaratok, tovabbi_fuggvenyek) {
       EXPECT_EQ(2, je.size());
       EXPECT_TRUE(je.checkSeat(je[0].get_vsz(), je[0].get_ksz(), je[0].get_hely()));
       EXPECT_FALSE(je.checkSeat("AAA222", 12, 21));
    } ENDM

    return 0;
}
