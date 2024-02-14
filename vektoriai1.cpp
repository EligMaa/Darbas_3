#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>
#include <algorithm>
#include <vector>

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

};

/// ivairus vyriski vardai ir pavardes
const vector<string> vyrV = {"Jonas", "Petras", "Antanas", "Juozas", "Kazimieras", "Algirdas", "Rimas", "Mindaugas", "Rokas", "Paulius","Kajus", "Pijus", "Titas"};
const vector<string> vyrP = {"Kazlauskas", "Petrauskas", "Jonaitis", "Antanaitis", "Rimkus", "Grybauskas", "Brazauskas", "Vaitkevicius", "Statkus", "Sutkaitis","Baciuska", "Zulkus"};

/// ivairus moteriski vardai ir pavardes
const vector <string> motV = {"Ona", "Marija", "Lina", "Gabija", "Jurga", "Egle", "Ruta", "Aiste", "Kamile", "Rugile", "Ugne","Selina","Monika", "Paulina", "Adriana"};
const vector <string> motP = {"Kazlauskiene", "Petrauskiene", "Jonaite", "Antanaite", "Rimkute", "Grybauskiene", "Brazauskiene", "Vaitkeviciute", "Zobelaite","Macaite","Mockute"};

void spausdinimas(int &m, vector<studentas>& var );
double galutinis(vector<studentas>& var, int &k,int &pasirinkimas);
double mediana(vector<studentas>& var,int &k);
double vidurkis(vector<studentas>& var,int &k);
void atsitiktiniaiPazymiai(vector<studentas>& var, int &m);
void tikrinimas(int &pasirinkimas);
void ivedimasRanka(vector<studentas>& var, int &m);
void atsitiktiniaiPazVar (vector<studentas>& var, int &m);


int main() {

srand(time(nullptr));                                       /// inicializuoja atsitiktinių skaičių generatorių naudojant dabartinį laiką kaip pradinį numerį

int m;
int meniu;
bool baigti = false;

cout<<"Iveskite kiek yra studentu: ";
    while (!(cin >> m) || (m<1))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');                                           /// Ignoruojama visą eilutę iki naujos
        cout << "Klaida! Iveskite naturaluji skaiciu " << endl;
    }
vector <studentas> var (m);                                      
cout<<endl;

do
{
   cout<<"1 - ivedimas ranka"<<endl;
   cout<<"2 - generuoti pazymius"<<endl;
   cout<<"3 - generuoti ir pazymius ir studentu vardus, pavardes"<<endl;
   cout<<"4 - baigti darba"<<endl;
   cout<<"Iveskite pasirinkima: "<<endl;
   cout<<"--------------------------------------------------------"<<endl;
   cin>>meniu;

    switch (meniu)                                                      ///meniu su pasirinkimais
    {
        case 1:
            ivedimasRanka(var, m);
            spausdinimas(m, var);
            cout<<endl;
            break;
        case 2:
            atsitiktiniaiPazymiai(var,m);
            spausdinimas(m, var);
            cout<<endl;            
            break;
        case 3:
            atsitiktiniaiPazVar(var,m);
            spausdinimas(m, var);
            cout<<endl;
            break;
        case 4:
            cout<<"Darbas baigiamas"<<endl;
            baigti=true;
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


} while (!baigti);

}

void atsitiktiniaiPazVar (vector<studentas>& var, int &m){
    
    int n;

    for (int i = 0; i<m; i++){
        
        bool lytis ;                                                           ///jeigu 0 - vyras, jeigu 1 - moteris  
        lytis = rand() % 2;                                                    ///arba 0 arba 1

        if(lytis==0){

            int indeksas = rand() % (vyrV.size());
            var[i].Vardas=vyrV[indeksas];

            indeksas = rand() % (vyrP.size());
            var[i].Pavarde=vyrP[indeksas];
            cout<<"--------------------------------------------------------"<<endl;
            cout<<i+1<<"-ojo"<<" studento vardas: "<<var[i].Vardas<<endl;
            cout<<i+1<<"-ojo"<<" studento pavarde: "<<var[i].Pavarde<<endl;
        }

        if(lytis==1){

            int indeksas = rand() % (motP.size());
            var[i].Vardas=motV[indeksas];

            indeksas = rand() % (motP.size());

            var[i].Pavarde=motP[indeksas];
            cout<<"--------------------------------------------------------"<<endl;
            cout<<i+1<<"-ojo"<<" studento vardas: "<<var[i].Vardas<<endl;
            cout<<i+1<<"-ojo"<<" studento pavarde: "<<var[i].Pavarde<<endl;
       }
 
        cout<<" Iveskite kiek namu darbu uzduociu atliko studentas: ";
        while (!(cin >> n) || (n<0 || n>100))
        {
          cin.clear();
           cin.ignore(numeric_limits<streamsize>::max(), '\n');                                           /// Ignoruojama visą eilutę iki naujos+
           cout << "Klaida! Iveskite nuo 1 iki 100: " << endl;
        }

        var[i].pazKiekis=n;
        var[i].tarpiniai.resize(n);

        cout<<" Atsitiktinai sugeneruoti namu darbu rezultatai: "<<endl;

        for(int j=0; j<n;j++)
        {

            var[i].tarpiniai[j]= rand()% 10+1;                                  ///generuoja atsitikstinius skaicius intervale nuo 1 iki 10

            cout<< var[i].tarpiniai[j]<<"\t";

        }

        cout<<endl;
        cout<<" Atsitiktinai sugeneruotas studento ezamino rezultatas: ";
        var[i].egz_rez= rand()% 10+1;                                           ///generuoja atsitikstinius skaicius intervale nuo 1 iki 10
        cout<<var[i].egz_rez<<endl;
        cout<<endl;

    }

}

