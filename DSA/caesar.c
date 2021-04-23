#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        int key = atoi(argv[1]);
        printf("%d", key);
        char ptx[500], ctx[500];
        printf("plaintext: ");
        scanf("%[^\n]%*c", &ptx);
        printf("%s", ptx);
        for (int i = 0; i < strlen(ptx); i++)
        {
            if (ptx[i] >= 'A' && ptx[i] <= 'Z')
            {
                ctx[i] = ((((toascii(ptx[i]) - 65) + key) % 26) + 65);
            }
            else if (ptx[i] >= 'a' && ptx[i] <= 'z')
            {
                ctx[i] = ((((toascii(ptx[i]) - 97) + key) % 26) + 97);
            }
            else
            {
                ctx[i] = ptx[i];
            }
        }
        printf("ciphertext: %s", ctx);
    }
    else
    {
        printf("Usage: ./caesar key");
    }
}
