#include <iostream>
#include <list>

using namespace std;

list<int> quick_sort(list<int> lst, int size)
{
    if(size > 1)
    {
        int pivot = lst.front();
        list<int> smaller, greater;
        int iter1 = 0, iter2 = 0;
        list<int>::iterator it = lst.begin();
        it++;
        for (it; it != lst.end(); ++it)
        {
            cout <<"  "<<*it<<" ";
            if(*it <= pivot)
            {
                smaller.push_back(*it);
                lst.pop_front();
                iter1++;
            }
            else
            {
                greater.push_back(*it);
                lst.pop_front();
                iter2++;
            }
        }
        lst.pop_front();
        cout << endl;
        smaller = quick_sort(smaller, iter1);
        greater = quick_sort(greater, iter2);
        smaller.push_back(pivot);
        smaller.splice(smaller.end(), greater);
        return smaller;
    }
    
    return lst;
}

void test_quick_sort()
{
    int arr[10] = {3, -3, 22, 0, 3, -11, 44, 23, -1, 8};
    list<int> main_list;
    for (int i = 0; i < 10; ++i)
    {
        main_list.push_back(arr[i]); 
    }
    main_list = quick_sort(main_list, 10);

    for (int i = 0; i < 10; ++i)
    {
        cout << main_list.front() <<"  ";
        main_list.pop_front();
    }    
}

int main()
{
  test_quick_sort();
  return 0;
}