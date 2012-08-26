#include<stdio.h>
#include<assert.h>
#include <fstream>
#include <vector>
#include <algorithm>
#include <new>
#include <string>
#include <iostream>
/* maxVertices represents maximum number of vertices that can be present in the graph. */
void Dfs(vector<int> &graph, int presentVertex,int *visited)
{
        printf("Now visiting vertex %d\n",presentVertex);
        visited[presentVertex] = 1;
        /* Iterate through all the vertices connected to the presentVertex and perform dfs on those
           vertices if they are not visited before */
//        int iter;
        for(int iter=0;iter<graph[presentVertex].size();iter++)
        {
                if(!visited[graph[presentVertex][iter]])
                {
                        Dfs(graph,graph[presentVertex][iter],visited);
                }
        }
        return;
};
/* Input Format: Graph is directed and unweighted. First two integers must be number of vertces and edges
   which must be followed by pairs of vertices which has an edge between them. */
int main()
{
        ifstream InFile;
        InFile.open("input.txt");
        int n,m;
        InFile >> n >> m;
//        int graph[maxVertices][maxVertices],size[maxVertices]={0},visited[maxVertices]={0};
        vector <int> graph[n];
        int *visited = new int[n];
        memset(visited,0,sizeof(visited));

        int vertex1,vertex2;
        for(int iter=0;iter<m;iter++)
        {
                InFile >> vertex1 >> vertex2;
                assert(vertex1>=0 && vertex1<n);
                assert(vertex2>=0 && vertex2<n);

                graph[vertex1].push_back(vertex2);
        }
//        int presentVertex;
        for(int presentVertex=0;presentVertex<n;presentVertex++)
        {
                if(!visited[presentVertex])
                {
                        Dfs(graph,presentVertex,visited);
                }
        }
        return 0;

}
