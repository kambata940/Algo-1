#include "CountSort.h"

using namespace std;

int main()
{
    int arr[10] = {3, -3, 3, 0, 3, -1, 4, 2, -1, -8};
    int size = 10;
    count_sort(arr, size);

    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    return 0;
}