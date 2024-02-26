#include "funkcijos0_3.h"

void rusiavimas(vector<studentas>& var){                                                        ///pagal pasirinktus kriterijus surusiuoja kursiokai vektoriu

    int meniu;
    bool baigti = false;
    int pasirinkimas=0;

    do{

        cout<<"Pasirinkite kaip norite rusiuoti duomenimis:"<<endl;
        cout<<"1 - pagal studento varda"<<endl;
        cout<<"2 - pagal studento pavarde"<<endl;
        cout<<"3 - pagal studento galutini ivertinima su vidurkiu"<<endl;
        cout<<"4 - pagal studento galutini ivertinima su mediana"<<endl;

        cout<<"--------------------------------------------------------"<<endl;

        try {
            cout << "Iveskite pasirinkima: " << endl;
            string input;
            cin >> input;

            if (input.find_first_not_of("0123456789") != string::npos) {                                  ///tikrina ar ivestas skaicius naturalusis
            throw invalid_argument("Netinkamas pasirinkimas");
            }

            meniu = stoi(input);

            if (meniu < 1 || meniu > 4) {
                throw invalid_argument("Iveskite nuo 1 iki 4 ");
            }
                        
            cout << endl;
        } 
                    
        catch (const invalid_argument & e) {
            cerr << "Klaida: " << e.what() << endl;
            cout << endl;
            continue;
        }


        for(int i=0;i<var.size(); i++){
            pasirinkimas=0;
            var[i].gal_vid=galutinis(var,i,pasirinkimas);
            
            pasirinkimas=1;
            var[i].gal_med=galutinis(var,i,pasirinkimas);
        }


        switch (meniu)                                                                                  /// meniu skirtas v0.2
        {
            case 1:
                sort(var.begin(), var.end(), rikiuotiVarda);
                baigti = true;

                break;
            case 2:
                sort(var.begin(), var.end(), rikiuotiPavarde);
                baigti = true;

                break;
            case 3:
                sort(var.begin(), var.end(), rikiuotiVid);
                baigti = true;

                break;
            case 4:
                sort(var.begin(), var.end(), rikiuotiMed);
                baigti = true;

                break;

            default:
                cout<< "Iveskite nuo 1 iki 4 " << endl;

                break;

        }

        }while (!baigti);


    }

void spausdinami_surikiuoti(vector<studentas>& var,double &laikas){                                            ///isspausdina i rezultatu faila surikiuota sarasa
   
    auto start = std::chrono::high_resolution_clock::now();                                                 /// pradeti laiko skaiciavima


    ofstream print ("rez.txt");
    print<< left <<setw(15)<< "Vardas"<<setw(15)<<"Pavarde"<<setw(15)<<"Galutinis (Vid.) "<<setw(15)<<"Galutinis (Med.) "<<endl;
    print<<"-----------------------------------------------------------"<<endl;

    for(int i=0; i<var.size(); i++){
    
        print<<left <<setw(15)<<var[i].Vardas<<setw(15)<<var[i].Pavarde;
        print<<setw(15)<<fixed<<setprecision(2) << var[i].gal_vid << setw(20) << setprecision(2) << var[i].gal_med << endl;

    }    

    auto end = std::chrono::high_resolution_clock::now();                                                   /// baigti laiko skaiciavima
    std::chrono::duration<double> time = end - start;                                                       /// laikas
    laikas += time.count();
    cout<<" Uztruko: "<< laikas<<"s."<<endl;
    cout<<endl;

    print.close();
}

