# Darbas_2
Šioje versijoje reikėjo vietoje turimos v1.2 klasės Studentas sukurti dvi: bazinę (abstrakčią) klasę, skirtą bendrai aprašyti žmogų ir tuomet iš jos išvestinę (derived) klasę.<br>
Ivykdžius užduotį CLASS'ės atrodo taip:

    class zmogus {
        protected:
            string Vardas;
            string Pavarde;

        public:
            zmogus() : Vardas(""), Pavarde("") {}
            zmogus(const std::string& Var, const std::string& Pav) : Vardas(Var), Pavarde(Pav) {}
    
            virtual ~zmogus() {}
    
            void set_Vardas(string var){
                Vardas = var;
            }
            void set_Pavarde(string pav){
                Pavarde = pav;
            }
    
            virtual std::string get_Vardas() const = 0;
    
            virtual std::string get_Pavarde() const {
                return Pavarde;
            }
    
            
    };
    
    class studentas : public zmogus {
        protected:
        
            int egz_rez;
            int pazKiekis;
            vector<int> tarpiniai;
            double vidurkis;
            double mediana;
            double gal_vid;
            double gal_med;
    
        public:
            studentas () : tarpiniai (), pazKiekis (0), egz_rez (0){}
    
            studentas(string Var, string Pav, vector<int> tarp,double egz ) : zmogus(Var, Pav) {
                
                tarpiniai = tarp;
                pazKiekis = tarp.size();
                egz_rez = egz;
                pazKiekis = tarpiniai.size();
    
            }
    
            virtual std::string get_Vardas() const override {
                return Vardas;
            }
             
            /// destruktorius
            ~studentas ( ){tarpiniai.clear();}
    
            /// kopijavimo konstruktorius
            studentas(const studentas& other) : zmogus(other.get_Vardas(), other.get_Pavarde()) {
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
                    zmogus :: set_Vardas (other.get_Vardas());
                    zmogus :: set_Pavarde (other.get_Pavarde());
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
                zmogus :: set_Vardas (move(other.Vardas));
                zmogus :: set_Pavarde (move(other.Pavarde));
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
                    zmogus::Vardas = std::move(other.Vardas);
                    zmogus::Pavarde = std::move(other.Pavarde);
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
            out << left << setw(15) << stud.get_Vardas() << setw(15) << stud.get_Pavarde();
            out << setw(15) << fixed << setprecision(2) << stud.get_gal_v_m(0);
            out << setw(20) << setprecision(2) << stud.get_gal_v_m(1) << "\n";
            return out;
            }
    
            friend ostream& su_mediana(ostream& out, const studentas& stud) {
                out << left << setw(15) << stud.get_Vardas() << setw(15) << stud.get_Pavarde();
                out << setw(20) << setprecision(2) << stud.gal_med << "\n";
                return out;
            }
    
            friend ostream& su_vidurkiu(ostream& out, const studentas& stud) {
                out << left << setw(15) << stud.get_Vardas() << setw(15) << stud.get_Pavarde();
                out << setw(20) << setprecision(2) << stud.gal_vid<< "\n";
                return out;
            }
    
    
            friend istream& operator>>(istream& in, studentas &stud) {                      /// ivesties operatorius
                
                string vardas, pavarde;
                in >> vardas >> pavarde;
    
                stud.set_Vardas(vardas); 
                stud.set_Pavarde(pavarde);
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
    
            void set_egz(int egz){            egz_rez = egz;        }
    
            double get_egz(){            return egz_rez;        }
    
            void set_tarpiniai(vector<int> tarp){            tarpiniai = tarp;        }
    
            vector <int> get_tarpiniai( ){            return tarpiniai;        }
    
            void set_paz_kiekis(int paz){            pazKiekis = paz;                 }
    
            int get_paz_kieki(){            return pazKiekis;        }
    
            void set_vidurkis(int vidur){            vidurkis = vidur;        }
    
            void set_vidurkis(){            vidurkis = accumulate(tarpiniai.begin(), tarpiniai.end(), 0.0) / tarpiniai.size();        }
    
            double get_vidurkis(){     return vidurkis;        }
    
            void set_mediana(int medi){  mediana = medi;    }
    
            double get_mediana(){  return mediana; }
    
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
    
    };

Kad "class zmogus" taptų abstrakčia, joje sukūriau virtualią funkciją: ```virtual std::string get_Vardas() const = 0;``` , o "class studentas" override'inau funciją ```virtual std::string get_Vardas() const override {
            return Vardas;
        }```
### Rule of five
Destructor (Destruktorius): Naudojamas atlaisvinti visus resursus, kurie buvo išskirti objekto gyvavimo metu. Destruktorius yra iškviečiamas, kai objektas sunaikinamas, arba kai jis pasibaigia vykdymas, jei objektas yra vietinis funkcijos kintamasis.<br>

Copy Constructor (Kopijavimo konstruktorius): Kopijavimo konstruktorius yra naudojamas sukurti naują objektą, kuris yra identiškas esamam objektui. Tai įvyksta, kai naujas objektas yra inicijuojamas kitu esamu objektu.<br>

Copy Assignment Operator (Kopijavimo priskyrimo operatorius): Kopijavimo priskyrimo operatorius yra naudojamas priskiriant vieną objektą kitam, esant tam tikroms sąlygoms.<br>

Move Constructor (Perkėlimo konstruktorius): Perkėlimo konstruktorius yra naudojamas perkelti resursus iš vieno objekto į kitą objektą, nepriklausomai nuo to, kuriuo objektu yra naudojamas šis konstruktorius.<br>

Move Assignment Operator (Perkėlimo priskyrimo operatorius): Perkėlimo priskyrimo operatorius yra naudojamas perkelti resursus iš vieno objekto į kitą objektą, naudojant priskyrimo operaciją (pvz., =).<br>

Klasė, kuri naudoja dinamiškai išskirtus resursus, turėtų papildomai implementuoti visus penkis šiuos specialiuosius narius. Tai užtikrins, kad resursai būtų valdomi tinkamai, kai objektai yra kopijuojami, perkeliami ar sunaikinami.<br>
