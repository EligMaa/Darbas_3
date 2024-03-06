## Ši programa yra skirta studentų galutiniam įvertinimui skaičiuoti.
### Vartotojas gali pasirinkti: duomenis gauti iš pareiktų failų, įvesti informaciją apie studentus ranka, generuoti atsitiktine tvarka studentų duomenis.
### Egzistuoja pasirinkimas skirtas programos greičiui išmatuoti. Sparta išmatuojama pagal kiek laiko užtruko kiekvienas iš žemiau išvardintų žingsnių:
#### • failų kūrimas ir jo uždarymas
#### • duomenų nuskaitymas iš failo
#### • studentų rūšiavimas į dvi grupes/kategorijas (į atskirus konteinerius)
#### • surūšiuotų studentų išvedimas į du naujus failus
#### • visos programos veikimo laikas
#### 
#### Tyrimas buvo atliktas su 1 000, 10 000, 100 000, 1 000 000, 10 000 000 įrašų. Sugeneruota po 20 namų darbų, o galutinis pažymys skaičiuojamas su vidurkiu.
![image](https://github.com/EligMaa/Darbas_1/assets/151032480/98e3febe-5ff2-4af2-89fe-42911d8a822b)
![image](https://github.com/EligMaa/Darbas_1/assets/151032480/38469017-a4c1-42e2-99d4-6c9840376208)
![image](https://github.com/EligMaa/Darbas_1/assets/151032480/25bf78be-e2eb-4376-8516-5496cb1b973e)
![image](https://github.com/EligMaa/Darbas_1/assets/151032480/079612b8-6d75-41f0-960b-e4cf5c2d31f8)
![image](https://github.com/EligMaa/Darbas_1/assets/151032480/112ff2f9-b933-49fc-ba78-d6e1f19bf94d)
#### Testavimas su 10 000 000 įrašų nepavyko, kadangi kompiuteris nepakelia tokio dydžio vektoriaus sukūrimo. 

| Failų  dydžiai |Failų sukūrimas | Failų skaitymas | Rūšiavimas į konteinerius | Vargšų  įrašymas į failą | Galvočių  įrašymas į failą | Iš viso užtruko  |
|-----------|----------|-----------|----------------|------------------|------------------|----------|
|      1 000| 0.018764 | 0.009964  |    0.001932    |     0.014498     |     0.003988     | 0.048846 |
|     10 000| 0.090841 | 0.103651  |    0.031795    |     0.04195      |     0.035881     | 0.304118 |
|    100 000| 0.753351 |  1.0625   |    0.36946     |     0.290834     |     0.409702     | 2.88585  |
|  1 000 000| 6.60534  |   9.89    |    4.61572     |     2.54418      |     4.12193      | 27.7772  |
| 10 000 000| 61.9845  |     -     |        -       |        -         |        -         |     -    |
#### Laiko vidurkiai atlikus testavimus su visais įrašais po 5 kartus:
#### • 1 000 - 0.03 s.
#### • 10 000 - 0.28 s.
#### • 100 000 - 2.78 s.
#### • 1 000 000 - 27.85 s.