void atsitiktiniaiPazymiai(vector<studentas>& var, int &m){

    int n;                                                                          ///namu darbu kiekis

    for (int i =0; i<m; i++){
        cout<<"--------------------------------------------------------"<<endl;
        cout<<" Iveskite "<<i+1<<" studento varda: ";
        cin>>var[i].Vardas;
        cout<<" Iveskite "<<i+1<<" studento pavarde: ";
        cin>>var[i].Pavarde;
        
        cout<<" Iveskite kiek namu darbu uzduociu atliko studentas: ";
        while (!(cin >> n) || (n<1 && n>100))
        {
          cin.clear();
           cin.ignore(numeric_limits<streamsize>::max(), '\n');                                           /// Ignoruojama visą eilutę iki naujos+
           cout << "Klaida! Iveskite nuo 1 iki 100: " << endl;
        }

        var[i].pazKiekis=n;

        cout<<" Atsitiktinai sugeneruoti namu darbu rezultatai: "<<endl;

        for(int j=0; j<n;j++)
        {

            var[i].tarpiniai[j]= rand()% 10+1;                                  ///generuoja atsitikstinius skaicius intervale nuo 1 iki 10

            cout<< var[i].tarpiniai[j]<<"\t";

        }

        cout<<endl;
        cout<<" Atsitiktinai sugeneruotas studento ezamino rezultatas: "<<endl;
        var[i].egz_rez= rand()% 10+1;                                           ///generuoja atsitikstinius skaicius intervale nuo 1 iki 10
        cout<<var[i].egz_rez<<endl;
        cout<<endl;
    }

}

void ivedimasRanka(vector<studentas>& var, int &m){

    for (int i =0; i<m; i++){
        cout<<"--------------------------------------------------------"<<endl;
        cout<<" Iveskite "<<i+1<<" studento varda: ";
        cin>>var[i].Vardas;
        cout<<" Iveskite "<<i+1<<" studento pavarde: ";
        cin>>var[i].Pavarde;
        
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
        var[i].pazKiekis=kiek;
        
        var[i].tarpiniai = skaiciams;

        cout<<"\n Iveskite "<<i+1<<" studento ezamino rezultata: "<<endl;
        cin>>var[i].egz_rez;
        cout<<endl;
    }
}

void tikrinimas(int &pasirinkimas){

    while (!(cin >> pasirinkimas) || (pasirinkimas!=0 && pasirinkimas!=1))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');                                           /// Ignoruojama visą eilutę iki naujos
        cout << "Klaida! Iveskite 1 arba 0: " << endl;
    }
}

void spausdinimas(int &m, vector<studentas>& var){

    int pasirinkimas; 

    cout<<"Jei norite spausdinti studentu galutini iverinima naudojant vidurki iveskite: 0";
    cout<<"\nJei norite spausdinti studentu galutini iverinima naudojant mediana iveskite: 1\n"<<endl;

    tikrinimas(pasirinkimas);                                                                          ///patikrina ar ivesta 0 arba 1

    cout<<endl;
    
    if(pasirinkimas==0){                                                       ///isvedama informacija apie studentus ir galutinis rezultatas apskaiciuotas su vidurkiu

        cout<< left <<setw(15)<< "Pavarde"<<setw(15)<<"Vardas"<<setw(15)<<"Galutinis (Vid.) "<<endl;
        cout<<"------------------------------------------------"<<endl;
        for(int i=0;i<m; i++){
           cout<<left<<setw(15)<<var[i].Vardas<<setw(15)<<var[i].Pavarde;
         cout<<setw(15) << fixed<< setprecision(2)<<galutinis(var,i,pasirinkimas)<<endl;
        }
    }

    else {                                                                      ///isvedama informacija apie studentus ir galutinis rezultatas apskaiciuotas su mediana

        cout<< left <<setw(15)<< "Pavarde"<<setw(15)<<"Vardas"<<setw(15)<<"Galutinis (Med.) "<<endl;
        cout<<"-------------------------------------------------------"<<endl;

        for(int i=0;i<m; i++){

            cout<<left<<setw(15)<<var[i].Vardas<<setw(15)<<var[i].Pavarde;
         cout<<setw(30)<< fixed<< setprecision(2)<<galutinis(var,i,pasirinkimas)<<endl;
        }


    } 

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

