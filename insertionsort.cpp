#include <iostream>
using namespace std;
int main()
{
    int T;
    cin >> T;
    for (int test=0;test<T;test++)
    {
        int counter=0;
        int a[10000];
        int N;
        cin >> N;
        for(int i=0;i<N;i++)
            cin >> a[i];

        long long ret = 1LL * N * (N - 1) / 2 ;
        cout << ret << endl;
//        for(int i=1;i<N;i++)
//        {
//            int j=i;
//            while ((j>0)&&(a[j]<a[j-1]))
//            {
//                int temp=0;
//                temp = a[j];
//                a[j]=a[j-1];
//                a[j-1]=temp;
//                counter++;
//                j--;
//            }
//        }
//        cout << counter << endl;
       }
    return 0;
}
