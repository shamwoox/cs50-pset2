#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    
    if(argc == 2) {
        printf("plaintext: ");
        string s = get_string(); //get string from user
        //iterate over string
        for(int i = 0, n = strlen(s); i < n; i++) {
            if(isalpha(s[i])) { //check if alpha
                if(isupper(s[i])) { //check if upper
                    s[i] = (((s[i] - 65) + atoi(argv[1])) % 26) + 65; //shift by key
                } else if (islower(s[i])) { //check if lower
                    s[i] = (((s[i] - 97) + atoi(argv[1])) % 26) + 97; //shift by key
                }
            }
        }
        printf("ciphertext: %s\n", s); //print results
        return 0;
    } else {
        printf("Usage: ./caesar k \n"); //print if wrong input
        return 1;
    }
}