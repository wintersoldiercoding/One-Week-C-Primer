#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

#define AES_KEY_SIZE 128 // AES key size in bits (128, 192, or 256)

void encryptFile(const char *inputFileName, const char *outputFileName, const char *password) {
    unsigned char iv[AES_BLOCK_SIZE]; // Initialization Vector (IV)
    AES_KEY aesKey;

    FILE *inputFile = fopen(inputFileName, "rb");
    FILE *outputFile = fopen(outputFileName, "wb");

    if (!inputFile || !outputFile) {
        printf("Error opening files.\n");
        return;
    }

    // Generate random IV
    if (RAND_bytes(iv, AES_BLOCK_SIZE) != 1) {
        printf("Error generating IV.\n");
        fclose(inputFile);
        fclose(outputFile);
        return;
    }

    // Set up AES encryption key
    if (AES_set_encrypt_key((const unsigned char *)password, AES_KEY_SIZE, &aesKey) != 0) {
        printf("Error setting up AES encryption key.\n");
        fclose(inputFile);
        fclose(outputFile);
        return;
    }

    // Write the IV to the output file
    fwrite(iv, 1, AES_BLOCK_SIZE, outputFile);

    int bytesRead, bytesEncrypted;
    unsigned char inputBuffer[AES_BLOCK_SIZE];
    unsigned char outputBuffer[AES_BLOCK_SIZE];

    // Perform encryption on each block of data
    while ((bytesRead = fread(inputBuffer, 1, AES_BLOCK_SIZE, inputFile)) > 0) {
        AES_cfb128_encrypt(inputBuffer, outputBuffer, bytesRead, &aesKey, iv, &bytesEncrypted, AES_ENCRYPT);
        fwrite(outputBuffer, 1, bytesEncrypted, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("File encrypted successfully.\n");
}

void decryptFile(const char *inputFileName, const char *outputFileName, const char *password) {
    unsigned char iv[AES_BLOCK_SIZE]; // Initialization Vector (IV)
    AES_KEY aesKey;

    FILE *inputFile = fopen(inputFileName, "rb");
    FILE *outputFile = fopen(outputFileName, "wb");

    if (!inputFile || !outputFile) {
        printf("Error opening files.\n");
        return;
    }

    // Read IV from the input file
    if (fread(iv, 1, AES_BLOCK_SIZE, inputFile) != AES_BLOCK_SIZE) {
        printf("Error reading IV from the input file.\n");
        fclose(inputFile);
        fclose(outputFile);
        return;
    }

    // Set up AES decryption key
    if (AES_set_decrypt_key((const unsigned char *)password, AES_KEY_SIZE, &aesKey) != 0) {
        printf("Error setting up AES decryption key.\n");
        fclose(inputFile);
        fclose(outputFile);
        return;
    }

    int bytesRead, bytesDecrypted;
    unsigned char inputBuffer[AES_BLOCK_SIZE];
    unsigned char outputBuffer[AES_BLOCK_SIZE];

    // Perform decryption on each block of data
    while ((bytesRead = fread(inputBuffer, 1, AES_BLOCK_SIZE, inputFile)) > 0) {
        AES_cfb128_encrypt(inputBuffer, outputBuffer, bytesRead, &aesKey, iv, &bytesDecrypted, AES_DECRYPT);
        fwrite(outputBuffer, 1, bytesDecrypted, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("File decrypted successfully.\n");
}

int main() {
    char inputFileName[256];
    char outputFileName[256];
    char password[256];
    int choice;

    printf("File Encryption and Decryption Program\n");
    printf("1. Encrypt File\n");
    printf("2. Decrypt File\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter input file name: ");
    scanf("%s", inputFileName);

    printf("Enter output file name: ");
    scanf("%s", outputFileName);

    printf("Enter password: ");
    scanf("%s", password);

    if (choice == 1) {
        encryptFile(inputFileName, outputFileName, password);
    } else if (choice == 2) {
        decryptFile(inputFileName, outputFileName, password);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
