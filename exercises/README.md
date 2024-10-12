# Exerciții propuse pentru laboratorul 2

### EASY

1. Scrie un program care citește de la tastatură două numere naturale, le adună și afișează rezultatul pe ecran.

*Scop:* familiarizarea cu sintaxa funcției de citire

2. Scrie un fișier Makefile care automatizează compilarea și execuția programului scris anterior.

*Scop*: familiarizarea cu Makefile

3. Scrie un program care împarte două numere reale citite de la tastatură și afișează rezultatul cu fix 3 zecimale, pe o lungime totală de 10 caractere printabile.

*Scop:* familiarizarea cu tipurile de date și descriptorii funcției de afișare
**HINT:** Vezi sintaxa descriptorilor pentru float pe textul laboratorului [(click)](https://ocw.cs.pub.ro/courses/programare/laboratoare/lab01).

4. Explică de ce `ex4.c` afișează 1.

*Scop:* familiarizarea cu tipurile de date

### MEDIUM

5. Folosind librăria matematică, afișați cubul unui număr citit de la tastatură.

*Scop:* familiarizarea cu căutarea în documentație și procesul de linkare
**HINT:** Vezi ce funcție ai putea folosi în documentația librăriei [(click)](https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/math.h.html).
**HINT:** Nu uita să dai link la librăria matematică cu `-lm`.

6. Verificați folosind două abordări diferite dacă un număr natural citit de la tastatură este par.

*Scop:* familiarizarea cu operatorii.
**HINT**: operație aritmetică și operație pe biți

### BONUS / HARD:

7. Verificați dacă două numere sunt egale folosind un operator pe biți (nu `==`). Explicați de ce merge.

*Scop:* familiarizarea cu operatorii.

8. Scrie un program care primește ca parametri (nu de la tastatură) două numere și le adună.
Acest program scrie pe ecran mesaje de eroare dacă nu se introduc două numere.

*Scop:* familiarizarea cu variațiile funcției main
**HINT:** aveți nevoie de `#include <stdlib.h>` împreună cu funcția `atoi(n)`, parametrii sunt pasați ca șiruri de caractere și trebuie convertiți pentru a-i putea aduna.
