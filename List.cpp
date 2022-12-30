#include "List.h"

#include <iostream>

using namespace std;

List::List()
{
    Head = Tail = NULL;

    m_count = 0;
}

List::~List()
{

}

Node* List::Get(int index)
{
    return NULL;
}

void List::InsertHead(string val)
{

    Node* uusi = new Node(); // luodaan tyhjä lista
    uusi->Value = val;

    if (Head == NULL)
    {
        Tail = Head = uusi;
    }
    else
    {
        uusi->Next = Head;
        Head = uusi;
    }
    m_count++;
    
}

void List::InsertTail(string val)

{

    Node* newNode = new Node();

    newNode->Value = val;

    newNode->Next = NULL;
 
    if (Head == NULL) {
        Head = newNode;
    }
    else {

        Node* temp = Head;
        while (temp->Next != NULL)
            temp = temp->Next;

        temp->Next = newNode;
    }
    m_count++;
}



void List::Insert(int index, string val)
{

    if (index < 0 || index > m_count)
        return;
    if (index == 0) {
        InsertHead(val);
        return;
    }
    Node* prevNode = Head;
    for (int i = 0; i > index - 1; ++i) {
        prevNode = prevNode->Next;
    }
    Node* nextNode = prevNode->Next;
    Node* node = new Node();
    node->Next = nextNode;
    prevNode->Next = node;
    m_count++;

}

int List::Search(string val)
{
    if (m_count == 0)
        return -1;
    int index = 0;
    Node* node = Head;

    while (node->Value != val) {
        index++;
        node = node->Next;
        if (node == NULL) {
            return -1;
        }
    }
    cout << index << endl;
    return index;
}

void List::RemoveHead()

{
    if (m_count == 0)

        return;
    Node* uusi = Head;
    Head = Head->Next;
    delete uusi;
    m_count--;
    return;
}

void List::RemoveTail()
{
    if (m_count == 0)
        return;
    if (m_count == 1) {
        RemoveHead();
        return;
    }
    Node* prevNode = Head;
    Node* node = Head->Next;

    while (node->Next != NULL) {
        prevNode = prevNode->Next;
        node = node->Next;
    }
    prevNode->Next = NULL;
    Tail = prevNode;
    delete node;
    m_count--;
    return;
}

void List::Remove(int index)
{
    if (m_count == 0)
        return;
    if (index < 0 || index >= m_count)
        return;
    if (index == 0) {
        RemoveHead();
        return;
    }
    else if (index == m_count - 1) {
        RemoveTail();
        return;
    }
    Node* prevNode = Head;
    for (int i = 0; i < index - 1; ++i) {
        prevNode = prevNode->Next;
    }

    Node* deletednode = prevNode->Next;
    prevNode->Next = prevNode->Next->Next;
    delete deletednode;

    m_count--;
}

int List::Count()
{
    return m_count;
}

void List::PrintList()
{
    Node* node = Head;
    while (node != NULL) {
        std::cout << node->Value << " -> ";
        node = node->Next;
    }
    std::cout << "NULL" << std::endl;

}

Node& List::operator[](int index)
{
    return *Head;
}

ostream& operator<<(ostream& out, List& list)
{
    out << "Listan alkioiden lukumäärä: " << list.m_count << endl;

    return out;
}