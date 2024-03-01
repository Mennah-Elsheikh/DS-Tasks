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
    Stack(int size) :  
                      size(size), top(-1)
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
    bool valid_parantheses(string s)
    {
        Stack stk(s.size());

        for (char c : s)
        {
            if (c == '(' || c == '[' || c == '{')
            {
                stk.push(c);
            }
            else
            {
                if (stk.isEmpty())
                {
                    return false;
                }
                if ((c == ']' && stk.peek() == '[') || (c == '}' && stk.peek() == '{') || (c == ')' && stk.peek() == '('))
                {
                    stk.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        return stk.isEmpty();
    }
};

int main()
{
    string s = "((()))";
    Stack stk(s.size());
    if (stk.valid_parantheses(s))
    {
        cout << "is valid " << endl;
    }
    else
    {
        cout << "is not valid" << endl;
    }
    return 0;
}
