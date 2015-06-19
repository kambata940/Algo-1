#include <iostream>
#include <algorithm>

using namespace std;

int* insertion_sort(int * arr, int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        int j = i;
        while (arr[j + 1] < arr[j] && j >= 0)
        {
            swap(arr[j + 1], arr[j]);
            j--;
        }
    }
}