#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
#include <random>
#include <ctime>
#include <sstream>
#include <chrono>



using namespace std;

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
const vector<string> vyrV = {"Jonas", "Petras", "Antanas", "Juozas", "Kazimieras", "Algirdas", "Rimas", "Mindaugas", "Rokas", "Paulius","Kajus", "Pijus", "Titas"};
const vector<string> vyrP = {"Kazlauskas", "Petrauskas", "Jonaitis", "Antanaitis", "Rimkus", "Grybauskas", "Brazauskas", "Vaitkevicius", "Statkus", "Sutkaitis","Baciuska", "Zulkus"};

/// ivairus moteriski vardai ir pavardes
const vector <string> motV = {"Ona", "Marija", "Lina", "Gabija", "Jurga", "Egle", "Ruta", "Aiste", "Kamile", "Rugile", "Ugne","Selina","Monika", "Paulina", "Adriana"};
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
void skaitymas_isvedimas(vector<studentas>& var, vector<string>&failoPav, int indeksas,int &kiekND, double &laikas);             ///nuskaito duomenis is failo ir iraso i kita faila
void spausdinimasFailo(vector<studentas>& var,  int &kiekMok,int &kiekND, int &pasirinkimas);
void failoKurimas( int &kiekND);
void rusiavimas(vector<studentas>& var);
void spausdinami_surikiuoti(vector<studentas>& kursiokai);


bool rikiuotiVarda(const studentas &a, const studentas &b) {
    return a.Vardas < b.Vardas;
}

bool rikiuotiPavarde(const studentas &a, const studentas &b) {
    return a.Pavarde < b.Pavarde;
}

bool rikiuotiVid(const studentas &a, const studentas &b) {
    return a.gal_vid < b.gal_vid;
}

bool rikiuotiMed(const studentas &a, const studentas &b) {
    return a.gal_med < b.gal_med;
}



int main() {

srand(time(nullptr));                                       /// inicializuoja atsitiktinių skaičių generatorių naudojant dabartinį laiką kaip pradinį numerį

int meniu;
int meniu_duomenu_ivedimui;
int studSk;
bool baigti = false;
bool baigti_duom_ived = false;
vector <studentas> var, kursiokai;                                      

do
{ 
    cout<<"Pasirinkite kaip dirbsite su duomenimis:"<<endl;
    cout<<"1 - domenu ivedimas"<<endl;
    cout<<"2 - duomenu skaitymas is failo"<<endl;
    cout<<"3 - baigti darba"<<endl;
    cout<<"--------------------------------------------------------"<<endl;
    cin>>meniu;
    cout<<endl;

    switch (meniu)                                                                                  /// meniu skirtas v0.2
    {
    case 1:
    
        cout<<"Duomenu ivedimui pasirinkite buda: "<<endl;
        do
            {
            cout<<"1 - ivedimas ranka"<<endl;
            cout<<"2 - generuoti pazymius"<<endl;
            cout<<"3 - generuoti ir pazymius ir studentu vardus, pavardes"<<endl;
            cout<<"4 - baigti darba"<<endl;
            cout<<"Iveskite pasirinkima: "<<endl;
            cout<<"--------------------------------------------------------"<<endl;
            cin>>meniu_duomenu_ivedimui;

                switch (meniu_duomenu_ivedimui)                                                      ///meniu skirtas v0.1
                {
                    case 1:
                        ivedimasRanka(var,studSk);
                        spausdinimas(var);
                        cout<<endl;
                        break;
                    case 2:
                        atsitiktiniaiPazymiai(var, studSk);
                        spausdinimas(var);
                        cout<<endl;            
                        break;
                    case 3:
                        atsitiktiniaiPazVar(var, studSk);
                        spausdinimas( var);
                        cout<<endl;
                        break;
                    case 4:
                        cout<<"Darbas su duomenu ivedimu baigtas\n"<<endl;
                        baigti_duom_ived=true;
                        break;
                    default:
                        cout<< "Klaida! Iveskite nuo 1 iki 4 " << endl;

                        while (!(meniu_duomenu_ivedimui) || (meniu_duomenu_ivedimui<1 && meniu_duomenu_ivedimui>4))
                        {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');                                           /// Ignoruojama visą eilutę iki naujos
                            break;
                        }
                        cout<<endl;
                }

            } while (!baigti_duom_ived);
        break;

    case 2:
        cout<<" Duomenu skaitymas is failo 'kursiokai.txt' "<<endl;
        su_duomenimis_is_failu(kursiokai, var);
        break;
    
    case 3:
        cout<<"Darbas su duomenu ivedimu baigtas\n"<<endl;
        baigti=true;
        break;

    default:
        cout<< "Klaida! Iveskite nuo 1 iki 2 " << endl;

        while (!(meniu) || (meniu<1 && meniu>2))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');                                           /// Ignoruojama visą eilutę iki naujos
            break;
        }
        cout<<endl;
        break;
    
    }

} while (!baigti);


