/*#####################################################################################################################*/
/*Class Node and its Constructors*/

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node();

    Node(int data);

    Node(int data, Node *next);

    Node(int data, Node *next, Node *prev);
};

/*//////////////////////////////////////////////////////////////////////////*/

Node::Node()
{
    this->data = 0;
    this->next = this->prev = nullptr;
}

/*//////////////////////////////////////////////////////////////////////////*/

Node::Node(int data)
{
    this->data = data;
    this->next = this->prev = nullptr;
}

/*//////////////////////////////////////////////////////////////////////////*/

Node::Node(int data, Node *next)
{
    this->data = data;
    this->next = next;
    this->prev = nullptr;
}
/*//////////////////////////////////////////////////////////////////////////*/

Node::Node(int data, Node *next, Node *prev)
{
    this->data = data;
    this->next = next;
    this->prev = prev;
}