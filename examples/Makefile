SOURCES = $(wildcard *.c)
TARGETS = $(SOURCES:.c=)

all: $(TARGETS)

ex%: ex%.c  
	gcc -o $@ -lm $<

.PHONY: clean
clean:
	rm -f $(TARGETS)
