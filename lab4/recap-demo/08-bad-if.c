#include <stdio.h>

int main(void) {
    int number = 5, floors = 11, apartments = 50, rents = 25, expenses = 10000;

    // very bad!
    if (number == 5) {
        if (floors == 11) {
            if (apartments == 50) {
                if (rents == 25) {
                    if (expenses == 10000) {
                        printf("good\n");
                    }
                }
            }
        }
    }
    // also very hard to maintain if-elses

    // instead: SHORT-CIRCUIT
    if (number != 5) {
        return 1; // wrong number
    }

    if (floors != 11) {
        return 1; // wrong floors
    }

    if (apartments != 50) {
        return 1; // wrong apartments
    }

    // ... and so on

    printf("good\n");

    return 0;
}
