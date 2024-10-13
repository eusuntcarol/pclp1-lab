# Exerciții propuse pentru laboratorul 2

### EASY

1. (*) Explică de ce `ex1.c` afișează 1.

*Scop:* familiarizarea cu tipurile de date

2. Scrie un program care citește de la tastatură două numere naturale,
le adună și afișează rezultatul pe ecran.

*Scop:* familiarizarea cu sintaxa funcției de citire

3. Scrie un program care împarte două numere reale citite de la tastatură și
afișează rezultatul cu fix 3 zecimale, pe o lungime totală de 10 caractere
printabile.

*Scop:* familiarizarea cu tipurile de date și descriptorii funcției de afișare
**HINT:** Vezi sintaxa descriptorilor pentru float pe textul laboratorului
[(click)](https://ocw.cs.pub.ro/courses/programare/laboratoare/lab01).

### MEDIUM

4. Folosind librăria matematică, afișați cubul unui număr citit de la tastatură.

*Scop:* familiarizarea cu căutarea în documentație și procesul de linkare<br>
**HINT:** Vezi ce funcție ai putea folosi în documentația librăriei
[(click)](https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/math.h.html).<br>
**HINT:** Nu uita să dai link la librăria matematică cu `-lm`.

5. Verificați folosind două abordări diferite dacă un număr natural citit de la
tastatură este par.

*Scop:* familiarizarea cu operatorii.<br>
**HINT**: operație aritmetică și operație pe biți

6. Verificați dacă două numere sunt egale folosind un operator pe biți (nu `==`).
Explicați de ce merge.

*Scop:* familiarizarea cu operatorii.

### BONUS / HARD:

7. Scrie un fișier Makefile care automatizează compilarea și execuția
unui program scris anterior.

*Scop:* familiarizarea cu Makefile
**HINT:** Vezi [textul laboratorului](https://ocw.cs.pub.ro/courses/programare/laboratoare/lab01)
sau [exemplul din repo](../examples/Makefile).

8. Se dau două momente de timp specificate prin ore, minute și secunde (hh:mm:ss - programul
primește de la utilizator fix acest format).<br>
Determinați numărul de ore, minute și secunde dintre cele două momente.<br>
Se consideră timpul de la primul moment la al doilea.<br>
Se va afișa pe ecran diferența în formatul hh:mm:ss, cu padding 0 în cazul
în care numărul rezultat nu are două caractere.<br><br>
*Exemplu de output:* 00:34:07, reprezentând 34 de minute și 7 secunde.<br>

Sanity checks + coduri de eroare returnate
- cod eroare 1: orele nu sunt în intervalul [0, 24)
- cod eroare 2: minutele nu sunt în intervalul [0, 60)
- cod eroare 3: secundele nu sunt în intervalul [0, 60)
- cod eroare 4: al doilea moment este înaintea primului

**NOTĂ:** pentru a vedea codul de exit al ultimului program rulat, folosiți `echo $?`

9. Scrie un program care primește ca argumente de rulare (nu de la tastatură)
două numere și le adună.
Acest program scrie pe ecran mesaje de eroare dacă nu se introduc două numere.

*Scop:* familiarizarea cu variațiile funcției main<br>
**HINT:** aveți nevoie de `#include <stdlib.h>` împreună cu funcția `atoi(n)`,
parametrii sunt pasați ca șiruri de caractere și trebuie convertiți pentru a-i
putea aduna.
