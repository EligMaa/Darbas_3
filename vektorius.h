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

            // Perkėlimo konstruktorius
            VEKTORIUS(VEKTORIUS && naujas) {create(); swap(naujas); naujas.uncreate();}

            // Pasiekia elemeta tam tikrame indekse
            T &at(size_t indeksas)
            {
                if (indeksas >= dydis)
                    throw std::out_of_range("Indeksas už ribų");
                return r_masyvas[indeksas];
            }

            // Elementas pagal indeksą []
            T &operator[](size_t indeksas)
            {
                if (indeksas >= dydis)
                    throw std::out_of_range("Indeksas už ribų");
                return r_masyvas[indeksas];
            }

            const T &operator[](size_t indeksas) const
            {
                if (indeksas >= dydis)
                    throw std::out_of_range("Indeksas už ribų");
                return r_masyvas[indeksas];
            }

            // Pirmas elementas
            T &front()
            {
                if (dydis == 0)
                    throw std::out_of_range("Vektorius yra tuščias");
                return r_masyvas[0];
            }

            const T &front() const
            {
                if (dydis == 0)
                    throw std::out_of_range("Vektorius yra tuščias");
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

            T *data() noexcept
            {
                return r_masyvas;
            }

            const T *data() const noexcept
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

            // Ar vektorius yra tuščias
            bool empty() const
            {
                return kiekis == 0;
            }

            // grazina kiek yra elementu 
            size_t size() const { return dydis; }

            // kiek daugiausiai elementu vektorius gali tureti
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

            // Išvalyti vektorių
            void clear()
            {
                dydis = 0;
                delete[] r_masyvas;
                r_masyvas = new T[kiekis];
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

            void erase(size_t indeksas) {
                if (indeksas < 0 || indeksas >= dydis)
                    return;
                dydis--;
                std::move(&r_masyvas[indeksas + 1], &r_masyvas[dydis], &r_masyvas[indeksas]);
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

            void resize(size_t naujas_kiekis) {
                T* naujas_masyvas = new T[naujas_kiekis];
                move(r_masyvas, r_masyvas + dydis, naujas_masyvas);
                delete[] r_masyvas;
                r_masyvas = naujas_masyvas;
                kiekis = naujas_kiekis;
            }

            void swap(VEKTORIUS& other) noexcept {
                std::swap(r_masyvas, other.r_masyvas);
                std::swap(dydis, other.dydis);
                std::swap(kiekis, other.kiekis);
            }

            //tikrina ar vektoriai lygus
            template<typename T>
            bool operator==(const VEKTORIUS<T>& lhs, const VEKTORIUS<T>& rhs) {
                if (lhs.size() != rhs.size()) {
                    return false;
                }
                for (size_t i = 0; i < lhs.size(); ++i) {
                    if (lhs[i] != rhs[i]) {
                        return false;
                    }
                }
                return true;
            }

            // tikrina ar vektoriai ne lygus
            template<typename T>
            bool operator!=(const VEKTORIUS<T>& lhs, const VEKTORIUS<T>& rhs) {
                return !(lhs == rhs);
            }

            
            template<typename T>
            bool operator<(const VEKTORIUS<T>& lhs, const VEKTORIUS<T>& rhs) {
                size_t min_size = std::min(lhs.size(), rhs.size());
                for (size_t i = 0; i < min_size; ++i) {
                    if (lhs[i] < rhs[i]) {
                        return true;
                    } else if (lhs[i] > rhs[i]) {
                        return false;
                    }
                }
                return lhs.size() < rhs.size();
            }

            template<typename T>
            bool operator<=(const VEKTORIUS<T>& lhs, const VEKTORIUS<T>& rhs) {
                return !(rhs < lhs);
            }

            template<typename T>
            bool operator>(const VEKTORIUS<T>& lhs, const VEKTORIUS<T>& rhs) {
                return rhs < lhs;
            }

            template<typename T>
            bool operator>=(const VEKTORIUS<T>& lhs, const VEKTORIUS<T>& rhs) {
                return !(lhs < rhs);
            }
           
    };

#endif // VEKTORIUS_H