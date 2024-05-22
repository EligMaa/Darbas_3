#include "funkcijos3.h"
#include "vektorius.h"


void testuoti_clase(){

    {
    string vardas = "Rugile", pavarde = "Macaite";
    VEKTORIUS <int> pazymiai = {1,2,3,4,5};
    int egzamino_rez = 9.5;

    cout<<"Abstraktumo tikrinimas: "<<endl;
    cout << std::boolalpha;
    cout << "zmogus yra abstrakti klase: " << std::is_abstract<zmogus>::value << std::endl;
    // zmogus naujas("vardas", "pavarde");

    studentas naujasstudentas(vardas, pavarde, pazymiai, egzamino_rez);
    naujasstudentas.set_vidurkis (); 
    naujasstudentas.set_gal_v_m();
    ///konstruktoriaus ir tuo paciu isvesties metodu testavimas

    cout<<"konstruktoriaus testavimas: "<<endl;
    cout<<naujasstudentas.get_Vardas()<<" "<<naujasstudentas.get_Pavarde()<<" ";
        for(int pazymys : naujasstudentas.get_tarpiniai()) {
        cout << pazymys << " ";
    }
    cout<<endl<<naujasstudentas.get_egz()<<endl;

    cout << naujasstudentas;                     ///isvesties

    cout<<"Iveskite varda, pavarde ir namu darbu pazymius, paskutinis pazimys turi buti egzamino rezultatas, norint baigti ivedima iveskite neigiama skaiciu: "<<endl;
    cin >> naujasstudentas;                     /// ivesties
    cout<<naujasstudentas.get_Vardas()<<" "<<naujasstudentas.get_Pavarde()<<" ";
        for(int pazymys : naujasstudentas.get_tarpiniai()) {
        cout << pazymys << " ";
    }
    cout<<endl<<naujasstudentas.get_egz()<<endl;


    ///konstruktoriaus kopijavimo testavimas
    studentas kopijastudentas(naujasstudentas);

    cout<<endl<<"konstruktoriaus kopijavimo testavimas: "<<endl;
    cout << naujasstudentas;
    cout << kopijastudentas;

    
    ///konstruktoriaus perkelimo testavimas

    studentas perkeliamasstudentas(move(naujasstudentas));
    
    cout<<endl<<"Perkelimo testavimas: "<<endl;
    cout << naujasstudentas;
    cout << perkeliamasstudentas;

    // Copy assignment operator test
    studentas kitastudentas;
    kitastudentas = kopijastudentas;

    cout<<endl<<"Kopijuoto assignment operator testavimas: "<<endl;
    cout << kopijastudentas;
    cout << kitastudentas;


    // Move assignment operator test
    studentas perkeliamasstudentas2;
    perkeliamasstudentas2 = move(kopijastudentas);
    

    cout<<endl<<"Perkelto assignment operator testavimas: "<<endl;
    cout << kopijastudentas;
    cout << perkeliamasstudentas2;
    }

    /*
    sioje vietoje jau ivyko destruktorius todel jei bandytumeme isvesti
    perkeliamasstudentas2 varda ar kitus duomenis, tai nepavyktu
    */
    cout << "Perkeliamasstudentas2 sunaikintas" << endl;



}


void testFail_3strategija(vector<studentas> &var)
{

    double laikas = 0.0, galutinis = 0, suskirstymas = 0.0;
    int kiekND, indeksas = 0, studSk, laboras = 4, pasirinkimas;

    vector<studentas> vargsai;

    VEKTORIUS <string> failoPav{"test1000.txt", "test10000.txt", "test100000.txt", "test1000000.txt", "test10000000.txt"}; /// vektorius saugo failu pavadinimus
    VEKTORIUS <string> pav{"v1000.txt", "g1000.txt", "v10000.txt", "g10000.txt", "v100000.txt", "g100000.txt", "v1000000.txt", "g1000000.txt", "v10000000.txt", "g10000000.txt"};

    cout << endl;
    cout << "Iveskite kaip norite rusiuoti vargsus ir galvocius (0 - pagal vidurki, 1 - pagal mediana): " << endl;
    tikrinimas(pasirinkimas);
    cout << "VECTOR" << endl;

    studSk = 1000;

    for (int i = 0; i < 4; i++)
    {
        cout << "Testavimo laikai su " << studSk << " duomenu:" << endl;

        skaitymas(var, failoPav, indeksas, laikas, laboras);
        cout << "Failo skaitymas uztruko " << laikas << "s." << endl;
        galutinis += laikas;

        didejimo(var, laikas);

        cout << "Failo rusiavimas didejimo tvarka uztruko " << laikas << "s." << endl;
        galutinis += laikas;

        rusiavimasTest_3strategija(var, vargsai, laikas, pasirinkimas, indeksas);
        galutinis += laikas;
        suskirstymas += laikas;

        cout << "Failo suskirstymas i vargsiukus ir gudruolius uztruko " << suskirstymas << "s." << endl;
        cout << "Is viso darbas su " << studSk << " duomenu uztruko: " << galutinis << "s.\n"
             << endl;
        studSk *= 10;
        spausdinimasTest(vargsai, var, pav, laikas, pasirinkimas, indeksas);

        indeksas++;
    }
}

