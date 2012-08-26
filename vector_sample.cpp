#include <vector>
#include <iostream>

using namespace std;
int main()
{
    int n=2;
    vector <int> a[n];
    for (int i=0;i<n;i++)
    {
        int t1,t2;
        cin >> t1 >> t2;
        a[i].push_back(t1);
        a[i].push_back(t2);

    }
    cout << a[0][0] << endl;
    cout << a[1][0] << endl;
    cout << a[1][1] << endl;

    return 0;
}
