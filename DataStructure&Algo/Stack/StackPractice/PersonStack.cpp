#include<bits/stdc++.h>
#include"../TemplateStack.h"
using namespace std;

int globalID = 100;

class person
{
    string name;
    int id;
    float salary;
public:
    person()
    {
        name = "";
        id = -1;
        salary = -1.0;
    }

    void setName(string name)
    {
        this->name = name;
    }
    void setSalary(float salary)
    {
        this->salary = salary;
    }

    person(string name, float salary)
    {
        setName(name);
        setSalary(salary);
        id = globalID;
        globalID++;
    }

    int getID()
    {
        return id;
    }
    string getName()
    {
        return name;
    }
    float getSalary()
    {
        return salary;
    }

    void print()
    {
        cout << name << " | " << id << " | " << salary << endl;
    }
};

int main()
{
    Stack <person> st;
    person a("Shihab", 235.2);
    person b("Sohan", 345.43);
    person c("Mishon", 263.3);

    st.push(a);
    st.push(b);
    st.push(c);

    while (!st.empty())
    {
        person printObj;
        printObj = st.pop();
        printObj.print();
    }
    

    // person printObj;
    // printObj = st.top();
    // printObj.print();

    cout << st.size() << endl;
    
    return 0;
    
}