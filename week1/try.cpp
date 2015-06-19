#include <iostream>

using namespace std;

int main()
{
    int * p1, * p2;
    p1 = new int [10];
    p1[0] = 1;
    p1[3] = 55;
    p2 = p1 + 3;
    swap(*p1, *p2);
    cout << p2[0] <<" v" <<p1[0];
    return 0;
}