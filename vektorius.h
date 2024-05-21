#ifndef VEKTORIUS_H
#define VEKTORIUS_H
#include "manoBiblioteka.h"

#include <iostream>
#include <algorithm> 
#include <sstream>
#include <cassert>
#include <chrono> 
#include <iomanip> 
#include <numeric> 

template <typename T>
    class VEKTORIUS
    {
        private:
            T *r_masyvas;        /// Rodiklis į masyvą.
            size_t dydis;        /// kiek elementu yra vektoriuje
            size_t kiekis;       /// kiek elementu gali buti
            
        public:
  
            typedef T *rodykle;
            typedef T *iterator;
            typedef size_t size_type;
            typedef T reiksme_type;
            std::allocator<T> alloc;
            typedef const T* const_iterator;
            typedef std::reverse_iterator<iterator> reverse_iterator;
            typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
            iterator pradzia;
            iterator pab;


            // Konstruktorius
            VEKTORIUS() : r_masyvas(nullptr), dydis(0), kiekis(0) {}

            // VEKTORIUS(std::initializer_list<T> init_list) {
            //     dydis = init_list.size();
            //     kiekis = dydis;
            //     r_masyvas = new T[kiekis];
            //     std::copy(init_list.begin(), init_list.end(), r_masyvas);
            // }

            VEKTORIUS(size_type n_dydis, const T& value = T())
                : kiekis(new T[n_dydis]), dydis(n_dydis), kiekis(n_dydis)
            {
                std::fill(r_masyvas, r_masyvas + dydis, value);
            }

            // VEKTORIUS(size_t initial_size) : dydis(initial_size), kiekis(0) {
            //     r_masyvas = new T[initial_size];
            // }

            VEKTORIUS(std::initializer_list<T> sarasas)
                : r_masyvas(new T[sarasas.size()]), dydis(sarasas.size()), kiekis(sarasas.size())
            {
                std::copy(sarasas.begin(), sarasas.end(), r_masyvas);
            }


            // Kopijavimo konstruktorius
            VEKTORIUS(const VEKTORIUS& kitas)
                : r_masyvas(new T[kitas.dydis]), dydis(kitas.dydis), kiekis(kitas.kiekis)
            {
                for(int i = 0; i !=dydis; ++i)
                {
                    r_masyvas[i]=kitas.r_masyvas[i];
                }
            }

            // Kopijavimo priskyrimo operatorius
            VEKTORIUS &operator=(const VEKTORIUS& naujas)
            {
                 if (this != &naujas) {
                    T* naujiDuom = new T[naujas.dydis];
                    for(int i = 0; i !=dydis; ++i)
                    {
                        naujiDuom[i]=naujas.r_masyvas[i];
                    }
                    delete[] r_masyvas;    // atlaisvinama sena atmintis
                    r_masyvas = naujiDuom; // mduom pointina i nauja atminti
                    dydis = naujas.dydis;
                    kiekis = naujas.kiekis;
                }
                return *this;
            }

            // Perkėlimo priskyrimo operatorius
            VEKTORIUS &operator=(VEKTORIUS &&naujas) 
            {
                if (&naujas == this) return *this;
                delete[] r_masyvas; // atlaisviname seną atmintį
                r_masyvas = naujas.r_masyvas; // elem point'ina į v.elem atmintį
                dydis = naujas.dydis; // atnaujiname size
                kiekis = naujas.kiekis;
                naujas.r_masyvas = nullptr; // v neturi jokių elementų
                naujas.dydis = 0;
                naujas.kiekis= 0;

                return *this; // grąžiname objektą
            }

            // Perkėlimo konstruktorius
            VEKTORIUS(VEKTORIUS && naujas) noexcept
                : r_masyvas(naujas.r_masyvas), dydis(naujas.dydis), kiekis(naujas.kiekis)
            {
                naujas.r_masyvas = nullptr;
                naujas.dydis = 0;
                naujas.kiekis = 0;
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

            const T& at(size_type indeksas) const
            {
                if (indeksas >= dydis)
                    throw std::out_of_range("Index out of range");
                return r_masyvas[indeksas];
            }

            // Elementas pagal indeksą []
            T &operator[](size_t indeksas)
            {
                if (indeksas >= dydis)
                    throw std::out_of_range("Indeksas uz ribu");
                return r_masyvas[indeksas];
            }

            const T &operator[](size_t indeksas) const
            {
                if (indeksas >= dydis)
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

            T* data() noexcept { return r_masyvas; }

            // grazina iteratoriu i pradzia
            iterator begin() noexcept { return r_masyvas; }
            const_iterator begin() const noexcept { return r_masyvas; }
            iterator end() noexcept { return r_masyvas + dydis; }
            const_iterator end() const noexcept { return r_masyvas + dydis; }

            const_iterator cbegin() const noexcept { return r_masyvas; }
            const_iterator cend() const noexcept { return r_masyvas + dydis; }
            reverse_iterator rbegin() noexcept { return reverse_iterator(end()); }
            const_reverse_iterator rbegin() const noexcept { return const_reverse_iterator(end()); }

            reverse_iterator rend() noexcept { return reverse_iterator(begin()); }
            const_reverse_iterator rend() const noexcept { return const_reverse_iterator(begin()); }

            const_reverse_iterator crbegin() const noexcept { return const_reverse_iterator(end()); }
            const_reverse_iterator crend() const noexcept { return const_reverse_iterator(begin()); }
        
            // Ar VEKTORIUS yra tuščias
            bool empty() const noexcept
            {
                return dydis == 0;
            }

            // grazina kiek yra elementu 
            size_type size() const noexcept { return dydis; }

            // kiek daugiausiai elementu VEKTORIUS gali tureti
            size_type max_size() const noexcept{ return std::numeric_limits<size_t>::max(); }

            // Rezervuoti vietą elementams
            void reserve(size_type naujsKiekis)
            {
                if (naujsKiekis <= kiekis)
                    return;

                T* naujiDuom = new T[naujsKiekis];
                for (size_type k = 0; k < dydis; ++k)
                    naujiDuom[k] = std::move(r_masyvas[k]);

                delete[] r_masyvas;
                r_masyvas = naujiDuom;
                kiekis = naujsKiekis;
            }

            size_type capacity() const noexcept{ return kiekis; }

            // funkcija sumažina vektoriaus talpą, kad ji atitiktų jo dydį
            void shrink_to_fit() {
                if (dydis < kiekis) {
                    T* naujiDuom = new T[dydis];
                    std::copy(r_masyvas, r_masyvas + dydis, naujiDuom);
                    delete[] r_masyvas;
                    r_masyvas = naujiDuom;
                    kiekis = dydis;
                }
            }

            void clear() noexcept
            {
                dydis = 0;
            }

            // Elemento iterpimas į vektorių
            iterator insert(const_iterator pos, const T& reiksme) {
                size_type index = pos - begin();
                if (dydis == kiekis) {
                    size_type new_capacity = (kiekis == 0) ? 1 : kiekis * 2;
                    reserve(new_capacity);
                }

                // Perstumiam visus elementus nuo įterpimo vietos į dešinę per viena
                for (size_type i = dydis; i > index; --i) {
                    r_masyvas[i] = std::move(r_masyvas[i - 1]);
                }

                // Įterpiame naują elementą į vietą 'pos'
                r_masyvas[index] = reiksme;
                ++dydis;

                return begin() + index;
            }                   

            iterator erase(const_iterator pos) {
                size_type index = pos - begin();
                if (index >= dydis) {
                    throw std::out_of_range("Index out of range");
                }

                // Perstumiam visus elementus nuo vienetu i kaire
                for (size_type i = index; i < dydis - 1; ++i) {
                    r_masyvas[i] = std::move(r_masyvas[i + 1]);
                }

                --dydis;
                return begin() + index;
            }

            iterator erase(const_iterator pirmas, const_iterator paskutinis)
            {
                size_type pirmas_indeks = pirmas - begin();
                size_type paskutinis_indeks = paskutinis - begin();
                if (pirmas_indeks > paskutinis_indeks || paskutinis_indeks > dydis) {
                    throw std::out_of_range("Invalid range");
                }

                size_type istrinamas = paskutinis_indeks - pirmas_indeks;
                for (size_type i = pirmas_indeks; i < dydis - istrinamas; ++i) {
                    r_masyvas[i] = std::move(r_masyvas[i + istrinamas]);
                }

                dydis -= istrinamas;
                return begin() + pirmas_indeks;
            }

            void push_back(const T& pradziaa) {
                if (kiekis == dydis) {
                    reserve(kiekis == 0 ? 1 : kiekis * 2);
                }
                r_masyvas[dydis++] = pradziaa;
            }

            void pop_back()
            {
                if (dydis > 0)
                --dydis;
            }

            // iterator resize(size_t n_dydis) {
            //     if (n_dydis == 0) { 
            //         dydis = 0;
            //         kiekis = 2;
            //         T *naujas = new T[kiekis];
            //         delete[] r_masyvas;
            //         r_masyvas = naujas;
            //         return 0;
            //     }
            //     size_t lim;
            //     T *naujas = new T[n_dydis]; 
            //     if (n_dydis < dydis) {
            //         dydis = n_dydis;
            //         lim = n_dydis;
            //     }
            //     else lim = dydis;
            //     std::move(&r_masyvas[0], &r_masyvas[lim], naujas);
            //     kiekis = n_dydis;
            //     delete[] r_masyvas; 
            //     r_masyvas = naujas;
            // }

            void resize(size_type new_size)
            {
                if (new_size < dydis) {
                    dydis = new_size;
                } else if (new_size > dydis) {
                    reserve(new_size);
                    dydis = new_size;
                }
            }

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


        T suma() const {
            return std::accumulate(begin(), end(), T());
        }
           
    };

    

#endif // VEKTORIUS_H