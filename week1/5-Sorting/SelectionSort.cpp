#include "SelectionSort.h"

using namespace std;

int main()
{
    int arr[10] = {3, -3, 22, 0, 3, -11, 44, 23, -1, 8};
    int size = 10;
    selection_sort(arr, size);
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    return 0;
}