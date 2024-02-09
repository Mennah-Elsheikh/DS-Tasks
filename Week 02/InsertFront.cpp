#include <iostream>
#include <cassert>
using namespace std;

struct Node
{
    int data{};
    Node *next{};
    Node(int data) : data(data) {}
};

class LinkedList
{
private:
    Node *head{};
    Node *tail{};
    int length = 0;

public:
    ~LinkedList()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *deleted_node = current;
            current = current->next;
            delete deleted_node;
        }
        head = nullptr;
        tail = nullptr;
        length = 0;
    }
    void Insert_front(int value)
    {
        Node *new_node = new Node(value); // create new node
        if (!head)
        {
            head = tail = new_node;
        }
        else
        {
            new_node->next = head;
            head = new_node;
        }
        ++length;
    }
    void print()
    {
        // DON'T change head itself
        for (Node *cur = head; cur; cur = cur->next)
            cout << cur->data << " ";
        cout << "\n";
    }

    // using is_empty() function
    void insert_end(int value)
    {
        Node *item = new Node(value);

        if (is_empty()) // if the list is empty
            head = tail = item;
        else
        {
            tail->next = item;
            tail = item;
        }
        ++length;
    }
    bool is_empty()
    {
        return !head;
    }
};

int main()
{

    LinkedList list;
    list.insert_end(6);
    list.insert_end(10);
    list.insert_end(8);
    list.insert_end(15);

    list.Insert_front(7);
    list.Insert_front(5);
    list.Insert_front(1);
    list.print();
    // 1 5 7 6 10 8 15
    return 0;
}
