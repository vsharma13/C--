#include "SimpleList.h"

// Node class Definitions

template<typename T>
Node<T>::Node(T value) : data(value), next(nullptr), prev(nullptr) {}

template <typename T>
T Node<T>::getData() const {return data;}

template <typename T> 
Node<T>* Node<T>::GetNext() const { return next; }

template <typename T> 
Node<T>* Node<T>::GetPrevious() const { return prev; }

template <typename T>
void Node<T>::SetNext(Node<T>* nextNode) { next = nextNode; }

template <typename T>
void Node<T>::SetPrevious(Node<T>* prevNode) { prev = prevNode; }

// LinkedList class Method's definitions

/*
    Utility function : Copy the given linkedList
*/
template <typename T>
inline void LinkedList<T>::copyList(const LinkedList &llist)
{
    head = nullptr;
    Node<T>* current = llist.head;
    while ( current != nullptr ){
        ListAddNodeAtEnd( current -> Getdata());
        current = current->GetNext();
        if(current == llist.head) break; // Stop if the list is circular
    }
}

/*
    Utility function : move the given linkedList
*/
template<class T> void LinkedList<T>::moveLList(LinkedList&& llist)
{
    type = llist.type;
    head = llist.head;
    llist.head = nullptr;
}

/*
    Utility function : clear the given linkedList
*/
template <typename T>
void LinkedList<T>::clearList() {
    while(head) {
        ListRemoveNodeAtBeginning();
    }
}

/* LinkedList Class default constructor*/
template <typename T>
LinkedList<T>::LinkedList(ListType lltype) : type(lltype), head(nullptr) {};

/* LinkedList Class copy constructor*/

template <typename T>
LinkedList<T>::LinkedList(const LinkedList &other) : type(other.type), head(nullptr)
{
    copyList(other);
}

/* LinkedList Class copy assignment operator*/

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& llist) {
    if (this != &llist) {
        clearList();
        type = llist.type;
        copyList(llist);
    }
    return *this;
}

/* LinkedList Class move constructor*/

template <typename T>
LinkedList<T>::LinkedList(LinkedList&& llist) noexcept : type(llist.type), head(llist.head) {
    llist.head = nullptr;
}

/* LinkedList Class move assignment operator*/
template <typename T> 
LinkedList<T>& LinkedList<T>::operator=(LinkedList&& llist) noexcept {

    if (this != llist ) {
        clearList();
        type = llist.type;
        head = llist.head;
        llist.head = nullptr;
    }
    return *this;
}

/* Destructor */

template <typename T> LinkedList<T>::~LinkedList() {
    clearList();
}

//Linked List member functions
template <typename T>
void LinkedList<T>::ListInitialize() {
    head = nullptr;
}

template <typename T>
void LinkedList<T>::ListAddNodeAtEnd(T value) {
    
    Node<T>* newNode = new Node<T>(value);
    if (!head) {
        head = newNode;
    }
    else {
        Node<T>* temp = head;
        while (temp->getNext() != nullptr) {
            temp = temp->GetNext();
        }
        temp = temp->SetNext(newNode);
        if(type == doubly || type == circular) {
            newNode->SetPrevious(temp);
        }
        if(type == circular) {
            newNode->SetNext(head);
            head->SetPrevious(newNode);
        }
        
    }
}

template <typename T>
void LinkedList<T>::ListAddNodeAtBeginning(T value) {

    Node<T>* newNode = new Node<T>(value);
    if(!head) {
        head = newNode;
        if (type == circular) {
            head->SetNext(head);
            head->SetPrevious(head);
        }
        else {
            newNode->SetNext(head);
            if( type == doubly || type == circular) {
                head->SetPrevious(newNode);
            }
            head = newNode;
            if ( type == circular) {
                Node<T>* temp = head;
                while (temp->GetNext() != head) {
                    temp = temp->GetNext();
                }
                temp->SetNext(head);
                head->SetPrevious(temp);
            }
        }
    }
}

template <typename T>
void LinkedList<T>::ListAddNodeAt(T value, size_t position) {
    if (position == 0) {
        ListAddNodeAtBeginning(value);
        return;
    }

    Node<T>* newNode = new Node<T>(value);
    Node<T>* temp = head;

    for(size_t i=0; i < position-1 && temp->GetNext() != nullptr; ++i) {
        temp = temp->GetNext();
    }

    newNode->SetNext(temp->GetNext());

    if( temp->GetNext() != nullptr && (type == doubly || type  == circular)) {
        temp->GetNext()->SetPrevious(newNode);
    }

    temp->SetNext(newNode);
    if(type == doubly || type == circular) {
        newNode->SetPrevious(temp);
    }
}

template <typename T>
void LinkedList<T>::ListRemoveNodeAtEnd(T value)
{
    if (!head) return;

    if (head->getNext() == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node<T>* temp = head;
    while (temp->getNext()->getNext() != nullptr) {
        temp = temp->getNext();
    }

    delete temp->getNext();
    temp->setNext(nullptr);
}

template <typename T>
void LinkedList<T>::ListRemoveNodeAtBeginning(T value)
{
    if (!head) return;

    Node<T>* temp = head;
    head = head->getNext();
    if (head && (type == Doubly || type == Circular)) {
        head->setPrev(nullptr);
    }
    delete temp;

    if (type == Circular && head) {
        Node<T>* tail = head;
        while (tail->getNext() != head) {
            tail = tail->getNext();
        }
        tail->setNext(head);
    }
}

template <typename T>
void LinkedList<T>::ListRemoveNodeAt(T value, size_t pos)
{
    if (position == 0) {
        ListRemoveNodeAtBeginning();
        return;
    }

    Node<T>* temp = head;
    for (size_t i = 0; i < position - 1 && temp->getNext() != nullptr; ++i) {
        temp = temp->getNext();
    }

    if (temp->getNext() == nullptr) return;

    Node<T>* nodeToDelete = temp->getNext();
    temp->setNext(nodeToDelete->getNext());
    if (nodeToDelete->getNext() != nullptr && (type == Doubly || type == Circular)) {
        nodeToDelete->getNext()->setPrev(temp);
    }
    delete nodeToDelete;
}
