    #include <iostream>
    #include <fstream>
    #include <sstream>
    #include <stdio.h>
    using namespace std;

    //var
    int surp_count;
    int score_count;
int main()
{
    char input[] = "B-large.in";
    char output[] = "out.txt";
    ifstream InFile;
    ofstream OutFile;
    InFile.open(input);
    OutFile.open(output);
    int t,n,s,p;
    InFile >> t;
    int ans=0;
    for(int i=0;i<t;i++)
    {
        InFile >>n>>s>>p;
        int S;
        ans = 0;
        for(int j=0;j<n;j++)
        {
             InFile >> S;
 //            cout << S << endl;
            int o = S /3;
            if(o==0) {if(p==0) ans++;}
            else if(S%3 == 0)
            {
                if(o+1==p) {if(s!=0){ans = ans+1; s--;}}
                else if(o>=p){ans = ans+1;}
            }
            else if(S%3 == 1) {
                    if(o+1>=p){ans++;}
            }

            else if(S%3==2)
            {
                if(o+2==p){if(s!=0){ans = ans+1; s--;}}
                else if(o+1>=p){ans = ans+1;}
            }

        }
         OutFile << "Case #"<< i+1 << ": "<< ans << endl;

    }
    InFile.close();
    OutFile.close();
}
