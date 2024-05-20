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
            size_t dydis;        /// Dabartinis vektoriaus talpumas.
            size_t kiekis;       /// Dabartinis elementų skaičius vektoriuje.

        public:
  
            typedef T *rodykle;
            typedef T *iteratorius;

            // Konstruktorius
            VEKTORIUS() : r_masyvas(nullptr), dydis(0), kiekis(0) {}

            VEKTORIUS(std::initializer_list<T> init_list) {
                dydis = init_list.size();
                kiekis = dydis;
                r_masyvas = new T[kiekis];
                std::copy(init_list.begin(), init_list.end(), r_masyvas);
            }

            // Dekstruktorius
            ~VEKTORIUS()
            {
                delete[] r_masyvas;
            }

            pointer begin()
            {
                rodykle it;
                it = (&r_masyvas[0]);
                return it;
            }
            
            pointer end()
            {
                rodykle it;
                it = &r_masyvas[dydis - 1];
                return it;
            };
            
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

            size_t size() const { return dydis; }
            size_t capacity() const { return kiekis; }

            void erase(size_t val) {
                if (val < 0 || val >= dydis)
                    return;
                dydis--;
                std::move(&r_masyvas[val + 1], &r_masyvas[dydis], &r_masyvas[val]);
            }

            // grazin iteratori i pradzia
            T* begin() {
                return r_masyvas;
            }

            T* end() {
                return (r_masyvas + dydis);
            }

            const T* begin() const {
                return r_masyvas;
            }

            const T* end() const {
                return r_masyvas + dydis;
            }

            void sort()
            {
                sort(begin(), end());
            }

            template <typename lyginti>
            void sort(lyginti comp)
            {
                sort(begin(), end(), comp);
            }
                    
            void resize(size_t naujas_kiekis) {
                T* naujas_masyvas = new T[naujas_kiekis];
                move(r_masyvas, r_masyvas + dydis, naujas_masyvas);
                delete[] r_masyvas;
                r_masyvas = naujas_masyvas;
                kiekis = naujas_kiekis;
            }

            // Rezervuoti vietą elementams
            void reserve(size_t naujas_kiekis)
            {
                if (naujas_kiekis > dydis)
                {
                    T *duomenys = new T[naujas_kiekis];
                    for (size_t i = 0; i < kiekis; ++i)
                    {
                        duomenys[i] = std::move(r_masyvas[i]);
                    }
                    delete[] r_masyvas;
                    r_masyvas = duomenys;
                    dydis = naujas_kiekis;
                }
            }

            // Ar vektorius yra tuščias
            bool empty() const
            {
                return kiekis == 0;
            }

            void reverse()
            {
                reverse(begin(), end());
            }

            // Elementas pagal indeksą []
            T &operator[](size_t indeksas)
            {
                if (indeksas >= kiekis)
                    throw std::out_of_range("Indeksas už ribų");
                return r_masyvas[indeksas];
            }

            // Pirmas elementas
            T &front()
            {
                if (kiekis == 0)
                    throw std::out_of_range("Vektorius yra tuščias");
                return r_masyvas[0];
            }

            // // Paskutinis elementas
            T& back() {
                if (dydis == 0) {
                    throw std::out_of_range("VEKTORIUS tuscias");
                }
                return r_masyvas[dydis - 1];
            }

            // Elemento iterpimas į vektorių
            T *insert(iterator pozicija, const T &reiksme)
            {
                size_t indeksas = pozicija - begin();
                if (kiekis >= dydis)
                {
                    size_t naujas_kiekis;
                    if (dydis == 0) {
                        naujas_kiekis = 1;
                    } else {
                        naujas_kiekis = dydis * 2;
                    }

                    reserve(naujas_kiekis);
                }
                std::move_backward(begin() + indeksas, end(), end() + 1);
                r_masyvas[indeksas] = reiksme;
                ++kiekis;
                return begin() + indeksas;
            }          
            
            // Pirmas pasikartojantis elementas vektoriuje
            T &first_duplicate()
            {
                for (size_t i = 0; i < kiekis; ++i)
                {
                    for (size_t j = i + 1; j < kiekis; ++j)
                    {
                        if (r_masyvas[i] == r_masyvas[j])
                        {
                            return r_masyvas[i];
                        }
                    }
                }
                throw std::logic_error("Vektorius neturi pasikartojančių elementų");
            }

            // Elementu sk, kurie atitinka sąlyga
            template <typename Predicate>
            size_t count_if(Predicate pred)
            {
                size_t sum = 0;
                for (const auto &element : *this)
                {
                    if (pred(element))
                    {
                        ++sum;
                    }
                }
                return sum;
            }

            //Surikiuoti vektoriu
            template <typename Func>
            void sort_by(Func func)
            {
                std::sort(begin(), end(), [&](const T &a, const T &b)
                        { return func(a) < func(b); });
            }

            // Sukeičia du elementus pagal ju indeksus
            void swap_elements(size_t indeksas1, size_t indeksas2)
            {
                if (indeksas1 >= kiekis || indeksas2 >= kiekis)
                {
                    throw std::out_of_range("Indeksas už ribų");
                }
                std::swap(r_masyvas[indeksas1], r_masyvas[indeksas2]);
            }

            // Vektoriaus elementų tvarka keiciama tarp nurodytų indeksų            
            void rotate(iterator start, iterator middle, iterator end)
            {
                size_t leftkiekis = middle - start;
                size_t rightkiekis = end - middle;
                VEKTORIUS<T> temp(leftkiekis + rightkiekis); // Temporary VEKTORIUS to store rotated elements

                // Copy elements from the left side to temporary VEKTORIUS
                for (size_t i = 0; i < leftkiekis; ++i)
                {
                    temp[i] = std::move(start[i]);
                }

                // Move elements from the right side to the original VEKTORIUS's left side
                for (size_t i = 0; i < rightkiekis; ++i)
                {
                    start[i] = std::move(middle[i]);
                }

                // Move elements from the temporary VEKTORIUS to the original VEKTORIUS's right side
                for (size_t i = 0; i < leftkiekis; ++i)
                {
                    start[rightkiekis + i] = std::move(temp[i]);
                }
            }

            // Tikrina ar vektorius surikiuotas didėjančia tvarka
            bool is_sorted() const
            {
                return std::is_sorted(begin(), end());
            }

            // Spausdina vektorių į srautą
            friend std::ostream &operator<<(std::ostream &out, const VEKTORIUS &vektorius)
            {
                out << "[";
                if (!vektorius.empty())
                {
                    out << vektorius[0];
                    for (size_t i = 1; i < vektorius.size(); ++i)
                    {
                        out << ", " << vektorius[i];
                    }
                }
                out << "]";
                return out;
            }
            
    };

#endif // VEKTORIUS_H