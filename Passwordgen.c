// Password generator in C
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void passwordGenerator(int N)
{
    int i = 0;
    int randomizer = 0;

    srand(((unsigned int)(time NULL)));
    
    char numbers[] = "0123456789";
    char letters[] = "abcdefghijklmnopqrstuvwxyz";
    char LETTERS[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char symbols[] = "~!@#$^&*()_+-={}[]:<>,./?";
    char password[N];

    randomizer = rand() % 4;

    for ( i = 0; i < N; i++) {
        
        if (randomizer == 1) {
            password[i] = numbers[rand() % 10];
            randomizer = rand() % 4;
            printf("%c", password[i]);
        }
        else if (randomizer == 2) {
            password[i] = symbols[rand() % 25];
            randomizer = rand() % 4;
            printf("%c", password[i]);
        }
        else if (randomizer == 3) {
            password[i] = LETTERS[rand() % 26];
            randomizer = rand() % 4;
            printf("%c", password[i]);
        }
        else {
          password[i] = letters[rand() % 26];
          randomizer = rand() % 4;
          printf("%c", password[i]);
        }
    }
}

int main()
{
    int N = 10;

    passwordGenerator(N);

    return 0;
}
