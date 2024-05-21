# V3.0 
VEKTORIUS konteineris veikia (funkcionalumo prasme) lygiai taip pat, kaip ir std::vector. VEKTORIUS klasė talpina funkcijas, kurios atitinka std::vector funkcionalumą. Tam patikrinti yra atlikti testavimai <br>
1. PUSH_BACK:<br>

                      VEKTORIUS <int> V={0};
                      vector <int> v={0};
                      /// PUSH_BACK
                      cout<<"\nPush_back:"<<endl;
                      for (int i = 1; i <= 10; i++) {
                          v.push_back(i);
                          V.push_back(i);
                      }
Rezultatai:<br>
![image](https://github.com/EligMaa/Darbas_3/assets/151032480/4a5c2a7b-33fc-4378-9081-a7ca7d3c18a3)<br>
2. POP_BACK:<br>

                      v.pop_back();
                      V.pop_back();
                      cout<<"\n\nPop_back:"<<endl;
                      cout<<"Std::vector :"<<endl;
                      for (int i = 0; i < v.size(); i++) {
                          cout<<v[i]<<" ";
                      }
                      cout<<"\nSukurtas VEKTORIUS:"<<endl;
                      for (int i = 0; i < V.size(); i++) {
                          cout<<V[i]<<" ";
                      }
Rezultatai:<br>
![image](https://github.com/EligMaa/Darbas_3/assets/151032480/eb4944e2-09ca-44c6-bf23-935616563672)<br>
3. INSERT:<br>

                    v.insert(v.begin(), 15);
                    V.insert(V.begin(), 15);
                
                    cout<<"\n\nInsert:"<<endl;
                    cout<<"Std::vector :"<<endl;
                    for (int i = 0; i < v.size(); i++) {
                        cout<<v[i]<<" ";    }
                    cout<<"\nSukurtas VEKTORIUS:"<<endl;
                    for (int i = 0; i < V.size(); i++) {
                        cout<<V[i]<<" ";
                    }
Rezultatai:<br>
![image](https://github.com/EligMaa/Darbas_3/assets/151032480/af15bf1d-040a-4412-840c-11ca391ef400)<br>

4. ERASE:<br>

                    v.erase(v.begin()+5);
                    V.erase(V.begin()+5);
                    cout<<"\n\nErase:"<<endl;
                    cout<<"Std::vector :"<<endl;
                    for (int i = 0; i < v.size(); i++) {
                        cout<<v[i]<<" ";
                    }
                    cout<<"\nSukurtas VEKTORIUS:"<<endl;
                    for (int i = 0; i < V.size(); i++) {
                        cout<<V[i]<<" ";
                    }
Rezultatai:<br>
![image](https://github.com/EligMaa/Darbas_3/assets/151032480/95652be7-b6b8-4002-90ca-4089a4019551)<br>

5. OPERATORIAI:<br>

                    VEKTORIUS <int> V2 = {5,5,6};
                    VEKTORIUS <int> V1 = {1,2,3};
                
                    /// Operatoriai
                    cout<<"Operatoriu tikrinimas:"<<endl;
                    {
                        if (V2==V1) cout << "V1 ir V2 yra lygus" << endl;
                        if (V1!=V2) cout << "V1 ir V2 nera lygus" << endl;
                        if (V1<V2) cout << "V1 yra mazesnis uz V2" << endl;
                        if (V1>V2) cout << "V1 yra didesnis uz V2" << endl;
                        if (V1<=V2) cout << "V1 yra mazesnis arba lygus V2" << endl;
                        if (V1>=V2) cout << "V1 yra didesnis arba lygus V2" << endl;
                
                    }
Rezultatai:<br>
   ![image](https://github.com/EligMaa/Darbas_3/assets/151032480/a1bc2e64-60a9-411f-a776-92887f8c3eaa)<br><br>


Spartumo analizė lyginant std::vector ir VEKTORIUS naudojant funkciją PUSH_BACK:<br>
|   Analizė    | 10 000     | 100 000     | 1 000 000    | 10 000 000  |  100 000 000  |
| ------------ | ---------- | ----------- | ------------ | ----------- | --------------|
| std::vector  | 0 s.       | 0.001996 s. | 0.017991 s.  | 0.168293 s. | 1.48176 s.    |
| VEKTORIUS    | 0 s.       | 0.002295 s. | 0.013004 s.  | 0.092636 s. | 0.755751 s.   |


Vector ir std::vector atminties perskirstymo užpildant 100000000 elementų analizė. Perskirstymas įvyksta tada, kai yra patenkinama sąlyga: capacity() == size(), t.y. kai nelieka vietos capacity()`naujiems elementams.<br>

            unsigned int sk = 100000000;  // 10000, 100000, 1000000, 10000000, 100000000
            std::vector<int> v1;
            int std_vector_perskirstymas = 0;
            for (int i = 1; i <= sk; ++i) {
                v1.push_back(i);
                if (v1.capacity() == v1.size()) {
                    ++std_vector_perskirstymas;
                }
            }
            cout << "Atmintis buvo perskirstyta " << std_vector_perskirstymas << " kartu su std::vector" << endl;

            VEKTORIUS<int> v2;
            int vector_perskirstymas = 0;
            for (int i = 1; i <= sk; ++i) {
                v2.push_back(i);
                if (v2.capacity() == v2.size()) {
                    ++vector_perskirstymas;
                }
            } 
            cout << "Atmintis buvo perskirstyta " << vector_perskirstymas << " kartu su Vector" << endl;

Rezultatai:<br>
![image](https://github.com/EligMaa/Darbas_3/assets/151032480/4ed84b77-897f-4cf7-9c68-fc1136b2ca14)
![image](https://github.com/EligMaa/Darbas_3/assets/151032480/6b658f2a-ada4-4d5a-bcd5-c382e144bffb)


