#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    FILE *fp;
    fp = fopen("/host/Users/lemmy/Coding n' Stuff/input.txt","r");
    int test,m,n;
    fscanf(fp,"%d", &test);
    int d[20];
    int sum=0;
    while(test)
    {
        fscanf(fp,"%d %d", &n, &m);
        for(int i=0;i<n;i++)
        {
            fscanf(fp,"%d",&d[i]);
        }

    for (int nStartIndex = 0; nStartIndex < n; nStartIndex++)
    {
        int nSmallestIndex = nStartIndex;
        for (int nCurrentIndex = nStartIndex + 1; nCurrentIndex < n; nCurrentIndex++)
        {
            if (d[nCurrentIndex] < d[nSmallestIndex])
                nSmallestIndex = nCurrentIndex;
        }
        swap(d[nStartIndex], d[nSmallestIndex]);
    }//

	//print array
	for(int i=0;i<n;i++)
	{
		printf("\n %d",d[i]);
	}

        for(int i=1;i<(2^n);i++)
        {
            for(int j=0;j<=n;j++)
            {
                printf("j -- \n",j);
                if(i & (1<<j))
                    sum = sum + d[j];

                if(sum == m)
                    break;
            }
        }
        if(sum == m)
            printf("Yes");
        else
            printf("No");

        printf("\n\n%d\n\n",sum);

        printf("\n");
        test--;
    }
}
