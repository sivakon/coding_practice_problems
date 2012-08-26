// Home  » April Challenge 2012 » PDS Number » All Submissions » Tiancheng Lou [971535]
// Average:
// Poor
// Okay
// Good
// Great
// Awesome
// No votes yet
// Problem Title: 
// PDS Number

// CodeChef submission 971535 (C++ 4.3.2) plaintext list. Status: AC, problem PDSNUM, contest APRIL12. By ACRush (ACRush), 2012-04-09 23:12:29.

#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <functional>
#include <utility>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
using namespace std;
typedef long long int64;
typedef unsigned long long uint64;
// #define two(X) (1<<(X))
// #define twoL(X) (((int64)(1))<<(X))
// #define contain(S,X) ((S&two(X))>0)
// #define containL(S,X) ((S&twoL(X))>0)
// typedef pair<int,int> ipair;
// int countbit(int n)
//     {
//         return (n==0)?0:(1+countbit(n&(n-1)));
//     }
// int lowbit(int n)
//     {
//         return (n^(n-1))&n;
//     }
// const double pi=acos(-1.0);
// const double eps=1e-11;
// template<class T> T sqr(T x)
//     {
//         return x*x;
//     }
// template<class T> void checkmin(T &a,T b)
//     {
//         if (b<a) a=b;
//     }
// template<class T> void checkmax(T &a,T b)
//     {
//         if (b>a) a=b;
//     }
// #define SIZE(X) ((int)((X).size()))
// #define LENGTH(X) ((int)((X).length()))
// #define MP(A,B) make_pair(A,B)
int gcd(int a,int b) 
    {
        return (b==0)?a:gcd(b,a%b);
     }
int lcm(int a,int b)
     { 
        return a*(b/gcd(a,b));  
     }
 
const int max_states=350;
const int oo=1000000005;
 
int n_states;
int states[max_states],next[max_states][10];
map<int,int> map_states;
int map_states_small[10];
int cL[11],f[11][max_states][100];
 
void preprocess()
{
int m=1;
for (int i=2;i<=9;i++)
     for (int p=i;p<100;p*=i)
         m=lcm(m,p);

n_states=0;
states[n_states++]=1;
map_states[1]=0;
for (int cl=0;cl<n_states;cl++)
    for (int i=0;i<10;i++)
    {
        int key=states[cl]*i;
        if (key>0)
            key=gcd(key,m);
        if (map_states.find(key)!=map_states.end())
            next[cl][i]=map_states[key];
        else
        {
            map_states[key]=next[cl][i]=n_states;
            states[n_states++]=key;
        }
    }

for (int i=0;i<10;i++) 
    map_states_small[i]=map_states[i];
//printf("n_states = %d\n",n_states);
memset(f,0,sizeof(f));
for (int p=0;p<n_states;p++) 
    for (int s=1;s<100;s++) 
        if (states[p]%s==0) 
            f[0][p][s]++;

for (int c=1;c<=10;c++) 
    for (int p=0;p<n_states;p++) 
        for (int s=0;s<100;s++)
        {
            int t=0;
            for (int i=0;i<10 && i+s<100;i++) 
                { 
                    t+=f[c-1][next[p][i]][s+i]; 
                    if (t>=oo) 
                        { 
                            t=oo; 
                            break; 
                        } 
                }
            f[c][p][s]=t;
        }
memset(cL,0,sizeof(cL));
for (int c=1;c<=10;c++) 
    for (int i=1;i<10;i++) 
        { 
            cL[c]+=f[c-1][map_states_small[i]][i]; 
            if (cL[c]>=oo) 
                {
                    cL[c]=oo; 
                    break; 
                } 
        }
//for (int c=1;c<=10;c++) printf("c = %2d total = %d\n",c,cL[c]);
}
 
int solve(int n)
    {
        int L=1;
        for (;cL[L]<n;L++) 
            n-=cL[L];

        int ret=0,p=map_states_small[1],s=0;
        for (int k=0;k<L;k++) 
            for (int d=(int)(k==0);d<10;d++)
            {
                int t=f[L-1-k][next[p][d]][s+d];
                if (t<n) 
                    n-=t;
                else 
                { 
                    ret=ret*10+d; 
                    p=next[p][d]; 
                    s+=d; 
                    break; 
                }
            }
            return ret;
    }
 
int main()
{
    #ifdef _MSC_VER
    freopen("input.txt","r",stdin);
    #endif
    preprocess();
    for (int n;scanf("%d",&n)!=-1 && n!=0;) 
        printf("%d\n",solve(n));

    return 0;
}