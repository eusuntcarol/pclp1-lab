# Tablouri, vectori unidimensionali

**Înainte de a rezolva exercițiile, citiți [textul laboratorului](https://ocw.cs.pub.ro/courses/programare/laboratoare/lab05).**

**Pentru notarea acestui laborator vom folosi scripturi de testare automată.**

**În timp ce rezolvați, rulați manual programele, iar când sunteți siguri că ați terminat, rulați scriptul aferent exercițiului pentru a testa corectitudinea.**

**Pentru a descărca scripturile, urmați pașii:**
1. `git clone https://github.com/eusuntcarol/pclp1-lab` - descarcă repository cu laboratoarele
2. `cd pclp1-lab` - navigăm în directorul descărcat
3. `git fetch origin` - descărcăm toate "ramurile" proiectului
4. `git checkout lab4` - schimbăm "ramura" pe cea a laboratorului de azi
5. `cd exercises` - navigăm în directorul cu exerciții
6. `chmod +x *.sh` - facem toate scripturile executabile
7. Pentru testarea unui exercițiu folosește `./check.sh <nr_exercitiu>`
8. Pentru rularea tuturor testelor folosește `./all.sh`

### EASY

1. Creați un fișier `ex1.c`.

Se citesc de la tastatură un număr natural `n`, apoi `n` numere naturale sortate **descrescător**.<br>
Să se stabilească, folosind căutarea binară, dacă un număr `c` citit de la tastatură aparține vectorului citit anterior.

*Exemple de rulare:*
```sh
./ex1.out
> Input:
7
342 314 223 221 182 112 45
314

> Output: "DA"

./ex1.out
> Input:
7
342 314 223 221 182 112 45
999

> Output: "NU"
```

2. Creați un fișier `ex2.c`.

Citește un vector de întregi strict mai mari decât 0 de la tastatură. Te vei opri din citit elemente ale vectorului într-una din situațiile următoare:
- ai citit deja N = 10 de elemente
- ai citit de la tastatură valoarea 0 sau o valoare negativă (aceasta NU trebuie adăugată în vector)
Afișează, la ieșirea standard, pe câte o linie nouă, indicele fiecărei valori impare din vector împreună cu valoarea propriu-zisă sub forma `<indice> : <valoare>`. La final, pe o linie nouă, afișați numărul total de elemente impare din vector. Considerați că primul element din vector se află pe poziția 0.

*Exemple de rulare:*
```sh
./ex2.out
> Input:
3 5 2 7 10 5 0

> Output:
0 : 3
1 : 5
3 : 7
5 : 5
4
```

### MEDIUM

3. Creează un fișier `ex3.c`.
Se citesc de la tastatură un număr natural `n`, apoi `n` numere naturale sortate **crescător**.<br>
Apoi, se citesc de la tastatură un număr natural `m`, apoi `m` numere naturale sortate **descrescător**.<br>
Aplicați algoritmul de interclasare pe acești doi vectori. Vectorul rezultat va avea valorile în ordine crescătoare.


*Exemplu de rulare:*
```sh
> Input:
7
1 3 3 5 6 7 11
5
8 4 4 3 2

> Output:
1 2 3 3 3 4 4 5 6 7 8 11
```

4. Creează un fișier `ex4.c`.

O adresă IPv4 este de forma `A.B.C.D`, unde `A`, `B`, `C` și `D` sunt întregi cu valori între `0` și `255`.<br>
Se citesc de la tastatură un număr natural `n`, iar apoi `n` adrese IPv4 diferite, constituind un pool de adrese folosite într-o rețea.<br>
După citirea acestui pool, se citește de la tastatură încă o adresă IPv4. Să se stabilească dacă această adresă este folosită sau nu.<br>
Adresele din pool se vor memora sub forma unui vector, după cum urmează:
```c
v[i * 4 + 0] = A
v[i * 4 + 1] = B
v[i * 4 + 2] = C
v[i * 4 + 3] = D
```
Dă o dimensiune corespunzătoare vectorului, astfel încât să poată memora până la 1024 de adrese.<br>
Cum ai putea folosi `#define` ca să-ți fie mai ușor adaptarea codului dacă vrei să modifici numărul de adrese care pot fi memorate?

*Exemple de rulare:*
```sh
./ex5.out
> Input:
3
10.10.10.1
10.10.11.2
10.10.11.3
10.10.11.1

> Output: "NEFOLOSIT"

./ex5.out
> Input:
3
10.10.11.1
10.10.11.2
10.10.11.3
10.10.11.1

> Output: "FOLOSIT"
```

### ADVANCED

5. Creați un fișier `ex5.c`.

Scrie un program care convertește un număr întreg (32 de biți) din baza 10 în baza 2.<br>
Biții se vor salva într-un vector unidimensional.<br>
Afișează biții grupați câte 8 (grupați în bytes).

*Exemplu de rulare:*
```sh
./ex6.out
5
> Output: 00000000 00000000 00000000 00000101
```

6. Creați un fișier `ex6.c`.

Extinde codul scris la exercițiul anterior și convertește două numere întregi (32 de biți) din baza 10 în baza 2.<br>
Folosindu-te de cei doi vectori generați și de biți, implementați suma acestor două numere.<br>
Rezultatul va fi salvat tot pe biți într-un alt vector.<br>
Afișează, pe rând, cele două numere convertite și rezultatul, după cum e prezentat în exemplu.<br>
*P.S.:* Consideră numerele fără semn. Nu te preocupa de overflow. Dacă numărul introdus depășește 32 de biți, folosește doar cei mai nesemnificativi 32 de biți (cei din dreapta). Rezultatul va fi tot pe 32 de biți.

*Exemplu de rulare:*
```sh
./ex7.out
5 11

> Output:
A = 5 = 00000000 00000000 00000000 00000101
B = 11 = 00000000 00000000 00000000 00001011
A + B = 16 = 00000000 00000000 00000000 00010000


./ex7.out
5 11

> Output:
A = 2147483649 = 10000000 00000000 00000000 00000001
B = 2147483649 = 10000000 00000000 00000000 00000001
A + B = 2 = 00000000 00000000 00000000 00000010
```
