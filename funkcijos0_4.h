#ifndef FUNKCIJOS4_H
#define FUNKCIJOS4_H

#include "manoBiblioteka.h"

struct studentas
{
    string Vardas;
    string Pavarde;
    int egz_rez;
    int pazKiekis;
    vector <int> tarpiniai; 
    double vidurkis;
    double mediana;
    double gal_vid;
    double gal_med;
};

/// ivairus vyriski vardai ir pavardes
const vector<string> vyrV = {"Jonas", "Petras", "Antanas", "Juozas","Arnas","Dziugas", "Mantas", "Stasius","Vilius", "Kazimieras", "Algirdas", "Rimas", "Mindaugas", "Rokas", "Paulius","Kajus", "Pijus", "Titas"};
const vector<string> vyrP = {"Kazlauskas", "Petrauskas", "Jonaitis", "Antanaitis", "Rimkus", "Grybauskas", "Brazauskas", "Vaitkevicius", "Statkus", "Sutkaitis","Baciuska", "Zulkus"};

/// ivairus moteriski vardai ir pavardes
const vector <string> motV = {"Ona", "Marija", "Lina", "Gabija", "Jurga", "Egle", "Ruta","Aida","Karolina","Austeja","Karina","Meda","Jorune", "Gintare", "Deimante", "Aiste", "Kamile", "Rugile", "Ugne","Selina","Monika", "Paulina", "Adriana"};
const vector <string> motP = {"Kazlauskiene", "Petrauskiene", "Jonaite", "Antanaite", "Rimkute", "Grybauskiene", "Brazauskiene", "Vaitkeviciute", "Zobelaite","Macaite","Mockute"};

void spausdinimas(vector<studentas>& var);
double galutinis(vector<studentas>& var, int &k,int &pasirinkimas);
double mediana(vector<studentas>& var,int &k);
double vidurkis(vector<studentas>& var,int &k);
void atsitiktiniaiPazymiai(vector<studentas>& var, int &studSk);
void tikrinimas(int &pasirinkimas);
void ivedimasRanka(vector<studentas>& var, int &studSk);
void atsitiktiniaiPazVar (vector<studentas>& var, int &studSk);

void su_duomenimis_is_failu(vector<studentas>& kursiokai, vector<studentas>& var);
void skaitymas(vector<studentas>& var, vector<string>&failoPav, int indeksas, double &laikas,int laboras);             ///nuskaito duomenis is failo ir iraso i kita faila
void failoKurimas(vector<string>&failoPav, int indeksas, int &kiekND,int &studSk, double &laikas);
void rusiavimas(vector<studentas>& var);
void spausdinami_surikiuoti(vector<studentas>& var,double &laikas);


bool rikiuotiVarda(const studentas &a, const studentas &b);
bool rikiuotiPavarde(const studentas &a, const studentas &b);
bool rikiuotiVid(const studentas &a, const studentas &b);
bool rikiuotiMed(const studentas &a, const studentas &b);

void testavimui(vector<studentas>& var);
void rusiavimasTest(vector<studentas>& var, vector<studentas>& vargsai,vector<studentas>& galvociai, double &laikas, int &pasirinkimas);
void spausdinimasTest(vector<studentas>& vargsai, vector<studentas>& galvociai, vector<string> pav, double &laikas,int &pasirinkimas);


#endif