all: app.out argc.out argv.out envp.out app_include.out app_math.out

# --------------------------------------------------

app.out: app.o
	gcc -o app.out app.o

app.o: app.c  
	gcc -c app.c

run: app.out
	./app.out

# --------------------------------------------------

app_include.out: app_include.o hello.o
	gcc -o app_include.out app_include.o hello.o

hello.o: hello.c hello.h
	gcc -c hello.c

# --------------------------------------------------

app_math.out: app_math.o
	gcc -o app_math.out app_math.o -lm

# --------------------------------------------------

argc.out: argc.c
	gcc -o argc.out argc.c

argv.out: argv.c
	gcc -o argv.out argv.c

envp.out: envp.c
	gcc -o envp.out envp.c

# clean up
.PHONY: clean
clean:
	rm -f *.i *.s *.o *.out