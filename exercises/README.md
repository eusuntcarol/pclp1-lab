# Structuri

**Înainte de a rezolva exercițiile, citiți [textul laboratorului](https://ocw.cs.pub.ro/courses/programare/laboratoare/lab11).**

**TOATE EXERCIȚIILE SE SALVEAZĂ ÎNTR-UN SINGUR FIȘIER `lab10.c`**

### EASY

1.
Creați un `enum` care să descrie mai multe tipuri de sateliți:
- `SATELLITE_TEMP` cu valoarea `2`
- `SATELLITE_RAINFALL` cu valoarea neprecizată, deci, ce valoare va primi automat?
- `SATELLITE_IS_WATER` cu valoarea `6`
- `SATELLITE_COMMUNICATION` cu valoare neprecizată, ce valoare va avea?

2.
Creați o structură `Satellite` care să conțină următoarele câmpuri:
- `name` - un șir de caractere alocat dinamic
- `type` - un enum de tipul `SatelliteType` (definit anterior)
- `latitude` - un întreg
- `longitude` - un întreg
- `data` - un union care să conțină:
    - `temperature` - un întreg
    - `rainfall` - un byte (0 sau 1)
    - `isWater` - un byte (0 sau 1) - 1 dacă este apă, 0 altfel, de ex. pământ
    - `message` - un șir de caractere alocat dinamic

### MEDIUM

3.
Se citește de la tastatură un număr `n` de sateliți.
Se alocă dinamic un vector de `n` sateliți și se completează datele pentru fiecare satelit (decideți voi cum citiți datele, cât să respecte structura `Satellite`).

Pentru fiecare tip de satelit, se va actualiza câmpul `data` astfel:
- `data.temperature` - pentru tipul `SATELLITE_TEMP`
- `data.rainfall` - pentru tipul `SATELLITE_RAINFALL`
- `data.isWater` - pentru tipul `SATELLITE_IS_WATER`
- `data.message` - pentru tipul `SATELLITE_COMMUNICATION`

Alocați memorie pentru `name` și `message` oricât vreți

4.
Scrieți o funcție care primește un pointer la un satelit și afișează toate datele despre acel satelit în funcție de tipul său.

5.
Bazându-vă pe vectorul de sateliți, afișați toate datele despre sateliți, folosind funcția de la punctul anterior.

6.
Citind de la intrare o longitudine și o latitudine, afișați toți sateliții care se află în acea poziție, inclusiv datele despre ei.

7.
Citind de la tastatură un anumit tip de satelit, afișați toți sateliții de acel tip, inclusiv datele despre ei.

### ADVANCED

8. 
După un număr folosiri, sateliții încep să se oprească (❗️❗️❗️❗️ cei care i-au proiectat au uitat să dea FREE la memoria alocată ❗️❗️❗️❗️).

Folosind `rand() % 3`, opriți un satelit dacă valoarea este 0 și adăugați acest satelit la un vector de sateliți opriți.
Adăugați un câmp `stopped` în structura `Satellite` care să fie 1 dacă satelitul este oprit și 0 altfel.
Un satelit oprit nu mai poate fi folosit pentru a citi date.

Vectorul de sateliți opriți va fi de tipul `SatelliteStopped[]`, care va conține:
- un pointer la satelitul oprit
- un vector static de 31 de caractere **printabile** care să conțină responsabilul care trebuie să pornească satelitul (de exemplu, "baiatul cu ciocanul")

9.
Sortați sateliții (`qsort`) în funcție de temperatură și afișați-i.

10. (actually easy :) )
Se dealocă memoria toată memoria alocată în tot programul.