return 0;
}

void rusiavimas(vector<studentas>& kursiokai){                                                        ///pagal pasirinktus kriterijus surusiuoja kursiokai vektoriu

    kursiokai.clear();
    ifstream failas("kursiokai.txt");
    if(!failas.is_open())                                                    ///patikrina ar failas egzustuoja
    {
        cout<<"Klaida! Failas nerastas"<<endl;
        return;
    }

    double vidurkis, medi;
    int pasirinkimas, mok=5;

    ///perskaitomi duomenys is failo
    while (!failas.eof())
    {   
        studentas naujasStudentas;                                     ///sukuria nauja objekta

        string line;
        getline(failas, line);

        failas>>naujasStudentas.Vardas>>naujasStudentas.Pavarde;
   
        double sum = 0;

            for(int i = 0; i<5; i++){
                int pazymys;
                failas>>pazymys;
                naujasStudentas.tarpiniai.push_back(pazymys);
                sum+=pazymys;

            }

            failas>>naujasStudentas.egz_rez;

            double vidurkis = sum / 5; 
            naujasStudentas.gal_vid = vidurkis*0.4+0.6*naujasStudentas.egz_rez; 
            double medi;
            sort(naujasStudentas.tarpiniai.begin(), naujasStudentas.tarpiniai.end());

            ///kadangi 5 pazymiai o 5 yra nelyginis skaicius
            medi= ( naujasStudentas.tarpiniai[5/2]);
            
            naujasStudentas.gal_med = medi * 0.4 + 0.6 * naujasStudentas.egz_rez;


        kursiokai.push_back(naujasStudentas);

        naujasStudentas.tarpiniai.clear();
    }

    failas.close();

    int meniu;
    
        cout<<"Pasirinkite kaip norite rusiuoti duomenimis:"<<endl;
        cout<<"1 - pagal studento varda"<<endl;
        cout<<"2 - pagal studento pavarde"<<endl;
        cout<<"3 - pagal studento galutini ivertinima su vidurkiu"<<endl;
        cout<<"4 - pagal studento galutini ivertinima su mediana"<<endl;

        cout<<"--------------------------------------------------------"<<endl;
        cin>>meniu;
        cout<<endl;

   

        switch (meniu)                                                                                  /// meniu skirtas v0.2
        {
            case 1:
                sort(kursiokai.begin(), kursiokai.end(), rikiuotiVarda);

                break;
            case 2:
                sort(kursiokai.begin(), kursiokai.end(), rikiuotiPavarde);
                break;
            case 3:
                sort(kursiokai.begin(), kursiokai.end(), rikiuotiVid);

                break;
            case 4:
                sort(kursiokai.begin(), kursiokai.end(), rikiuotiMed);

                break;

            default:
                cout<< "Klaida! Iveskite nuo 1 iki 4 " << endl;

                while (!(meniu) || (meniu<1 && meniu>4))
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');                                           /// Ignoruojama visą eilutę iki naujos
                    break;
                }
                cout<<endl;

        }
   

}

