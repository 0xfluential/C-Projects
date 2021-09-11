#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

struct Accounts {
    char username[20], password[20];
} accs[20];

int findline(char *str) 
{
    FILE *fp = fopen("Login.txt", "a+");
    int linenum = 0, find_line = 0;
    char *buffer = NULL;
    size_t size = 0;
    while(getline(buffer, &size, fp) != -1) 
    {
        int argc = 0;
        unsigned char *argv[10] = {{0}};
        char *token = strtok(buffer, " ");
        while(token != NULL && argc < 5) 
        {
            argv[argc] = malloc(strlen(token) + 1);
            strcpy(argv[argc], token);
            token = strtok(NULL, " ");
            argc++;
        }
        int k;
        for(k = 0; k < argc; k++) 
        {
            if(!strcmp(argv[k], str)) 
            {
                find_line = k;
                break;
            }
        }
        argc = 0;
        for(k = 0; k < argc; k++) 
        {
            free(argv[argc]);
        }
        if(find_line != 0) break;
            linenum++;
    }
    fclose(fp);
    return find_line;

}

int Reloadaccs() 
{
    FILE *fp = fopen("Login.txt", "a+");
    int x = 0, s = 0, c;
    for(c = getc(fp); c != EOF; c = getc(fp)) 
    {
        if(c == '\n') x++;
    }
    rewind(fp);

    while(s != x) 
    {
        fscanf(fp, "%s %s", accs[s].username, accs[s].password);
        s++;
    }
    fclose(fp);
}

char *rand_str(char *dst, int size) 
{
        static const char text[] ="abcdefghijklmnopqrstuvwxyz0123456789!@#$^&*()_+[]:<>,.";
                                  "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$^&*()_+[]:<>,.";
        int i, len = rand() % (size - 1);
        for (i = 0; i < len; ++i) 
        {
                dst[i] = text[rand() % (sizeof text - 1)];
        }
        dst[i] = '\0';
        return dst;
}

int Captcha(void) 
{
    char mytext[10];
    char store[9];
    char captcha_prompt[9];
    srand(time(0));
    puts(rand_str(mytext, sizeof mytext));
    printf("Enter The Captcha Given Above: ", captcha_prompt);
    scanf("%s", captcha_prompt);
    if (!strcmp(captcha_prompt, mytext)) 
    {
        printf("Captcha Succesfull!\n");
        return 0;
    }
    else
    {
        printf("Captcha Failed...\n");
        return 1;
    }
}

int main() 
{
    char username[20], password[20];
    printf("Enter Username: ");
    scanf("%s", username);

    printf("Enter Password: ");
    scanf("%s", password);

    Reloadaccs();
    if(Captcha() == 1)
        return 0;

    int foundline = findline(username);
    if(!strcmp(accs[foundline].username, username)&& !strcmp(accs[foundline].password, password)) 
    {
        printf("Successfully Logged In\n");
        return 0;
    }
    else
        printf("Login Credentials Incorrect\n");
}
