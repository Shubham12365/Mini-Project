#include <bits/stdc++.h>
using namespace std;

int main()
{

    ifstream read;
    read.open("File1.dat");
    string line;
    getline(read, line);
    for(int i=0;i<line.length();i++){
        if (line[i] >= 'a' && line[i] <= 'z')
            line[i] = line[i] - 32;
    cout << line[i];
    }
    
    read.close();
    ofstream out;
    out.open("File2.dat");
    out<<line;
    out.close();
    return 0;
}
