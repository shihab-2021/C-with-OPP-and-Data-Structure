#include<bits/stdc++.h>
using namespace std;

void print_vector(vector<int> v)
{
    for (int i = 0; i < 5; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> v;
    // vector<int>:: iterator it;

    // ------------------------rend
    v.push_back(100);   //  begin
    v.push_back(200);
    v.push_back(300);
    v.push_back(400);
    v.push_back(500);   //  rbegin
    // ------------------------end

    for(auto it=v.begin(); it!=v.end(); it++)
        cout << *it << " ";
    cout << endl;

    // for (int i = 0; i < v.size(); i++)
    //     cout << v[i] << " ";
    // cout << endl;

    for (int i = 0; i < v.size()+2; i++)
        cout << v.at(i) << " ";
    cout << endl;
    
    cout << v[0] << endl;
    cout << v.front() << endl;

    cout << v[v.size()-1] << endl;
    cout << v.back() << endl;

    // v.resize(3);
    // v.shrink_to_fit();

    // print_vector(v);

    vector<int> v1, v2;
    v1.push_back(100);
    v1.push_back(200);

    v2.push_back(300);
    v2.push_back(400);

    v1 = v2;
    // v1.assign(v2);
    print_vector(v1);

    v1.pop_back();
    v1.pop_back();
    print_vector(v1);

    v2.clear();
    print_vector(v2);

    v1.push_back(100);
    v1.push_back(200);

    v2.push_back(300);
    v2.push_back(400);
    v2.push_back(500);

    // swap(v1[0], v2[0]);
    // swap(v1, v2);
    v1.swap(v2);
    print_vector(v1);
    print_vector(v2);

    vector<int> v3;
    v3.push_back(1);    //  0
    v3.push_back(2);    //  1
    v3.push_back(4);    //  2
    v3.push_back(5);    //  3
    // v3.end()             //  4

    v3.insert(v3.begin()+2, 3);
    print_vector(v3);
    // v3.insert(v3.begin()+2, 3, 3);
    // print_vector(v3);

    v3.erase(v3.begin()+1, v3.begin()+3);
    print_vector(v3);

    v3.push_back(1);
    v3.push_back(2);
    v3.push_back(3);
    v3.push_back(4);
    v3.push_back(5);

    sort(v3.begin(), v3.end()); //  O(nlog(n))
    // sort(v3.begin(), v3.end(), greater<int>()); 
    // reverse(v3.begin(), v3.end());
    print_vector(v3);
    // sort(v3.begin(), v3.end()-2);
    // print_vector(v3);

    int n;
    cin >> n;
    vector<int> v4(n);
    print_vector(v4);   // 0 0 0 0 0 0 ......
    vector<int> v4(n, 5);
    print_vector(v4);   // 5 5 5 5 5 5 ......
    // for (int i = 0; i < n; i++)
    // {
    //     int a;
    //     cin >> a;
        // v4.push_back(a);       This is not wright way for this situation 
    // }
    // print_vector(v4);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];    // good way for this situation
    }
    

    return 0;
}