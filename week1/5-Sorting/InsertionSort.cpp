#include "InsertionSort.h"
using namespace std;

int main()
{
    int arr[10] = {3, -3, 22, 0, 222, -11, 44, 23, -1, 8};
    int size = 10;
    insertion_sort(arr, size);

    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }

    return 0;
}