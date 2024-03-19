# V1.0 pradinė
Programa apdoroja pasirinktus studentų failus ir skaičiuoja veikimo spartą naudojant skirtingus konteinerius: vector, list, deque.<br>
Testas atliekamas su CPU Intel Core i5, Tiger lake 11-a karta, 6 branduoliai, dažnis 2.7. GHz. Maksimalus operatyviosios (RAM) atminties kiekis 32 GB, taktinis dažnis	3200 MHz. Kietasis diskas	SSD (samsung mzalq512hblu-00bl2) M.2 2242 NVMe PCIE 3, talpa	512 GB. <br>
## Strategijos
**Pirma strategija:**<br>
Programos testavimas su VECTOR:<br>
![image](https://github.com/EligMaa/Darbas_1/assets/151032480/b3416ac6-acc5-4152-a278-5ab1a5a52c76)<br>
Programos testavimas su LIST:<br>
![image](https://github.com/EligMaa/Darbas_1/assets/151032480/7e46cc2c-0f8d-44b8-9a8f-5b064f3c642c)<br>
Programos testavimas su DEQUE:<br>
![image](https://github.com/EligMaa/Darbas_1/assets/151032480/2ad11dc4-2315-4528-9d11-eccd7ceff55d)<br>
<br>
**Antra strategija:**<br>
Programos testavimas su VECTOR:<br>
![image](https://github.com/EligMaa/Darbas_1/assets/151032480/a51d086a-1ca1-47cd-9963-07641ca27103)<br>
Programos testavimas su LIST:<br>
![image](https://github.com/EligMaa/Darbas_1/assets/151032480/09d34863-8ce1-4165-9fc5-91edcaa4df53)<br>
Programos testavimas su DEQUE:<br>
![image](https://github.com/EligMaa/Darbas_1/assets/151032480/d51f5859-031c-4367-8bd3-fd485590a3cc)<br>
<br>
**Trečia strategija:**<br>
Programos testavimas su VECTOR:<br>
![image](https://github.com/EligMaa/Darbas_1/assets/151032480/1da665d9-e74c-40e8-b22c-7ce9c4601e92)<br>
Programos testavimas su LIST:<br>
![image](https://github.com/EligMaa/Darbas_1/assets/151032480/78e93a47-1c09-4a25-a296-5d2f3bb9cf18)<br>
Programos testavimas su DEQUE:<br>
![image](https://github.com/EligMaa/Darbas_1/assets/151032480/6cf25d18-86e9-4b6f-9f6c-af1a33b0e548)<br>
<br>
Programos spartos palyginimas atsižvelgiant į rūšiavimo laiką su VECTOR konteineriais:<br>
|              |   1000   |   10000  |  100000  | 1000000  |
| ------------ | -------- | -------- | -------- | -------- |
| 1 strategija | 0.012241 | 0.108126 |  1.19830 | 13.0926  |
| 2 strategija | 0.035067 | 3.25702  |  322.892 | 33768.4  |
| 3 strategija | 0.000998 | 0.007093 | 0.067696 | 0.711148 |

Akivaizdu, kad rūšiavimas atliekamas žymiai greičiau naudojant trečią strategiją, kuri naudoja greitus rūšiavimo algoritmus, tokius kaip remove_if.<br>

## Programos paleidimas
1. Parsisiųskite failus iš pateikto linko: https://github.com/EligMaa/Darbas_1/releases/tag/V0.1 naudodami instrukciją pateiktą šiame linke: https://blog.hubspot.com/website/download-from-github <br>
2. Susiinstaliuokite VisualStudioCode pagal pateiktą linką: https://www.youtube.com/watch?v=DMWD7wfhgNY <br>
3. Parsisiųstą aplankalą atsidarykite VisualStudioCode. Įrankių juostoje paspauskite 'Terminal' -> 'New terminal' ir įveskite pateiktas eilutes: <br>
make pagrindine <br>
make funkcijos <br>
make prog <br>
./prog <br>
Programa jau paruošta naudoti.
## Naudojimo instrukcija
Paleidus programą egzistuoja meniu, kur vartotojas gali pasirinkti kaip nori dirbti su duomenimis:<br>
1 - duomenų įvedimas<br>
2 - duomenų skaitymas iš failo<br>
3 - programos laiko testavimas naudojant failų generavimą<br>
4 - programos laiko testavimas naudojant failų rūšiavimą<br>
5 - baigti darbą<br>
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
Pasirinkus **3** variantą vartotojas gali testuoti programos laiką, kuriant pasirinkto dydžio failus:<br>
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
