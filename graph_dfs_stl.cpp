#include <cstdio>
#include <stdio.h>
#include <vector>
#include <queue>
#include <iostream>
#include <cstring>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
    ifstream InFile;
    InFile.open("input.txt");
    int n, m;
    InFile >> n >> m;
    vector <int> graph[n];
    int *l = new int[n];
    memset(l,0,n*sizeof(int));
//    for(int i=0;i<n;i++)
//        cout << l[i] << endl;

//    int t=0;
    for(int i = 0; i < m; i ++)
    {
        int u, v;
        InFile >> u >> v;
        u-=1;
        v-=1;
        l[u]++;
        l[v]++;
//        cout << u << " " << v << endl;
        graph[u].push_back(v);
        graph[v].push_back(u);
//        cout << graph[v-1][t] << "  " << graph[u-1][t] << endl;
//        t++;
    }
    for(int i=0;i<n;i++)
//        cout << l[i] << endl;
        if (l[i]==0)
        {
            printf("NO");
            return 0;
        }
     vector <int> p;
//    for(p=graph[0].begin())
    for(int i=0;i<n;i++)
        p.push_back(graph[i].size());

    sort(p.rbegin(),p.rend());
    if((p[0] <= 3)&&(n=(m+1))) printf("YES");
    else printf("NO");
return 0;
}
