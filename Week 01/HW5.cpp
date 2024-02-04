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
    int find(int value)
    { // searching for an item and return his index if found and -1 if not
        for (int i = 0; i < size; ++i)
            if (arr[i] == value)
                return i;
        return -1; // -1 for not found item
    }
    int find_transposition(int value)
    {
        int idx = find(value); // this is the find function we creared before
        if (idx <= 0)
        {
            return idx;
            // -1 => the item is not found
            // 0 =>  the item is actually the first item => we can't shift this position more than that *_*
        }
        else
        {
            swap(arr[idx], arr[idx - 1]);
            // what is actually happened :)
            //int temp = arr[idx-1];
            //arr[idx-1] = arr[idx];
            //arr[idx] = temp;

            return idx;
        }
    }
};

int main()
{
    int n = 4;
    Vector v(n);
    for (int i = 0; i < n; ++i)
        v.set(i, i);
    v.print();
    cout << v.find_transposition(1) << endl;
}
