#include<bits/stdc++.h>
using namespace std;

class Example
{
    public: 
        int x;
        Example(int a)
        {
            x = a;
        }
        Example operator +(Example obj)
        {
            Example ans(0);
            ans.x = x + obj.x;
            return ans;
        }
};

int main()
{
    Example a(10), b(20);
    Example ans = a+b;
    cout << ans.x << endl;
    return 0;
}