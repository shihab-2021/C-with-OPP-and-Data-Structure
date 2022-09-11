#include<bits/stdc++.h>
using namespace std;

void print_list(list<int> l)
{
    list<int>:: iterator it;
    for(it=l.begin(); it!=l.end(); it++)
        cout << *it << " ";
    cout << endl;
}

int main()
{
    list<int> l;
    l.push_back(10);
    l.push_front(20);
    l.push_front(30);
    l.push_back(40);

    cout << l.front() << endl;
    print_list(l);

    return 0;
}