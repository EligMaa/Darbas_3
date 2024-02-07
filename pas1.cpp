#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
using namespace std;

const int n = 3;                                                            ///kiek namu uzduociu kiekis
const int m = 2;                                                            ///studentu skaicius

struct vartotojas
{
    string Vardas;
    string Pavarde;
    int egz_rez;
    int tarpiniai[n];
};


int main() {

for (int i =1; i<=m;i++){

vartotojas var_i;
double sum=0.0;

cout<<" Iveskite "<<i<<" vartotojo varda:";
cin>>var_i.Vardas;
cout<<" Iveskite "<<i<<" vartotojo pavarde:";
cin>>var_i.Pavarde;
cout<<" Iveskite vartotojo namu darbu rezultatus: "<<endl;
for(int j=0; j<n;j++){

cin>>var_i.tarpiniai[j];
sum=+var_i.tarpiniai[j];

}
cout<<" Iveskite "<<i<<"  vartotojo ezamino rezultata:";
cin>>var_i.egz_rez;

cout<<" Galutinis balas: "<<(sum/n)*0.4+0.6+var_i.egz_rez<<endl;
cout<<endl;

}



}