void spausdinami_surikiuoti(vector<studentas>& kursiokai){                                            ///isspausdina i rezultatu faila surikiuota sarasa
    ofstream print ("rez.txt");
    print<< left <<setw(15)<< "Vardas"<<setw(15)<<"Pavarde"<<setw(15)<<"Galutinis (Vid.) "<<setw(15)<<"Galutinis (Med.) "<<endl;
    print<<"-----------------------------------------------------------"<<endl;

    for(int i=0; i<kursiokai.size(); i++){
    
        print<<left <<setw(15)<<kursiokai[i].Vardas<<setw(15)<<kursiokai[i].Pavarde;
        print<<setw(15)<<fixed<<setprecision(2) << kursiokai[i].gal_vid << setw(20) << setprecision(2) << kursiokai[i].gal_med << endl;

    }      

    print.close();
}

void skaitymas_isvedimas(vector<studentas>& var, vector<string>&failoPav, int indeksas,int &kiekND, double &laikas){  ///nuskaito pasirinkta faila pagal indeksa ir sukuria rezultatu faila

    studentas naujasStudentas;                                     ///sukuria nauja objekta
    int kiekMok=0;                                                 ///mokiniu skaicius
    int pasirinkimas;
    vector <int> skaiciams; 

    ifstream failas(failoPav[indeksas]);
    if(!failas.is_open())                                                    ///patikrina ar failas egzustuoja
    {
        cout<<"Klaida! Failas nerastas"<<endl;
        return;
    }
 
    ///pasirenkama ar rezultatus spausdins su vidurkiu ar mediana
    cout<<"Jei norite spausdinti studentu galutini iverinima naudojant vidurki iveskite: 0";
    cout<<"\nJei norite spausdinti studentu galutini iverinima naudojant mediana iveskite: 1\n"<<endl;

    tikrinimas(pasirinkimas);                                                                          ///patikrina ar ivesta 0 arba 1
    
    auto start = chrono::high_resolution_clock::now();                                                 /// pradeti laiko skaiciavima

    while (!failas.eof())
    {   
        string line;
        getline(failas, line);
        failas>>naujasStudentas.Vardas>>naujasStudentas.Pavarde;
        kiekMok++;
       
        for(int i=0; i<kiekND; i++){

            int pazimys;
            failas>>pazimys;
            skaiciams.push_back(pazimys);
        }
        naujasStudentas.tarpiniai=skaiciams;

        skaiciams.clear();                                                                              ///isvalomas vektorius
        failas.ignore();
        failas>>naujasStudentas.egz_rez;
        var.push_back(naujasStudentas);

        cout<<endl;
        spausdinimasFailo(var, kiekMok, kiekND, pasirinkimas);                                         /// funkcija kuri ispausdina rezultatu faila

        var.clear();                                                                                   ///isvalomas vektorius
    }
    auto end = chrono::high_resolution_clock::now();                                                   /// baigti laiko skaiciavima
    chrono::duration<double> time = end - start;                                                       /// laikas
    laikas = time.count();
    cout<<" Uztruko: "<< laikas<<"s."<<endl;
    cout<<endl;
    failas.close();
}