void skaitymas(vector<studentas>& var, vector<string>&failoPav, int indeksas, double &laikas){  ///nuskaito pasirinkta faila pagal indeksa ir sukuria rezultatu faila

    studentas naujasStudentas;                                     ///sukuria nauja objekta
    int kiekMok=0;                                                 ///mokiniu skaicius
    int pasirinkimas;
    ifstream failas(failoPav[indeksas]);

    try{
        if(!failas.is_open())                                                    ///patikrina ar failas egzustuoja
        {
            throw std::runtime_error ("Failas nerastas");
        }

    }

    catch ( const std::exception & e){
        cerr<<"Klaida: "<<e.what()<<endl;
        cout << endl;
        return ;
    }


    vector <int> skaiciams; 
    string line;
    getline(failas, line);                       ///pirma eilute mums nereikalinga

    auto start = std::chrono::high_resolution_clock::now();                                                 /// pradeti laiko skaiciavima

    while (!failas.eof())
    {   
        getline(failas, line);
        kiekMok++;
        istringstream dalijimas (line);              ///leidzia is eilutes skaityti kaip is failo

        dalijimas>>naujasStudentas.Vardas>>naujasStudentas.Pavarde;

        while (!dalijimas.eof()) {
            int pazimys;
            dalijimas>>pazimys;
            skaiciams.push_back(pazimys);

        }
        naujasStudentas.egz_rez=skaiciams.back();    ///paskutinis skaicius
        skaiciams.pop_back();                        ///istrina paskutini skaiciu

        naujasStudentas.tarpiniai = skaiciams;       
        naujasStudentas.pazKiekis = skaiciams.size();
        skaiciams.clear();                                                                              ///isvalomas vektorius
        
        var.push_back(naujasStudentas);

    }
    failas.close();
    rusiavimas(var);

    auto end = std::chrono::high_resolution_clock::now();                                                   /// baigti laiko skaiciavima
    std::chrono::duration<double> time = end - start;                                                       /// laikas
    laikas = time.count();

}

void failoKurimas( int &kiekND){                                                                              ///sukuria "kursiokai.txt" faila

    ofstream failas ("kursiokai.txt");

    failas<< left <<setw(15)<< "Vardas"<<setw(15)<<"Pavarde"<<setw(5)<<"ND1"<<setw(5)<<"ND2"<<setw(5)<<"ND3";
    failas<<setw(5)<<"ND4"<<setw(5)<<"ND5"<<setw(5)<<"Egz."<<endl;

    int m = 10;                                                                       ///studentu skaicius
    
    
            for (int i = 0; i<m; i++){
        
                bool lytis ;                                                           ///jeigu 0 - vyras, jeigu 1 - moteris  
                lytis = rand() % 2;                                                    ///arba 0 arba 1

                studentas naujasStudentas;                                             ///sukuria nauja objekta

                if(lytis==0){

                    int indeksas = rand() % (vyrV.size());                             ///atsitinktinai  istrenkamas vardas
                    naujasStudentas.Vardas=vyrV[indeksas];
                    indeksas = rand() % (vyrP.size());
                    naujasStudentas.Pavarde=vyrP[indeksas];

                    failas<<left <<setw(15)<<naujasStudentas.Vardas;
                    failas<<left <<setw(15)<<naujasStudentas.Pavarde;               
                
                }

                if(lytis==1){

                    int indeksas = rand() % (motP.size());
                    naujasStudentas.Vardas=motV[indeksas];

                    indeksas = rand() % (motP.size());
                    naujasStudentas.Pavarde=motP[indeksas];

                    failas<<left <<setw(15)<<naujasStudentas.Vardas;
                    failas<<left <<setw(15)<<naujasStudentas.Pavarde;
                }
 

                for(int j=0; j<kiekND;j++)
                {
                    int pazymys = ( rand()% 10+1);                                               ///generuoja atsitikstinius skaicius intervale nuo 1 iki 10

                    failas<< left <<setw(5)<< pazymys;
                    naujasStudentas.tarpiniai.push_back(pazymys);
                }

                naujasStudentas.egz_rez= rand()% 10+1;                                           ///generuoja atsitikstinius skaicius intervale nuo 1 iki 10
                
                if(i==9){

                    failas<<naujasStudentas.egz_rez;                                             ///kad nesusidarytu papildoma eilute nededamas endl

                }
                else
                failas<<naujasStudentas.egz_rez<<endl;
                
                naujasStudentas.tarpiniai.clear();
            }       
  
      


    failas.close();
}

