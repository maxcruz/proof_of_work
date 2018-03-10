#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include "pow.h"
#include "sha256.h"

#define START 25
#define COUNT 5

void check_hash(char *hash, struct proof *proofs, int sequence, int c, clock_t start) {
    for (int i = 0; i < c; i++) {
        if (proofs[i].found) continue;
        int n = proofs[i].length;
        clock_t time = clock() - start;
        double time_taken = ((double) time) / CLOCKS_PER_SEC;
        if (check_pow(hash, n)) {
            proofs[i].time = time_taken;
            proofs[i].found = true;
            proofs[i].sequence = sequence;
            proofs[i].hash = hash;
            print_proof(proofs[i]);
            return;
        }
    }
}

int main(int argc, char *argv[]) {

    struct proof samples[COUNT];
    init_proofs(samples, START, COUNT);

    clock_t start = clock();

    bool random = argc == 1 && argv[0] == "--random";

    int nonce = 0;
    while (true) {

        char macondo[] = "Muchos años después, frente al pelotón de fusilamiento, el Coronel Aureliano Buendía había de "
                "recordar aquella tarde remota en que su padre lo llevó a conocer el hielo. Macondo era entonces una "
                "aldea de %d";

        if (random) nonce = 0; //TODO: Get nonce randomly
        else nonce++;

        int length_nonce = (int) floor(log10(fabs(nonce))) + 1;
        int n = sizeof(macondo) + length_nonce;

        char plain[n];
        sprintf(plain, macondo, nonce);

        char hash[65];
        sha256(plain, hash);

        check_hash(hash, samples, nonce, COUNT, start);

        if (proofs_completed(samples, COUNT)) break;
    }

    return 0;
}