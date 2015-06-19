#include <iostream>
#include <map>


using namespace std;
// 
int count_sort(int* arr, int size, int rangeOfNumbers = 10)
{
    map<int, int> allNumbers;
    for (int i = -rangeOfNumbers; i <= rangeOfNumbers; ++i)
    {
        allNumbers[i] = 0;
    }

    for (int i = 0; i < size; ++i)
    {
        int each = arr[i];
        allNumbers[each] += 1;
    }
    int counter = 0;
    for (int i = -rangeOfNumbers; i <= rangeOfNumbers; ++i)
    {
        for (int j = 0; j < allNumbers[i]; ++j)
        {
            arr[counter] = i;
            counter++;
        }
    }
}