void rusiavimasTest_3strategija(vector<studentas> &var, vector<studentas> &vargsai, double &galutinisLaikas, int &pasirinkimas, int indeksas)
{

    vargsai.clear();

    auto start = std::chrono::high_resolution_clock::now(); /// pradeti laiko skaiciavima
    vargsai.reserve(var.size());

    var.erase(std::remove_if(var.begin(), var.end(), [&](const studentas &s) {
        int k = &s - &var[0]; // skaiciuoja dabartinio elemento indeksa
        if (galutinis(var, k, pasirinkimas) < 5.0) {
            vargsai.push_back(s); // pideda elementa prie vargsai
            return true;           // nurodo kad elementas turi buti istrinamas is var
        }
        return false;
    }), var.end());

    // cout<<"size of varg"<<vargsai.size()<<endl;
    // cout<<"size of ger"<<var.size()<<endl;

    auto end = std::chrono::high_resolution_clock::now(); /// baigti laiko skaiciavima
    std::chrono::duration<double> time = end - start;
    galutinisLaikas = time.count();
}

void testFail_2strategija(vector<studentas> &var)
{

    double laikas = 0.0, galutinis = 0, suskirstymas = 0.0;
    int kiekND, indeksas = 0, studSk, laboras = 4, pasirinkimas;

    vector<studentas> vargsai;

    VEKTORIUS<string> failoPav{"test1000.txt", "test10000.txt", "test100000.txt", "test1000000.txt", "test10000000.txt"}; /// vektorius saugo failu pavadinimus
    VEKTORIUS<string> pav{"v1000.txt", "g1000.txt", "v10000.txt", "g10000.txt", "v100000.txt", "g100000.txt", "v1000000.txt", "g1000000.txt", "v10000000.txt", "g10000000.txt"};

    cout << endl;
    cout << "Iveskite kaip norite rusiuoti vargsus ir galvocius (0 - pagal vidurki, 1 - pagal mediana): " << endl;
    tikrinimas(pasirinkimas);
    cout << "VECTOR" << endl;

    studSk = 1000;

    for (int i = 0; i < 4; i++)
    {
        cout << "Testavimo laikai su " << studSk << " duomenu:" << endl;

        skaitymas(var, failoPav, indeksas, laikas, laboras);
        cout << "Failo skaitymas uztruko " << laikas << "s." << endl;
        galutinis += laikas;

        didejimo(var, laikas);

        cout << "Failo rusiavimas didejimo tvarka uztruko " << laikas << "s." << endl;
        galutinis += laikas;

        rusiavimasTest_2strategija(var, vargsai, laikas, pasirinkimas, indeksas);
        galutinis += laikas;
        suskirstymas += laikas;

        cout << "Failo suskirstymas i vargsiukus ir gudruolius uztruko " << suskirstymas << "s." << endl;
        cout << "Is viso darbas su " << studSk << " duomenu uztruko: " << galutinis << "s.\n"
             << endl;
        studSk *= 10;
        spausdinimasTest(vargsai, var, pav, laikas, pasirinkimas, indeksas);

        indeksas++;
    }
}

void rusiavimasTest_2strategija(vector<studentas> &var, vector<studentas> &vargsai, double &galutinisLaikas, int &pasirinkimas, int indeksas)
{

    vargsai.clear();

    auto start = std::chrono::high_resolution_clock::now(); /// pradeti laiko skaiciavima
    vargsai.reserve(var.size());

    int k = 0;
    for (auto it = var.begin(); it != var.end(); ++it)
    {
        double galutinis_vid = galutinis(var, k, pasirinkimas);
        ++k; 
        if (galutinis_vid < 5.0)
        {
            vargsai.push_back(*it); // prideda elementa prie vargsiu
            it = var.erase(it);      // istrina elementa ir nurodo nauja iteratoriu
            if (it == var.end())     // tikrina ar jau pabaiga
                break;
        }
    }


    auto end = std::chrono::high_resolution_clock::now(); /// baigti laiko skaiciavima
    std::chrono::duration<double> time = end - start;     
    galutinisLaikas = time.count();
}

