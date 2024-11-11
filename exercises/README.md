# 🔠 Șiruri de caractere (strings)

**Înainte de a rezolva exercițiile, citiți [textul laboratorului](https://ocw.cs.pub.ro/courses/programare/laboratoare/lab10).**

fără checker azi, n-am avut suficient timp si pt asta 😅😅

### EASY

1. Creați un fișier `ex1.c`.

Se citesc un șir de caractere, un cuvânt și un caracter.<br>
Se afișează caracterul și cuvântul citite.<br>
Se afișează șirul de caractere citit și lungimea acestuia.<br>
Se numără și se afișează de câte ori apare caracterul specificat în șirul de caractere.<br>
Se numără și se afișează de câte ori apare cuvântul specificat în șirul de caractere și pozițiile la care începe fiecare apariție.

*Exemple de rulare:*
```sh
./ex1.out
> Input:
Ana banana
na
a

> Output:
na a
Ana banana 11
1 # prima apariție - # și ce e după # nu se afișeaza
6 # a doua apariție
8 # a treia apariție
3 # numărul total de apariții ale cuvântului
```

2. Creați un fișier `ex2.c`.

Se citește un șir de caractere format din litere mari și mici ale alfabetului englez și spații.<br>
Pentru fiecare literă, să se transforme literele mici în litere mari și invers.

*Exemplu de rulare:*
```sh
./ex2.out
> Input:
sE iA NoTa maaaRE lA parTIAL

> Output:
Se Ia nOtA MAAAre La PARtial
```

### MEDIUM

3. Creați un fișier `ex3.c`.

Se citesc un șir de caractere și un cuvânt.<br>
Se elimină toate aparițiile cuvântului din șirul de caractere.<br>
Dacă ștergerea unui cuvânt lasă un spațiu în exces, acesta este eliminat și el.<br>
Se afișează șirul de caractere rezultat.<br>

*Exemple de rulare:*
```sh
./ex3.out
> Input:
Sirul de caractere este un sir de caractere
rac

> Output:
Sirul de catere este un sir de catere

./ex3.out
> Input:
Ana are mere si pere si pere si mere
si

> Output: (sa se elimine si spatiile in exces)
Ana are mere pere pere mere

GRESIT:
Ana are mere  pere  pere  mere
```

4. Creează un fișier `ex4.c`.

Se citește de la tastatură un șir de caractere format din litere mici ale alfabetului englez și spații.<br>
Să se despartă cuvintele din șir (`strtok`) folosind spațiile ca separatori și să se numere vocalele și consoanele din fiecare cuvânt.

*Exemple de rulare:*
```sh
./ex5.out
> Input:
Pclp1 e misto

> Output:
Pclp: 0 vocale, 4 consoane
e: 1 vocala, 0 consoane
misto: 2 vocale, 3 consoane
```

5. Creați un fișier `ex5.c`
Ne propunem să înțelegem mai bine cum funcționează funcțiile de manipulare a șirurilor din C.<br>
Pentru acest exercițiu, veți implementa propriile voastre funcții:
`my_strlen`, `my_strcpy`, `my_strcmp`, `mystr_str`.<br>
Pentru testarea problemei, se va introduce de la tastatură un număr, reprezentând funcția pe care dorim să o testăm.<br>
După aceea, se vor introduce parametrii necesari pentru funcția respectivă, astfel:
- numărul 1 pentru `my_strlen`, se va introduce un șir de caractere
- numărul 2 pentru `my_strcpy`, se va introduce un șir de caractere și un alt șir de caractere
- numărul 3 pentru `my_strcmp`, se va introduce un șir de caractere și un alt șir de caractere (vedeți ce returnează funcția `strcmp` din `string.h`)
- numărul 4 pentru `my_strstr`, se va introduce un șir de caractere și un alt șir de caractere (vedeți ce returnează funcția `strstr` din `string.h`)
Rezultatul fiecărei funcții va fi afișat pe ecran, așa cum rezultatul funcțiilor din `string.h` ar fi fost afișat.

### ADVANCED

6. Creați un fișier `ex6.c`.

Ne propunem să înțelegem mai bine cum funcționează funcția `strtok` din C, așa că vom implementa propria funcție `my_strtok`.

Funcția `my_strtok` va avea ca parametri un șir de caractere și un șir de caractere ce conține separatorii.<br>
Funcția va returna un pointer la primul caracter al următorului cuvânt din șirul de caractere sau `NULL` dacă nu mai există cuvinte.<br>
Funcția va modifica șirul de caractere primit ca primul parametru, astfel încât să înlocuiască separatorii cu terminatori de șir.<br>
Funcția se va apela inițial cu primul parametru reprezentând șirul de caractere în care dorim să facem modificările, iar apoi se va apela succesiv cu `NULL` ca prim parametru pentru a obține restul de cuvinte din șir. Cu alte cuvinte, la primul apel, funcția "va încărca" în memoria sa șirul de caractere primit (vezi `static`).

*Exemple de utilizare:*
```sh
my_strtok("Ana are mere", " ");
> Result: pointer la "Ana"

my_strtok(NULL, " ");
> Result: pointer la "are"

my_strtok(NULL, " ");
> Result: pointer la "mere"

my_strtok(NULL, " ");
> Result: NULL
```

6. Creați un fișier `ex6.c`.

Se citește un șir de caractere și un caracter.
Toate aparițiile caracterului în șir trebuie înlocuite cu un număr secvențial, urmat de restul șirului de la acea poziție.

*Exemplu de rulare:*
```sh
./ex6.out
> Input:
Ana are mere si pere
e

> Output:
Ana ar1 m2r3 si p4r5

./ex6.out
> Input: (se observă că trebuie să deplasați caracterele dacă se ajunge la 10)
welcome to the jungle, it gets worse here every day, learn to live like an animal in the jungle where wee play
e

> Output:
w1lcom2 to th3 jungl4, it g5ts wors6 h7r8 9v10ry day, l11arn to liv12 lik13 an14 animal in th15 jungl16 wh17r18 w1920 play
```
