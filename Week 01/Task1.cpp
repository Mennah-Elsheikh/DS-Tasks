#include <iostream>
#include <assert.h>
using namespace std;
class Vector
{ // the whole code
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
    // HW => medium 1
    void right_rotate()
    {
        if (size <= 1) // if the array is empty or have one item "We don't need to use the function :) "
            return;    // return nothing

        int last_item = arr[size - 1]; // assign the last item to variable => with the first iteration we lose it !
        for (int i = size - 1; i > 0; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[0] = last_item;
        // 0 1 2 3 4 => 0 1 2 3 3 => 0 1 2 2 3 => 0 1 1 2 3 => 0 0 1 2 3 => 4 0 1 2 3
    }
    // Another good solution
    //  void right_rotate ()
    // {
    //     int last_item = arr[size - 1] ;
    //     for(int i = size-2  ; i >= 0  ; i--)
    //     {
    //         arr[i] = arr[i];
    //     }
    //     arr[0] = last_item;
    // }
    // HW => medium 2
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
    // HW => medium 3
    void right_rotate(int times)
    {
        times %= size; // the trick here is when we rotate the array times as the size we return to the original one
                       // like as 0 1 2 3 => 3 0 1 2 => 2 3 0 1 => 0 1 2 3 the same array "after rotates 4 times (size)"
        while (times--)
            right_rotate();
    }
    // HW => medium 4
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
    int find(int value)
    { // searching for an item and return his index if found and -1 if not
        for (int i = 0; i < size; ++i)
            if (arr[i] == value)
                return i;
        return -1; // -1 for NOT found
    }
    // HW => medium 5
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
            //    int  temp = idx-1 ;
            //    arr[idx-1] = value ;
            //    arr[idx] = temp ;
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
    v.left_rotate();
    v.print();
    v.right_rotate();
    v.print();
    cout << "the index of the founded element " << v.find_transposition(2) << endl;
    v.right_rotate(7);
    v.print();
    v.right_rotate(4);
    v.print();
}