void su_duomenimis_is_failu(vector<studentas>& kursiokai,vector<studentas>& var){                         ///jei pasirinko dirbti su duomenu failais

    int meniu;
    double laikas;
    bool baigti = false;
    int kiekND, indeksas;
    vector<string> failoPav {"kursiokai.txt","studentai10000.txt", "studentai100000.txt","studentai1000000.txt"};            ///vektorius saugo failu pavadinimus

    cout<<"Pasirinkite kuri duomenu faila nauduosite: "<<endl;

        do
        {
            cout<<"1 - is sugeneruoto duomenu failo 'kursiokai.txt'"<<endl;
            cout<<"2 - is testavimo failo su 10000 studentu duomenu"<<endl;
            cout<<"3 - is testavimo failo su 100000 studentu duomenu"<<endl;
            cout<<"4 - is testavimo failo su 1000000 studentu duomenu"<<endl;
            cout<<"5 - baigti darba"<<endl;
            cout<<"--------------------------------------------------------"<<endl;
           
            try {
                        cout << "Iveskite pasirinkima: " << endl;
                        string input;
                        cin >> input;

                        if (input.find_first_not_of("0123456789") != string::npos) {                                  ///tikrina ar ivestas skaicius naturalusis
                            throw invalid_argument("Netinkamas pasirinkimas");
                        }

                        meniu = stoi(input);

                        if (meniu < 1 || meniu > 5) {
                            throw invalid_argument("Iveskite nuo 1 iki 5 ");
                        }
                        cout << endl;
                    } 
                    
                    catch (const invalid_argument & e) {
                        cerr << "Klaida: " << e.what() << endl;
                        cout << endl;
                        continue;
                    }

                switch (meniu)                                                      ///meniu skirtas v0.1
                {
                        case 1:
                            indeksas=0;                                             ///indeksas, kuris nurodo kelintas failo pavadinimas yra vektoriuje 
                            kiekND = 5;
                            failoKurimas( kiekND);
                            skaitymas(kursiokai, failoPav, indeksas, laikas);
                            spausdinami_surikiuoti(kursiokai, laikas);

                        
                            break;
                        case 2:
                            indeksas=1;
                            skaitymas(var, failoPav, indeksas, laikas);
                            spausdinami_surikiuoti(var, laikas);


                            break;
                        case 3:
                            indeksas=2;
                            skaitymas(var, failoPav, indeksas, laikas);
                            spausdinami_surikiuoti(var, laikas);

                            break;
                        case 4:
                            indeksas=3;
                            skaitymas(var, failoPav, indeksas, laikas);
                            spausdinami_surikiuoti(var, laikas);
                            
                            break;

                        case 5:
                            cout<<"Darbas su duomenu ivedimu baigtas\n"<<endl;
                            baigti=true;
                            break;

                        default:

                            cout << "Iveskite nuo 1 iki 5 " << endl;
                            

                    }

               
                

        }while (!baigti); 



}

bool rikiuotiVarda(const studentas &a, const studentas &b) {
    return a.Vardas < b.Vardas;
}

bool rikiuotiPavarde(const studentas &a, const studentas &b) {
    return a.Pavarde < b.Pavarde;
}

bool rikiuotiVid(const studentas &a, const studentas &b) {
    return a.gal_vid < b.gal_vid;
}

bool rikiuotiMed(const studentas &a, const studentas &b) {
    return a.gal_med < b.gal_med;
}

