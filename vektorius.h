#ifndef VEKTORIUS_H
#define VEKTORIUS_H
#include "manoBiblioteka.h"

#include <iostream>
#include <algorithm> 
#include <sstream>
#include <cassert>
#include <chrono> 
#include <iomanip> 

template <typename T>
    class VEKTORIUS
    {
        private:
            T *r_masyvas;        /// Rodiklis į masyvą.
            size_t dydis;      /// Dabartinis vektoriaus talpumas.
            size_t kiekis;      /// Dabartinis elementų skaičius vektoriuje.

        public:
  
            typedef T *rodykle;
            typedef T *iteratorius;

            // Konstruktorius
            VEKTORIUS() : r_masyvas(nullptr), dydis(0), kiekis(0) {}

            // Dekstruktorius
            ~VEKTORIUS()
            {
                delete[] r_masyvas;
            }
            
            // Kopijavimo konstruktorius
            VEKTORIUS(const VEKTORIUS& v) { create(v.begin(), v.end()); } 

            // Kopijavimo priskyrimo operatorius
            VEKTORIUS &operator=(const VEKTORIUS& other)
            {
                if (this != &other)
                {
                    clear();
                    reserve(other.size());
                    for (size_t i = 0; i < other.size(); ++i)
                    {
                        push_back(other.r_masyvas[i]);
                    }
                }
                return *this;
            }

            // Perkėlimo konstruktorius
            VEKTORIUS(VEKTORIUS && naujas) {create(); swap(naujas); naujas.uncreate();}

            // Perkėlimo priskyrimo operatorius
            VEKTORIUS &operator=(VEKTORIUS &&other) noexcept
            {
                if (this != &other)
                {
                    clear();
                    r_masyvas = other.r_masyvas;
                    dydis = other.dydis;
                    kiekis = other.kiekis;
                    other.r_masyvas = nullptr;
                    other.dydis = 0;
                    other.kiekis = 0;
                }
                return *this;
            }

            void push_back(T data) {
                if (dydis >= kiekis){
                    resize(dydis*2);
                }
                r_masyvas[dydis] = data;
                dydis++;
            }

            // Pašalinti paskutinį elementą
            void pop_back()
            {
                dydis = dydis - 1;
                T *laikinas = new T[dydis];
                for (size_t i = 0; i < dydis; i++)
                    laikinas[i] = r_masyvas[i];
                delete[] r_masyvas;
                r_masyvas = laikinas;
            };

            // Išvalyti vektorių
            void clear()
            {
                dydis = 0;
                delete[] r_masyvas;
                r_masyvas = new T[kiekis];
            }



    };

#endif // VEKTORIUS_H