#include <iostream>
using namespace std;

int const MAX = 100000;


void merge(int*& arr, int middle_index, int last_index)
{
    int size1 = middle_index, size2 = last_index - middle_index + 1;
    int L[size1+1], R[size2+1];
    int rightIter = 0, leftIter = 0, i = 0;
    for (i = 0; i < last_index+1; ++i)
    {
        if (i < size1)
        {
            L[leftIter] = arr[i];
            leftIter++;
        }
        else
        {
            R[rightIter] = arr[i];
            rightIter++;
        }
        
    }
    L[size1] = MAX;
    R[size2] = MAX;
    rightIter = 0;
    leftIter = 0;
    i = 0;
    
    while(L[leftIter] < MAX || R[rightIter] < MAX) 
    {
        if(L[leftIter] <= R[rightIter])
        {

            arr[i] = L[leftIter];
            leftIter++;
        }
        else
        {
            arr[i]  = R[rightIter];
            rightIter++;
        }
        i++;
    }
}

void merge_sort(int* arr, int size)
{
    if(size > 1)
    {
        int size1 = size/2, size2 = size - size1;
        
        merge_sort(arr, size1);
        merge_sort(arr + size1, size2);
        merge(arr, size1 , size - 1);
    }
}

int main()
{
    int arr[10] = {3, -3, 22, 0, 3, -11, 44, 23, -1, 8};
    merge_sort(arr, 10);
    for (int i = 0; i < 10; ++i)
    {
        cout << arr[i] << " ";
    }
    return 0;
}