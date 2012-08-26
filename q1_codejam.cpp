#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>

using namespace std;
int main()
{
    char input[] = "A-small-attempt0.in";
    char output[] = "out.txt";
    ifstream InFile;
    ofstream OutFile;
    InFile.open(input);
    OutFile.open(output);
    int t, l;
    InFile >> t;
    string s;
    s = new char[101];
    getline(InFile, s);
    for(int j = 1; j<=t; j++)
    {
        getline(InFile, s);
        l = (s).size();
        OutFile << "Case #" << j << ": ";
        for(int i =0;i<l;i++)
        {
            if(s[i] == 'y') OutFile <<'a';
            else if (s[i]=='n') OutFile << 'b';
            else if (s[i]=='f') OutFile << 'c';
            else if (s[i]=='i') OutFile << 'd';
            else if (s[i]=='c') OutFile << 'e';
            else if (s[i]=='w') OutFile << 'f';
            else if (s[i]=='l') OutFile << 'g';
            else if (s[i]=='b') OutFile << 'h';
            else if (s[i]=='k') OutFile << 'i';
            else if (s[i]=='u') OutFile << 'j';
            else if (s[i]=='o') OutFile << 'k';
            else if (s[i]=='m') OutFile << 'l';
            else if (s[i]=='x') OutFile << 'm';
            else if (s[i]=='s') OutFile << 'n';
            else if (s[i]=='e') OutFile << 'o';
            else if (s[i]=='v') OutFile << 'p';
            else if (s[i]=='z') OutFile << 'q';
            else if (s[i]=='p') OutFile << 'r';
            else if (s[i]=='d') OutFile << 's';
            else if (s[i]=='r') OutFile << 't';
            else if (s[i]=='j') OutFile << 'u';
            else if (s[i]=='g') OutFile << 'v';
            else if (s[i]=='t') OutFile << 'w';
            else if (s[i]=='h') OutFile << 'x';
            else if (s[i]=='a') OutFile << 'y';
            else if (s[i]=='q') OutFile << 'z';
            else OutFile << ' ';

        }
            OutFile << '\n';
        }
    InFile.close();
    OutFile.close();
    return 0;
    }
