
#ifndef SIMPLELIST_H
#define SIMPLELIST_H

#include <utility>

typedef enum LinkedListType {
    Singly =0,
    Doubly = 1,
    Circular =2 
}ListType;

template <typename T> class Node {
    T data;
    Node* next;
    Node* prev; //prev pointer will only be used in case if list is doubly or circular
    
    public:
        Node(T value);

        // getter and setter methods to encapsulate the da  ta, 
        // next, and prev members.
        T getData() const { return data; }
        Node<T>* GetNext() const {return next; }
        Node<T>* GetPrevious() const {return prev; }

        void SetNext(Node<T>* nextNode) { next = nextNode; }
        void SetPrevious(Node<T>* prevNode) { prev = prevNode; }
};

template <typename T> class LinkedList {
    
    private:
        ListType type;
        Node<T>* head;
        void copyList(const LinkedList& llist);
        void moveLList(LinkedList&& llist);
        void clearList();

    public:
        //Implement rule of five
        LinkedList(ListType lltype); //add definition in source file : type(lltype), head(nullptr) {}
        LinkedList(const LinkedList& llist); //Copy Constructor
        LinkedList& operator=(const LinkedList& llist); // Assignment operator
        LinkedList(LinkedList&& llist) noexcept; //Move operator
        LinkedList& operator=(LinkedList&& llist) noexcept; //Move Assignment operator
       
        Node<T>* getHead() const { return head; }

        void ListInitialize();
        void ListAddNodeAtEnd(T value);
        void ListAddNodeAtBeginning(T value);
        void ListAddNodeAt(T value, size_t pos);
        void ListRemoveNodeAtEnd(T value);
        void ListRemoveNodeAtBeginning(T value);
        void ListRemoveNodeAt(T value, size_t pos);

        ~LinkedList();

};

#endif