void testFail(vector<studentas> &var)
{

    double laikas = 0.0, galutinis = 0, suskirstymas = 0.0;
    int kiekND, indeksas, studSk, laboras = 4, pasirinkimas;

    vector<studentas> vargsai, galvociai;

    VEKTORIUS<string> failoPav{"test1000.txt", "test10000.txt", "test100000.txt", "test1000000.txt", "test10000000.txt"}; /// vektorius saugo failu pavadinimus
    VEKTORIUS<string> pav{"v1000.txt", "g1000.txt", "v10000.txt", "g10000.txt", "v100000.txt", "g100000.txt", "v1000000.txt", "g1000000.txt", "v10000000.txt", "g10000000.txt"};

    cout << endl;
    cout << "Iveskite kaip norite rusiuoti vargsus ir galvocius (0 - pagal vidurki, 1 - pagal mediana): " << endl;
    tikrinimas(pasirinkimas);
    cout << "VECTOR" << endl;

    indeksas = 0; /// indeksas, kuris nurodo kelintas failo pavadinimas yra vektoriuje
    studSk = 1000;
    galutinis = 0;

    for (int i = 0; i < 4; i++)
    {
        cout << "Testavimo laikai su " << studSk << " duomenu:" << endl;

        skaitymas(var, failoPav, indeksas, laikas, laboras);
        cout << "Failo skaitymas uztruko " << laikas << "s." << endl;
        galutinis += laikas;

        didejimo(var, laikas);

        cout << "Failo rusiavimas didejimo tvarka uztruko " << laikas << "s." << endl;
        galutinis += laikas;

        rusiavimasTest(var, vargsai, galvociai, laikas, pasirinkimas, indeksas);
        galutinis += laikas;
        suskirstymas += laikas;

        cout << "Failo suskirstymas i vargsiukus ir gudruolius uztruko " << suskirstymas << "s." << endl;
        cout << "Is viso darbas su " << studSk << " duomenu uztruko: " << galutinis << "s.\n"
             << endl;
        studSk *= 10;

        spausdinimasTest(vargsai, galvociai, pav, laikas, pasirinkimas, indeksas);
        indeksas++;
    }
}

void didejimo(vector<studentas> &var, double &laikas)
{

    auto start = std::chrono::high_resolution_clock::now();

    sort(var.begin(), var.end(), rikiuotiVid);

    auto end = std::chrono::high_resolution_clock::now(); /// baigti laiko skaiciavima
    std::chrono::duration<double> time = end - start;     /// laikas
    laikas = time.count();
}

void testavimui(vector<studentas> &var)
{

    int meniu, pasirinkimas;
    double laikas = 0.0, galutinis = 0;
    bool baigti = false;
    int kiekND, indeksas, studSk, laboras = 4;

    vector<studentas> vargsai, galvociai;

    VEKTORIUS<string> failoPav{"test1000.txt", "test10000.txt", "test100000.txt", "test1000000.txt", "test10000000.txt"}; /// vektorius saugo failu pavadinimus
    VEKTORIUS<string> pav1{"v1000.txt", "g1000.txt"};
    VEKTORIUS<string> pav2{"v10000.txt", "g10000.txt"};
    VEKTORIUS<string> pav3{"v100000.txt", "g100000.txt"};
    VEKTORIUS<string> pav4{"v1000000.txt", "g1000000.txt"};
    VEKTORIUS<string> pav5{"v10000000.txt", "g10000000.txt"};

    cout << "\nIveskite kiek namu darbu atliko studentai (nuo 1 iki 20): " << endl;
    while (!(cin >> kiekND) || (kiekND <= 0 || kiekND > 20))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); /// Ignoruojama visą eilutę iki naujos
        cout << "Iveskite nuo 1 iki 20: " << endl;
    }

    cout << "\nPasirinkite kiek vartotoju duomenu generuosite: " << endl;

    do
    {
        cout << "1 - su 1000 studentu duomenu" << endl;
        cout << "2 - su 10000 studentu duomenu" << endl;
        cout << "3 - su 100000 studentu duomenu" << endl;
        cout << "4 - su 1000000 studentu duomenu" << endl;
        cout << "5 - su 10000000 studentu duomenu" << endl;
        cout << "6 - baigti darba" << endl;
        cout << "--------------------------------------------------------" << endl;

        try
        {
            cout << "Iveskite pasirinkima: " << endl;
            string input;
            cin >> input;

            if (input.find_first_not_of("0123456789") != string::npos)
            { /// tikrina ar ivestas skaicius naturalusis
                throw invalid_argument("Netinkamas pasirinkimas");
            }

            meniu = stoi(input);

            if (meniu < 1 || meniu > 6)
            {
                throw invalid_argument("Iveskite nuo 1 iki 6 ");
            }
            cout << endl;
        }

        catch (const invalid_argument &e)
        {
            cerr << "Klaida: " << e.what() << endl;
            cout << endl;
            continue;
        }

        cout << endl;
        switch (meniu) /// meniu skirtas v0.1
        {
        case 1:
            indeksas = 0; /// indeksas, kuris nurodo kelintas failo pavadinimas yra vektoriuje
            studSk = 1000;
            galutinis = 0;
            cout << "Testavimo laikai su 1000 duomenu:" << endl;
            failoKurimas(failoPav, indeksas, kiekND, studSk, laikas);
            cout << "Failo sukurimas uztruko " << laikas << "s.\n"
                 << endl;
            galutinis += laikas;

            break;
        case 2:
            indeksas = 1;
            studSk = 10000;
            galutinis = 0;
            cout << "Testavimo laikai su 10000 duomenu:" << endl;
            failoKurimas(failoPav, indeksas, kiekND, studSk, laikas);
            cout << "Failo sukurimas uztruko " << laikas << "s.\n"
                 << endl;
            galutinis += laikas;

            break;
        case 3:
            indeksas = 2;
            studSk = 100000;
            galutinis = 0;
            cout << "Testavimo laikai su 100000 duomenu:" << endl;
            failoKurimas(failoPav, indeksas, kiekND, studSk, laikas);
            cout << "Failo sukurimas uztruko " << laikas << "s.\n"
                 << endl;
            galutinis += laikas;

            break;
        case 4:
            indeksas = 3;
            studSk = 1000000;
            galutinis = 0;
            cout << "Testavimo laikai su 1000000 duomenu:" << endl;

            failoKurimas(failoPav, indeksas, kiekND, studSk, laikas);
            cout << "Failo sukurimas uztruko " << laikas << "s.\n"
                 << endl;
            galutinis += laikas;

            break;
        case 5:
            indeksas = 4;
            studSk = 10000000;
            galutinis = 0;
            cout << "Testavimo laikai su 10000000 duomenu:" << endl;

            failoKurimas(failoPav, indeksas, kiekND, studSk, laikas);
            cout << "Failo sukurimas uztruko " << laikas << "s.\n"
                 << endl;
            galutinis += laikas;
            break;

        case 6:
            cout << "Darbas baigtas\n"
                 << endl;
            baigti = true;
            break;

        default:

            cout << "Iveskite nuo 1 iki 6 " << endl;
        }

    } while (!baigti);
}

