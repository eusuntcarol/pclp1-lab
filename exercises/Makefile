SOURCES = $(wildcard *.c)
TARGETS = $(SOURCES:.c=.out)

all: $(TARGETS)

ex%.out: ex%.c  
	gcc -o $@ $< -lm

.PHONY: clean all
clean:
	rm -f $(TARGETS)
