#ifndef FUNKCIJOS1_H
#define FUNKCIJOS1_H

#include "manoBiblioteka.h"

class studentas {
    private:
    
        string Vardas;
        string Pavarde;
        int egz_rez;
        int pazKiekis;
        vector<int> tarpiniai;
        double vidurkis;
        double mediana;
        double gal_vid;
        double gal_med;

    public:
        studentas () : Vardas ( ""), Pavarde ( ""), tarpiniai (), pazKiekis (0), egz_rez (0){} 

        void set_egz(int egz){
            egz_rez = egz;
        }
        double get_egz(){
            return egz_rez;
        }

        void set_tarpiniai(vector<int> tarp){
            tarpiniai = tarp;
        }
        vector <int> get_tarpiniai( ){
            return tarpiniai;
        }

        void set_paz_kiekis(int paz){
            pazKiekis = paz;
        }
        int get_paz_kieki(){
            return pazKiekis;
        }

        void set_vidurkis(int vidur){
            vidurkis = vidur;
        }
        double get_vidurkis(){
            return vidurkis;
        }

        void set_mediana(int medi){
            mediana = medi;
        }
        double get_mediana(){
            return mediana;
        }

        void set_gal_v_m (int pasirinkimas, double gal){
            if (pasirinkimas == 0) gal_vid = gal;
            if (pasirinkimas == 1) gal_med = gal;
        }
        double get_gal_v_m (int pasirinkimas) const{
            if (pasirinkimas == 0) return gal_vid;
            if (pasirinkimas == 1) return gal_med ;
        }

        string set_Vardas (string var){
            Vardas = var;
        }
        string get_Vardas ()const{
            return Vardas;
        }

        string set_Pavarde (string pav){
            Pavarde = pav;
        }
        string get_Pavarde ()const{
            return Pavarde;
        }

        virtual ~studentas ( ){}
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
void didejimo (vector<studentas>& var, double &laikas);

void testavimui(vector<studentas>& var);
void rusiavimasTest(vector<studentas>& var, vector<studentas>& vargsai,vector<studentas>& galvociai, double &laikas, int &pasirinkimas,int indeksas);
void spausdinimasTest(vector<studentas>& vargsai, vector<studentas>& galvociai, vector<string> pav, double &laikas,int &pasirinkimas, int indeksas);
void testFail(vector<studentas>& var);
void testFail_3strategija(vector<studentas> &var);
void rusiavimasTest_3strategija(vector<studentas> &var, vector<studentas> &vargsai, double &galutinisLaikas, int &pasirinkimas, int indeksas);
void testFail_2strategija(vector<studentas> &var);
void rusiavimasTest_2strategija(vector<studentas> &var, vector<studentas> &vargsai, double &galutinisLaikas, int &pasirinkimas, int indeksas);

/// funkcijos su list

void testFail_list_3strategija(list<studentas> &var);
void rusiavimasTest_list_3strategija(list<studentas> &var, list<studentas> &vargsai, double &galutinisLaikas, int &pasirinkimas, int indeksas);
void testFail_list_2strategija(list<studentas> &var);
void rusiavimasTest_list_2strategija(list<studentas> &var, list<studentas> &vargsai, double &galutinisLaikas, int &pasirinkimas, int indeksas);
void rusiavimasTest_list(list<studentas>& var, list<studentas>& vargsai,list<studentas>& galvociai, double &laikas, int &pasirinkimas,int indeksas);
void spausdinimasTest_list(list<studentas>& vargsai, list<studentas>& galvociai, vector<string> pav, double &laikas,int &pasirinkimas,int indeksas);
void testFail_list(list<studentas>& var);
double mediana_list(list<studentas>& var,list<studentas>::iterator it);
double vidurkis_list(list<studentas>& var,list<studentas>::iterator it);
double galutinis_list(list<studentas>& var, list<studentas>::iterator it ,int &pasirinkimas);
void skaitymas_list(list<studentas>& var, vector<string>& failoPav, int indeksas, double& laikas, int laboras);             ///nuskaito duomenis is failo ir iraso i kita faila
void rusiavimas_list(list<studentas>& var);
void didejimo_list (list<studentas>& var, double &laikas);


/// funkcijos su deque
void testFail_deque_3strategija(deque<studentas> &var);
void rusiavimasTest_deque_3strategija(deque<studentas> &var, deque<studentas> &vargsai, double &galutinisLaikas, int &pasirinkimas, int indeksas);
void testFail_deque_2strategija(deque<studentas> &var);
void rusiavimasTest_deque_2strategija(deque<studentas> &var, deque<studentas> &vargsai, double &galutinisLaikas, int &pasirinkimas, int indeksas);
void testFail_deque(deque<studentas>& var);
void rusiavimasTest_deque(deque<studentas>& var, deque<studentas>& vargsai, deque<studentas>& galvociai, double& galutinisLaikas, int& pasirinkimas, int indeksas);
void spausdinimasTest_deque(deque<studentas> &vargsai, deque<studentas> &galvociai, vector<string> pav, double &laikas, int &pasirinkimas, int &indeksas);
void skaitymas_deque(deque<studentas>& var, vector<string>& failoPav, int indeksas, double& laikas, int laboras);
void rusiavimas_deque(deque<studentas>& var);
double galutinis_deque(deque<studentas>& var, deque<studentas>::iterator it ,int &pasirinkimas);
double mediana_deque(deque<studentas>& var, deque<studentas>::iterator it);
double vidurkis_deque(deque<studentas>& var, deque<studentas>::iterator it);
void didejimo_deque (deque<studentas>& var, double &laikas);


#endif