void rusiavimasTest(vector<studentas> &var, vector<studentas> &vargsai, vector<studentas> &galvociai, double &galutinisLaikas, int &pasirinkimas, int indeksas)
{

    vargsai.clear();
    galvociai.clear();

    vargsai.reserve(var.size());
    galvociai.reserve(var.size());

    auto start = std::chrono::high_resolution_clock::now(); /// pradeti laiko skaiciavima

    for (int i = var.size() - 1; i >= 0; i--)
    {

        double galutin = galutinis(var, i, pasirinkimas);
        var[i].set_gal_v_m();
        
        
        if (galutin < 5.0)
        {
            vargsai.push_back(var[i]);
        }
        else
        {
            galvociai.push_back(var[i]);
        }
    }
    var.clear();

    

    if (pasirinkimas == 0)
    {
        sort(vargsai.begin(), vargsai.end(), rikiuotiVid);
        sort(galvociai.begin(), galvociai.end(), rikiuotiVid);
    }
    else
    {
        sort(vargsai.begin(), vargsai.end(), rikiuotiMed);
        sort(galvociai.begin(), galvociai.end(), rikiuotiMed);
    }

    auto end = std::chrono::high_resolution_clock::now(); /// baigti laiko skaiciavima
    std::chrono::duration<double> time = end - start;     /// laikas
    galutinisLaikas = time.count();                       /// laikas
}

void spausdinimasTest(vector<studentas> &vargsai, vector<studentas> &galvociai, VEKTORIUS<string> pav, double &laikas, int &pasirinkimas, int indeksas)
{

    laikas = 0;
    int numeris;

    auto start_1 = std::chrono::high_resolution_clock::now(); /// pradeti laiko skaiciavima

    if (indeksas == 0)
        numeris = 0;
    if (indeksas == 1)
        numeris = 2;
    if (indeksas == 2)
        numeris = 4;
    if (indeksas == 3)
        numeris = 6;
    if (indeksas == 4)
        numeris = 8;

    ofstream print_vargsiukai(pav[numeris]);

    print_vargsiukai << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(15);
    if (pasirinkimas == 0)
        print_vargsiukai << "Galutinis (Vid.) " << endl;
    else
        print_vargsiukai << "Galutinis (Med.) " << endl;
    print_vargsiukai << "------------------------------------------------" << endl;

    ofstream print_galvociai(pav[numeris + 1]);
    print_galvociai << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(15);
    if (pasirinkimas == 0)
        print_galvociai << "Galutinis (Vid.) " << endl;
    else
        print_galvociai << "Galutinis (Med.) " << endl;

    print_galvociai << "------------------------------------------------" << endl;

    for (int i = vargsai.size() - 1; i >= 0; i--)
    {
        print_vargsiukai << vargsai[i]; 
            
    }
    print_vargsiukai.close();

    for (int i = galvociai.size() - 1; i >= 0; i--)
    {
        galvociai[i].set_gal_v_m( ) ;
        print_galvociai << galvociai[i];
    }

    print_galvociai.close();

    auto end_1 = std::chrono::high_resolution_clock::now(); /// baigti laiko skaiciavima
    std::chrono::duration<double> time_1 = end_1 - start_1; /// laikas
    laikas = time_1.count();

    vargsai.clear();
    galvociai.clear();
}

void skaitymas(vector<studentas> &var, VEKTORIUS<string> &failoPav, int indeksas, double &laikas, int laboras)
{ /// nuskaito pasirinkta faila pagal indeksa ir sukuria rezultatu faila
    
    int kiekMok = 0;           /// mokiniu skaicius
    ifstream failas(failoPav[indeksas]);
    var.clear();
    

    try
    {
        if (!failas.is_open()) /// patikrina ar failas egzustuoja
        {
            throw std::runtime_error("Failas nerastas");
        }
    }

    catch (const std::exception &e)
    {
        cerr << "Klaida: " << e.what() << endl;
        cout << endl;
        return;
    }

    string line;
    getline(failas, line); /// pirma eilute mums nereikalinga

    auto start = std::chrono::high_resolution_clock::now(); /// pradeti laiko skaiciavima

    while (!failas.eof())
    {
        getline(failas, line);
        kiekMok++;
        istringstream dalijimas(line); /// leidzia is eilutes skaityti kaip is failo

        studentas naujasStudentas;

        dalijimas >> naujasStudentas;    ///naudojamas ivesties metodas

        VEKTORIUS <int> temp = naujasStudentas.get_tarpiniai();
        
        naujasStudentas.set_vidurkis(std::accumulate(temp.begin(), temp.end(), 0.0) / temp.size()); 
        naujasStudentas.set_gal_v_m ();

        var.push_back(naujasStudentas);

    }
    failas.close();


    if (laboras == 3)
        rusiavimas(var); /// 3 labaratoriniam skirtas rusiavimas

    auto end = std::chrono::high_resolution_clock::now(); /// baigti laiko skaiciavima
    std::chrono::duration<double> time = end - start;     /// laikas
    laikas = time.count();
}

