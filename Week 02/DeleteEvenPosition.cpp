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
    void delete_even_position()
    {
        if (length == 1)
        {
            return;
        }
        else if (length == 2)
        {
            head->next = nullptr;
            delete(tail);
            --length;
         }
        else
        {
            Node *prev = head;
            Node *curr = head->next;
            while (curr && curr->next)
            {
                prev->next = curr->next;
                curr->next = nullptr;
                delete (curr);
                /////////////
                prev = prev->next;
                if (prev != nullptr)
                {
                    curr = prev->next;
                }
                else
                {
                    curr = nullptr;
                }

                length--;
            }
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
    list.insert_end(10);
    list.print();
    // 1 2 3 4 10
    list.delete_even_position();
    list.print();
    // 1 3 10
    LinkedList list2;
    list2.insert_end(1);
    list2.insert_end(2);
    list2.insert_end(3);
    list2.insert_end(4);
    list2.insert_end(5);
    list2.insert_end(6);
    list2.print();
    // 1 2 3 4 5 6
    list2.delete_even_position();
    list2.print();
    // 1 3 5
    LinkedList list3;
    list3.insert_end(4);
    list3.insert_end(5);
    list3.print();
    list3.delete_even_position();
    list3.print();
    return 0;
}
