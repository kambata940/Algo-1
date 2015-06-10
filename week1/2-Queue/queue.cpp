#include <iostream>
#include <list>

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


class queue
{
    vector data;
public:
    queue() :data() {}

    void push(int value)
    {
        data.add(value);
    }

    bool pop()
    {
        data.remove(0);
    }

    int peek()
    {
        if(data.getSize() == 0) return false;
        return data.get(0);
    }

    int getSize()
    {
        return this->data.getSize();
    }
};

void testQueue()
{
    queue NewQueue;
    NewQueue.push(5);
    cout << NewQueue.peek() <<endl<<NewQueue.getSize() <<endl;
    NewQueue.push(0);
    NewQueue.pop();
    cout << NewQueue.peek()<<endl;
    NewQueue.pop();
    NewQueue.push(500);
    cout << NewQueue.peek()<<endl;
}

int main()
{
    testQueue();
    return 0;
}