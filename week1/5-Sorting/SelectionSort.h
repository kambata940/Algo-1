#include <iostream>
#include <algorithm>

using namespace std;

int* selection_sort(int * arr, int size)
{
    if(size <= 1) return arr;

    for (int i = 0; i < size; ++i)
    {
        int minElem  = arr[i];
        for (int j = i + 1; j < size; ++j)
        {
            if(arr[j] < minElem)
            {
                swap(arr[j], minElem);
            }
        }
        arr[i] = minElem;
    }

    return arr;
}