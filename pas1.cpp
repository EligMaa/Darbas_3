#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <string>

using namespace std;

struct studentas
{
    string Vardas;
    string Pavarde;
    int egz_rez;
    int pazKiekis;
    int* tarpiniai;                         ///rodykle i masyvo adresa
    double galutinis;
};

void spausdinimas();


int main() {

int n;
int m;

cout<<"Iveskite kiek yra studentu: ";
cin >> m;
studentas* var = new studentas [m];


for (int i =0; i<m;i++){

double sum=0.0;

cout<<" Iveskite "<<i+1<<" studento varda:";
cin>>var[i].Vardas;
cout<<" Iveskite "<<i+1<<" studento pavarde:";
cin>>var[i].Pavarde;

cout<<"Iveskite kiek namu darbu uzduociu atliko studentas: ";
cin>>n;

var[i].tarpiniai = new int [n];

cout<<" Iveskite studento namu darbu rezultatus: "<<endl;
for(int j=0; j<n;j++){

cin>>var[i].tarpiniai[j];

}

cout<<" Iveskite "<<i+1<<" vartotojo ezamino rezultata:";
cin>>var[i].egz_rez;

var[i].galutinis=(sum/n)*0.4+0.6+var[i].egz_rez;
cout<<endl;

}

cout<<"Pavarde\t\t Vardas\t\t Galutinis (Vid.)"<<endl;
cout<<"-------------------------------------------------------"<<endl;
for(int i=1;i<=m; i++){

   // cout<<
}

delete[] var;
delete[] var->tarpiniai;


}


void spausdinimas(){

    
}




