#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char *s;
    s=malloc(256);
    scanf("%255s",s);
    char *t = malloc(strlen(s)+1);
    if (t == NULL)
    {
        return 1;
    }

    for (int i = 0,n=strlen(s); i < n+1; i++)
    {
        t[i]=s[i];
    }
    
    if (strlen(t)>0)
    {
        t[0] = toupper(t[0]);
    }

    printf("s: %s\n",s);
    printf("t: %s\n",t);

    free(t);
}