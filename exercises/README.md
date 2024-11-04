# Tablouri, vectori unidimensionali

**Înainte de a rezolva exercițiile, citiți [textul laboratorului](https://ocw.cs.pub.ro/courses/programare/laboratoare/lab08).**

**Pentru notarea acestui laborator vom folosi scripturi de testare automată.**

**În timp ce rezolvați, rulați manual programele, iar când sunteți siguri că ați terminat, rulați scriptul aferent exercițiului pentru a testa corectitudinea.**

**Pentru a descărca scripturile, urmați pașii:**
1. `git clone https://github.com/eusuntcarol/pclp1-lab lab5`
2. `cd lab5`
3. `git fetch origin lab5`
4. `git checkout lab5`
5. `cd exercises`
6. `chmod +x *.sh`
7. Pentru testarea unui exercițiu folosește `./check.sh <nr_exercitiu>`
8. Pentru rularea tuturor testelor folosește `./all.sh`

### EASY

1. Creați un fișier `ex1.c`.

Scrieți o funcție care interschimbă două numere întregi.

*Exemplu de rulare:*
```sh
./ex1.out
> Input:
a = 2
b = 5

> Output:
a = 5
b = 2
```

2. Deschide fișierul `ex2.c`.

Programul conține niște erori intenționate.<br/>
Corectează-le și explică de ce sunt greșite.<br/>
Aplică modificări **doar** la referențierile sau dereferențierile lui `p`.<br/>
Programul ar trebui să adauge 10 la valoarea lui `a` prin intermediul lui `p`.

*HINT:* Compilează programul manual și observă warning-urile, te vor ajuta să
identifici greșelile.

### MEDIUM

3. Creează un fișier `ex3.c`.

Știind că un vector `v` este prin definiție un pointer constant către prima
poziție din vector, scrieți un program care citește un număr natural `n`,
apoi `n` numere, iterează prin vector și actualizează fiecare element
împărțindu-l la `i + 1`, unde `i` este indexul elementului curent.<br>
Toate accesările elementelor vectorului se vor face folosind pointerul `v`
și aritmetica pointerilor  (adică nu veți folosi `v[i]`).

Afișează vectorul rezultat, elementele fiind separate printr-un spațiu.

Vectorul poate avea cel mult 128 de elemente (folosiți `#define` - good practice).<br/>
În teste pot apărea mai mult de 100 de elemente, aveți grijă să tratați corect această situație.

*Exemplu de rulare:*
```sh
> Input:
7
1 3 3 5 6 7 11

> Output:
1 1 1 1 1 1 1
```

4. Creează un fișier `ex4.c`.

Scrieți o funcție care interclaseaza doi vectori de numere întregi,
primul vector fiind sortat **descrescător**, iar al doilea **crescător**.<br>
Funcția trebuie să aibă următoarea semnătură:
```c
void merge(int *a, int n, int *b, int m, int *c, int *k);
```
unde:
- `a` este primul vector
- `n` este numărul de elemente din primul vector
- `b` este al doilea vector
- `m` este numărul de elemente din al doilea vector
- `c` este vectorul rezultat
- `k` este numărul de elemente din vectorul rezultat

*Exemplu de rulare:*
```sh
./ex4.out
> Input:
5
8 4 4 3 2
7
1 3 3 5 6 7 11

> Output:
1 2 3 3 3 4 4 5 6 7 8 11
```

### ADVANCED

5. Creați un fișier `ex5.c`.

Citește despre [pointeri la funcții](../examples/README.md) înainte să începi.

Ne propunem să scriem mai multe funcții care respectă o anumită "interfață".
Cu alte cuvinte, toate funcțiile vor avea o semnătură asemănătoare,
dar comportamentul lor va fi diferit.<br>

În programarea funcțională (cu care vă veți lupta la anu'), există 3 tipuri
de operații:
- **map**, care aplică o funcție pe fiecare element dintr-un vector
- **filter**, care elimină elementele care nu respectă o anumită condiție
- **reduce**, care combină elementele dintr-un vector într-un singur element,
de exemplu, suma lor

Aceste funcții vor avea următoarea semnătură:
```c
// v este vectorul
// n este numărul de elemente din vector
// f este funcția care se aplică pe fiecare element din vector
// parametrul lui f este un pointer la elementul din v pe care
//      se aplică f
// funcția map va efectua modificările in-place, adică va modifica
//      direct valorile din vectorul v
void map(int *v, int n, void (*f)(int *));


// v este vectorul
// n este numărul de elemente din vector
// cond este funcția care verifică condiția și returnează 1
//      dacă elementul trebuie păstrat, 0 altfel
// parametrul lui f este un pointer la elementul din v pe care
//      se verifică condiția
// funcția filter va efectua modificările in-place, adică direct
//      în vectorul v (nu va crea un nou vector), deci n va fi modificat
void filter(int *v, int *n, int (*cond)(int *)); 


// v este vectorul
// n este numărul de elemente din vector
// f este funcția care combină elementele
// f va primi 2 parametri, elementele din vector
// reduce va returna rezultatul combinării elementelor
// în general, unul dintre parametrii lui f va fi rezultatul parțial
//      al operației
int reduce(int *v, int n, int (*f)(int, int)); 
```

Pentru mapări, vom considera următoarele aplicații:
- `add_1` care adună 1 la fiecare element
- `mul_2` care înmulțește fiecare element cu 2
- `square` care ridică fiecare element la pătrat

Pentru filtrare, vom considera următoarele condiții:
- `is_even` care returnează 1 dacă elementul este par, 0 altfel
- `less_than_1000` care returnează 1 dacă elementul este mai mic decât 1000, 0 altfel

Pentru reducere, vom considera următoarele operații:
- `sum` care adună elementele
- `product` care înmulțește elementele
- `max` care returnează maximul elementelor
- `min` care returnează minimul elementelor

Pentru fiecare secțiune, se definește, global, câte un vector, după cum urmează:
```
MAPPERS[0] = add_1
MAPPERS[1] = mul_2
MAPPERS[2] = square

FILTERS[0] = is_even
FILTERS[1] = less_than_1000

REDUCERS[0] = sum
REDUCERS[1] = product
REDUCERS[2] = max
REDUCERS[3] = min
```
Acestea sunt definite în pseudocod, stabiliți voi tipurile corespunzătoare
pentru vectori.

Mai departe, se va citi un număr `n` și apoi `n` numere întregi, care vor
fi stocate într-un vector.<br>
Se citește un număr `c` care reprezintă numărul de comenzi care vor fi
aplicate pe vector.<br>

Comenzile vor fi de forma: `<tip> <index>`, `MAPPERS` având tipul `1`,
`FILTERS` `2` și `REDUCERS` `3`.<br>
Deci, dacă se citește `0 2`, se va aplica `square` pe vector, dacă se citește
`1 1`, se va aplica `less_than_1000` pe vector, iar dacă se citește `2 3`,
se va aplica `min` pe vector.<br>
După fiecare comandă, se va afișa vectorul sau rezultatul reducerii.

*Exemplu de rulare:*
```sh
./ex5.out
> Input:
5           # numărul de elemente din vector
1 2 3 4 5   # vectorul
5           # numărul de comenzi
0 0         # add_1
1 0         # is_even
0 2         # square
0 1         # mul_2
2 0         # sum

> Output:
2 3 4 5 6   # vectorul rezultat după add_1
2 4 6       # vectorul rezultat după is_even
4 16 36     # vectorul rezultat după square
8 32 72     # vectorul rezultat după mul_2
112         # suma elementelor din vectorul final
```
