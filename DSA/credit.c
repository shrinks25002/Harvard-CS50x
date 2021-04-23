#include <stdio.h>
#include <conio.h>
#include <math.h>

void main(){

    unsigned long long num;
    printf("Number: ");
    scanf("%llu",&num);
    int i=1,j=0;
    int c=1;
    unsigned long long num1 = num;
    unsigned long long num2 = num1;
    unsigned long long num3 = num1;
    unsigned long long prod,sum=0,sum1=0;

    while (num>pow(10,i))
    {
        unsigned long long digit = num/(pow(10,i));
        digit%=10;
        prod=2*digit;
        if(prod/10==0){
            sum=sum+prod;
        }else{
            sum = sum+(prod%10)+(prod/10);
        }
        printf("%llu\n",sum);
        i=i+2;
    }

    while (num>pow(10,j))
    {
        unsigned long long digit = num/(pow(10,j));
        digit%=10;
        sum1=sum1+digit;
        printf("%llu\n",sum1);
        j=j+2;
    }

    int total  = sum+sum1;

    printf("%llu\n",total);
    
    if (total%10==0)
    {
        printf("VALID");
        while (num>=10)
        {
            num/=10;
            c++;
        }
        printf("%llu, %d",num,c);

        if ((num==4) && (c==13 || c==16))
        {
            printf("VISA");
        }
        else{
            while (num1)
            {
                num3 = num2;
                num2 = num1;
                num1/=10;
            }
            printf("%llu, %d",num3,c);
            if ((num3==51 ||num3==52 ||num3==53 ||num3==54 ||num3==55) && (c==16))
            {
                printf("MASTERCARD");
            }

            else if ((num3==34 ||num3==37) && (c==15))
            {
                printf("AMEX");
            }
            
            else{
                printf("INVALID");
            }
        }
        
    }
    else{
        printf("INVALID");
    }
    
}
