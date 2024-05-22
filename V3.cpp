#include "funkcijos3.h"
#include "vektorius.h"


int main() {

    srand(time(nullptr));                                       /// inicializuoja atsitiktinių skaičių generatorių naudojant dabartinį laiką kaip pradinį numerį

    int meniu, meniu_testas;
    int meniu_duomenu_ivedimui;
    int studSk;
    bool baigti = false;
    bool baigti_duom_ived ,baigti_testa = false;
    vector <studentas> var, kursiokai; 
    list <studentas> varList, kursiokaiList; 
    deque <studentas> varDeque, kursiokaiDeque; 

                                      

    do
    { 
        cout<<"Pasirinkite kaip dirbsite su duomenimis:"<<endl;
        cout<<"1 - domenu ivedimas"<<endl;
        cout<<"2 - duomenu skaitymas is failo"<<endl;
        cout<<"3 - programos laiko testavimas naudojant failu generavima"<<endl;
        cout<<"4 - programos laiko testavimas naudojant failu rusiavimas"<<endl;
        cout<<"5 - testuoti class"<<endl;
        cout<<"6 - baigti darba"<<endl;
        cout<<"--------------------------------------------------------"<<endl;
        
            try {
                cout << "Iveskite pasirinkima: " << endl;
                string input;
                cin >> input;

                if (input.find_first_not_of("0123456789") != string::npos) {                                  ///tikrina ar ivestas skaicius naturalusis
                throw invalid_argument("Netinkamas pasirinkimas");
                }

                meniu = stoi(input);

                if (meniu < 1 || meniu > 6) {                                                                ///tikrina ar ivestas skaicius yra nuo 1 iki 3
                    throw invalid_argument("Klaida! Iveskite nuo 1 iki 6 ");
                }
                            
            } 
                        
            catch (const invalid_argument & e) {
                cerr << "Klaida: " << e.what() << endl;
                cout << endl;

                continue;
            }    

        switch (meniu)                                                                                  /// meniu skirtas v0.2
        {
            case 1:
            
                cout<<"Duomenu ivedimui pasirinkite buda: "<<endl;
                do
                {
                    cout<<"1 - ivedimas ranka"<<endl;
                    cout<<"2 - generuoti pazymius"<<endl;
                    cout<<"3 - generuoti ir pazymius ir studentu vardus, pavardes"<<endl;
                    cout<<"4 - baigti darba"<<endl;
                    cout<<"--------------------------------------------------------"<<endl;
                    
                    
                    try {
                        cout << "Iveskite pasirinkima: " << endl;
                        string input;
                        cin >> input;

                        if (input.find_first_not_of("0123456789") != string::npos) {                                  ///tikrina ar ivestas skaicius naturalusis
                        throw invalid_argument("Netinkamas pasirinkimas");
                        }

                        meniu = stoi(input);

                        if (meniu < 1 || meniu > 4) {                                                                ///tikrina ar ivestas skaicius yra nuo 1 iki 4
                            throw invalid_argument("Iveskite nuo 1 iki 4 ");
                        }
                                    
                    } 
                            
                    catch (const invalid_argument & e) {
                        cerr << "Klaida: " << e.what() << endl;
                        cout << endl;
                        continue;
                    }
                    
                    switch (meniu)                                                      ///meniu skirtas v0.1
                        {
                            case 1:
                                var.clear();
                                ivedimasRanka(var,studSk);
                                spausdinimas(var);
                                cout<<endl;
                                break;
                            case 2:
                                var.clear();
                                atsitiktiniaiPazymiai(var, studSk);
                                spausdinimas(var);
                                cout<<endl;            
                                break;
                            case 3:
                                var.clear();
                                atsitiktiniaiPazVar(var, studSk);
                                spausdinimas( var);
                                cout<<endl;
                                break;
                            case 4:
                                cout<<"Darbas su duomenu ivedimu baigtas\n"<<endl;
                                baigti=true;
                                break;
                            default:
                                cout<< "Iveskite nuo 1 iki 4 " << endl;

                                break;
                        }

                } while (!baigti);
                break;

            case 2:
                su_duomenimis_is_failu(kursiokai, var);
                break;

            case 3:
                testavimui(var);
                break;

            case 4:

                do{

                    cout<<"\n1 - VECTOR\n";
                    cout<<"2 - LIST\n";
                    cout<<"3 - DEQUE\n";
                    cout<<"4 - BAIGTI DARBA\n";
                    

                    try {
                            cout << "\nIveskite pasirinkima: " << endl;
                            string input;
                            cin >> input;

                            if (input.find_first_not_of("0123456789") != string::npos) {                                  ///tikrina ar ivestas skaicius naturalusis
                                throw invalid_argument("Netinkamas pasirinkimas");
                            }

                            meniu_testas = stoi(input);

                            if (meniu_testas < 1 || meniu_testas > 4) {                                                                ///tikrina ar ivestas skaicius yra nuo 1 iki 4
                                throw invalid_argument("Iveskite nuo 1 iki 4 ");
                            }
                                            
                        } 
                                    
                    catch (const invalid_argument & e) {
                        cerr << "Klaida: " << e.what() << endl;
                        cout << endl;
                        continue;
                    }

                
                    switch (meniu_testas)
                    {
                        case 1:
                            // cout<<"\nPirma strategija:\n";
                            // testFail(var);
                            // cout<<"\nAntra strategija:\n";
                            // testFail_2strategija(var);
                            cout<<"\nTrecia strategija:\n";
                            testFail_3strategija(var);

                            break;

                        case 2:
                            cout<<"\nSioje programoje LIST konteineriai nenaudojami\n";

                            break;

                        case 3:
                            cout<<"\nSioje programoje DEQUE konteineriai nenaudojami\n";
                            
                            break;

                        case 4: 
                            baigti_testa = true;
                        
                        default:
                            break;
                    }
                            
                    // break;
                }while(!baigti_testa);
            
            case 5: 
                cout<<"Klases testavimas:\n"<<endl;
                testuoti_clase();

            case 6:
                cout<<"Darbas su duomenu ivedimu baigtas\n"<<endl;
                baigti=true;
                break;

            default:
                cout<< "Iveskite nuo 1 iki 6 " << endl;

                break;
            
            }

    } while (!baigti);


    return 0;
}

