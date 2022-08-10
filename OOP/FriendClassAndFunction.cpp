#include<bits/stdc++.h>
using namespace std;

class Parent
{
    private:
        int taka;
    public:
        Parent(int tk)
        {
            taka = tk;
        }
        friend class ParentFriend;
        friend void tellSecret(Parent *ptr);
};

class ParentFriend
{
    public:
        void tellSecret(Parent *ptr)
        {
            cout << ptr->taka << " from friend class." << endl;
        }
};

void tellSecret(Parent *ptr)
{
    cout << ptr->taka << " from friend function." << endl;
}

int main()
{
    Parent pt(1500);
    ParentFriend pf;
    pf.tellSecret(&pt);
    tellSecret(&pt);
    return 0;
}