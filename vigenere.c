#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[]) {
    //Accept only two arguments
    if(argc != 2) {
        printf("Usage: ./caesar k \n"); //Print if wrong input
        return 1;
    }

    string key = argv[1];
    //Decline if key has nonalpha character
    for(int i = 0, n = strlen(key); i < n; i++) {
        if(!isalpha(key[i])) {
            printf("Usage: ./caesar k \n"); //Print if wrong input
            return 1;
        }
    }
    
    printf("plaintext: ");
    string s = get_string(); //get string from user
    int keyLength = strlen(key); //length of the key
    
    for(int i = 0, j = 0, n = strlen(s); i < n; i++) { //iterate over plain text
        if(isalpha(s[i])) {
            int keyPosition = j % keyLength; //iterate over key
            if(isupper(s[i])) {
                s[i] = (((s[i] - 65) + (tolower(key[keyPosition]) - 97)) % 26) + 65; //shift ith index of plain text by alpha index of key
            }
            if(islower(s[i])) {
                s[i] = (((s[i] - 97) + (tolower(key[keyPosition]) - 97)) % 26) + 97; //shift ith index of plain text by alpha index of key
            }
            j++; //Increment key's index if alpha
        }
    }
    printf("ciphertext: %s\n", s); //print results
    return 0;
    
}