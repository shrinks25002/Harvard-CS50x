#include<stdio.h>
#include<conio.h>

void draw(int h);

int main(){
    int height;
    scanf("%d",&height);
    draw(height);
}

void draw(int h){
    if (h == 0)
    {
        return;
    }
    draw(h-1);
    for (int i = 0; i < h; i++)
    {
        printf("#");
    }
    printf("\n");
}