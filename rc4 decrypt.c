#include <stdio.h>
#include <string.h>


void rc4_init(unsigned char S[], const char *key) {
    int key_len = strlen(key);
    int j = 0;

    for (int i = 0; i < 256; i++) {
        S[i] = i;
    }

    for (int i = 0; i < 256; i++) {
        j = (j + S[i] + (unsigned char)key[i % key_len]) % 256;
     
        unsigned char temp = S[i];
        S[i] = S[j];
        S[j] = temp;
    }
}

// Decrypts data using RC4 PRGA
void rc4_transform(unsigned char *data, int len, const char *key) {
    unsigned char S[256];
    rc4_init(S, key);

    int i = 0;
    int j = 0;

    for (int n = 0; n < len; n++) {
        i = (i + 1) % 256;
        j = (j + S[i]) % 256;

        // swaps S[i] and S[j]
        unsigned char temp = S[i];
        S[i] = S[j];
        S[j] = temp;

        unsigned char k = S[(S[i] + S[j]) % 256];
        data[n] ^= k;
    }
}

int main() {
    char filename[] = "file.txt";
    char key[] = "superduper";
    unsigned char buffer[10000];

    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Could not open %s\n", filename);
        return 1;
    }

    int bytes_read = fread(buffer, 1, sizeof(buffer), fp);
    fclose(fp);

    // Decrypt content
    rc4_transform(buffer, bytes_read, key);


    fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: Could not write to %s\n", filename);
        return 1;
    }

    fwrite(buffer, 1, bytes_read, fp);
    fclose(fp);

    printf("[+] Decrypted '%s' successfully.\n", filename);
    return 0;
}