void failoKurimas( int &kiekND){                                                                              ///sukuria "kursiokai.txt" faila

    ofstream failas ("kursiokai.txt");

    failas<< left <<setw(15)<< "Vardas"<<setw(15)<<"Pavarde"<<setw(5)<<"ND1"<<setw(5)<<"ND2"<<setw(5)<<"ND3";
    failas<<setw(5)<<"ND4"<<setw(5)<<"ND5"<<setw(5)<<"Egz."<<endl;

    int m = 10;                                                                       ///studentu skaicius
    
    
            for (int i = 0; i<m; i++){
        
                bool lytis ;                                                           ///jeigu 0 - vyras, jeigu 1 - moteris  
                lytis = rand() % 2;                                                    ///arba 0 arba 1

                studentas naujasStudentas;                                             ///sukuria nauja objekta

                if(lytis==0){

                    int indeksas = rand() % (vyrV.size());                             ///atsitinktinai  istrenkamas vardas
                    naujasStudentas.Vardas=vyrV[indeksas];
                    indeksas = rand() % (vyrP.size());
                    naujasStudentas.Pavarde=vyrP[indeksas];

                    failas<<left <<setw(15)<<naujasStudentas.Vardas;
                    failas<<left <<setw(15)<<naujasStudentas.Pavarde;               
                
                }

                if(lytis==1){

                    int indeksas = rand() % (motP.size());
                    naujasStudentas.Vardas=motV[indeksas];

                    indeksas = rand() % (motP.size());
                    naujasStudentas.Pavarde=motP[indeksas];

                    failas<<left <<setw(15)<<naujasStudentas.Vardas;
                    failas<<left <<setw(15)<<naujasStudentas.Pavarde;
                }
 

                for(int j=0; j<kiekND;j++)
                {
                    int pazymys = ( rand()% 10+1);                                               ///generuoja atsitikstinius skaicius intervale nuo 1 iki 10

                    failas<< left <<setw(5)<< pazymys;
                    naujasStudentas.tarpiniai.push_back(pazymys);
                }

                naujasStudentas.egz_rez= rand()% 10+1;                                           ///generuoja atsitikstinius skaicius intervale nuo 1 iki 10
                
                if(i==9){

                    failas<<naujasStudentas.egz_rez;                                             ///kad nesusidarytu papildoma eilute nededamas endl

                }
                else
                failas<<naujasStudentas.egz_rez<<endl;
                
                naujasStudentas.tarpiniai.clear();
            }       


        
    
    


    failas.close();
}

void spausdinimasFailo(vector<studentas>& var,  int &kiekMok,int &kiekND, int &pasirinkimas){        ///isspausdinami duomenys i rezultatu faila


    studentas naujasStudentas = var[var.size()-1];                                     ///sukuria nauja objekta

    ///jei pasirinko spausdinti galutini rezultata su viduriu
    if(pasirinkimas==0){    

        if(kiekMok==1){
            ofstream print ("rez.txt");
            print<< left <<setw(15)<< "Vardas"<<setw(15)<<"Pavarde"<<setw(15)<<"Galutinis (Vid.) "<<endl;
            print<<"------------------------------------------------"<<endl;
            print<<left <<setw(15)<<naujasStudentas.Vardas<<setw(15)<<naujasStudentas.Pavarde;
            
            double sum = 0;

            for(int i = 0; i<kiekND; i++){

                sum+=naujasStudentas.tarpiniai[i];

            }
            double vidurkis = sum / kiekND; 
            vidurkis = vidurkis*0.4+0.6*naujasStudentas.egz_rez; 

            print<<setw(15) << fixed<< setprecision(2)<<vidurkis<<endl;

            print.close();

        }

        else{

            ofstream print ("rez.txt", ios::app);
            print<<left <<setw(15)<<naujasStudentas.Vardas<<setw(15)<<naujasStudentas.Pavarde;

            double sum = 0;

            for(int i = 0; i<kiekND; i++){

                sum+=naujasStudentas.tarpiniai[i];

            }
            double vidurkis = sum / kiekND;
            vidurkis = vidurkis*0.4+0.6*naujasStudentas.egz_rez; 
            print<<setw(15) << fixed<< setprecision(2)<<vidurkis<<endl;
            
            print.close();
        }
    }

    ///jei pasirinko spausdinti galutini rezultata su mediana
    if(pasirinkimas==1){       


        if(kiekMok==1){
            ofstream print ("rez.txt");
            print<< left <<setw(15)<< "Vardas"<<setw(15)<<"Pavarde"<<setw(15)<<"Galutinis (Med.) "<<endl;
            print<<"------------------------------------------------"<<endl;
            print<<left <<setw(15)<<naujasStudentas.Vardas<<setw(15)<<naujasStudentas.Pavarde;

            double medi;
            sort(naujasStudentas.tarpiniai.begin(), naujasStudentas.tarpiniai.end());

            ///jei lyginis pazymiu skaicius
            if((kiekND%2)==0){
                medi= ( double(naujasStudentas.tarpiniai[kiekND/2-1]) + (naujasStudentas.tarpiniai[kiekND/2]) ) /2;
            }

            ///jei nelyginis pazymiu skaicius
            else {
                medi= ( naujasStudentas.tarpiniai[kiekND/2]);
            }
            medi = medi * 0.4 + 0.6 * naujasStudentas.egz_rez;
            print<<setw(15) << fixed<< setprecision(2)<<medi<<endl;
            print.close();

        }

        else{

            ofstream print ("rez.txt", ios::app);
            print<<left <<setw(15)<<naujasStudentas.Vardas<<setw(15)<<naujasStudentas.Pavarde;
            
            double medi;
            sort(naujasStudentas.tarpiniai.begin(), naujasStudentas.tarpiniai.end());

            if((kiekND%2)==0){
                medi= ( double(naujasStudentas.tarpiniai[kiekND/2-1]) + (naujasStudentas.tarpiniai[kiekND/2]) ) /2;
            }

            ///jei nelyginis pazymiu skaicius
            else {
                medi= ( naujasStudentas.tarpiniai[kiekND/2]);
            }
            medi = medi * 0.4 + 0.6 * naujasStudentas.egz_rez;

            print<<setw(15) << fixed<< setprecision(2)<<medi<<endl;
            print.close();
        }
    }

}

