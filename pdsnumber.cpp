#include <stdio.h>
#include <iostream>
using namespace std;
#include <stdlib.h>
#include <math.h>
bool psdn(int num)
{
    int nDigits = (int)ceil(log10(num));
    int prod = 1;
    int sum = 0;
    for(int i=1; i<= nDigits; i++)
    {

//        if(prod == 0)
//            return true;
        int k = num%10;
//        printf("k is %d num is %d ",k,num);
        if(k == 0)
            return false;

        sum = sum + k;
//        printf("prod_prev= %d    %d\n", prod, k);
        prod = prod * k;
//        printf("prod_after= %d    %d\n", prod, k);
        num = num/10;
    }
//    printf("\n prod = %d sum = %d \n",prod,sum);
    if(prod%sum)
        return true;
    else
        return false;
}

int main()
{
    //calculating numbers till 10^9
    //number 476 = (4*7*6)/(4+7+6)
     int n = 100000000;
    int *nArray;
    nArray = (int *)malloc(sizeof(int) * n);
    for(int t=1;t<=10;t++)
    {
        nArray[t-1] = t;
    }
    int j=9;
    for(int i=11;i<= 100000000;i++)
    {
        bool s = psdn(i);
        if(!s)
        {
//            printf("in loop\n");
//            printf("\n%d\n",j);
            j++;
            nArray[j] = i;
//            printf("%d \n",nArray[j]);
        }
    }
    printf("j value is %d ", j+1);


//    for(int t=0;t<=10;t++)
//    {
//        printf("nArray[%d] is %d\n",t,nArray[t]);
//    }

    return 0;
}

