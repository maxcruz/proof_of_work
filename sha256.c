#include <openssl/sha.h>
#include <string.h>
#include <stdio.h>
#include "sha256.h"

void sha256(char *plain, char buffer[65]) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, plain, strlen(plain));
    SHA256_Final(hash, &sha256);
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) sprintf(buffer + (i * 2), "%02x", hash[i]);
    buffer[64] = 0;
}