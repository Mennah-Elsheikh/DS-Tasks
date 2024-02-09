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
    void swap_head_tail()
    {
        // if (head == nullptr || tail == nullptr || head == tail)
        //     return; // List is empty, has only one node, or head and tail are already the same
        // or
        if (length == 0 || length == 1)
        {
            return;
        }
        else if (length == 2)
        {
            tail->next = head;
            head->next = NULL;
            swap(head, tail);
        }
        else
        {
            Node *point = head;
            while (point->next != tail)
            {
                point = point->next;
            }
            tail->next = head->next;
            point->next = head;
            head->next = nullptr;
            swap(tail, head);
        }
    }
};

int main()
{

    LinkedList list;
    list.insert_end(1);
    list.insert_end(2);
    list.insert_end(3);
    list.insert_end(4);
    list.insert_end(5);
    list.print();
    // 1 2 3 4 5
    list.swap_head_tail();
    list.print();
    // 5 2 3 4 1
    return 0;
}
