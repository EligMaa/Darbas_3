# V2.0 
Naudojant Doxygen kodo dokumentacija yra aprašyta HTML/TEX formatais ir pateikti kataloguose. 
Klasių testavimui yra naudojamas C++ Unit test Catch2 framework'as. 
Testo pavyzdys:<br>

         TEST_CASE("konstruktoriaus testavimas") {
             string vardas = "Rugile";
             string pavarde = "Macaite";
             vector<int> pazymiai = {1, 2, 3, 4, 5};
             double egzamino_rez = 9.5;
         
             studentas naujasstudentas(vardas, pavarde, pazymiai, egzamino_rez);
         
             REQUIRE(naujasstudentas.get_Vardas() == vardas);
             REQUIRE(naujasstudentas.get_Pavarde() == pavarde);   
             REQUIRE(naujasstudentas.get_egz() == egzamino_rez);
             REQUIRE(naujasstudentas.get_tarpiniai() == pazymiai);
         }

<br>Testavimui pasibaigus išmetama lentelė su rezultatais, šio kodo atvėju visi testai teigiami:<br>
![image](https://github.com/EligMaa/Darbas_2/assets/151032480/6e380b29-7580-4d38-b0fe-e171d631570d)<br>

## Programos paleidimas
1. Parsisiųskite failus iš pateikto linko: https://github.com/EligMaa/Darbas_2/tree/v2 naudodami instrukciją pateiktą šiame linke: https://blog.hubspot.com/website/download-from-github <br>
2. Susiinstaliuokite VisualStudioCode pagal pateiktą linką: https://www.youtube.com/watch?v=DMWD7wfhgNY <br>
3. Atidarykite parsisiųstą dokumentą iš github ir paspauskite dešiniu klavišu ant juostos su dokumento pavadinimu:<br>
   ![image](https://github.com/EligMaa/Darbas_1/assets/151032480/6177c4ce-f06c-4caf-8a94-6c3132fbf582)<br>
Paspauskite 'Kopijuoti adresą kaip tekstą'.<br>
5. Parsisiųstą aplankalą atsidarykite VisualStudioCode. Įrankių juostoje paspauskite 'Terminal' -> 'New terminal' ir įveskite pateiktas eilutes: <br>
 + cd 'jūsų nukopijuotas adresas' <br>
 + make pagrindine <br>
 + make funkcijos <br>
 + make prog <br>
 + ./prog <br>
<br>Programa jau paruošta naudoti.
## Naudojimo instrukcija
Paleidus programą egzistuoja meniu, kur vartotojas gali pasirinkti kaip nori dirbti su duomenimis:<br>
1 - duomenų įvedimas<br>
2 - duomenų skaitymas iš failo<br>
3 - programos laiko testavimas naudojant failų generavimą<br>
4 - programos laiko testavimas naudojant failų rūšiavimą<br>
5 - testuoti class<br>
6 - baigti darbą<br>
<br>
Pasirinkus **1** variantą vartotojas gali pasirinkti kaip įvesti studentų duomenis:<br>
1 - įvedimas ranka <br>
2 - generuoti pažymius <br>
3 - generuoti ir pažymius ir studentų vardus, pavardes<br>
4 - baigti darbą<br>
Gaunami duomenys yra įrašomi programos pabaigoje į lentelė su studentų vardais, pavardėmis ir jų galutiniais įvertinimais (jie skaičiuojami pasirinkus medianą ar vidurkį).<br>
<br>
Pasirinkus **2** variantą vartotojas gali pasirinkti su kuriuo duomenų failu nori dirbti:<br>
1 - iš sugeneruoto duomenu failo 'kursiokai.txt'<br>
2 - iš testavimo failo su 10000 studentų duomenų<br>
3 - iš testavimo failo su 100000 studentų duomenų<br>
4 - iš testavimo failo su 1000000 studentų duomenų<br>
5 - baigti darbą<br>
Duomenys yra nuskaitomi iš pasirinkto failo. Vartotojas taip pat turi galimybę pasirinkti kaip nuskaityti failai bus rūšiuojami:<br>
1 - pagal studento vardą<br>
2 - pagal studento pavardę<br>
3 - pagal studento galutinį įvertinimą su vidurkiu<br>
4 - pagal studento galutinį įvertinimą su mediana<br>
<br>
Pasirinkus **3** variantą vartotojas gali pasirinkti kokio dydžio failus jis nori sukurti:<br>
1 - su 1000 studentų duomenų<br>
2 - su 10000 studentų duomenų<br>
3 - su 100000 studentų duomenų<br>
4 - su 1000000 studentų duomenų<br>
5 - su 10000000 studentų duomenų<br>
6 - baigti darbą<br>
<br>
Pasirinkus **4** variantą vartotojas gali testuoti programos laiką, rūšiuojant failus su pasirinktu konteineriu:<br>
1 - vector<br>
2 - list<br>
3 - deque<br>
4 - baigti darbą<br>
<br>
Pasirinkus **5** variantą vartotojas gali testuoti ar klasė veikia tinkamai naudojant RULE OF FIVE.<br>
<br>
[V1.1](https://github.com/EligMaa/Darbas_2/tree/v1.1) - šioje versijoje studentai saugomi class objektuose, ištestuotas struct ir class greitis<br>
[V1.2](https://github.com/EligMaa/Darbas_2/tree/v1.2) - šiai užduočiai reikėjo realizuoti visus reikiamus "Rule of five" ir įvesties/išvesties operatorius turimai Studentas klasei.<br>
[V1.5](https://github.com/EligMaa/Darbas_2/tree/v1.5) - šioje versijoje reikėjo vietoje turimos v1.2 klasės Studentas sukurti dvi: bazinę (abstrakčią) klasę, skirtą bendrai aprašyti žmogų ir tuomet iš jos išvestinę (derived) klasę.<br>
