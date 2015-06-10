#include <iostream>

using namespace std;

class vector
{
    int size, capacity;
    int *arr;

    void extendVector()
    {
        capacity *= 2;
        int *temp = new int [capacity];
        for (int i = 0; i < size - 1; --i)
        {
            temp[i] = arr[i];
        }
        arr = temp;
    }
public:
    vector()
    {
        size = 0;
        capacity = 100;
        arr = new int [100]; 
    }

    vector(const int capacity)
    {
        this->capacity = capacity;
        size = 0;
        arr = new int [capacity]; 
    }

    int getSize()
    {
        return this->size;
    }

    int getCapacity()
    {
        return this->capacity;
    }

    bool insert(const int index, const int value)
    {
        if (index < 0 || index > size) return false;
        if (index == size)
        {
            this->add(index);
            return true;
        }

        for (int i = size; i > index; --i)
        {
            arr[i] = arr[i -1];
        }
        arr[index] = value;
        return true;
    }

    void add(const int value)
    {
        if (size == capacity) extendVector();
        arr[size] = value;
        size++;
    }

    bool pop()
    {
        if (size == 0 )
        {
            return false;       
        }
        
        if (4 * size < capacity)
        {
            capacity = 2 * size;
            int * temp = new int [capacity];
            for (int i = 0; i < size; ++i)
            {
                temp[i] = arr[i];
            }
            arr = temp;
        }
        size--;
    }

    bool remove(int index)
    {
        if (index < 0 || index > size)
        {
            return false;
        }
        if (index == size)
        {
            return pop();
        }
        if (4 * size == capacity)
        {
            capacity = 2 * size;
            int * temp = new int [capacity];
            for (int i = 0; i < index; ++i)
            {
                temp[i] = arr[i];
            }
            arr = temp;
        }
        for (int i = index; i < size; ++i)
        {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    int get(const int index)
    {
        return arr[index];
    }
};

void testVector()
{
	vector NewVector;
	for (int i = 0; i < 10; ++i)
	{
		NewVector.add(i + 2);
	}
	NewVector.insert(3, 555);
	NewVector.pop();
	NewVector.remove(5);

	for (int i = 0; i < NewVector.getSize(); ++i)
	{
		cout << NewVector.get(i)<< "  ";

	}
}

int main()
{
	testVector();
	return 0;
}