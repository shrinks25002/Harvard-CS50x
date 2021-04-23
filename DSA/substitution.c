#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        char *key = argv[1];
        if (strlen(key) != 26)
        {
            printf("Key must contain 26 characters.");
        }
        else
        {
            printf("%s", key);
            char ptx[500], ctx[500];
            printf("\nplaintext: ");
            scanf("%[^\n]%*c", &ptx);
            printf("%s", ptx);
            for (int i = 0; i < strlen(ptx); i++)
            {
                if (ptx[i] >= 'A' && ptx[i] <= 'Z')
                {
                    ctx[i] = key[toascii(ptx[i]) - 65];
                }
                else if (ptx[i] >= 'a' && ptx[i] <= 'z')
                {
                    ctx[i] = tolower(key[toascii(ptx[i]) - 97]);
                }
                else
                {
                    ctx[i] = ptx[i];
                }
            }
            printf("ciphertext: %s", ctx);
        }
    }
    else
    {
        printf("Usage: ./substitution key");
    }
}