void rusiavimas(vector<studentas> &var)
{ /// pagal pasirinktus kriterijus surusiuoja kursiokai vektoriu

    int meniu;
    bool baigti = false;
    int pasirinkimas = 0;

    do
    {

        cout << "Pasirinkite kaip norite rusiuoti duomenimis:" << endl;
        cout << "1 - pagal studento varda" << endl;
        cout << "2 - pagal studento pavarde" << endl;
        cout << "3 - pagal studento galutini ivertinima su vidurkiu" << endl;
        cout << "4 - pagal studento galutini ivertinima su mediana" << endl;

        cout << "--------------------------------------------------------" << endl;

        try
        {
            cout << "Iveskite pasirinkima: " << endl;
            string input;
            cin >> input;

            if (input.find_first_not_of("0123456789") != string::npos)
            { /// tikrina ar ivestas skaicius naturalusis
                throw invalid_argument("Netinkamas pasirinkimas");
            }

            meniu = stoi(input);

            if (meniu < 1 || meniu > 4)
            {
                throw invalid_argument("Iveskite nuo 1 iki 4 ");
            }

            cout << endl;
        }

        catch (const invalid_argument &e)
        {
            cerr << "Klaida: " << e.what() << endl;
            cout << endl;
            continue;
        }

        for (int i = 0; i < var.size(); i++)
        {
            pasirinkimas = 0;
            var[i].set_gal_v_m() ;

            pasirinkimas = 1;
            var[i].set_gal_v_m();
        }

        switch (meniu) /// meniu skirtas v0.2
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
            cout << "Iveskite nuo 1 iki 4 " << endl;

            break;
        }

    } while (!baigti);
}

void spausdinami_surikiuoti(vector<studentas> &var, double &laikas)
{ /// isspausdina i rezultatu faila surikiuota sarasa

    auto start = std::chrono::high_resolution_clock::now(); /// pradeti laiko skaiciavima

    ofstream print("rez.txt");
    print << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Galutinis (Vid.) " << setw(15) << "Galutinis (Med.) " << endl;
    print << "-----------------------------------------------------------" << endl;

    for (int i = 0; i < var.size(); i++) {
        print << var[i];                    ///naudojamas isvesties metodas
    }


    auto end = std::chrono::high_resolution_clock::now(); /// baigti laiko skaiciavima
    std::chrono::duration<double> time = end - start;     /// laikas
    laikas += time.count();
    cout << " Uztruko: " << laikas << "s." << endl;
    cout << endl;

    print.close();
}

void failoKurimas(VEKTORIUS<string> &failoPav, int indeksas, int &kiekND, int &studSk, double &laikas)
{ /// sukuria "kursiokai.txt" faila

    auto start = std::chrono::high_resolution_clock::now(); /// pradeti laiko skaiciavima

    ofstream failas(failoPav[indeksas]);

    using hrClock = std::chrono::high_resolution_clock;
    std::mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
    std::uniform_int_distribution<int> dist(0, 99);

    failas << left << setw(15) << "Vardas" << setw(15) << "Pavarde";

    for (int i = 1; i <= kiekND; i++)
    {

        failas << "ND" << left << setw(5) << i;
    }
    failas << "Egz." << endl;

    int m = studSk; /// studentu skaicius

    for (int i = 1; i <= m; i++)
    {

        failas << "Vardas" << setw(8) << left << i << " Pavarde" << left << setw(8) << i;

        for (int j = 0; j < kiekND; j++)
        {
            int pazymys = (rand() % 10 + 1); /// generuoja atsitikstinius skaicius intervale nuo 1 iki 10

            failas << left << setw(7) << pazymys;
        }

        if (i == m)
        {

            failas << rand() % 10 + 1; /// kad nesusidarytu papildoma eilute nededamas endl
        }
        else
            failas << rand() % 10 + 1 << endl;
    }

    failas.close();

    auto end = std::chrono::high_resolution_clock::now(); /// baigti laiko skaiciavima
    std::chrono::duration<double> time = end - start;     /// laikas
    laikas = time.count();
}

