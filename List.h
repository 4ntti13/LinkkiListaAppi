#include <ostream>
#include "Node.h"

class List
{
public:
    int m_count;
    Node* Head;
    Node* Tail;

    List();
    ~List();
    Node* Get(int index);
    void InsertHead(std::string val);
    void InsertTail(std::string val);
    void Insert(int index, std::string val);
    int Search(std::string val);
    void RemoveHead();
    void RemoveTail();
    void Remove(int index);
    int Count();
    void PrintList();

    Node& operator[](int index);

    friend std::ostream& operator<<(std::ostream& out, List& list);
};


