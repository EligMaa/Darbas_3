#ifndef FUNKCIJOS3_H
#define FUNKCIJOS3_H
#include <numeric>
#include "VEKTORIUS.h"

#include "manoBiblioteka.h"

class zmogus {
    protected:
        string Vardas;
        string Pavarde;

    public:
        zmogus() : Vardas(""), Pavarde("") {}
        zmogus(const std::string& Var, const std::string& Pav) : Vardas(Var), Pavarde(Pav) {}

        virtual ~zmogus() {}

        void set_Vardas(string var){
            Vardas = var;
        }
        void set_Pavarde(string pav){
            Pavarde = pav;
        }

        virtual std::string get_Vardas() const = 0;

        virtual std::string get_Pavarde() const {
            return Pavarde;
        }

        
};

class studentas : public zmogus {
    protected:
    
        double egz_rez;
        int pazKiekis;
        VEKTORIUS <int> tarpiniai;
        double vidurkis;
        double mediana;
        double gal_vid;
        double gal_med;

    public:
        studentas () : tarpiniai (), pazKiekis (0), egz_rez (0){}

        studentas(string Var, string Pav, VEKTORIUS <int> tarp, double egz ) : zmogus(Var, Pav) {
            
            tarpiniai = tarp;
            pazKiekis = tarp.size();
            egz_rez = egz;
            pazKiekis = tarpiniai.size();

        }

        virtual std::string get_Vardas() const override {
            return Vardas;
        }
         
        /// destruktorius
        ~studentas ( ){tarpiniai.clear();}

        /// kopijavimo konstruktorius
        studentas(const studentas& other) : zmogus(other.get_Vardas(), other.get_Pavarde()) {
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
                zmogus :: set_Vardas (other.get_Vardas());
                zmogus :: set_Pavarde (other.get_Pavarde());
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
            other.vidurkis = 0;
            other.mediana = 0;
            other.gal_vid = 0;
            other.gal_med = 0;
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
                other.vidurkis = 0;
                other.mediana = 0;
                other.gal_vid = 0;
                other.gal_med = 0;
            }
            return *this;
        }

        friend ostream& operator<<(ostream& out, const studentas &stud) {                ///isvesties operatorius
        out << left << setw(15) << stud.get_Vardas() << setw(15) << stud.get_Pavarde();
        out << setw(15) << fixed << setprecision(2) << stud.get_gal_v_m(0);
        out << setw(20) << setprecision(2) << stud.get_gal_v_m(1) << "\n";
        return out;
        }

        friend ostream& su_mediana(ostream& out, const studentas& stud) {
            out << left << setw(15) << stud.get_Vardas() << setw(15) << stud.get_Pavarde();
            out << setw(20) << setprecision(2) << stud.gal_med << "\n";
            return out;
        }

        friend ostream& su_vidurkiu(ostream& out, const studentas& stud) {
            out << left << setw(15) << stud.get_Vardas() << setw(15) << stud.get_Pavarde();
            out << setw(20) << setprecision(2) << stud.gal_vid<< "\n";
            return out;
        }


        friend istream& operator>>(istream& in, studentas &stud){
            in >> stud.Vardas >> stud.Pavarde;
            int paz;
            VEKTORIUS <int> pzm;
            while(in >> paz)
            {
                stud.tarpiniai.push_back(paz);
            }
            if(!stud.tarpiniai.empty())
            {
                stud.egz_rez = stud.tarpiniai.back();
                stud.tarpiniai.pop_back();
            }
            
            return in;
        }

        bool operator==(const studentas stud) const {                      /// ivesties operatorius
            
            if (get_Vardas() == stud.get_Vardas() && get_Pavarde() == stud.get_Pavarde()  ) 
            true;
            else false;
            
        }

        void set_egz(int egz){            egz_rez = egz;        }

        double get_egz(){            return egz_rez;        }

        void set_tarpiniai(VEKTORIUS <int> tarp){            tarpiniai = tarp;        }

        VEKTORIUS <int> get_tarpiniai( ) const{       return tarpiniai;        }

        void set_paz_kiekis(int paz){            pazKiekis = paz;                 }

        int get_paz_kieki(){            return pazKiekis;        }

        void set_vidurkis(double vidur){            vidurkis = vidur;        }

        // void set_vidurkis(){            vidurkis = accumulate(tarpiniai.begin(), tarpiniai.end(), 0.0) / tarpiniai.size();        }
        void set_vidurkis() {
            double sum = 0.0;
            for (size_t i = 0; i < tarpiniai.size(); ++i) {
                sum += tarpiniai[i];
            }
            vidurkis = (tarpiniai.size() > 0) ? (sum / tarpiniai.size()) : 0;
        }


        double get_vidurkis(){     return vidurkis;        }

        void set_mediana(double medi){  mediana = medi;    }

        double get_mediana(){  return mediana; }

        void set_gal_v_m (){
           
            gal_vid = vidurkis * 0.4 + 0.6 *egz_rez;
            pazKiekis = tarpiniai.size();
    
            sort(tarpiniai.begin(), tarpiniai.end());

            if ((pazKiekis % 2) == 0)
                {
                    mediana = (double(tarpiniai[pazKiekis / 2 - 1]) + (tarpiniai[pazKiekis / 2])) / 2;
                    if(mediana >10) mediana = gal_vid;
                }
            else
                {
                    mediana = (tarpiniai[pazKiekis / 2]);
                    if(mediana >10) mediana = gal_vid;
                }

                gal_med = mediana * 0.4 + 0.6 *egz_rez;
           

        }
        double get_gal_v_m (int pasirinkimas) const{
            if (pasirinkimas == 0) return gal_vid;
            if (pasirinkimas == 1) return gal_med ;
        }

};


