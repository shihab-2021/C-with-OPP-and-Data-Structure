#include<iostream>
#include<iomanip>
#include<stdio.h>
using namespace std;

int main()
{
    double n = 9.987979892;

    cout << n << endl;
    cout << fixed << setprecision(4) << n << endl;
    cout << fixed << setprecision(8) << n << endl;

    printf("%.4lf\n", n);

    return 0;
}