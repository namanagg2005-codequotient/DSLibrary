#include "linkedList.h"
#include <cstdlib>
#include <new>
#include <iostream>
#include <stdexcept>

template <typename T>
Node<T> :: Node() : value(), prev(NULL), next(NULL) {}

template <typename T>
Node<T> :: Node(T value){
    this->value = value;
    prev = NULL;
    next = NULL;
}

template <typename T>
Node<T> ::~Node(){}

template <typename T>
LinkedList<T> :: LinkedList(){
    head = tail = NULL;
    length = 0;
}

template <typename T>
LinkedList<T> ::LinkedList(T arr[], int n) {
    head = NULL;
    tail = NULL;
    length = 0;

    for (int i = 0; i < n; i++) {
        insertBack(arr[i]);
    }
}

template <typename T>
LinkedList<T> :: LinkedList(const LinkedList<T>& other) {
    head = NULL;
    tail = NULL;
    length = 0;

    Node<T>* temp = other.head;

    while (temp != NULL) {
    insertBack(temp->value);
        temp = temp->next;
    }
}

template <typename T>
LinkedList<T> ::~LinkedList() {
    Node<T>* temp = head;

    while (temp != NULL) {
        Node<T>* nextNode = temp->next;

        temp->~Node<T>();
        free(temp);

        temp = nextNode;
    }

    head = NULL;
    tail = NULL;
    length = 0;
}

template <typename T>
LinkedList<T>& LinkedList<T> ::operator=(const LinkedList<T>& other)
{
    if (this == &other)
        return *this;
    Node<T>* temp = head;
    while (temp != NULL) {
            Node<T>* next = temp->next;

            temp->~Node<T>();
            free(temp);

            temp = next;
        }
        head = NULL;
        tail = NULL;
        length = 0;
        temp = other.head;
        while (temp != NULL) {
            insertBack(temp->value);
            temp = temp->next;
        }
        return *this;
    }
