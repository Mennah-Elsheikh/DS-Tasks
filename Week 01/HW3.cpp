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
    void right_rotate()
    {
        if (size <= 1)
            return;
        int last_item = arr[size - 1];
        for (int i = size - 1; i > 0; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[0] = last_item;
    }
    void right_rotate(int times)
    {
        times %= size; // the trick here is when we rotate the array times as the size we return to the original one
                       // like as 0 1 2 3 => 3 0 1 2 => 2 3 0 1 => 0 1 2 3 the same array "after rotates 4 times (size)"
        while (times--)
            right_rotate();
    }
};

int main()
{
    int n = 4;
    Vector v(n);
    for (int i = 0; i < n; ++i)
        v.set(i, i);
    v.print();
    v.right_rotate(7);
    v.print();
    v.right_rotate(4);
    v.print();
}
