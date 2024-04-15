# Darbas_2
Šiai užduočiai reikėjo realizuoti visus reikiamus "Rule of five" ir įvesties/išvesties operatorius turimai Studentas klasei.<br>
### Rule of five
Destructor (Destruktorius): Naudojamas atlaisvinti visus resursus, kurie buvo išskirti objekto gyvavimo metu. Destruktorius yra iškviečiamas, kai objektas sunaikinamas, arba kai jis pasibaigia vykdymas, jei objektas yra vietinis funkcijos kintamasis.<br>

Copy Constructor (Kopijavimo konstruktorius): Kopijavimo konstruktorius yra naudojamas sukurti naują objektą, kuris yra identiškas esamam objektui. Tai įvyksta, kai naujas objektas yra inicijuojamas kitu esamu objektu.<br>

Copy Assignment Operator (Kopijavimo priskyrimo operatorius): Kopijavimo priskyrimo operatorius yra naudojamas priskiriant vieną objektą kitam, esant tam tikroms sąlygoms.<br>

Move Constructor (Perkėlimo konstruktorius): Perkėlimo konstruktorius yra naudojamas perkelti resursus iš vieno objekto į kitą objektą, nepriklausomai nuo to, kuriuo objektu yra naudojamas šis konstruktorius.<br>

Move Assignment Operator (Perkėlimo priskyrimo operatorius): Perkėlimo priskyrimo operatorius yra naudojamas perkelti resursus iš vieno objekto į kitą objektą, naudojant priskyrimo operaciją (pvz., =).<br>

Klasė, kuri naudoja dinamiškai išskirtus resursus, turėtų papildomai implementuoti visus penkis šiuos specialiuosius narius. Tai užtikrins, kad resursai būtų valdomi tinkamai, kai objektai yra kopijuojami, perkeliami ar sunaikinami.<br>

