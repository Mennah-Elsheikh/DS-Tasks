#include <iostream>
#include <cassert>
using namespace std;

class Stack
{
private:
    int size{};
    int top{};
    char *array{};

public:
    Stack(int size) : size(size), top(-1)
    {
        array = new char[size];
    }

    ~Stack()
    {
        delete[] array;
    }

    void push(int x)
    {
        assert(!isFull());
        array[++top] = x;
    }

    int pop()
    {
        assert(!isEmpty());
        return array[top--];
    }

    int peek()
    {
        assert(!isEmpty());
        return array[top];
    }

    int isFull()
    {
        return top == size - 1;
    }

    int isEmpty()
    {
        return top == -1;
    }
    int reverse_a_number(int num)
    {
        // 123 => 321 push 3 , push 2 , push 1 => pop() => 1  + 2 * 10 + 3 * 100
        if (num == 0)
            return 0;
        Stack stk(30);
        while (num)
        {
            int n = num % 10;
            stk.push(n);
            num /= 10;
        }
        int result = 0;
        int n = 1;
        while (!stk.isEmpty())
        {
            result += stk.pop() * n;
            n = n * 10;
        }
        return result;
    }
    void display()
    { // push 10 20 30 40 => display 40 30 20 10 :)
        for (int i = top; i >= 0; i--)
            cout << array[i] << " ";
        cout << "\n";
    }
};

int main()
{

    Stack stk(3);
    cout << stk.reverse_a_number(123) << endl;
    return 0;
}
