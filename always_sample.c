#include <stdio.h>
int main()
{
    int i=0;
    scanf("%d",&i);
    printf("%d \n",i);

    int n[10] ={0};
    for(i=0;i<10;i++)
        printf("%d\n",n[i]);
    return 0;
}
int prime (int number)
{
    int i=0,c=0;
    for(i=1;i<=number;i++)
        if(number%i == 0)
            c++;

    if(c==2)
        return 1;
    else
        return 0;
}