void su_duomenimis_is_failu(vector<studentas>& kursiokai,vector<studentas>& var){                         ///jei pasirinko dirbti su duomenu failais

    int meniu;
    double laikas;
    bool baigti = false;
    int kiekND, indeksas;
    vector<string> failoPav {"kursiokai.txt","studentai10000.txt", "studentai100000.txt","studentai1000000.txt"};            ///vektorius saugo failu pavadinimus

    cout<<"Pasirinkite kuri duomenu faila nauduosite: "<<endl;
        do
        {
            cout<<"1 - is sugeneruoto duomenu failo"<<endl;
            cout<<"2 - is testavimo failo su 10000 studentu duomenu"<<endl;
            cout<<"3 - is testavimo failo su 100000 studentu duomenu"<<endl;
            cout<<"4 - is testavimo failo su 1000000 studentu duomenu"<<endl;
            cout<<"5 - baigti darba"<<endl;
            cout<<"Iveskite pasirinkima: "<<endl;
            cout<<"--------------------------------------------------------"<<endl;
            cin>>meniu;

            switch (meniu)                                                      ///meniu skirtas v0.1
            {
                    case 1:
                        indeksas=0;                                             ///indeksas, kuris nurodo kelintas failo pavadinimas yra vektoriuje 
                        kiekND = 5;
                        failoKurimas( kiekND);
                        rusiavimas(kursiokai);
                        spausdinami_surikiuoti(kursiokai);
                    
                        break;
                    case 2:
                        indeksas=1;
                        kiekND = 15;
                        skaitymas_isvedimas(var, failoPav, indeksas, kiekND, laikas);

                        break;
                    case 3:
                        indeksas=2;
                        kiekND = 20;
                        skaitymas_isvedimas(var, failoPav, indeksas, kiekND, laikas);

                        break;
                    case 4:
                        indeksas=3;
                        kiekND = 7;
                        skaitymas_isvedimas(var, failoPav, indeksas, kiekND, laikas);
                        
                        break;

                    case 5:
                        cout<<"Darbas su duomenu ivedimu baigtas\n"<<endl;
                        baigti=true;
                        break;

                    default:
                        cout<< "Klaida! Iveskite nuo 1 iki 5 " << endl;

                        while (!(meniu) || (meniu<1 && meniu>5))
                        {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');                                           /// Ignoruojama visą eilutę iki naujos
                            continue;
                            break;
                        }
                        cout<<endl;
                }

        }while (!baigti); 

}


