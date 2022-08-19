#include <iostream>
#include <cstdlib>
#include "Node.cpp"

/*#####################################################################################################################*/
/*Linked List Class*/

class Linked_list
{

public:
    int length;
    Node *head;
    Node *tail;
    Linked_list();
    Linked_list(int length);
    void insert_node(int key_next, int new_data);
    void delete_node(int key);
    void set_data();
    void print();
    void swap_data(Node *node1, Node *node2);
    Node *operator[](int n)
    {
        Node *ptr = head;
        for (size_t i = 0; i < n; i++)
        {
            ptr = ptr->next;
        }
        return ptr;
    }
};

/*//////////////////////////////////////Constructors////////////////////////////////////*/

Linked_list::Linked_list()
{
    tail = head = new Node();
    length = 1;
}

Linked_list::Linked_list(int length)
{
    this->length = length;
    this->head = new Node();
    Node *current, *previous = head;

    for (size_t i = 0; i < length - 1; i++)
    {
        current = new Node(0, nullptr, previous);
        previous->next = current;
        previous = current;
    }
    tail = current;
    set_data();
}
/*//////////////////////////////////////insert function////////////////////////////////////*/

void Linked_list::insert_node(int key, int new_data)
{
    Node *ptr = this->head;
    while (ptr->data != key)
    {
        ptr = ptr->next;
    }

    Node *new_node = new Node(new_data, ptr->next, ptr->prev);
    ptr->next = new_node;
    new_node->next->prev = new_node;
    this->length++;
}
/*//////////////////////////////////////delete function////////////////////////////////////*/

void Linked_list::delete_node(int key)
{
    Node *ptr = this->head;
    while (ptr->data != key)
    {
        ptr = ptr->next;
    }

    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    delete ptr;
    length--;
}
/*//////////////////////////////////////set data function////////////////////////////////////*/

void Linked_list::set_data()
{
    Node *ptr = this->head;
    for (int data, i = 0; i < this->length - 1; i++)
    {
        // std::cout << "Enter the data for the node " << i + 1 << " : ";
        // std::cin >> data;

        ptr->data = rand() % 1000;
        ptr = ptr->next;
    }
}

/*//////////////////////////////////////print function////////////////////////////////////*/

void Linked_list::print()
{
    Node *ptr = head;
    for (size_t i = 0; i < this->length - 1; i++)
    {
        std::cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

/*//////////////////////////////////////swap data function////////////////////////////////////*/

void Linked_list::swap_data(Node *node1, Node *node2)
{
    int temp = node1->data;
    node1->data = node2->data;
    node2->data = temp;
}

/*#####################################################################################################################*/
/*operator overloads*/

// Linked_list operator [] (int n){

// }
