#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
using namespace std;

struct vartotojas
{
    string Vardas;
    string Pavarde;
    int egz_rez;
    int tarpiniai[3];
};


int main() {

for (int i =1; i<=3;i++){

vartotojas var_i;

cout<<" Iveskite vartotojo varda:";
cin>>var_i.Vardas;
cout<<" Iveskite vartotojo pavarde:";
cin>>var_i.Pavarde;
cout<<" Iveskite vartotojo 10 tarpiniu rezultatu:";
for(int j=0; j<3;j++){

cin>>var_i.tarpiniai[j];

}
cout<<" Iveskite vartotojo ezamino rezultata:";
cin>>var_i.egz_rez;

}



}