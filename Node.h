#include <string>

class Node
{
public:
    Node* Next;
    std::string Value;

    Node() { Next = NULL; Value = ""; }
};



