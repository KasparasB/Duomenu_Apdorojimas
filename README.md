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

*Pataisytas header failas
*Pridėtas funkcijų failas
*Pridėtas tikrinimas, ar pažymys nėra raidė
