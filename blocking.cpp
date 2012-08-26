#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std;

const int maxn  =   105;

int ship[maxn],port[maxn][maxn],rank[maxn][maxn];
int n,m,proposed[maxn],mx[maxn],my[maxn];

inline bool cmp(const int &i,const int &j)
{
    return ship[i]<ship[j];
}

int main()
{
    ifstream InFile;
    InFile.open("input.txt");
    InFile >> n;
    for (int i=0;i<n;++i){
        for (int j=0;j<n;++j){
            InFile >> ship[j];
            rank[i][j]=j;
            port[j][i]=ship[j];
//            cout << " " << rank[i][j] << "RANK" << endl;
        }

        sort(rank[i],rank[i]+n,cmp);
    }
    cout << "OUTPUT: " << endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout << rank[i][j] << "   " << port[j][i] << endl;
    }

    memset(mx,-1,sizeof(mx));
    memset(my,-1,sizeof(my));
    memset(proposed,0,sizeof(proposed));
    bool change=true;
    while (change){
        change=false;
        for (int i=0;i<n;++i) while (mx[i]==-1){
            change=true;
            int w=rank[i][proposed[i]++];
            if (my[w]==-1){
                my[w]=i;
                mx[i]=w;
            }else{
                int j=my[w];
                if (port[w][i]>port[w][j]){
                    my[w]=i;
                    mx[i]=w;
                    mx[j]=-1;
                }
            }
        }
    }

    for (int i=0;i<n;++i)
        printf("%d ",mx[i]+1);
    puts("");
}

