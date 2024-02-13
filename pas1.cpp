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
void atsitiktiniaiPazymiai(studentas var[], int &m);
void tikrinimas(int &pasirinkimas);
void ivedimasRanka(studentas var[], int &m);
void atsitiktiniaiPazVar (studentas var[], int &m);

int main() {

int n;
int m;
int pasirinkimas;
int meniu;
bool baigti = false;

cout<<"Iveskite kiek yra studentu: ";
cin >> m;
studentas* var = new studentas [m];                               /// rodyklė rodanti i dinamineje atmintyje sukurta strukturu masyva
cout<<endl;

do
{
    cout<<"Kaip noretumete uzpildyti duomenis: "<<endl;
   cout<<"1 - ivedimas ranka"<<endl;
   cout<<"2 - generuoti pazymius"<<endl;
   cout<<"3 - generuoti ir pazymius ir studentu vardus, pavardes"<<endl;
   cout<<"4 - baigti darba"<<endl;
   cout<<"Iveskite pasirinkima: ";
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
            cout<<endl;
    }


} while (!baigti);

delete[] var->tarpiniai;
delete[] var;

}

void atsitiktiniaiPazVar (studentas var[], int &m){
    int n;                                                            ///namu darbu kiekis
    
    cout<<"Nera tokios funkcijos :) "<<endl;

    // for (int i =0; i<m; i++){
    //     cout<<" Iveskite "<<i+1<<" studento varda: ";
    //     cin>>var[i].Vardas;
    //     cout<<" Iveskite "<<i+1<<" studento pavarde: ";
    //     cin>>var[i].Pavarde;
        
    //     cout<<" Iveskite kiek namu darbu uzduociu atliko studentas: ";
    //     cin>>n;

    //     var[i].pazKiekis=n;
    //     var[i].tarpiniai = new int [n];

    //     cout<<" Atsitiktinai sugeneruoti namu darbu rezultatai: "<<endl;

    //     for(int j=0; j<n;j++)
    //     {

    //         var[i].tarpiniai[j]= rand()% (1-10+1);                                  ///generuoja atsitikstinius skaicius intervale nuo 1 iki 10

    //         cout<< var[i].tarpiniai[j]<<"\t";

    //     }

    //     cout<<endl;
    //     cout<<" Atsitiktinai sugeneruotas studento ezamino rezultatas: ";
    //     var[i].egz_rez= rand()% (1-10+1);                                           ///generuoja atsitikstinius skaicius intervale nuo 1 iki 10
    //     cout<<var[i].egz_rez<<endl;
    //     cout<<endl;
    // }

}

void atsitiktiniaiPazymiai(studentas var[], int &m){

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

void ivedimasRanka(studentas var[], int &m){

    for (int i =0; i<m; i++){
        cout<<" Iveskite "<<i+1<<" studento varda: ";
        cin>>var[i].Vardas;
        cout<<" Iveskite "<<i+1<<" studento pavarde: ";
        cin>>var[i].Pavarde;
        
        cout<<" Iveskite studento namu darbu rezultatus (noredami baigti ivedima iveskite 0): "<<endl;
        
        int pazimys;
        int kiek=0;                                   /// pazymiu sk
        int skaiciams [100];

        while (true)
        {
            
            while (!(cin >> pazimys) || pazimys<0 || pazimys>10)                                            ///prasyv vis ivesti pazimi,kol jis bus teisingas
            {
               cin.clear();
               cin.ignore(numeric_limits<streamsize>::max(), '\n');
               cout << "Klaida. Iveskite skaiciu nuo 1 iki 10" << endl;
            }            

            if(pazimys==0)break;                      ///jei iveda 0 nutraukiamas

            else{
            skaiciams[kiek]=pazimys;
            kiek++;
            }
        }

        var[i].tarpiniai = new int [kiek];
        var[i].pazKiekis=kiek;
        for(int j=0; j<kiek;j++)
        {
            var[i].tarpiniai[j] = skaiciams[j]; 
        }

        cout<<"\n Iveskite "<<i+1<<" studento ezamino rezultata: ";
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