void atsitiktiniaiPazVar (vector<studentas>& var, int &studSk){
    
    int n;
    int m = (rand() % 10) + 1;                                                         ///atsitiktinai sugeneruoja kiek yra studentu
    studSk=m;
    do{
            for (int i = 0; i<m; i++){
        
                bool lytis ;                                                           ///jeigu 0 - vyras, jeigu 1 - moteris  
                lytis = rand() % 2;                                                    ///arba 0 arba 1

                studentas naujasStudentas;                                     ///sukuria nauja objekta

                if(lytis==0){

                    int indeksas = rand() % (vyrV.size());                             ///atsitinktinai  istrenkamas vardas
                    naujasStudentas.Vardas=vyrV[indeksas];
                    indeksas = rand() % (vyrP.size());
                    naujasStudentas.Pavarde=vyrP[indeksas];
                    cout<<"--------------------------------------------------------"<<endl;
                    cout<<i+1<<"-ojo"<<" studento vardas: "<<naujasStudentas.Vardas<<endl;
                    cout<<i+1<<"-ojo"<<" studento pavarde: "<<naujasStudentas.Pavarde<<endl;
                }

                if(lytis==1){

                    int indeksas = rand() % (motP.size());
                    naujasStudentas.Vardas=motV[indeksas];

                    indeksas = rand() % (motP.size());

                    naujasStudentas.Pavarde=motP[indeksas];
                    cout<<"--------------------------------------------------------"<<endl;
                    cout<<i+1<<"-ojo"<<" studento vardas: "<<naujasStudentas.Vardas<<endl;
                    cout<<i+1<<"-ojo"<<" studento pavarde: "<<naujasStudentas.Pavarde<<endl;
                }
 
                n= rand()% 10+1;                                                                 ///atsitiktinai sugeneruoja kiek namu darbu atliko studentas
                cout<<" Studentas atliko "<<n<<" namu darbu uzduotis"<<endl;

                naujasStudentas.pazKiekis=n;
                naujasStudentas.tarpiniai.resize(n);


                cout<<" Atsitiktinai sugeneruoti namu darbu rezultatai: "<<endl;

                for(int j=0; j<n;j++)
                {

                    naujasStudentas.tarpiniai[j]= rand()% 10+1;                                  ///generuoja atsitikstinius skaicius intervale nuo 1 iki 10

                    cout<< naujasStudentas.tarpiniai[j]<<"\t";

                }

                cout<<endl;
                cout<<" Atsitiktinai sugeneruotas studento ezamino rezultatas: ";
                naujasStudentas.egz_rez= rand()% 10+1;                                           ///generuoja atsitikstinius skaicius intervale nuo 1 iki 10
                cout<<naujasStudentas.egz_rez<<endl;
                cout<<endl;

                var.push_back(naujasStudentas);                                          ///pridedamas naujas studentas i vektoriu

            }       


        m--;
    }while (m==0);
    
    

}

void atsitiktiniaiPazymiai(vector<studentas>& var, int &studSk){

    int n;                                                                          ///namu darbu kiekis
    bool pasirinkimas;
    int i=0;
    do
    {   if(i!=0){
        cout<<"--------------------------------------------------------"<<endl;
        cout<<" Jei norite irasyti studenta iveskite 1, o jei norite baigti vedima - 0"<<endl;

        while (!(cin >> pasirinkimas) || (pasirinkimas!=0 && pasirinkimas!=1))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');                                           /// Ignoruojama visą eilutę iki naujos
            cout << " Iveskite 1 arba 0: " << endl;
        } 
        }

        if(pasirinkimas==false && i>0) break;

        i++;
        
        studentas naujasStudentas;                                     ///sukuria nauja objekta

        cout<<"--------------------------------------------------------"<<endl;
        cout<<" Iveskite "<<i<<" studento varda: ";
        cin>>naujasStudentas.Vardas;
        cout<<" Iveskite "<<i<<" studento pavarde: ";
        cin>>naujasStudentas.Pavarde;
        
            cout<<" Iveskite kiek namu darbu uzduociu atliko studentas: ";
            while (!(cin >> n) || (n<1 && n>100))
            {
             cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(), '\n');                                           /// Ignoruojama visą eilutę iki naujos+
              cout << "Iveskite nuo 1 iki 100: " << endl;
            }

            naujasStudentas.pazKiekis=n;
            naujasStudentas.tarpiniai.resize(n);

            cout<<" Atsitiktinai sugeneruoti namu darbu rezultatai: "<<endl;

            for(int j=0; j<n;j++)
            {
                
               naujasStudentas.tarpiniai[j]= rand()% 10+1;                                  ///generuoja atsitikstinius skaicius intervale nuo 1 iki 10

               cout<< naujasStudentas.tarpiniai[j]<<"\t";

            }

            cout<<endl;
            cout<<" Atsitiktinai sugeneruotas studento ezamino rezultatas: "<<endl;
            naujasStudentas.egz_rez= rand()% 10+1;                                           ///generuoja atsitikstinius skaicius intervale nuo 1 iki 10
            cout<<naujasStudentas.egz_rez<<endl;
            var.push_back(naujasStudentas);
            pasirinkimas=true;
            studSk=i;


    }while(pasirinkimas==true);
}

