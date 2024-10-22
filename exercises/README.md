# Funcții, iterativ vs. recursiv

### EASY

1. Creați un fișier `ex1.c`.

**i.** Scrie un program care citește de la tastatură un număr natural `n`, iar apoi apelează o funcție *iterativă*, `sum_iter`, care citește `n` numere naturale și întoarce suma acestora. Rezultatul se afișează la stdout (pe ecran).

**ii.** Pornind de la funcția anterioară, scrie o funcție *recursivă*, `sum_rec`, care rezolvă aceeași problemă.

*Exemplu de rulare:*
```sh
./ex1.out
3
1 2 3
> Output: 6
```

2. Creați un fișier `ex2.c`.

Scrie un program care conține o funcție *recursivă* care verifică dacă un număr citit de la tastatură este palindrom.<br>
*Un număr se consideră palindrom dacă citit invers este identic cu numărul iniţial.*

*Exemple de rulare:*
```sh
./ex2.out
121
> Output: "PALINDROM"

./ex2.out
1234
> Output: "NU E PALINDROM"
```


3. Creează un fișier `ex3.c`.
(**EXTRA**, treci la următorul și dacă mai ai timp te întorci aici)

**i.** Extinde funcționalitatea programului pe care l-ai scris în `ex2.c` astfel încât să permită citirea a oricât de multe numere și verifică dacă aceste numere respectă condiția de palindrom.<br>
*Programul se oprește la întâlnirea unui număr negativ.*<br>
*Side note: **NU** trebuie să folosiți vectori, lucrați cu numărul odată cu citirea lui.*

**ii.** Adaptează codul astfel încât să folosiți `break`, dacă nu ai folosit deja.

**iii.** Folosește, pe rând, atât `while`, cât și `do ... while`. Explică care sunt diferențele.

*Exemplu de rulare:*
```sh
./ex3.out
121
> Output: "PALINDROM"
1123211
> Output: "PALINDROM"
1234
> Output: "NU E PALINDROM"
-1
> Output: "STOP"
```


### MEDIUM

4. Creează un fișier `ex4.c`.

Scrie o funcție cu semnătura `int replace(int n, int x, int y)` care înlocuiește toate aparițiile cifrei `x` din `n` cu cifra `y`.

*Exemplu de folosire:*
```sh
replace(503554455, 5, 8)

> Return: 803884488
```

5. Creează un fișier `ex5.c`.

Scrie o funcție recursivă care citește numere încontinuu până la citirea unui număr negativ.<br>
Când se îndeplinește condiția de oprire, se vor afișa pe ecran numărul de numere pare, impare, suma numerelor pare și a celor impare.

**Q:** Ai cum să faci funcția asta fără să transmiți ca parametru datele calculate?

*Exemplu de rulare:*
```sh
./ex5.out
1 2 3 4 5 -1
> Output: "Even: 2, Odd: 3
Even sum: 6, Odd sum: 9"
```

### ADVANCED

6. Creați un fișier `ex6.c`.

Scrieți un program care convertește un număr din baza 10 în baza 2.<br>
Dacă s-au calculat mai puțin de 32 de biți, restul până la 32 îi considerăm 0 (padding).<br>
Afișați biții grupați câte 8 (grupați în bytes).

*Exemplu de rulare:*
```sh
./ex6.out
5
> Output: 00000000 00000000 00000000 00000101
```

**HINT**: Există vreo instrucțiune specială care v-ar putea ajuta să printați padding-ul?

7. Creați un fișier `ex7.c`.

Scrieți un program care convertește un număr din baza 2 în baza 10.<br>
De la tastatură se citesc biții cei mai din stânga (least significant bits). Restul până la 32 îi considerăm 0 (padding).

*Exemplu de rulare:*
```sh
./ex7.out
101
> Output: 5
```
