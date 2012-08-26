#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <fstream>
using namespace std;
int main()
{
    int n;
    //char *p = "input.txt";
    //ifstream infile(p);
    cin >> n;
    vector<int> myVector;
    vector<int>::iterator it;
    vector<int>::reverse_iterator rit;
    for(int i=0;i<4;i++)
    {
        int temp;
        cin >> temp;
        myVector.push_back(temp);
    }
    sort(myVector.rbegin(),myVector.rend());

    printf("last\n");
    for(int i=0;i<n-4;i++)
    {
        int temp;
        cin >> temp;
        int last=myVector.back();
        if (temp>last)
        {
            myVector.pop_back();
            myVector.push_back(temp);
            printf("size is %d\n",myVector.size());
            sort(myVector.rbegin(),myVector.rend());
        }
    }
    printf(" %d \n",*it);
    for (it=myVector.begin(); it!=myVector.end(); it++)
        printf("%d\n",*it);

}
