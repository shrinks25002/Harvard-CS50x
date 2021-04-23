#include <stdio.h>
#include <conio.h>

void main(){
    int years = 0;
    int start,end;
    printf("Start size: ");
    scanf("%d",&start);
    printf("End size: ");
    scanf("%d",&end);
    while (start<end)
    {
        start=start+(start/3)-(start/4);
        years=years+1;        
    }
    printf("%d",years);
}