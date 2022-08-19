#include <iostream>
#include <cstdlib>
#include "Linked_list.cpp"
using namespace std;

int main()
{

    int n;
    cout << "Enter the number of Linked Lists: ";
    cin >> n;
    Linked_list list[n];

    for (size_t i = 0; i < n; i++)
    {
        list[i] = Linked_list(rand() % 30 + 5);
        cout << "List " << i + 1 << " : ";
        list[i].print();
        cout << endl
             << "element 5 : " << list[i][4]->data;
        cout << endl;
    }

    return 0;
}