#include <iostream>
using namespace std;
class MinHeap
{
private:
    int *arr;
    int parent(int i)
    {
        return abs(i - 1) / 2;
    }
    int left(int i)
    {
        return 2 * i + 1;
    }
    int right(int i)
    {
        return 2 * i + 2;
    }
    void heapify(int i)
    {
        int l = left(i), r = right(i), s = i;
        if (l < size and arr[l] < arr[i])
            s = l;
        if (r < size and arr[r] < arr[i])
            s = r;
        swap(arr[i], arr[s]);
        heapify(s);
    }

public:
    int capacity;
    int size;

    MinHeap(int capacity)
    {
        this->size = 0;
        this->capacity = capacity;
        this->arr = new int(capacity);
    }
    void insert(int data)
    {
        if (size == capacity)
            return;
        this->arr[size++] = data;
        int i = size - 1;
        while (i != 0 or arr[i] > arr[parent(i)])
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }
    int top()
    {
        return this->arr[0];
    }
};

int main()
{
    MinHeap mh = MinHeap(100);
    mh.insert(10);
    cout<<mh.top()<<endl;
    mh.insert(20);
    cout<<mh.top()<<endl;
    mh.insert(100);
    cout<<mh.top()<<endl;
    mh.insert(5);
    cout<<mh.top()<<endl;
    return 0;
}