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
    InFile.open("LABYR1_input.txt");
    int n, m;
    InFile >> n >> m;
    vector <int> graph[n];
    for(int i = 0; i < m; i ++)
    {
        for(int j=0;j<n;j++)
       {
            char t;
            InFile >> t;
            if(t!='#')
            {
                graph[i].push_back((int)(j));
                graph[j].push_back((int)(i));
            }
        }


    }
    vector <int> sizes;
    for(int i=0;i<n;i++)
        sizes.push_back(graph[i].size());

    sort(sizes.rbegin(),sizes.rend());
    printf("%d",++sizes[0]);
    return 0;
}