void atsitiktiniaiPazVar (vector<studentas>& var, int &studSk){
    
    int n;
    int m = (rand() % 10) + 1;                                                         ///atsitiktinai sugeneruoja kiek yra studentu
    studSk=m;
    do{
            for (int i = 0; i<m; i++){
        
                bool lytis ;                                                           ///jeigu 0 - vyras, jeigu 1 - moteris  
                lytis = rand() % 2;                                                    ///arba 0 arba 1

                studentas naujasStudentas;                                     ///sukuria nauja objekta

                if(lytis==0){

                    int indeksas = rand() % (vyrV.size());                             ///atsitinktinai  istrenkamas vardas
                    naujasStudentas.Vardas=vyrV[indeksas];
                    indeksas = rand() % (vyrP.size());
                    naujasStudentas.Pavarde=vyrP[indeksas];
                    cout<<"--------------------------------------------------------"<<endl;
                    cout<<i+1<<"-ojo"<<" studento vardas: "<<naujasStudentas.Vardas<<endl;
                    cout<<i+1<<"-ojo"<<" studento pavarde: "<<naujasStudentas.Pavarde<<endl;
                }

                if(lytis==1){

                    int indeksas = rand() % (motP.size());
                    naujasStudentas.Vardas=motV[indeksas];

                    indeksas = rand() % (motP.size());

                    naujasStudentas.Pavarde=motP[indeksas];
                    cout<<"--------------------------------------------------------"<<endl;
                    cout<<i+1<<"-ojo"<<" studento vardas: "<<naujasStudentas.Vardas<<endl;
                    cout<<i+1<<"-ojo"<<" studento pavarde: "<<naujasStudentas.Pavarde<<endl;
                }
 
                n= rand()% 10+1;                                                                 ///atsitiktinai sugeneruoja kiek namu darbu atliko studentas
                cout<<" Studentas atliko "<<n<<" namu darbu uzduotis"<<endl;

                naujasStudentas.pazKiekis=n;
                naujasStudentas.tarpiniai.resize(n);


                cout<<" Atsitiktinai sugeneruoti namu darbu rezultatai: "<<endl;

                for(int j=0; j<n;j++)
                {

                    naujasStudentas.tarpiniai[j]= rand()% 10+1;                                  ///generuoja atsitikstinius skaicius intervale nuo 1 iki 10

                    cout<< naujasStudentas.tarpiniai[j]<<"\t";

                }

                cout<<endl;
                cout<<" Atsitiktinai sugeneruotas studento ezamino rezultatas: ";
                naujasStudentas.egz_rez= rand()% 10+1;                                           ///generuoja atsitikstinius skaicius intervale nuo 1 iki 10
                cout<<naujasStudentas.egz_rez<<endl;
                cout<<endl;

                var.push_back(naujasStudentas);                                          ///pridedamas naujas studentas i vektoriu

            }       


        m--;
    }while (m==0);
    
    

}

