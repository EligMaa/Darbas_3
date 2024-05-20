#include "vektorius.h"
#include "manoBiblioteka.h"

int main() {

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

    VEKTORIUS <int> V={0};
    vector <int> v={0};

    /// PUSH_BACK
    cout<<"\nPush_back:"<<endl;
    for (int i = 1; i <= 10; i++) {
        v.push_back(i);
        V.push_back(i);
    }
    cout<<"Std::vector :"<<endl;
    for (int i = 0; i < v.size(); i++) {
        cout<<v[i]<<" ";
    }
    cout<<"\nSukurtas VEKTORIUS:"<<endl;
    for (int i = 0; i < V.size(); i++) {
        cout<<V[i]<<" ";
    }

    /// POP_BACK
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

    /// RESIZE
    v.resize(6);
    V.resize(6);

    cout<<"\n\nResize:"<<endl;
    cout<<"Std::vector :"<<endl;
    for (int i = 0; i < v.size(); i++) {
        cout<<v[i]<<" ";    }
    cout<<"\nSukurtas VEKTORIUS:"<<endl;
    for (int i = 0; i < V.size(); i++) {
        cout<<V[i]<<" ";
    }

    /// ERASE 
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

    cout<<"\n\nTestavimas naudojant PUSH_BACK funkcija"<<endl;
    VEKTORIUS <int> LAIKO={0};
    vector <int> laiko={0};
    int l=10000;

    for(int j=0; j<5; j++){

        auto start = std::chrono::high_resolution_clock::now();
        for(int i=0; i<l; i++){

            laiko.push_back(i);
        }
        auto end = std::chrono::high_resolution_clock::now(); /// baigti laiko skaiciavima
        std::chrono::duration<double> time = end - start;
        cout<<"Su "<<l<<": "<<time.count()<<endl;
        l*=10;
    }

    for(int j=0; j<5; j++){

        auto start1 = std::chrono::high_resolution_clock::now();
        for(int i=0; i<l; i++){

            LAIKO.push_back(i);
        }
        auto end1 = std::chrono::high_resolution_clock::now(); /// baigti laiko skaiciavima
        std::chrono::duration<double> time1 = end1 - start1;
        cout<<"Su "<<l<<": "<<time1.count()<<endl;
        l*=10;
    }

    return 0;
}
