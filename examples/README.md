# Pointeri la funcții

Acum că am intrat în lumea pointerilor, there's no going back 👻.<br>

După cum ai aflat la curs, un program este împărțit în segmente de memorie,
iar acestea sunt: `.text`, `.data`, `.bss`, `.rodata`, `.stack` și `heap`
(mai multe detalii la PCLP2 / SO).<br>

Exercițiile anterioare au fost un warm-up pentru a te obișnui cu pointerii
/ adresele de memorie și ai lucrat în principiu cu `stack` și `.data` sau `.bss`
(dacă ai folosit variabile globale).<br>

Dar care e faza cu zona `.text`? Ei bine, aceasta este zona unde se află codul
programului, iar aceasta este **read-only**, ceea ce înseamnă că putem doar
citi și executat conținutul memoriei.
Aceasta este singura zonă de memorie care poate fi executată.<br>

Deci, în momentul în care noi scriem o funcție, aceasta ajunge în zona `.text`,
ceea ce înseamnă că are o anumită adresă în memorie, iar noi ne putem "juca"
cu această adresă.
Deci, o putem stoca într-un pointer și o putem apela folosind acel pointer.
Acești pointeri, se numesc, în mod evident, pointeri la funcții.<br>

Un pointer la funcție are o semnătură de forma:
```c
void (*f)(int) = 0xDEADBEEF;
```
`f` este un pointer la o funcție care primește un întreg (int) și
nu returnează nimic (void).

Alt exemplu:

```c
int* (*g)(int, int*) = 0xCAFEBABE;
```
`g` este un pointer la o funcție care primește un întreg și un pointer la un întreg
și returnează un pointer un la întreg.<br>

Vezi exemplul din [această sursă](./func_ptr.c).

Ca o paralelă între cum arată o funcție și cum arată un pointer la funcție,
din câte se vede doar adăugăm `*` ca să marcăm că e un pointer, iar mai
departe avem atribuirea unui pointer ca în mod normal.<br>
Partea interesantă e că putem avea vectori de pointeri la funcții, iar asta ne permite să facem chestii mai interesante.<br>
Pentru a avea un vector de pointeri la funcții, avem nevoie ca toate funcțiile să aibă aceeași semnătură.<br>
Hai să considerăm un exemplu simplu:
```c
int f1(int x);
int f2(int x);
int f3(int x);

int (*v[3])(int) = {f1, f2, f3};
```
Digerați puțin sintaxa, nu e chiar atât de oribil pe cât pare. Se combină noțiunile de pointeri la funcții și vectori.<br>