void atsitiktiniaiPazymiai(vector<studentas>& var, int &studSk){

    int n;                                                                          ///namu darbu kiekis
    bool pasirinkimas;
    int i=0;
    do
    {   if(i!=0){
        cout<<"--------------------------------------------------------"<<endl;
        cout<<" Jei norite irasyti studenta iveskite 1, o jei norite baigti vedima - 0"<<endl;

        while (!(cin >> pasirinkimas) || (pasirinkimas!=0 && pasirinkimas!=1))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');                                           /// Ignoruojama visą eilutę iki naujos
            cout << "Klaida! Iveskite 1 arba 0: " << endl;
        } 
        }

        if(pasirinkimas==false && i>0) break;

        i++;
        
        studentas naujasStudentas;                                     ///sukuria nauja objekta

        cout<<"--------------------------------------------------------"<<endl;
        cout<<" Iveskite "<<i<<" studento varda: ";
        cin>>naujasStudentas.Vardas;
        cout<<" Iveskite "<<i<<" studento pavarde: ";
        cin>>naujasStudentas.Pavarde;
        
            cout<<" Iveskite kiek namu darbu uzduociu atliko studentas: ";
            while (!(cin >> n) || (n<1 && n>100))
            {
             cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(), '\n');                                           /// Ignoruojama visą eilutę iki naujos+
              cout << "Klaida! Iveskite nuo 1 iki 100: " << endl;
            }

            naujasStudentas.pazKiekis=n;
            naujasStudentas.tarpiniai.resize(n);

            cout<<" Atsitiktinai sugeneruoti namu darbu rezultatai: "<<endl;

            for(int j=0; j<n;j++)
            {
                
               naujasStudentas.tarpiniai[j]= rand()% 10+1;                                  ///generuoja atsitikstinius skaicius intervale nuo 1 iki 10

               cout<< naujasStudentas.tarpiniai[j]<<"\t";

            }

            cout<<endl;
            cout<<" Atsitiktinai sugeneruotas studento ezamino rezultatas: "<<endl;
            naujasStudentas.egz_rez= rand()% 10+1;                                           ///generuoja atsitikstinius skaicius intervale nuo 1 iki 10
            cout<<naujasStudentas.egz_rez<<endl;
            var.push_back(naujasStudentas);
            pasirinkimas=true;
            studSk=i;


    }while(pasirinkimas==true);
}

void ivedimasRanka(vector<studentas>& var, int &studSk){

    bool pasirinkimas;
    int i=0;
    do
    {
        if(i!=0){
        cout<<"--------------------------------------------------------"<<endl;
        cout<<" Jei norite irasyti studenta iveskite 1, o jei norite baigti vedima - 0"<<endl;
    
        while (!(cin >> pasirinkimas) || (pasirinkimas!=0 && pasirinkimas!=1))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');                                           /// Ignoruojama visą eilutę iki naujos
            cout << "Klaida! Iveskite 1 arba 0: " << endl;
        } 
        }

        if(pasirinkimas==false && i==0){

            cout<<" Klaida! Reikia ivesti nors viena studenta "<<endl;
        }
        if(pasirinkimas==false && i>0) break;

        i++;
        studentas naujasStudentas;                                     ///sukuria nauja objekta
        cout<<"--------------------------------------------------------"<<endl;
        cout<<" Iveskite "<<i<<" studento varda: ";
        cin>>naujasStudentas.Vardas;
        cout<<" Iveskite "<<i<<" studento pavarde: ";
        cin>>naujasStudentas.Pavarde;
        
        cout<<" Iveskite studento namu darbu rezultatus (noredami baigti ivedima iveskite 0): "<<endl;
        
        int pazimys;
        int kiek=0;                                                                 /// pazymiu sk
        vector <int> skaiciams;

        while (true)
        {
            while (!(cin >> pazimys) || pazimys<0 || pazimys>10)                      ///tikrina ar pazimys yra intervale nuo 1 iki 10
            {
               cin.clear();
               cin.ignore(numeric_limits<streamsize>::max(), '\n');
               cout << " Klaida. Iveskite skaiciu nuo 1 iki 10" << endl;
            }            

            if(pazimys==0)break;                                                      ///jei iveda 0 nutraukiamas ciklas

            else{
            skaiciams.push_back(pazimys);
            kiek++;
            }
        }

        naujasStudentas.pazKiekis = kiek;
        naujasStudentas.tarpiniai = skaiciams;

        cout<<"\n Iveskite "<<i<<" studento ezamino rezultata: "<<endl;

            while (!(cin>>naujasStudentas.egz_rez) || (naujasStudentas.egz_rez<0 || naujasStudentas.egz_rez>10))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');                                           /// Ignoruojama visą eilutę iki naujos
                cout << "Klaida! Iveskite nuo 1 iki 10: " << endl;

            }
        cout<<endl;

        var.push_back(naujasStudentas);
        pasirinkimas=true;
        studSk=i;


    }while (pasirinkimas == true);


}

