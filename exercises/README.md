# Operații pe biți și măști pe biți 🫠

**Înainte de a rezolva exercițiile, citiți [textul laboratorului](https://ocw.cs.pub.ro/courses/programare/laboratoare/lab07).**

### EASY

1. Creează un fișier `ex1.c`.

**`void print_bits(int x)`**

Afișează toți bitii unui număr întreg x, cu un spațiu după fiecare byte, începând de la bitul 31 (cel mai semnificativ) și mergând spre bitul 0 (cel mai puțin semnificativ).

*Exemple de rulare:*
```sh
./ex1.out
> Input:
268

> Output:
00000000 00000000 00000001 00001100
```

2. Creează un fișier `ex2.c`.

**`int count_bits(int x)`**

Numără și returnează câți biți de valoare 1 sunt în reprezentarea binară a numărului întreg x.

*Exemplu de rulare:*
```sh
./ex2.out
> Input:
268
# 00000000 00000000 00000001 00001100

> Output:
3
```

### MEDIUM

3. Creează un fișier `ex3.c`.

**`to_big_endian(int x)`**

Scrieți o funcție care primește un număr întreg x și returnează reprezentarea sa în format big-endian (în ordinea octeților de la cel mai semnificativ la cel mai puțin semnificativ).
Afișați reprezentarea binară (ca la ex 1) a numărului întreg x în format big-endian și numărul în sine.


*Exemple de rulare:*
```sh
./ex3.out
> Input:
268
# 00000000 00000000 00000001 00001100

> Output:
201392128
00001100 00000001 00000000 00000000
```

4. Creează un fișier `ex4.c`.

Storyline: Să zicem că ne plac jocurile video și, după cursul de programare, vrem să creăm un joc și să ni-l rulăm pe un microcontroller,
să facem un fel de consolă portabilă.
Suntem studenți, bani de componente prea potente nu avem, așa că ne mulțumim cu un microcontroller cu câțiva KB de memorie,
deci trebuie să fim cât mai eficienți cu spațiul de memorie pe care îl avem ca să păstrăm cât mai multă memorie pentru jocul în sine,
grafici etc.

Setările ar putea consuma destul de mult spațiu dacă am folosi un întreg pentru fiecare în parte, iar cum acestea sunt doar
de tip on/off sau au doar câteva valori, am putea folosi un singur bit / 2 biți pentru fiecare setare și să le stocăm pe toate într-un întreg.

Citindu-se de la tastatură un întreg x, să se afișeze valorile setărilor, fiecare pe câte un rând, astfel (cei mai puțin semnificativi biți):
- bitul 1: reprezintă setarea de sunet (on/off)
- biții 2 și 3: reprezintă setarea de lumină: configurabil pe 4 niveluri: 00 - off, 01 - low, 10 - medium, 11 - high
- biții 4 și 5: reprezintă dificultatea jocului (easy/medium/hard): 00 - easy, 01 - medium, 10 - hard
- bitul 6: reprezintă dacă meniul este pe ecran sau nu
- bitul 7: reprezintă dacă jocul s-a terminat sau nu

Folosiți măști pe biți pentru a extrage valorile setărilor 🙂

*Exemple de rulare:*
```sh
./ex4.out
> Input:
71 # (01000111)

> Output:
Sound: on
Light: high
Difficulty: easy
Menu: not shown
Game over: yes
```

5. Creați un fișier `ex5.c`

**`int flip_odd_bytes(int x)`**

Face toggle (schimbă între 0 și 1) tuturor bitilor din acei bytes ai numărului întreg x care au valoare impară.

*Exemple de rulare:*
```sh
./ex5.out
> Input:
2467277397
# 10010011 00001111 10101010 01010101
#  impar     impar     par     impar

> Output:
1827711658
# 01101100 11110000 10101010 10101010
```

### ADVANCED

6. Creați un fișier `ex6.c` (examen iarnă 2023).

Se declară `perioada`, un întreg de tip `char` (8 biți) fără semn.
Folosindu-vă de operații pe biți și măști pe biți, codificați în `perioada` următoarele informații:
- cei mai semnificativi 4 biți reprezintă ora de început a unui interval orar (8 - 23).
- cei mai neînsemnificativi 4 biți reprezintă ora de sfârșit a intervalului orar (8 - 23).
De avut în vedere că putem avea numere de 5 biți (16 - 23). Cum se va rezolva această situație?
pentru a încăpea pe 4 + 4 = 8 biți?

Se citesc de la tastatură 4 caractere, primele două reprezentând ora de început a intervalului orar, iar ultimele două reprezentând ora de sfârșit a intervalului orar.
Afișați pe ecran numărul rezultat în urma codificării.

HINT: Nu folosim deloc intervalul 0 - 7, cum putem folosi acele valori?

*Exemple de utilizare:*
```sh
./ex6.out
> Input:
"0810" # ora de inceput 8, ora de sfarsit 10

> Output:
2
# 0000  |  0010
# 8 (0) |  10 (2)

./ex6.out
> Input:
"1423" # ora de inceput 15, ora de sfarsit 22

> Output:
111
# 0110   |  1111
# 14 (6) | 23 (15)
```
