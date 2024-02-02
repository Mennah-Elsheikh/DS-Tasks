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
    int pop(int idx) // the same as the left_rotate function :)
    {
        assert(idx >= 0 && idx < size); // check if the index is valid or not
        int deleted_item = arr[idx];    // we assign the item of the target index that we will pop it later from the array
        for (int i = idx + 1; i < size; i++)
        {
            arr[i - 1] = arr[i]; // shiftting to the left
        }
        size--; // the size will be decreased as we deleted an item alraedy
        // what is actually happened if the idx is 2  => 0 1 2 3 4 => 0 1 3 3 4 => 0 1 3 4 4 => 0 1 3 4
    }
};

int main()
{
    int n = 4;
    Vector v(n);
    for (int i = 0; i < n; ++i)
        v.set(i, i);
    v.print();
    v.pop(2);
    v.get_size();
    v.print();
}
