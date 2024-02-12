#include <iostream>
#include <fstream>
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
    double galutinis;
    double mediana;

};

void spausdinimas(int &m, studentas var[]);
double galutinis(studentas var[], int &k,int &pasirinkimas);
double mediana(studentas var[],int &k);
double vidurkis(studentas var[],int &k);




int main() {

int n;
int m;

cout<<"Iveskite kiek yra studentu: ";
cin >> m;
studentas* var = new studentas [m];                                /// rodyklė rodanti i dinamineje atmintyje sukurta strukturu masyva


for (int i =0; i<m;i++){

double sum=0.0;

cout<<" Iveskite "<<i+1<<" studento varda:";
cin>>var[i].Vardas;
cout<<" Iveskite "<<i+1<<" studento pavarde:";
cin>>var[i].Pavarde;

cout<<"Iveskite kiek namu darbu uzduociu atliko studentas: ";
cin>>n;

var[i].pazKiekis=n;
var[i].tarpiniai = new int [n];

cout<<" Iveskite studento namu darbu rezultatus: "<<endl;
for(int j=0; j<n;j++){
cin>>var[i].tarpiniai[j];
sum+=var[i].tarpiniai[j];
}

cout<<" Iveskite "<<i+1<<" studento ezamino rezultata:";
cin>>var[i].egz_rez;


// var[i].galutinis=(sum/n)*0.4+0.6*var[i].egz_rez;
cout<<endl;

}

spausdinimas(m, var);

delete[] var;
delete[] var->tarpiniai;


}


void spausdinimas(int &m,studentas var[]){

    int pasirinkimas; 
    cout<<"Jei norite spausdinti studentu galutini vidurki iveskite: 0\nJei norite spausdinti studentu galutine mediana iveskite: 1"<<endl;
    cin>>pasirinkimas;

    cout<< "Pavarde"<<setw(10)<<" Vardas"<<setw(10)<<"Galutinis (Vid.)"<<endl;
    cout<<"-------------------------------------------------------"<<endl;

    

    for(int i=0;i<m; i++){

       cout<<var[i].Vardas;
       cout<<setw(10)<<var[i].Pavarde;
       cout<<setw(20)<< setprecision(3)<<galutinis(var,i,pasirinkimas)<<endl;
    }

 

    //    cout<<mediana(var,i);

}

double galutinis(studentas var[], int &k,int &pasirinkimas){

    double gal;
    if(pasirinkimas==0){
     gal=vidurkis(var, k)*0.4+0.6*var[k].egz_rez;
    }

    else{
        gal=(mediana(var, k))*0.4+0.6*var[k].egz_rez;
    }

    return gal;
}


double mediana(studentas var[],int &k){

    int sk=var[k].pazKiekis;
    
}

double vidurkis(studentas var[],int &k){
    double sum=0.0;

    for(int j=0; j<var[k].pazKiekis;j++){
    sum+=var[k].tarpiniai[j];
    }
    double vid = sum/var[k].pazKiekis;

    return vid;
}




