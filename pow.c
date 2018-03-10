#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "pow.h"
#include "hex.h"

bool check_pow(char* hash, int n) {
    for (int i = 0; i < strlen(hash); i++) {
        char* binary = hex_to_bin(hash[i]);
        for (int j = 0; j < 4; j++) {
            if (binary[j] == '0') {
                n--;
                if (n == 0) return true;
            } else if (n > 0) return false;
        }
    }
}

void init_proofs(struct proof *proofs, int n, int c) {
    for (int i = 0; i < c; i++) {
        proofs[i].found = false;
        proofs[i].length = n;
        proofs[i].time = 0.0;
        proofs[i].sequence = 0;
        proofs[i].hash = "";
        n++;
    }
}

bool proofs_completed(struct proof *proofs, int c) {
    for (int i = 0; i < c; i++) if (! proofs[i].found) return false;
    return true;
}

void print_proof(struct proof sample) {
    printf("Length: %i\n", sample.length);
    printf("Hash: %s\n", sample.hash);
    printf("Time: %f\n", sample.time);
    printf("Sequence: %i\n", sample.sequence);
    printf("\n");
}