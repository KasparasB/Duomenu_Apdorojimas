# Duomenu Apdorojimas

Programa nuskaito:
* Studento vardą ir pavardę
* Automatiškai sugeneruoja:
1. Namų darbų skaičių (3-10)
2. Namų darbų pažymius (1-10)
3. Egzamino pažymį

Galima pasirinkti 2 skirtingus galutinio balo skaičiavimo būdus t.y., pagal medianą arba vidurkį

Duomenų nuskaitymas:

```shell

Kiek bus mokiniu: 2
Skaiciuoti pagal mediana ar vidurki? (1 - Mediana, 0 - Vidurkis)
1
Iveskite 1-ojo mokinio varda: Kasparas
Iveskite 1-ojo mokinio pavarde: Brazenas
Iveskite 2-ojo mokinio varda: Matas
Iveskite 2-ojo mokinio pavarde: Cenys

```
Duomenų išvedimas

```shell
Vardas   Pavarde  Galutinis (Med.)
___________________________________
Kasparas Brazenas 7.00
Matas    Cenys    6.60
```

Įkeltos dvi versijos: 
1. Atlikta su C masyvu
2. Atlikta su vektoriais

Versija su vektoriais turi daugiau pataisymų ir neleidžia vartotojui įvesti neteisingų duomenų

# v0.2 papildymas

Pridėtas header failas
Ištaisytos kai kurios klaidos
Patobulintas įvedimas (mažiau galimybių "užlaužti programą"
* Pridėta klaidingo failo apsauga
* Tikrinami mokinių vardai ir pavardės
* Žiūrima, ar mokinys turi daugiau nei vieną pažymį
* Mokiniai gali turėti skirtingus kiekius pažymių

Programa atpažįsta tekstinį failą TIK jeigu jo pirma eilutė atrodo štai taip:
```shell
Pavarde Vardas ND1 ND2 ND3 ND4 Egzaminas
```

MINUSAI:
netvarkingas ir ne optimalus kodas

# v0.3 papildymas

1. Pataisytas header failas
2. Pridėtas funkcijų failas
3. Pridėtas tikrinimas, ar pažymys nėra raidė


# v0.4 papildymas

Programos metu yra sukuriami 5 .txt failai (sudaryti iš: 1000, 10000, 100000, 1000000, 10000000 įrašų). Nebenaudojama funkcija tikrinti vardus ir pavardes, nes kuriami šabloniniai vardai su skaičiais.

Tuomet paskaičiuojami studentų rezultatai ir vardai su pavardėmis išvedami į atskirus failus pavadinimu "rezultatas.txt". Taip pat išvedami skirtingi failai mokiniams, kurių galutinis balas yra mažesnis nei 5 ir kurių balas yra lygus 5 arba didesnis.

Studentai yra surūšiuojami pagal vardus ir pavardes.

Programos spartos analizė atlikta su release mode (paimti duomenys suapvalinti iš 5 testų):


|Funkcija                     |n = 1000   |n = 10000     |n = 100000    |n = 1000000   |n = 10000000 |
|-----------------------------|----------|------------|------------|------------|-----------|
|Duomenų sukūrimas |0.009 s|0.09 s|0.87 s|8.581 s|86.05 s|
|Išvedimas|0.015        s|0.109         s|1.126 s|10.9 s|107.6 s|
|Išvedimas į 2 atskirus failus|0.007        s|0.053        s|0.532 s|5.486 s|55.86 s|
|Visas veikimo laikas|0.021        s|0.149        s|1.456 s|14.59 s|150.7 s|

Galimi neatitikimai su visu programos veikimo laiku dėl duomenų apvalinimo arba dėl netinkamose vietose pradedamo matuoti laiko.
