#include <stdio.h>
#include <conio.h>
#include <math.h>

void main(){
    int n=0;
    float dollars;
    printf("Cash owed: ");
    scanf("%f",&dollars);
    int cents = round(dollars*100);
    while (cents>=25)
    {
        cents=cents-25;
        ++n;
    }
    while (cents>=10)
    {
        cents=cents-10;
        ++n;
    }
    while (cents>=5)
    {
        cents=cents-5;
        ++n;
    }
    while (cents>=1)
    {
        cents=cents-1;
        ++n;
    }
    printf("%d",n);
}