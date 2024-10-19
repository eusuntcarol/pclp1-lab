# Exerciții propuse pentru laboratorul 2

### RECAP FROM LAST LAB
 - Scrie un program într-un fișier denumit `warmup.c` care citește de la tastatură două numere naturale, le adună și afișează rezultatul pe ecran.
 - Ce e type overflow?

### EASY

1. Creați un fișier `ex1.c`.

**i.** Scrieți un program care citește de la tastatură un număr natural `n`, apoi `n` numere naturale și afișează suma acestora.

**ii.** Adaptați programul astfel încât să aibă aceeași funcționalitate, dar folosind o etichetă și `goto`.

*Exemplu de rulare:*
```sh
./ex1.out
3
1 2 3
> Output: 6
```

*Scop*: familiarizarea cu structurile repetitive

2. Creați un fișier `ex2.c`.

Scrieţi un program care verifică dacă un număr citit de la tastatură este palindrom.
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

*Scop*: familiarizarea cu structurile repetitive și condițiile

3. Creați un fișier `ex3.c`.

**i.** Extindeți funcționalitatea programului pe care l-ați scris în `ex2.c` astfel încât să permită citirea a oricât de multe numere și verifică dacă aceste numere respectă condiția de palindrom.
*Programul se oprește la întâlnirea unui număr negativ.*
*Side note: **NU** trebuie să folosiți vectori, lucrați cu numărul odată cu citirea lui.*

**ii.** Adaptați codul astfel încât să folosiți `break`, dacă nu ați folosit deja.

**iii.** Folosiți atât `while`, cât și `do ... while`. Explicați care sunt diferențele.

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
>Output: "STOP"
```

*Scop*: exersarea capacității de a extinde un cod deja existent + familiarizarea cu instrucțiunile *speciale*

### MEDIUM
4. Creați un fișier `ex4.c`.

Ne propunem să afișăm în format englez o dată introdusă de la tastatură. Formatul citirii este `număr` **`.`** `număr`.
**Folosiți strict instrucțiunile `if`, `else if` și `else`.**

Verificați dacă datele sunt introduse corect:
- 28 de zile pentru februarie
- 30 de zile pentru aprilie, iunie, septembrie, noiembrie
- 31 de zile pentru ianuarie, martie, mai, iulie, august, octombrie și decembrie
- lunile între 1 și 12

*Exemple de rulare:*
```sh
./ex4.out
05.02
Output: "5th February"

./ex4.out
01.01
Output: "1st January"

./ex4.out
32.12
Output: "Invalid month"
```

5. Creați un fișier `ex5.c`.

Scrieți un program care rezolvă aceeași problemă ca mai devreme, doar că acum **folosind strict instrucțiunea `switch` în loc de `if`, `else if` și `else`**.

6. Care din variante vi se pare mai lizibilă?

7. Ștergeți un `break` și rulați programul astfel încât să intre în `case`-ul asociat instrucțiunii `break` pe care ați șters-o. Ce observați?

### ADVANCED

8. Creați un fișier `ex8.c`.

Scrieți un program care convertește un număr din baza 10 în baza 2.

*Exemplu de rulare:*
```sh
./ex8.out
5
> Output: 00000000 00000000 00000000 00000101
```

**HINT**: Folosiți-vă de un vector sau de recursivitate.

9. Creați un fișier `ex9.c`.

Scrieți un program care convertește un număr din baza 2 în baza 10.

*Exemplu de rulare:*
```sh
./ex9.out
101
> Output: 5
```

*Side note:* Introducem biții cei mai din stânga. Restul până la 32 îi considerăm 0 (padding).