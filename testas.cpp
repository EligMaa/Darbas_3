#define CATCH_CONFIG_MAIN
#include "FUNKCIJOS2.h" 
#include"catch.hpp"

TEST_CASE("konstruktoriaus testavimas") {
    string vardas = "Rugile";
    string pavarde = "Macaite";
    vector<int> pazymiai = {1, 2, 3, 4, 5};
    double egzamino_rez = 9.5;

    studentas naujasstudentas(vardas, pavarde, pazymiai, egzamino_rez);

    REQUIRE(naujasstudentas.get_Vardas() == vardas);
    REQUIRE(naujasstudentas.get_Pavarde() == pavarde);
    REQUIRE(naujasstudentas.get_egz() == egzamino_rez);
    REQUIRE(naujasstudentas.get_tarpiniai() == pazymiai);
}

TEST_CASE("Konstruktoriaus kopijavimo testavimas") {
    string vardas = "Rugile";
    string pavarde = "Macaite";
    vector<int> pazymiai = {1, 2, 3, 4, 5};
    double egzamino_rez = 9.5;

    studentas naujasstudentas(vardas, pavarde, pazymiai, egzamino_rez);
    studentas kopijastudentas(naujasstudentas);

    REQUIRE(kopijastudentas.get_Vardas() == vardas);
    REQUIRE(kopijastudentas.get_Pavarde() == pavarde);
    REQUIRE(kopijastudentas.get_egz() == egzamino_rez);
    REQUIRE(kopijastudentas.get_tarpiniai() == pazymiai);
}

TEST_CASE("Perkelimo konstruktoriaus testavimas") {
    string vardas = "Rugile";
    string pavarde = "Macaite";
    vector<int> pazymiai = {1, 2, 3, 4, 5};
    double egzamino_rez = 9.5;

    studentas naujasstudentas(vardas, pavarde, pazymiai, egzamino_rez);
    studentas perkeliamasstudentas(move(naujasstudentas));

    REQUIRE(perkeliamasstudentas.get_Vardas() == vardas);
    REQUIRE(perkeliamasstudentas.get_Pavarde() == pavarde);
    REQUIRE(perkeliamasstudentas.get_egz() == egzamino_rez);
    REQUIRE(perkeliamasstudentas.get_tarpiniai() == pazymiai);
}