void ivedimasRanka(vector<studentas>& var, int& studSk) {
    int i = 0;
    bool pasirinkimas;


    do 
    {
        cout << "--------------------------------------------------------" << endl;
        cout << " Jei norite irasyti studenta iveskite 1, o jei norite baigti vedima - 0" << endl;

        try {                                                                                      ///tikrina ivedima
            
            cin>> pasirinkimas;

            if (cin.fail()) {
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                throw invalid_argument("Netinkamas pasirinkimas");
            }

            if (pasirinkimas != 0 && pasirinkimas != 1) {
                throw invalid_argument("Netinkamas pasirinkimas");
            }        

        } 

        catch (const invalid_argument& e) {
            cerr << "Klaida: " << e.what() << endl;
            continue; 
        }

            if (pasirinkimas == false && i == 0) {
                cout << "Reikia ivesti nors viena studenta " << endl;
                continue;
            }

            if (pasirinkimas == false && i > 0) break;

            i++;
            studentas naujasStudentas;  // Sukuria nauja objekta
            cout << "--------------------------------------------------------" << endl;
            cout << " Iveskite " << i << " studento varda: ";
            cin >> naujasStudentas.Vardas;
            cout << " Iveskite " << i << " studento pavarde: ";
            cin >> naujasStudentas.Pavarde;

            cout << " Iveskite studento namu darbu rezultatus (noredami baigti ivedima iveskite 0): " << endl;

            int pazimys;
            string input;
            int kiek = 0;  // Pazymiu sk
            vector<int> skaiciams;

            while (true) {

                try{
                    cin>>input;

                    if (input.find('.') != string::npos) {                                   /// tikrina ar string yra "." , jei yra, ismes klaida
                        cerr << "Klaida! Iveskite skaiciu nuo 0 iki 10\n";
                        continue; 
                    }
                    
                    pazimys = stoi (input);                                                  /// jei string ivestas skaicius yra sveikasis pavercia ji i int tipo kintamaji


                    if(cin.fail()){
                        throw invalid_argument ("Netinkami duomenys");
                    }

                    if(pazimys < 0 || pazimys > 10){
                        throw invalid_argument ("Iveskite skaiciu nuo 0 iki 10\n");
                    }

                    
                    if(pazimys != static_cast<int>(pazimys)){
                        throw invalid_argument ("Iveskite sveikaji skaiciu");
                    }


                    if(pazimys ==0) break;

                    
                        skaiciams.push_back(pazimys);
                        kiek++;
                    
                }
                catch (const invalid_argument& e) {
                    cerr<<"Klaida: "<<e.what()<<endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    
                }


            }

            naujasStudentas.pazKiekis = kiek;
            naujasStudentas.tarpiniai = skaiciams;

        
            cout << " Iveskite " << i << " studento egzamino rezultata: ";


            while(true){

                try{
                    cin>>input;

                    if (input.find('.') != string::npos) {                                   /// tikrina ar string yra "." , jei yra, ismes klaida
                        cerr << "Klaida! Iveskite skaiciu nuo 0 iki 10\t";
                        continue; 
                    }
                    
                    naujasStudentas.egz_rez = stoi (input);                    
                   
                    if(cin.fail()){
                        throw invalid_argument ("Netinkami duomenys");
                    }

                    if(pazimys < 0 || pazimys > 10){
                        throw invalid_argument ("Iveskite skaiciu nuo 0 iki 10\t");
                    }
                    break;

                }
                catch (const invalid_argument& e){
                   cerr<<"Klaida: "<<e.what()<<endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                     
                }
            }

            cout << endl;

            var.push_back(naujasStudentas);
            studSk = i;
        
    } while (true);
}

