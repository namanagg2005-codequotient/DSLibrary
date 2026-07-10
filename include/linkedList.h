#ifndef LINKEDLIST_H
#define LINKEDLIST_H



template <typename T>
class Node {
public:
    T value;
    Node<T>* prev;
    Node<T>* next;

    Node();
    Node(T value);
    ~Node();
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int length;

public:
    /* Constructors */
    LinkedList();
    LinkedList(T arr[], int n);
    LinkedList(const LinkedList<T>& other);

    /* Destructor */
    ~LinkedList();

    /* Assignment Operator */
    LinkedList<T>& operator=(const LinkedList<T>& other);

    /* Insertion */
    void insertFront(T value);
    void insertBack(T value);
    void insert(int index, T value);

    /* Deletion */
    T deleteFront();
    T deleteBack();

    /* Searching */
    bool search(T value);

    /* Utility */
    int size();
    void printForeward();
    void printBackward();
};

#include "LinkedList.tpp"

#endif