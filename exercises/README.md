# Alocarea dinamică a memoriei

**Înainte de a rezolva exercițiile, citiți [textul laboratorului](https://ocw.cs.pub.ro/courses/programare/laboratoare/lab09).**

❗️ Nu uitați de programarea defensivă, verificați toate adresele întoarse - "sanity checks" ❗️

### EASY

1. Creează un fișier `ex1.c`.

Se citesc trei numere întregi: `n`, `k`, și `p`.
Se alocă dinamic un vector de dimensiune `n` și se inițializează cu zero.
Se citesc `p` valori care sunt plasate în vector de la poziția k până la
k + p - 1.
Se afișează toate elementele vectorului.
Se eliberează memoria alocată pentru vector.

*Exemplu de rulare:*
```sh
./ex1.out
> Input:
10 3 5      # n, k, p
1 2 3 4 5   # p numere

> Output:
0 0 0 1 2 3 4 5 0 0
```

### MEDIUM

2. Creează un fișier `ex2.c`.

Se citesc doi întregi `n` și `m`.

Se alocă dinamic o matrice de dimensiune `n x m` și se inițializează
elementele acesteia cu `1` (vezi o funcție din `string.h`).

Se citesc două numere `extraLines` & `extraCols`, reprezentând numărul de
linii, respectiv coloane cu care vom extinde matricea originară.

Adăugați, inițial, `extraLines` linii și inițializați noile elemente cu `2`.
Apoi, extindeți noua matrice cu încă `extraCols` coloane și inițializați
elementele acestora cu `3`.

Afișați matricea finală.

Eliberați memoria alocată pentru matrice și submatrice.

*Exemplu de rulare:*
```sh
./ex2.out
> Input:
2 3     # n, m
3 2     # extraLines, extraCols

> Output:
1 1 1 3 3
1 1 1 3 3
2 2 2 3 3
2 2 2 3 3
2 2 2 3 3
```

3. Creează un fișier `ex3.c`.
Scrieți un program care gestionează o listă de studenți utilizând
un vector de șiruri de caractere alocat dinamic.

Fiecare șir de caractere reprezintă numele unui student.
Programul trebuie să permită utilizatorului să adauge, să șteargă, să afișeze
și să caute un student în listă.

Precizări:
- lista de studenți este caracterizată prin două mărimi:
`size` (număr curent de elemente), respectiv `capacity` (capacitate maximă)
- capacitatea maximă a listei este inițial 1
- numărul curent de elemente este inițializat cu 0 și actualizat la fiecare
operație de inserare / ștergere din listă
- adăugarea unui nou student se face pe prima poziție liberă găsită
- în cazul în care se atinge capacitatea maximă a listei, aceasta trebuie
realocată cu dublul capacității curente
- căutarea unui student în listă trebuie realizată folosind o funcție de
căutare binară, acest lucru presupune sortarea listei înaintea căutării
(opțional: folosiți funcția `qsort` și `bsearch` din `stdlib.h`).
- se va sorta lista doar inaintea unei operatii de cautare
- la exit de va elibera toata memoria

*Exemplu de rulare:*
```sh
./ex3.out
> Input:
# inputul este orientativ, alegeti voi cum introduceti comenzile
ADD Student 1
ADD Student 2
ADD AStudent 3
DELETE Student 4
SHOW 2
ADD AStudent 4
SHOW 2
FIND Student 5
FIND AStudent 3
SHOW ALL
DELETE Student 1
SHOW ALL
ADD Student 5
SHOW ALL
EXIT

> Output:
ADD: 'Student 1'     # size = 1, capacity = 1
ADD: 'Student 2'     # size = 2, capacity = 2, s-a realocat că nu mai avea loc
ADD: 'AStudent 3'    # size = 3, capacity = 4, s-a realocat că nu mai avea loc
DEL: nu a fost gasit 'Student 4'
SHOW 2: 'Student 1'  # Ordinea ar fi [Student 1; Student 2; AStudent 3]
                     # nu s-a sortat pentru ca nu a fost niciun find
ADD: 'AStudent 4'    # size = 4, capacity = 4
SHOW 2: 'AStudent 4' # Ordinea ar fi [Student 1; Student 2; AStudent 3; AStudent4]
                     # nu s-a sortat pentru ca nu a fost niciun find
FIND Student 5: NULL
FIND AStudent 3: 0xSOME_ADDRESS
SHOW ALL: [AStudent 3 (0xaddr); AStudent4 (0xaddr); Student 1 (0xaddr); Student 2 (0xaddr)]
                     # Ordinea ar fi [AStudent 3; AStudent4; Student 1; Student 2]
                     # s-a sortat, a fost find
DEL: succes 'Student 1' # size = 3, capacity = 4
SHOW ALL: [AStudent 3 (0xaddr); AStudent4 (0xaddr); NULL; Student 2 (0xaddr)]
ADD: 'Student 5'
SHOW ALL: [AStudent 3 (0xaddr); AStudent4 (0xaddr); Student 5 (0xaddr); Student 2 (0xaddr)]
EXIT: s-a eliberat memoria
```