void su_duomenimis_is_failu(vector<studentas> &kursiokai, vector<studentas> &var)
{ /// jei pasirinko dirbti su duomenu failais

    int meniu;
    double laikas;
    bool baigti = false;
    int kiekND, indeksas, studSk, laboras = 3;
    VEKTORIUS<string> failoPav{"kursiokai.txt", "studentai10000.txt", "studentai100000.txt", "studentai1000000.txt"}; /// vektorius saugo failu pavadinimus

    cout << "Pasirinkite kuri duomenu faila nauduosite: " << endl;

    do
    {
        cout << "1 - is sugeneruoto duomenu failo 'kursiokai.txt'" << endl;
        cout << "2 - is testavimo failo su 10000 studentu duomenu" << endl;
        cout << "3 - is testavimo failo su 100000 studentu duomenu" << endl;
        cout << "4 - is testavimo failo su 1000000 studentu duomenu" << endl;
        cout << "5 - baigti darba" << endl;
        cout << "--------------------------------------------------------" << endl;

        try
        {
            cout << "Iveskite pasirinkima: " << endl;
            string input;
            cin >> input;

            if (input.find_first_not_of("0123456789") != string::npos)
            { /// tikrina ar ivestas skaicius naturalusis
                throw invalid_argument("Netinkamas pasirinkimas");
            }

            meniu = stoi(input);

            if (meniu < 1 || meniu > 5)
            {
                throw invalid_argument("Iveskite nuo 1 iki 5 ");
            }
            cout << endl;
        }

        catch (const invalid_argument &e)
        {
            cerr << "Klaida: " << e.what() << endl;
            cout << endl;
            continue;
        }

        switch (meniu) /// meniu skirtas v0.1
        {
        case 1:
            indeksas = 0; /// indeksas, kuris nurodo kelintas failo pavadinimas yra vektoriuje
            kiekND = 5;
            studSk = 10;
            failoKurimas(failoPav, indeksas, kiekND, studSk, laikas);
            skaitymas(kursiokai, failoPav, indeksas, laikas, laboras);
            spausdinami_surikiuoti(kursiokai, laikas);

            break;
        case 2:
            indeksas = 1;
            skaitymas(var, failoPav, indeksas, laikas, laboras);
            spausdinami_surikiuoti(var, laikas);

            break;
        case 3:
            indeksas = 2;
            skaitymas(var, failoPav, indeksas, laikas, laboras);
            spausdinami_surikiuoti(var, laikas);

            break;
        case 4:
            indeksas = 3;
            skaitymas(var, failoPav, indeksas, laikas, laboras);
            spausdinami_surikiuoti(var, laikas);

            break;

        case 5:
            cout << "Darbas su duomenu ivedimu baigtas\n"
                 << endl;
            baigti = true;
            break;

        default:

            cout << "Iveskite nuo 1 iki 5 " << endl;
        }

    } while (!baigti);
}




bool rikiuotiVarda(const studentas &a, const studentas &b)
{
    return a.get_Vardas() < b.get_Vardas();
}

bool rikiuotiPavarde(const studentas &a, const studentas &b)
{
    return a.get_Pavarde() < b.get_Pavarde();
}

bool rikiuotiVid(const studentas &a, const studentas &b)
{
    return a.get_gal_v_m(0) < b.get_gal_v_m(0);
}

bool rikiuotiMed(const studentas &a, const studentas &b)
{
    return a.get_gal_v_m(1) < b.get_gal_v_m(1);
}

void atsitiktiniaiPazVar(vector<studentas> &var, int &studSk)
{

    int n;
    var.clear();
    string vardas, pavarde;
    VEKTORIUS <int> skaiciams;

    int m = (rand() % 10) + 1; /// atsitiktinai sugeneruoja kiek yra studentu
    studSk = m;
   
        for (int i = 0; i < m; i++)
        {

            bool lytis;         /// jeigu 0 - vyras, jeigu 1 - moteris
            lytis = rand() % 2; /// arba 0 arba 1
                        
            if (lytis == 0)
            {

                int indeksas = rand() % (vyrV.size()); /// atsitinktinai  istrenkamas vardas
                vardas = vyrV[indeksas];

                indeksas = rand() % (vyrP.size());
                pavarde = vyrP[indeksas]; ;


                cout << "--------------------------------------------------------" << endl;
                cout << i + 1 << "-ojo"
                     << " studento vardas: " << vardas << endl;
                cout << i + 1 << "-ojo"
                     << " studento pavarde: " << pavarde << endl;
                     
            }

            if (lytis == 1)
            {

                int indeksas = rand() % (motP.size());
                vardas = motV[indeksas];

                indeksas = rand() % (motP.size());

                pavarde = motP[indeksas];

                cout << "--------------------------------------------------------" << endl;
                cout << i + 1 << "-ojo"
                     << " studento vardas: " << vardas << endl;
                cout << i + 1 << "-ojo"
                     << " studento pavarde: " << pavarde << endl;
            }

            n = rand() % 10 + 1; /// atsitiktinai sugeneruoja kiek namu darbu atliko studentas
            cout << " Studentas atliko " << n << " namu darbu uzduotis" << endl;

            cout << " Atsitiktinai sugeneruoti namu darbu rezultatai: " << endl;


            VEKTORIUS <int> tarpiniai ={};
            for (int j = 0; j < n; j++)
            {
                tarpiniai.push_back( rand() % 10 + 1); /// generuoja atsitikstinius skaicius intervale nuo 1 iki 10

                cout << tarpiniai[j] << "\t";
            }
            
            cout << endl;
            cout << " Atsitiktinai sugeneruotas studento ezamino rezultatas: ";
            int egz = (rand() % 10 + 1) ; /// generuoja atsitikstinius skaicius intervale nuo 1 iki 10
            cout << egz << endl;
            cout << endl;

            studentas naujasStudentas (vardas, pavarde, tarpiniai, egz);
            naujasStudentas.set_paz_kiekis(n); 
            naujasStudentas.set_vidurkis(std::accumulate(tarpiniai.begin(), tarpiniai.end(), 0.0) / tarpiniai.size()); 
            naujasStudentas.set_gal_v_m();
            
            var.push_back(naujasStudentas); /// pridedamas naujas studentas i vektoriu
        }

        m--;
   
}

