#include <stdio.h>
int countbit(int n)
{
    return (n==0)?0:(1 + countbit(n&(n-1)));
}
int main()

{
    int n;
    n = countbit(15);
    printf("n is %d", n);
    return 0;
}
