#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<int, int> M;
    M[3] = 9;
    M[2] = 3;
    M.insert(make_pair(1, 4));

    for(auto i : M)
        cout << "Key: " << i.first << " | " << i.second << endl;
    
    return 0;
}