void atsitiktiniaiPazymiai(vector<studentas> &var, int &studSk)
{

    int n; /// namu darbu kiekis
    bool pasirinkimas;
    string vardas, pavarde;
    var.clear();
    int i = 0;
    do
    {
        if (i != 0)
        {
            cout << "--------------------------------------------------------" << endl;
            cout << " Jei norite irasyti studenta iveskite 1, o jei norite baigti vedima - 0" << endl;

            while (!(cin >> pasirinkimas) || (pasirinkimas != 0 && pasirinkimas != 1))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); /// Ignoruojama visą eilutę iki naujos
                cout << " Iveskite 1 arba 0: " << endl;
            }
        }

        if (pasirinkimas == false && i > 0)
            break;

        i++;
        
        VEKTORIUS <int> tarpiniai ={};
        cout << "--------------------------------------------------------" << endl;
        cout << " Iveskite " << i << " studento varda: ";
        cin >> vardas;
        cout << " Iveskite " << i << " studento pavarde: ";
        cin >> pavarde;

        cout << " Iveskite kiek namu darbu uzduociu atliko studentas: ";
        while (!(cin >> n) || (n < 1 && n > 100))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); /// Ignoruojama visą eilutę iki naujos+
            cout << "Iveskite nuo 1 iki 100: " << endl;
        }
        

        cout << " Atsitiktinai sugeneruoti namu darbu rezultatai: " << endl;

        for (int j = 0; j < n; j++)
        {

            tarpiniai.push_back(rand() % 10 + 1); /// generuoja atsitikstinius skaicius intervale nuo 1 iki 10

            cout << tarpiniai[j] << "\t";
        }
    
        cout << endl;
        cout << " Atsitiktinai sugeneruotas studento ezamino rezultatas: " << endl;
        int egz=rand() % 10 + 1; /// generuoja atsitikstinius skaicius intervale nuo 1 iki 10
        cout << egz << endl;

        studentas naujasStudentas(vardas,pavarde, tarpiniai, egz);
        naujasStudentas.set_paz_kiekis(n);
        naujasStudentas.set_vidurkis(std::accumulate(tarpiniai.begin(), tarpiniai.end(), 0.0) / tarpiniai.size()); 
        naujasStudentas.set_gal_v_m();

        var.push_back(naujasStudentas);
        pasirinkimas = true;
        studSk = i;

        

    } while (pasirinkimas == true);
}

