# RC4 File Encryptor & Decryptor

A C implementation of RC4 stream cipher for file encryption and decryption.

## The Files
- `rc4 encrypt.c`: Encrypts `file.txt` using the RC4 stream cipher.
- `rc4 decrypt.c`: Decrypts `file.txt` using the same secret key to restore the original plaintext.

## &Usages

```bash
gcc rc4 encrypt.c -o rc4 encrypt
gcc rc4 decrypt.c -o rc4 decrypt
```

### for Encryption
```bash
./rc4 encrypt
```

### for Decryption
```bash
./rc4 decrypt
```
