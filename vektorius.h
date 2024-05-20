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
            size_t kiekis;       /// Dabartinis elementų skaičius vektoriuje
            
        public:
  
            typedef T *rodykle;
            typedef T *iterator;
            typedef size_t size_type;
            typedef T value_type;
            std::allocator<T> alloc;
            typedef const T* const_iterator;
            iterator pradzia;
            iterator pab;


            // Konstruktorius
            VEKTORIUS() : r_masyvas(nullptr), dydis(0), kiekis(0) {}

            VEKTORIUS(std::initializer_list<T> init_list) {
                dydis = init_list.size();
                kiekis = dydis;
                r_masyvas = new T[kiekis];
                std::copy(init_list.begin(), init_list.end(), r_masyvas);
            }

            VEKTORIUS(size_t initial_size) : dydis(initial_size), kiekis(0) {
                r_masyvas = new T[initial_size];
            }


            // Kopijavimo konstruktorius
            VEKTORIUS(const VEKTORIUS& v) { create(v.begin(), v.end()); } 

            // Kopijavimo priskyrimo operatorius
            VEKTORIUS &operator=(const VEKTORIUS& naujas)
            {
                if (this != &naujas)
                {
                    clear();
                    reserve(naujas.size());
                    for (size_t i = 0; i < naujas.size(); ++i)
                    {
                        push_back(naujas.r_masyvas[i]);
                    }
                }
                return *this;
            }

            // Perkėlimo priskyrimo operatorius
            VEKTORIUS &operator=(VEKTORIUS &&naujas) noexcept
            {
                if (this != &naujas)
                {
                    clear();
                    r_masyvas = naujas.r_masyvas;
                    dydis = naujas.dydis;
                    kiekis = naujas.kiekis;
                    naujas.r_masyvas = nullptr;
                    naujas.dydis = 0;
                    naujas.kiekis = 0;
                }
                return *this;
            }

            // Perkėlimo konstruktorius
            VEKTORIUS(VEKTORIUS && naujas) : VEKTORIUS() {
                swap(naujas);
            }

            // Dekstruktorius
            ~VEKTORIUS()
            {
                delete[] r_masyvas;
            }

            // Pasiekia elemeta tam tikrame indekse
            T &at(size_t indeksas)
            {
                if (indeksas >= kiekis)
                    throw std::out_of_range("Indeksas uz ribu");
                return r_masyvas[indeksas];
            }

            // Elementas pagal indeksą []
            T &operator[](size_t indeksas)
            {
                if (indeksas >= kiekis)
                    throw std::out_of_range("Indeksas uz ribu");
                return r_masyvas[indeksas];
            }

            const T &operator[](size_t indeksas) const
            {
                if (indeksas >= kiekis)
                    throw std::out_of_range("Indeksas uz ribu");
                return r_masyvas[indeksas];
            }

            // Pirmas elementas
            T &front()
            {
                if (dydis == 0)
                    throw std::out_of_range("VEKTORIUS yra tuščias");
                return r_masyvas[0];
            }

            const T &front() const
            {
                if (dydis == 0)
                    throw std::out_of_range("VEKTORIUS yra tuščias");
                return r_masyvas[0];
            }

            // Paskutinis elementas
            T &back()
            {
                if (dydis == 0)
                    throw std::out_of_range("VEKTORIUS tuscias");
                return r_masyvas[dydis - 1];
            }

            const T &back() const
            {
                if (dydis == 0)
                    throw std::out_of_range("VEKTORIUS tuscias");
                return r_masyvas[dydis - 1];
            }

            T *pradziaa() noexcept
            {
                return r_masyvas;
            }

            const T *pradziaa() const noexcept
            {
                return r_masyvas;
            }
            
            // grazina iteratoriu i pradzia
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

            T *rend() noexcept
            {
                return r_masyvas + dydis;
            }

            const T *rend() const noexcept
            {
                return r_masyvas + dydis;
            }

            // Ar VEKTORIUS yra tuščias
            bool empty() const
            {
                return kiekis == 0;
            }

            // grazina kiek yra elementu 
            size_t size() const { return kiekis; }

            // kiek daugiausiai elementu VEKTORIUS gali tureti
            size_t max_size() const { return std::numeric_limits<size_t>::max(); }

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

            size_t capacity() const { return dydis; }

            // funkcija sumažina vektoriaus talpą, kad ji atitiktų jo dydį
            void shrink_to_fit() {
                if (dydis > kiekis) {
                    T *duomenys = new T[kiekis];
                    for (size_t i = 0; i < kiekis; ++i) {
                        duomenys[i] = std::move(r_masyvas[i]);
                    }
                    delete[] r_masyvas;
                    r_masyvas = duomenys;
                    dydis = kiekis;
                }
            }

            void clear()
            {
                kiekis = 0;
                dydis = 0;
                delete[] r_masyvas;
                r_masyvas = nullptr;
            }



            // Elemento iterpimas į vektorių
            T *insert(T* pozicija, const T &reiksme)
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

            iterator erase(const_iterator pos) {
                size_type index = pos - begin();
                if (index >= kiekis) {
                    throw std::out_of_range("Index out of range");
                }

                // Perstumiam visus elementus nuo vienetu i kaire
                for (size_type i = index; i < kiekis - 1; ++i) {
                    r_masyvas[i] = std::move(r_masyvas[i + 1]);
                }

                --kiekis;
                return begin() + index;
            }

            iterator erase(const_iterator pirmas, const_iterator paskutinis)
            {
                size_type pirmas_indeks = pirmas - begin();
                size_type paskutinis_indeks = paskutinis - begin();
                if (pirmas_indeks > paskutinis_indeks || paskutinis_indeks > kiekis) {
                    throw std::out_of_range("Invalid range");
                }

                size_type istrinamas = paskutinis_indeks - pirmas_indeks;
                for (size_type i = pirmas_indeks; i < kiekis - istrinamas; ++i) {
                    r_masyvas[i] = std::move(r_masyvas[i + istrinamas]);
                }

                kiekis -= istrinamas;
                return begin() + pirmas_indeks;
            }

            void push_back(const T& pradziaa) {
                if (kiekis >= dydis) {
                    reserve(dydis == 0 ? 1 : dydis * 2);
                }
                r_masyvas[kiekis++] = pradziaa;
            }

            void pop_back()
            {
                if (kiekis == 0)
                    throw std::logic_error("VEKTORIUS yra tuscias");
                --kiekis;
            }

            iterator resize(size_t n_dydis) {
                if (n_dydis == 0) { 
                    dydis = 0;
                    kiekis = 2;
                    T *naujas = new T[kiekis];
                    delete[] r_masyvas;
                    r_masyvas = naujas;
                    return 0;
                }
                size_t lim;
                T *naujas = new T[n_dydis]; 
                if (n_dydis < dydis) {
                    dydis = n_dydis;
                    lim = n_dydis;
                }
                else lim = dydis;
                std::move(&r_masyvas[0], &r_masyvas[lim], naujas);
                kiekis = n_dydis;
                delete[] r_masyvas; 
                r_masyvas = naujas;
            }

            // void resize(size_type new_size)
            // {
            //     if (new_size < dydis) {
            //         dydis = new_size;
            //     } else if (new_size > dydis) {
            //         reserve(new_size);
            //         dydis = new_size;
            //     }
            // }
                       

            void swap(VEKTORIUS& naujas) noexcept {
                std::swap(r_masyvas, naujas.r_masyvas);
                std::swap(dydis, naujas.dydis);
                std::swap(kiekis, naujas.kiekis);
            }


            bool operator== (const VEKTORIUS<T>& naujas) const {
                if (size() != naujas.size()) {
                    return false;
                }
                return std::equal(begin(), end(), naujas.begin());
            }
            bool operator!= (const VEKTORIUS<T>& naujas) const {
                return !(*this == naujas);
            }
            bool operator < (const VEKTORIUS<T> & naujas) const {
                return std::lexicographical_compare(  begin(), end(), naujas.begin(), naujas.end());
            }
            bool operator <= (const VEKTORIUS<T> & naujas) const {
                return !(naujas < *this);
            }
            bool operator > (const VEKTORIUS<T> & naujas)const  {
                return std::lexicographical_compare( naujas.begin(), naujas.end(), begin(), end());
            }
            bool operator >= (const VEKTORIUS<T> & naujas) const {
                return !(naujas > *this);
            }
           
    };

    

#endif // VEKTORIUS_H