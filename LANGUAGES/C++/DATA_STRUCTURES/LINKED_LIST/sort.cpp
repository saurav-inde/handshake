#include "Linked_list.cpp"
#include <iostream>

class Sort_list : public Linked_list
{

public:
    using Linked_list ::Linked_list; // allow using base class constructor with given name
    void sort();
};

/*//////////////////////////////////////sort function body////////////////////////////////////*/

void Sort_list::sort()
{
    Node *ptr = head;
    // ith element selection for the selection sort
    for (size_t i = 0; i < this->length; i++)
    {
        if (i > 0)
        {
            ptr = ptr->next;
        }

        Node *min = ptr;
        for (Node *iter = ptr->next; iter != nullptr; iter = iter->next)
        {
            if (iter->data < min->data)
            {
                min = iter;
            }
        }
        swap_data(min, ptr);
    }
}

/*//////////////////////////////////////main function////////////////////////////////////*/

int main()
{

    Sort_list list1(30);
    list1.sort();
    list1.print();
}