void ivedimasRanka(vector<studentas> &var, int &studSk)
{
    int i = 0;
    bool pasirinkimas;
    string vardas, pavarde;
    var.clear();

    do
    {
        cout << "--------------------------------------------------------" << endl;
        cout << " Jei norite irasyti studenta iveskite 1, o jei norite baigti vedima - 0" << endl;

        try
        { /// tikrina ivedima

            cin >> pasirinkimas;

            if (cin.fail())
            { /// tikrina a nera ivesta raidziu
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Netinkamas pasirinkimas");
            }

            if (pasirinkimas != 0 && pasirinkimas != 1)
            { /// tikrina ar ivestas 0 arba 1
                throw invalid_argument("Netinkamas pasirinkimas");
            }
        }

        catch (const invalid_argument &e)
        {
            cerr << "Klaida: " << e.what() << endl;
            continue;
        }

        if (pasirinkimas == false && i == 0)
        {
            cout << "Reikia ivesti nors viena studenta " << endl;
            continue;
        }

        if (pasirinkimas == false && i > 0)
            break;

        i++;

        VEKTORIUS <int> skaiciams;
       
        cout << "--------------------------------------------------------" << endl;
        cout << " Iveskite " << i << " studento varda: ";
        cin >> vardas;
        cout << " Iveskite " << i << " studento pavarde: ";
        cin >> pavarde;

        cout << " Iveskite studento namu darbu rezultatus (noredami baigti ivedima iveskite 0): " << endl;

        int pazimys;
        string input;
        int kiek = 0; // Pazymiu sk
        

        while (true)
        {

            try
            {
                cin >> input;

                if (input.find('.') != string::npos)
                { /// tikrina ar string yra "." , jei yra, ismes klaida
                    cerr << "Klaida! Iveskite skaiciu nuo 0 iki 10\n";
                    continue;
                }

                pazimys = stoi(input); /// jei string ivestas skaicius yra sveikasis, pavercia ji i int tipo kintamaji

                if (cin.fail())
                { /// tikrina ar ivestas kintamasis yra int tipo
                    throw invalid_argument("Netinkami duomenys");
                }

                if (pazimys < 0 || pazimys > 10)
                {
                    throw invalid_argument("Iveskite skaiciu nuo 0 iki 10\n");
                }

                if (pazimys != static_cast<int>(pazimys))
                { /// tikrina ar skaicius int kintamasis
                    throw invalid_argument("Iveskite sveikaji skaiciu");
                }

                if (pazimys == 0)
                    break;

                skaiciams.push_back(pazimys);
                kiek++;
            }
            catch (const invalid_argument &e)
            {
                cerr << "Klaida: " << e.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        cout << " Iveskite " << i << " studento egzamino rezultata: ";
        int egz;

        while (true)
        {

            try
            {
                cin >> input;

                if (input.find('.') != string::npos)
                { /// tikrina ar string yra "." , jei yra, ismes klaida
                    cerr << "Klaida! Iveskite skaiciu nuo 0 iki 10\t";
                    continue;
                }

                egz = stoi(input);

                if (cin.fail())
                {
                    throw invalid_argument("Netinkami duomenys");
                }

                if (pazimys < 0 || pazimys > 10)
                {
                    throw invalid_argument("Iveskite skaiciu nuo 0 iki 10\t");
                }
                break;
            }
            catch (const invalid_argument &e)
            {
                cerr << "Klaida: " << e.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        cout << endl;

        studentas naujasStudentas (vardas, pavarde, skaiciams, egz);
        naujasStudentas.set_vidurkis(std::accumulate(skaiciams.begin(), skaiciams.end(), 0.0) / skaiciams.size());
        naujasStudentas.set_paz_kiekis(kiek);
        naujasStudentas.set_gal_v_m();


        var.push_back(naujasStudentas);
        studSk = i;

    } while (true);
}

void tikrinimas(int &pasirinkimas)
{ /// tikrina pasirinkima

    while (!(cin >> pasirinkimas) || (pasirinkimas != 0 && pasirinkimas != 1))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); /// Ignoruojama visą eilutę iki naujos
        cout << "Iveskite 1 arba 0: " << endl;
    }
}

void spausdinimas(vector<studentas> &var)
{

    int pasirinkimas;

    cout << "Jei norite spausdinti studentu galutini iverinima naudojant vidurki iveskite: 0";
    cout << "\nJei norite spausdinti studentu galutini iverinima naudojant mediana iveskite: 1\n"
         << endl;

    tikrinimas(pasirinkimas); /// patikrina ar ivesta 0 arba 1

    cout << endl;

    if (pasirinkimas == 0)
    { /// isvedama informacija apie studentus ir galutinis rezultatas apskaiciuotas su vidurkiu

        cout << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Galutinis (Vid.) " << endl;
        cout << "------------------------------------------------" << endl;

        for (const auto& studenta : var) {
            su_vidurkiu(cout, studenta);
        }
    }

    else
    { /// isvedama informacija apie studentus ir galutinis rezultatas apskaiciuotas su mediana

        cout << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Galutinis (Med.) " << endl;
        cout << "-------------------------------------------------------" << endl;

        for (const auto& studenta : var) {
            su_mediana(cout, studenta);
        }
    }

    var.resize(0);
}

double galutinis(vector<studentas> &var, int &k, int &pasirinkimas)
{ /// galutinio rezultato skaiciavimas

    double gal = 0.0;
    if (pasirinkimas == 0)
    {
        gal = vidurkis(var, k) * 0.4 + 0.6 *var[k].get_egz();
    }
    
    else
    {
        gal = mediana(var, k) * 0.4 + 0.6 *var[k].get_egz();
    }
    

    return gal;
}

double mediana(vector<studentas> &var, int &k)
{

    int pazymiai = var[k].get_paz_kieki();
    double medi;

    if (pazymiai == 0) /// jei nera ivesta pazymiu                                                        ///jeigu nebuvo ivestas nei vienas pazymys
    {
        return 0;
    }

    else
    {   
        VEKTORIUS <int> tarpiniai = var[k].get_tarpiniai();
        sort(tarpiniai.begin(), tarpiniai.end());

        if ((pazymiai % 2) == 0)
        {
           medi = (double(tarpiniai[pazymiai / 2 - 1]) + (tarpiniai[pazymiai / 2])) / 2;

        }

        else
        {
            medi = (tarpiniai[pazymiai / 2]);
        }
        var[k].set_mediana(medi);
        return medi;
    }
}

double vidurkis(vector<studentas> &var, int &k)
{
    double sum = 0.0;

    if (var[k].get_paz_kieki() == 0)  /// jeigu nebuvo ivestas nei vienas pazymys
    {
        return var[k].get_paz_kieki();
    }

    else
    {
        for (int j = 0; j < var[k].get_paz_kieki(); j++)
        { /// pazymiu suma
            VEKTORIUS <int> tarpiniai = var[k].get_tarpiniai();
            sum += tarpiniai[j];
        }
        double vid = sum / var[k].get_paz_kieki(); /// skaiciuojamas vidurkis

        var[k].set_vidurkis(vid);

        return vid;
    }
}
