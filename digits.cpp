#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int main()
{
    int n=100;
    long int k = pow(9,9);
    printf("%f\n",log10(n));
    printf("%ld \n",k);
    printf("ans - %d", (int)ceil(log10(n)));
}