/// ivairus vyriski vardai ir pavardes
const VEKTORIUS <string> vyrV = {"Jonas", "Petras", "Antanas", "Juozas","Arnas","Dziugas", "Mantas", "Stasius","Vilius", "Kazimieras", "Algirdas", "Rimas", "Mindaugas", "Rokas", "Paulius","Kajus", "Pijus", "Titas"};
const VEKTORIUS <string> vyrP = {"Kazlauskas", "Petrauskas", "Jonaitis", "Antanaitis", "Rimkus", "Grybauskas", "Brazauskas", "Vaitkevicius", "Statkus", "Sutkaitis","Baciuska", "Zulkus"};

/// ivairus moteriski vardai ir pavardes
const VEKTORIUS <string> motV = {"Ona", "Marija", "Lina", "Gabija", "Jurga", "Egle", "Ruta","Aida","Karolina","Austeja","Karina","Meda","Jorune", "Gintare", "Deimante", "Aiste", "Kamile", "Rugile", "Ugne","Selina","Monika", "Paulina", "Adriana"};
const VEKTORIUS <string> motP = {"Kazlauskiene", "Petrauskiene", "Jonaite", "Antanaite", "Rimkute", "Grybauskiene", "Brazauskiene", "Vaitkeviciute", "Zobelaite","Macaite","Mockute"};

void spausdinimas(vector<studentas>& var);
double galutinis(vector<studentas>& var, int &k,int &pasirinkimas);
double mediana(vector<studentas>& var,int &k);
double vidurkis(vector<studentas>& var,int &k);
void atsitiktiniaiPazymiai(vector<studentas>& var, int &studSk);
void tikrinimas(int &pasirinkimas);
void ivedimasRanka(vector<studentas>& var, int &studSk);
void atsitiktiniaiPazVar (vector<studentas>& var, int &studSk);
void su_duomenimis_is_failu(vector<studentas>& kursiokai, vector<studentas>& var);
void skaitymas(vector<studentas>& var, VEKTORIUS <string>&failoPav, int indeksas, double &laikas,int laboras);             ///nuskaito duomenis is failo ir iraso i kita faila
void failoKurimas(VEKTORIUS <string>&failoPav, int indeksas, int &kiekND,int &studSk, double &laikas);
void rusiavimas(vector<studentas>& var);
void spausdinami_surikiuoti(vector<studentas>& var,double &laikas);
bool rikiuotiVarda(const studentas &a, const studentas &b);
bool rikiuotiPavarde(const studentas &a, const studentas &b);
bool rikiuotiVid(const studentas &a, const studentas &b);
bool rikiuotiMed(const studentas &a, const studentas &b);
void didejimo (vector<studentas>& var, double &laikas);

void testavimui(vector<studentas>& var);
void rusiavimasTest(vector<studentas>& var, vector<studentas>& vargsai,vector<studentas>& galvociai, double &laikas, int &pasirinkimas,int indeksas);
void spausdinimasTest(vector<studentas>& vargsai, vector<studentas>& galvociai, VEKTORIUS <string> pav, double &laikas,int &pasirinkimas, int indeksas);
void testFail(vector<studentas>& var);
void testFail_3strategija(vector<studentas> &var);
void rusiavimasTest_3strategija(vector<studentas> &var, vector<studentas> &vargsai, double &galutinisLaikas, int &pasirinkimas, int indeksas);
void testFail_2strategija(vector<studentas> &var);
void rusiavimasTest_2strategija(vector<studentas> &var, vector<studentas> &vargsai, double &galutinisLaikas, int &pasirinkimas, int indeksas);

void testuoti_clase();

#endif