void tikrinimas(int &pasirinkimas){                                                                      ///tikrina pasirinkima

    while (!(cin >> pasirinkimas) || (pasirinkimas!=0 && pasirinkimas!=1))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');                                           /// Ignoruojama visą eilutę iki naujos
        cout << "Iveskite 1 arba 0: " << endl;
    }
}

void spausdinimas(vector<studentas>& var){

    int pasirinkimas; 

    cout<<"Jei norite spausdinti studentu galutini iverinima naudojant vidurki iveskite: 0";
    cout<<"\nJei norite spausdinti studentu galutini iverinima naudojant mediana iveskite: 1\n"<<endl;

    tikrinimas(pasirinkimas);                                                                          ///patikrina ar ivesta 0 arba 1

    cout<<endl;
    
    if(pasirinkimas==0){                                                       ///isvedama informacija apie studentus ir galutinis rezultatas apskaiciuotas su vidurkiu

        cout<< left <<setw(15)<< "Vardas"<<setw(15)<<"Pavarde"<<setw(15)<<"Galutinis (Vid.) "<<endl;
        cout<<"------------------------------------------------"<<endl;

        for(int i=0;i<var.size(); i++){
         cout<<left<<setw(15)<<var[i].Vardas<<setw(15)<<var[i].Pavarde;
         cout<<setw(15) << fixed<< setprecision(2)<<galutinis(var,i,pasirinkimas)<<endl;
        }
    }

    else {                                                                      ///isvedama informacija apie studentus ir galutinis rezultatas apskaiciuotas su mediana

        cout<< left <<setw(15)<< "Vardas"<<setw(15)<<"Pavarde"<<setw(15)<<"Galutinis (Med.) "<<endl;
        cout<<"-------------------------------------------------------"<<endl;

        for(int i=0;i<var.size(); i++){
            cout<<left<<setw(15)<<var[i].Vardas<<setw(15)<<var[i].Pavarde;
            cout<<setw(30)<< fixed<< setprecision(2)<<galutinis(var,i,pasirinkimas)<<endl;
        }


    } 

    var.resize(0);
}

double galutinis(vector<studentas>& var, int &k,int &pasirinkimas){                                     ///galutinio rezultato skaiciavimas

    double gal=0.0;
    if(pasirinkimas==0){
     gal=vidurkis(var, k) * 0.4 + 0.6 * var[k].egz_rez;
    }

    else{
        gal=(mediana(var, k)) * 0.4 + 0.6 * var[k].egz_rez;
    }

    return gal;
}

double mediana(vector<studentas>& var, int &k){

    int pazymiai = var[k].pazKiekis;
    double medi;

    if(pazymiai==0)                                              ///jei nera ivesta pazymiu                                                        ///jeigu nebuvo ivestas nei vienas pazymys
    { return 0; }

    else
    {
        sort(var[k].tarpiniai.begin(), var[k].tarpiniai.end());


        if((pazymiai%2)==0){
            medi= ( double(var[k].tarpiniai[pazymiai/2-1]) + (var[k].tarpiniai[pazymiai/2]) ) /2;
        }

     else {
         medi= ( var[k].tarpiniai[pazymiai/2]);
        }
        var[k].mediana=medi;
        return medi;
    }

}

double vidurkis(vector<studentas>& var, int &k){
    double sum=0.0;

    if(var[k].pazKiekis==0)                                       ///jeigu nebuvo ivestas nei vienas pazymys
    { return var[k].pazKiekis; }


    else {
        for(int j=0; j<var[k].pazKiekis;j++){                     ///pazymiu suma
            sum+=var[k].tarpiniai[j];
        }
        double vid = sum/var[k].pazKiekis;                       ///skaiciuojamas vidurkis

        var[k].vidurkis=vid;

        return vid;
    }


}