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
    bool is_the_same(LinkedList &list2)//passing object as a parameter (reference) 
    {
        if(length != list2.length)
        return false ;//actually they are not the same
        Node*current1 = head ;
        Node*current2 = list2.head;
        //i will iterate over each two nodes and chech if they are the same 
        while(current1)
        {
            if(current1->data != current2->data )
            {
                return false  ; //i won't continue 
            }
            current1 = current1->next ;
            current2 = current2->next ;
        }
        return true ;
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
    LinkedList list2 ; 
    list2.insert_end(6);
    list2.insert_end(10);
    list2.insert_end(8);
    list2.insert_end(15);

    list2.Insert_front(7);
    list2.Insert_front(5);
    list2.Insert_front(1);
    list2.print();
    // 1 5 7 6 10 8 15
    if(list.is_the_same(list2))//oop
    {
        cout<<"they are the same"<<endl;
    }
    else 
    {
        cout<<"they are not the same"<<endl;
    }


    return 0;
}