<br>
Įvykdžius reikalavimus CLASS atrodo taip:<br>

        class studentas{
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
            
                    studentas( string Var, string Pav, vector<int> tarp,double egz ) {
                        Vardas = Var;
                        Pavarde = Pav;
                        tarpiniai = tarp;
                        pazKiekis = tarp.size();
                        egz_rez = egz;
                        pazKiekis = tarpiniai.size();
            
                    }
            
                    /// destruktorius
                    ~studentas ( ){tarpiniai.clear(), Vardas.clear(),Pavarde.clear();}
            
                    /// kopijavimo konstruktorius
                    studentas(const studentas& other) {
                        Vardas = other.Vardas;
                        Pavarde = other.Pavarde;
                        egz_rez = other.egz_rez;
                        tarpiniai = other.tarpiniai;
                        vidurkis = other.vidurkis;
                        mediana = other.mediana;
                        gal_vid = other.gal_vid;
                        gal_med = other.gal_med;
                    }
            
                    /// kopijavimo assignment operatorius
                    studentas& operator=(const studentas& other) {
                        if (this != &other) {
                            Vardas = other.Vardas;
                            Pavarde = other.Pavarde;
                            egz_rez = other.egz_rez;
                            tarpiniai = other.tarpiniai;
                            vidurkis = other.vidurkis;
                            mediana = other.mediana;
                            gal_vid = other.gal_vid;
                            gal_med = other.gal_med;
                        }
                        return *this;
                    }
            
                    /// perkelimo konstruktorius
                    studentas(studentas&& other) noexcept {
                        Vardas = move(other.Vardas);
                        Pavarde = move(other.Pavarde);
                        egz_rez = other.egz_rez;
                        tarpiniai = move(other.tarpiniai);
                        vidurkis = other.vidurkis;
                        mediana = other.mediana;
                        gal_vid = other.gal_vid;
                        gal_med = other.gal_med;
                    }
            
                    /// perkelimo assignment operatorius
                    studentas& operator=(studentas&& other) noexcept {
                        if (this != &other) {
                            Vardas = move(other.Vardas);
                            Pavarde = move(other.Pavarde);
                            egz_rez = other.egz_rez;
                            tarpiniai = move(other.tarpiniai);
                            vidurkis = other.vidurkis;
                            mediana = other.mediana;
                            gal_vid = other.gal_vid;
                            gal_med = other.gal_med;
                        }
                        return *this;
                    }
            
                    friend ostream& operator<<(ostream& out, const studentas &stud) {                ///isvesties operatorius
                    out << left << setw(15) << stud.Vardas << setw(15) << stud.Pavarde;
                    out << setw(15) << fixed << setprecision(2) << stud.get_gal_v_m(0);
                    out << setw(20) << setprecision(2) << stud.get_gal_v_m(1) << "\n";
                    return out;
                    }
            
                    friend ostream& su_mediana(ostream& out, const studentas& stud) {
                        out << left << setw(15) << stud.Vardas << setw(15) << stud.Pavarde;
                        out << setw(20) << setprecision(2) << stud.gal_med << "\n";
                        return out;
                    }
            
                    friend ostream& su_vidurkiu(ostream& out, const studentas& stud) {
                        out << left << setw(15) << stud.Vardas << setw(15) << stud.Pavarde;
                        out << setw(20) << setprecision(2) << stud.gal_vid<< "\n";
                        return out;
                    }
            
            
                    friend istream& operator>>(istream& in, studentas &stud) {                      /// ivesties operatorius
                        in >> stud.Vardas >> stud.Pavarde;
                        int pazimys;
                        vector <int> pazymiai;
                        while (in >> pazimys && pazimys >= 0)
                        {
                            pazymiai.push_back(pazimys);
                        }
                        stud.egz_rez=pazymiai.back() ;
                        pazymiai.pop_back();
            
                        stud.tarpiniai = pazymiai;
            
                    }
            
                    double get_egz(){
                        return egz_rez;
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
            
                    void set_vidurkis(){
                        vidurkis = accumulate(tarpiniai.begin(), tarpiniai.end(), 0.0) / tarpiniai.size();
                    }
            
                    void set_mediana(int medi){
                        mediana = medi;
                    }
                   
                    void set_gal_v_m (){
                       
                        gal_vid = vidurkis * 0.4 + 0.6 *egz_rez;
                        pazKiekis = tarpiniai.size();
                
                        sort(tarpiniai.begin(), tarpiniai.end());
            
                        if ((pazKiekis % 2) == 0)
                            {
                                mediana = (double(tarpiniai[pazKiekis / 2 - 1]) + (tarpiniai[pazKiekis / 2])) / 2;
                            }
                        else
                            {
                                mediana = (tarpiniai[pazKiekis / 2]);
                            }
            
                            gal_med = mediana * 0.4 + 0.6 *egz_rez;
                        
            
                    }
                    double get_gal_v_m (int pasirinkimas) const{
                        if (pasirinkimas == 0) return gal_vid;
                        if (pasirinkimas == 1) return gal_med ;
                    }
            
                    string get_Vardas ()const{
                        return Vardas;
                    }
            
                    string get_Pavarde ()const{
                        return Pavarde;
                    }
            
                    
            };

<br>

### Įvesties/išvesties metodai
Mano sukurti metodai:<br>
![image](https://github.com/EligMaa/Darbas_2/assets/151032480/d47f08e6-8372-4196-bd41-b3d291b9d0cd)<br>
Juos panaudojau:<br>
![image](https://github.com/EligMaa/Darbas_2/assets/151032480/8bdf1d2b-8495-41be-954e-fec71222c51c)<br>
![image](https://github.com/EligMaa/Darbas_2/assets/151032480/294a60a2-781d-4bc3-a0ac-7bf5b6b86b59)<br>
![image](https://github.com/EligMaa/Darbas_2/assets/151032480/6d1754ba-bc9e-4ff7-adc6-37352c54d053)<br>