void tikrinimas(int &pasirinkimas){                                                                      ///tikrina pasirinkima

    while (!(cin >> pasirinkimas) || (pasirinkimas!=0 && pasirinkimas!=1))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');                                           /// Ignoruojama visą eilutę iki naujos
        cout << "Klaida! Iveskite 1 arba 0: " << endl;
    }
}

void spausdinimas(vector<studentas>& var){

    int pasirinkimas; 

    cout<<"Jei norite spausdinti studentu galutini iverinima naudojant vidurki iveskite: 0";
    cout<<"\nJei norite spausdinti studentu galutini iverinima naudojant mediana iveskite: 1\n"<<endl;

    tikrinimas(pasirinkimas);                                                                          ///patikrina ar ivesta 0 arba 1

    cout<<endl;
    
    if(pasirinkimas==0){                                                       ///isvedama informacija apie studentus ir galutinis rezultatas apskaiciuotas su vidurkiu

        cout<< left <<setw(15)<< "Vardas"<<setw(15)<<"Pavarde"<<setw(15)<<"Galutinis (Vid.) "<<endl;
        cout<<"------------------------------------------------"<<endl;

        for(int i=0;i<var.size(); i++){
         cout<<left<<setw(15)<<var[i].Vardas<<setw(15)<<var[i].Pavarde;
         cout<<setw(15) << fixed<< setprecision(2)<<galutinis(var,i,pasirinkimas)<<endl;
        }
    }

    else {                                                                      ///isvedama informacija apie studentus ir galutinis rezultatas apskaiciuotas su mediana

        cout<< left <<setw(15)<< "Vardas"<<setw(15)<<"Pavarde"<<setw(15)<<"Galutinis (Med.) "<<endl;
        cout<<"-------------------------------------------------------"<<endl;

        for(int i=0;i<var.size(); i++){
            cout<<left<<setw(15)<<var[i].Vardas<<setw(15)<<var[i].Pavarde;
            cout<<setw(30)<< fixed<< setprecision(2)<<galutinis(var,i,pasirinkimas)<<endl;
        }


    } 

    var.resize(0);
}

double galutinis(vector<studentas>& var, int &k,int &pasirinkimas){                                     ///galutinio rezultato skaiciavimas

    double gal;
    if(pasirinkimas==0){
     gal=vidurkis(var, k) * 0.4 + 0.6 * var[k].egz_rez;
    }

    else{
        gal=(mediana(var, k)) * 0.4 + 0.6 * var[k].egz_rez;
    }

    return gal;
}

double mediana(vector<studentas>& var, int &k){

    int pazymiai = var[k].pazKiekis;
    double medi;

    if(pazymiai==0)                                              ///jei nera ivesta pazymiu                                                        ///jeigu nebuvo ivestas nei vienas pazymys
    { return 0; }

    else
    {
        sort(var[k].tarpiniai.begin(), var[k].tarpiniai.end());


        if((pazymiai%2)==0){
            medi= ( double(var[k].tarpiniai[pazymiai/2-1]) + (var[k].tarpiniai[pazymiai/2]) ) /2;
        }

     else {
         medi= ( var[k].tarpiniai[pazymiai/2]);
        }
        var[k].mediana=medi;
        return medi;
    }

}

double vidurkis(vector<studentas>& var, int &k){
    double sum=0.0;

    if(var[k].pazKiekis==0)                                       ///jeigu nebuvo ivestas nei vienas pazymys
    { return var[k].pazKiekis; }

    else {
        for(int j=0; j<var[k].pazKiekis;j++){                     ///pazymiu suma
            sum+=var[k].tarpiniai[j];
        }
        double vid = sum/var[k].pazKiekis;                       ///skaiciuojamas vidurkis

        var[k].vidurkis=vid;

        return vid;
    }


}

