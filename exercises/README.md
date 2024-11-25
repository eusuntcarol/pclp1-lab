# Tablouri multidimensionale (statice, nu alocate dinamic)

**Înainte de a rezolva exercițiile, citiți [textul laboratorului](https://ocw.cs.pub.ro/courses/programare/laboratoare/lab06).**

### EASY

1. Creează un fișier `ex1.c`.

Citiți de la tastatură o matrice (puteți hardcoda dimensiunea maximă a matricei). Afișați matricea transpusă.

*Exemple de rulare:*
```sh
./ex1.out
> Input:
2 4		// număr de linii urmat de număr de coloane din matrice
1 2 3 4
5 6 7 8

> Output:
1 5
2 6
3 7
4 8
```

2. Creează un fișier `ex2.c`.

Citiți de la tastatură 2 matrice (puteți hardcoda dimensiunea maximă a matricelor)
– prima matrice numită în continuare A, iar a doua B. Determinați dacă este posibilă
operația de înmulțire de matrice folosind drept operanzi cele două matrice.
Determinați toate rezultatele posibile și afișati-le la consolă, precizând ordinea
în care s-au înmulțit operanzii. Dacă nu se poate efectua nicio operație de înmulțire,
afișați mesajul "Nu se poate efectua operatia de inmultire cu aceste matrice!".

Vă recomand să faceți o funcție ca să vă fie mai ușor la exercițiul următor 🙂.

*Exemplu de rulare:*
```sh
./ex2.out
> Input:
2 2		// număr de linii urmat de număr de coloane din matricea A
1 2
3 4
2 2		// număr de linii urmat de număr de coloane din matricea B
5 6
7 8

> Output:
A * B
19 22
43 50

B * A
23 34
31 46
```

### MEDIUM

3. Creează un fișier `ex3.c`.

Pornind de la programul anterior, permiteti citirea a `n` matrice, salvați-le într-un vector (deci o să aveți 3 dimensiuni).
Pe aceste matrice verificați care oricare două se pot înmulți și afișați rezultatele.

*Exemple de rulare:*
```sh
./ex3.out
> Input:
3       // se vor citi 3 matrice
2 2		// număr de linii urmat de număr de coloane din matricea M[0]
1 2
3 4
2 2		// număr de linii urmat de număr de coloane din matricea M[1]
5 6
7 8
2 2		// număr de linii urmat de număr de coloane din matricea M[2]
9 10
11 12

> Output:
M[0] * M[1]
19 22
43 50

M[0] * M[2]
31 34
71 78

M[1] * M[0]
23 34
31 46

M[1] * M[2]
111 122
151 166

M[2] * M[0]
39 58
47 70

M[2] * M[1]
115 134
139 162
```

### ADVANCED

4. Creați un fișier `ex4.c`.

Ne propunem sa logăm performanța angajaților unor companii în fiecare zi din lună, în mai mulți ani.
Pentru a mapa această problemă, ne vom folosi de un vector static, de 5 dimensiuni.

```v[companie][angajat][an][luna][zi]```

Vom considera că avem maxim 3 companii, cu maxim 5 angajați fiecare.
Pentru ani, vom folosi o notație relativă, de exemplu, v[0] va reprezenta anul curent, iar v[1]
va reprezenta anul trecut etc...
Vom avea maxim 3 ani.
Pentru fiecare zi, fiecare angajat primește un calificativ, între 0 și 5 care reprezintă gradul
de productivitate din ziua respectivă.
Să se afișeze, pe rând, cel mai productiv angajat de la fiecare companie, iar apoi cea mai productivă
companie overall.
Toate zilele care nu sunt primite ca intrare, se vor considera având calificativul 0.
Pentru a determina gradul de productivitate al unui angajat, se va face media aritmetică pentru
toate zilele în care a primit un calificativ (deci diferit de 0).

*Exemple de utilizare:*
```sh
./ex6.out
> Input:
2   # avem 2 companii
2   # avem 2 angajati la prima companie
5   # avem 5 intrări de productivitate pentru primul angajat
1 1 2024 10 # primul angajat are calificativul 10 pentru data 1.1.2024
1 2 2024 7
1 3 2024 5
1 4 2024 5
1 5 2024 3
3   # avem 3 intrări de productivitate pentru al doilea angajat
1 2 2024 9 # al doilea angajat are calificativul 9 pentru data 1.1.2024
1 2 2024 7
1 3 2024 5
3   # avem 3 angajati la a doua companie
2   # avem 2 intrări de productivitate pentru primul angajat
1 4 2024 5
1 5 2024 3
3   # avem 3 intrări de productivitate pentru al doilea angajat
1 3 2024 10
1 4 2024 5
1 5 2024 3
1   # avem 1 intrare de productivitate pentru al treilea angajat
1 3 2024 7

> Output:
Compania 0 are angajatul productiv 1 cu media 6.33
# Angajat 0 are media 6, iar angajat 1 are media 6.33
Compania 1 are angajatul productiv 2 cu media 7 
# Angajat 0 are 6.5, angajat 1 are 6, iar angajat 2 are 7
Cea mai productiva companie 1
# Comparand mediile celor mai productivi angajati de la ambele companii,
# observam ca acesta este la compania a doua
```
