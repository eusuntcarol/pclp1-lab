SOURCES = $(wildcard *.c)
TARGETS = $(SOURCES:.c=.out)

all: $(TARGETS)

%.out: %.c  
	gcc -o $@ $< -lm -fno-stack-protector

.PHONY: clean all
clean:
	rm -f $(TARGETS)
