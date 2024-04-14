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

        studentas( string Var, string Pav, vector<int> tarp,double egz ) {
            Vardas = Var;
            Pavarde = Pav;
            tarpiniai = tarp;
            pazKiekis = tarp.size();
            egz_rez = egz;
            pazKiekis = tarpiniai.size();

        }

        /// destruktorius
        ~studentas ( ){tarpiniai.clear(), Vardas.clear(),Pavarde.clear();}

        /// kopijavimo konstruktorius
        studentas(const studentas& other) {
            Vardas = other.Vardas;
            Pavarde = other.Pavarde;
            egz_rez = other.egz_rez;
            tarpiniai = other.tarpiniai;
            vidurkis = other.vidurkis;
            mediana = other.mediana;
            gal_vid = other.gal_vid;
            gal_med = other.gal_med;
        }

        /// kopijavimo assignment operatorius
        studentas& operator=(const studentas& other) {
            if (this != &other) {
                Vardas = other.Vardas;
                Pavarde = other.Pavarde;
                egz_rez = other.egz_rez;
                tarpiniai = other.tarpiniai;
                vidurkis = other.vidurkis;
                mediana = other.mediana;
                gal_vid = other.gal_vid;
                gal_med = other.gal_med;
            }
            return *this;
        }

        /// perkelimo konstruktorius
        studentas(studentas&& other) noexcept {
            Vardas = move(other.Vardas);
            Pavarde = move(other.Pavarde);
            egz_rez = other.egz_rez;
            tarpiniai = move(other.tarpiniai);
            vidurkis = other.vidurkis;
            mediana = other.mediana;
            gal_vid = other.gal_vid;
            gal_med = other.gal_med;
        }

        /// perkelimo assignment operatorius
        studentas& operator=(studentas&& other) noexcept {
            if (this != &other) {
                Vardas = move(other.Vardas);
                Pavarde = move(other.Pavarde);
                egz_rez = other.egz_rez;
                tarpiniai = move(other.tarpiniai);
                vidurkis = other.vidurkis;
                mediana = other.mediana;
                gal_vid = other.gal_vid;
                gal_med = other.gal_med;
            }
            return *this;
        }

        friend ostream& operator<<(ostream& out, const studentas &stud) {                ///isvesties operatorius
        out << left << setw(15) << stud.Vardas << setw(15) << stud.Pavarde;
        out << setw(15) << fixed << setprecision(2) << stud.get_gal_v_m(0);
        out << setw(20) << setprecision(2) << stud.get_gal_v_m(1) << "\n";
        return out;
        }

        friend ostream& su_mediana(ostream& out, const studentas& stud) {
            out << left << setw(15) << stud.Vardas << setw(15) << stud.Pavarde;
            out << setw(20) << setprecision(2) << stud.gal_med << "\n";
            return out;
        }

        friend ostream& su_vidurkiu(ostream& out, const studentas& stud) {
            out << left << setw(15) << stud.Vardas << setw(15) << stud.Pavarde;
            out << setw(20) << setprecision(2) << stud.gal_vid<< "\n";
            return out;
        }


        friend istream& operator>>(istream& in, studentas &stud) {                      /// ivesties operatorius
            in >> stud.Vardas >> stud.Pavarde;
            int pazimys;
            vector <int> pazymiai;
            while (in >> pazimys)
            {
                pazymiai.push_back(pazimys);
            }
            stud.egz_rez=pazymiai.back() ;
            pazymiai.pop_back();

            stud.tarpiniai = pazymiai;

        }


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

        void set_gal_v_m (){
           
            gal_vid = vidurkis * 0.4 + 0.6 *egz_rez;
            pazKiekis = tarpiniai.size();
    
            sort(tarpiniai.begin(), tarpiniai.end());

            if ((pazKiekis % 2) == 0)
                {
                    mediana = (double(tarpiniai[pazKiekis / 2 - 1]) + (tarpiniai[pazKiekis / 2])) / 2;
                }
            else
                {
                    mediana = (tarpiniai[pazKiekis / 2]);
                }

                gal_med = mediana * 0.4 + 0.6 *egz_rez;
            

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

void testuoti_clase();

#endif