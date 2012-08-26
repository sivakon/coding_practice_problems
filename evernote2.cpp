//#Enter your code here
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>
using namespace std;
struct myclass {
  bool operator() (pair<string,int> i,pair<string,int> j) {
        if(i.second<j.second)
            return true;
        else if(i.second=j.second)
            return i.first < i.second;
        else
            return false;
      }
} myf;

int main ()
{
  map<string,int> mymap;
  map<string,int>::iterator it;
  int n;
  cin >> n;
  for(int i=0;i<n;i++)
  {

  	string t;
  	cin >> t;
  	it=mymap.find(t);
   	if(it==mymap.end())
   	{
   	  mymap[t]=1;

   	}
  	else
	{
	  int temp=it->second;
	  temp+=1;
	  it->second=temp;
	}

  }


    vector< pair<string,int> > myVector;
    vector< pair<string,int> >::iterator vit;

    for(it=mymap.begin();it!=mymap.end();it++)
        myVector.push_back(std::make_pair(it->first,it->second));

    //for(vit=myVector.begin();vit!=myVector.end();vit++)
    //    cout << vit->first << " = > " << vit->second << endl;

    sort(myVector.begin(),myVector.end(),myf);
    reverse(myVector.begin(),myVector.end());
  // print content:
    //cout << "elements in mymap:" << endl;
    //for(vit=myVector.begin();vit!=myVector.end();vit++)
    //    cout << vit->first << " = > " << vit->second << endl;

    int c=myVector.size();
    int k;
    cin >> k;
    for(vit=myVector.begin();vit!=myVector.begin()+k;vit++)
        cout << vit->first << endl;
  return 0;
}
