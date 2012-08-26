/* This code is in public domain. Use for whatever purpose at your own risk. */
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>



#define MAXN  100000000  /* maximum value of N */
#define P1    1562501    /* = ceil(MAXN/64) */
#define P2    50000000   /* = ceil(MAXN/2) */
#define P3    5000       /* = ceil(ceil(sqrt(MAXN))/2) */

uint32_t sieve[P1];

#define GET(b) ((sieve[(b)>>5]>>((b)&31))&1)

void make()
{
    uint32_t i, j, k;
    memset(sieve, 0, sizeof(sieve));
    for (k = 1; k <= P3; k++)
        if (GET(k)==0) for(j=2*k+1,i=2*k*(k+1);i<P2;i+=j) sieve[i>>5]|=1<<(i&31);
}

int isprime(int p) { return p==2 || (p>2 && (p&1)==1 && (GET((p-1)>>1)==0)); }

int main()
{
    make();
    FILE *fp1,*fp2;
    fp1 = fopen("in","r");
    fp2 = fopen("out","w");

    int testcases=0;
    fscanf (fp1, "%d", &testcases);
    int i;
    int **input;
    input = ( int **)malloc(testcases*sizeof(int*));

    for(i=0;i<testcases;i++)
        input[i] = (int *)malloc(2 * sizeof(int));

    int r=0;
    for(r=0;r<testcases;r++)
        fscanf(fp1,"%d %d",&input[r][0],&input[r][1]);

    int j;
    for(j=0;j<testcases;j++)
    {
        int i;
        for (i = input[j][0]; i <= input[j][1]; i++)
            if (isprime(i))
                fprintf(fp2,"%d \n",i);
    }
    return 0;
}
