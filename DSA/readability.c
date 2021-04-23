#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <math.h>

void main(){
    char str[500];
    float L,S,index;
    float letters=0.0, words=0.0,sentences=0.0;
    printf("Text: ");
    scanf("%[^\n]%*c", &str);
    for(int i=0;i<strlen(str);i++){
        if ((str[i]>='a' && str[i]<='z')||(str[i]>='A' && str[i]<='Z'))
        {
            letters++;
        }else if (str[i]==' '){
            words++;
        }
        else if (str[i]=='?'||str[i]=='!'||str[i]=='.'){
            sentences++;
        }else{
            continue;
        }
    }
    printf("%f\n%f\n%f\n",letters,words+1.0,sentences);
    L=(letters/(words+1.0))*100.0;
    S=(sentences/(words+1.0))*100.0;
    index=L*0.0588-S*0.296-15.8;
    printf("%f\n",index);
    if(round(index)>=16){
        printf("Grade 16+");
    }else if(round(index)<1){
        printf("Before Grade 1");
    }else{
        printf("Grade %.0f",round(index));
    }
}