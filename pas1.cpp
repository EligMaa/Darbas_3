#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>
#include <algorithm>


using namespace std;

struct studentas
{
    string Vardas;
    string Pavarde;
    int egz_rez;
    int pazKiekis;
    int* tarpiniai;                         ///rodykle i masyvo adresa sukis saugos namu darbu rezultatus
    double vidurkis;
    double mediana;

};

void spausdinimas(int &m, studentas var[]);
double galutinis(studentas var[], int &k,int &pasirinkimas);
double mediana(studentas var[],int &k);
double vidurkis(studentas var[],int &k);
void atsitiktiniaiPazymiai(studentas var[], int &pasirinkimas, int &m);
void tikrinimas(int &pasirinkimas);
void ivedimasRanka(studentas var[], int &pasirinkimas, int &m);

int main() {

int n;
int m;
int pasirinkimas;

do
{
   cout<<"1 - ivedimas ranka"<<endl;
   cout<<"2 - generuoti pazymius"<<endl;
   cout<<"3 - generuoti ir pazymius ir studentu vardus, pavardes"<<endl;
   cout<<"4 - baigti darba"<<endl;
   cout<<"Iveskite pasirinkima: ";

} while (/* condition */);


cout<<"Iveskite kiek yra studentu: ";
cin >> m;
studentas* var = new studentas [m];                                /// rodyklė rodanti i dinamineje atmintyje sukurta strukturu masyva

cout << "Jei norite atsitiktinai generoti namu darbu ir egzamino pazymius iveskite 1, jei norite irasyti ranka - 0" << endl;

tikrinimas(pasirinkimas);
cout<<endl;

if(pasirinkimas==0){                                             ///jei norima ivesti rezultatus ranka
    ivedimasRanka(var, pasirinkimas, m);
}

else  {                                                          ///jei norima kad rezultatai butu sugeneruoti atsitiktinai
    atsitiktiniaiPazymiai(var, pasirinkimas, m);
}


spausdinimas(m, var);

delete[] var->tarpiniai;
delete[] var;


}

void atsitiktiniaiPazymiai(studentas var[], int &pasirinkimas, int &m){

    int n;                                                            ///namu darbu kiekis

    for (int i =0; i<m; i++){
        cout<<" Iveskite "<<i+1<<" studento varda: ";
        cin>>var[i].Vardas;
        cout<<" Iveskite "<<i+1<<" studento pavarde: ";
        cin>>var[i].Pavarde;
        
        cout<<" Iveskite kiek namu darbu uzduociu atliko studentas: ";
        cin>>n;

        var[i].pazKiekis=n;
        var[i].tarpiniai = new int [n];

        cout<<" Atsitiktinai sugeneruoti namu darbu rezultatai: "<<endl;

        for(int j=0; j<n;j++)
        {

            var[i].tarpiniai[j]= rand()% (1-10+1);                                  ///generuoja atsitikstinius skaicius intervale nuo 1 iki 10

            cout<< var[i].tarpiniai[j]<<"\t";

        }

        cout<<endl;
        cout<<" Atsitiktinai sugeneruotas studento ezamino rezultatas: ";
        var[i].egz_rez= rand()% (1-10+1);                                           ///generuoja atsitikstinius skaicius intervale nuo 1 iki 10
        cout<<var[i].egz_rez<<endl;
        cout<<endl;
    }

}

void ivedimasRanka(studentas var[], int &pasirinkimas, int &m){

    int n;                                                            ///namu darbu kiekis
    for (int i =0; i<m; i++){
        cout<<" Iveskite "<<i+1<<" studento varda: ";
        cin>>var[i].Vardas;
        cout<<" Iveskite "<<i+1<<" studento pavarde: ";
        cin>>var[i].Pavarde;
        
        cout<<" Iveskite kiek namu darbu uzduociu atliko studentas: ";
        cin>>n;

        var[i].pazKiekis=n;
        var[i].tarpiniai = new int [n];

        cout<<" Iveskite studento namu darbu rezultatus: "<<endl;
        for(int j=0; j<n;j++)
        {
        cin>>var[i].tarpiniai[j];

        cout<<" Iveskite "<<i+1<<" studento ezamino rezultata: ";
        cin>>var[i].egz_rez;
        cout<<endl;
        }
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

void spausdinimas(int &m,studentas var[]){

    int pasirinkimas; 

    cout<<"Jei norite spausdinti studentu galutini iverinima naudojant vidurki iveskite: 0";
    cout<<"\nJei norite spausdinti studentu galutini iverinima naudojant mediana iveskite: 1\n"<<endl;

    tikrinimas(pasirinkimas);

    cout<<endl;
    
    if(pasirinkimas==0){

        cout<< left <<setw(15)<< "Pavarde"<<setw(15)<<"Vardas"<<setw(15)<<"Galutinis (Vid.) "<<endl;
        cout<<"-------------------------------------------------------"<<endl;
        for(int i=0;i<m; i++){
           cout<<left<<setw(15)<<var[i].Vardas<<setw(15)<<var[i].Pavarde;
         cout<<setw(15) << fixed<< setprecision(2)<<galutinis(var,i,pasirinkimas)<<endl;
        }
    }

    else {

        cout<< left <<setw(15)<< "Pavarde"<<setw(15)<<"Vardas"<<setw(15)<<"Galutinis (Med.) "<<endl;
        cout<<"-------------------------------------------------------"<<endl;

        for(int i=0;i<m; i++){

            cout<<left<<setw(15)<<var[i].Vardas<<setw(15)<<var[i].Pavarde;
         cout<<setw(30)<< fixed<< setprecision(2)<<galutinis(var,i,pasirinkimas)<<endl;
        }


    } 

}

double galutinis(studentas var[], int &k,int &pasirinkimas){

    double gal;
    if(pasirinkimas==0){
     gal=vidurkis(var, k) * 0.4 + 0.6 * var[k].egz_rez;
    }

    else{
        gal=(mediana(var, k)) * 0.4 + 0.6 * var[k].egz_rez;
    }

    return gal;
}

double mediana(studentas var[],int &k){

    int pazymiai = var[k].pazKiekis;
    double medi;

    sort(var[k].tarpiniai, var[k].tarpiniai+pazymiai);


    if((pazymiai%2)==0){
      medi= ( double(var[k].tarpiniai[pazymiai/2-1]) + (var[k].tarpiniai[pazymiai/2]) ) /2;
    }

    else {
        medi= ( var[k].tarpiniai[pazymiai/2]);
    }
    var[k].mediana=medi;
    return medi;
}

double vidurkis(studentas var[],int &k){
    double sum=0.0;

    for(int j=0; j<var[k].pazKiekis;j++){
    sum+=var[k].tarpiniai[j];
    }
    double vid = sum/var[k].pazKiekis;

    var[k].vidurkis=vid;

    return vid;
}




