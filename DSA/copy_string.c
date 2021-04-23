#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>

void main(){
    char *s;
    s=malloc(256);
    scanf("%255s",s);
    char *t = s;

    t[0] = toupper(t[0]);

    printf("s: %s\n",s);
    printf("t: %s\n",t);
}