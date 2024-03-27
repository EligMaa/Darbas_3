# Darbas_2
## Pridėta klasė:<br>
```
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

        void set_gal_v_m (int pasirinkimas, double gal){
            if (pasirinkimas == 0) gal_vid = gal;
            if (pasirinkimas == 1) gal_med = gal;
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
        ~studentas ( ){}
};
```
Programos spartos palyginimas su struktūra ir class'e naudojant 3 strategija su VECTOR konteineriais :<br>
|    Struct    | Skaitymas  | Rūšiavimas | Suskirstymas |  Iš viso  |
| ------------ | ---------- | ---------- | ------------ | --------- |
|   100 000    | 0.995677 s.| 0.31507 s. | 0.067696 s.  | 1.52763 s.|
|   1 000 000  | 11.2832  s.| 4.61165 s. | 0.711148 s.  | 18.0659 s.|

|    Class     | Skaitymas  | Rūšiavimas | Suskirstymas |  Iš viso  |
| ------------ | ---------- | ---------- | ------------ | --------- |
|   100 000    | 1.10556 s. | 0.357524 s.| 0.390313 s.  | 2.01321 s.|
|   1 000 000  | 11.0742 s. | 4.57449 s. | 3.94622 s.   | 21.2178 s.|

Programa su struktūra veikia sparčiau nei class, tačiau skirtumas minimalus.<br>
<br>Programos spartos palyginimas su 1 000 000 dydžio failu naudojant flag'us: O1, O2, O3<br>

|     Class    | Skaitymas  | Rūšiavimas | Suskirstymas |  Iš viso  | Exe failo dydis |
| ------------ | ---------- | ---------- | ------------ | --------- | ----------------|
|      O1      | 11.2832  s.| 4.58047 s. | 3.97579 s.   | 21.0744 s.|     438 KB      |
|      O2      | 10.8566 s. | 4.54223 s. | 3.99914 s.   | 21.0245 s.|     438 KB      |
|      O3      | 10.7989 s. | 4.56988 s. | 3.92201 s.   | 20.9157 s.|     438 KB      |

|    Struct    | Skaitymas  | Rūšiavimas | Suskirstymas |  Iš viso  | Exe failo dydis |
| ------------ | ---------- | ---------- | ------------ | --------- | ----------------|
|      O1      | 10.0805 s. | 4.06028 s. | 0.696081 s.  | 16.36 s.  |     427 KB      |
|      O2      | 10.0178 s. | 4.21788 s. | 0.75521 s.   | 16.5173 s.|     427 KB      |
|      O3      | 9.93927 s. | 4.24828 s. | 0.789033 s.  | 16.4895 s.|     427 KB      |

Taigi, su struct naudojant flag O1 programa veikia greičiausiai, o su class greičiausiai veikia O3. Tačiau failų nuskaitymas greičiausiai įvyksta naudojant O3.
