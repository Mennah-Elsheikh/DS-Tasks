#include <iostream>
using namespace std;
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

    void push(char x)
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
    string reverse_subwords(string s)
    {
        string str = "";
        Stack stk(s.size());
        for (char c : s)
        {
            stk.push(c);
        }

        // pop characters from the stack to reverse the string
        while (!stk.isEmpty())
        {
            str += stk.pop();
        }
        return str;
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
    string s = "abc";
    cout << stk.reverse_subwords(s);
    return 0;
}
