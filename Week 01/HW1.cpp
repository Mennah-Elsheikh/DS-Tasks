#include <iostream>
#include <assert.h>
using namespace std;
class Vector
{
private:
    int *arr = nullptr;
    int size = 0;

public:
    Vector(int size) : size(size)
    {
        if (size < 0)
            size = 1;
        arr = new int[size]{};
    }

    ~Vector()
    {
        delete[] arr;
        arr = nullptr;
    }

    int get_size()
    {
        return size;
    }

    int get(int idx)
    {
        assert(0 <= idx && idx < size);
        return arr[idx];
    }

    void set(int idx, int val)
    {
        assert(0 <= idx && idx < size);
        arr[idx] = val;
    }

    void print()
    {
        for (int i = 0; i < size; ++i)
            cout << arr[i] << " ";
        cout << "\n";
    }

    void left_rotate()
    {
        int first_item = arr[0]; // assign the first item to variable => with the first iteration we lose it !
        for (int i = 1; i < size; i++)
        {
            arr[i - 1] = arr[i];
        }
        arr[size - 1] = first_item;
        // what is the actually happend 0 1 2 3 => 1 1 2 3 => 1 2 2 3 => 1 2 3 3 => 1 2 3 0
    }
};

int main()
{
    int n = 4;
    Vector v(n);
    for (int i = 0; i < n; ++i)
        v.set(i, i);
    v.print();
    v.left_rotate();
    v.print();
}
