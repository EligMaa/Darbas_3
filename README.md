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
};
```
Programos spartos palyginimas atsižvelgiant į rūšiavimo laiką su VECTOR konteineriais ir class'e naudojant 3 strategija:<br>
|              |   1000   |   10000  |  100000  | 1000000  | 10000000 |
| ------------ | -------- | -------- | -------- | -------- | ---------|
| Konteineris  | 0.000998 | 0.007093 | 0.067696 | 0.711148 |
| Class'ė      | 0.000998 | 0.007093 | 0.067696 | 0.711148 |
