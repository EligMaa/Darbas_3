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
![image](https://github.com/EligMaa/Darbas_3/assets/151032480/eb4944e2-09ca-44c6-bf23-935616563672)<br>
3. 

