#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <cstdio>
namespace p3q {

template <class T>
struct Node {
    const T *data;
    Node *prev;
    Node *next;
};

template <class T>
class List {
public:
    List();
    ~List();

    bool clear();
    bool contains( T item );

    bool insertAt( T &item, int position );
    bool insertAtEnd( T &item );
    bool insertAtFront( T &item );

    T    get( int position );
    T    getHead();
    T    getTail();

    bool remove( T item );
    bool removeAt( int position );

    int  size();

private:
    void deleteNode( Node<T> *&node );

    int itemCount;

    Node<T> *head;
    Node<T> *tail;
};

template <class T>
List<T>::List()
{
    itemCount = 0;
    head = NULL;
    tail = NULL;
}

template <class T>
List<T>::~List()
{
    clear();
}

template <class T>
bool List<T>::clear()
{
    if ( itemCount == 0 )
        return false;

    Node<T> *n = head;
    Node<T> *c;

    while( n != NULL ) {
        c = n; // copy ptr
        n = n->next;

        delete c;
    }

    itemCount = 0;
    head = NULL;
    tail = NULL;

    return true;
}

template <class T>
bool List<T>::contains( T item )
{
    Node<T> *n = head;

    while( n != NULL ) {
        if ( *n->data == item ) {
            return true;
        }
        n = n->next;
    }

    return false;
}

template <class T>
bool List<T>::insertAt( T &item, int position )
{
    if ( position < 0 || position > itemCount )
        return false;

    Node<T> *n = new Node<T>;
    n->data = &item;
    n->next = NULL;
    n->prev = NULL;

    if ( head == NULL ) {
        head = n;
        tail = n;
    }
    else if ( position == 0 ) { // head
        n->next = head;
        head->prev = n;
        head = n;
    }
    else if ( position == itemCount ) { // tail
        tail->next = n;
        n->prev = tail;
        tail = n;
    }
    else {
        Node<T> *node = head;
        int iterPos = 0;
        while( node != NULL ) {
            if ( iterPos == position ) {
                Node<T> *prev = node->prev;

                n->next = node;
                n->prev = prev;

                node->prev = n;
                prev->next = n;

                break;
            }
            iterPos++;
            node = node->next;
        }
    }

    itemCount++;
    return true;
}

template <class T>
bool List<T>::insertAtEnd( T &item )
{
    return insertAt( item, itemCount );
}

template <class T>
bool List<T>::insertAtFront( T &item )
{
    return insertAt( item, 0 );
}

template <class T>
T List<T>::get( int position )
{
    if ( position < 0 || position > itemCount )
        return NULL;

    Node<T> *n = head;
    int iterPos = 0;
    while ( n != NULL ) {
        if ( iterPos == position ) {
            return *n->data;
        }
        iterPos++;
        n = n->next;
    }

    return NULL;
}

template <class T>
T List<T>::getHead()
{
    return *head->data;
}

template <class T>
T List<T>::getTail()
{
    return *tail->data;
}

template <class T>
bool List<T>::remove( T item )
{
    if ( head == NULL )
        return false;
    Node<T> *node = head;
    while( node != NULL ) {
        if ( item == *node->data ) {
            deleteNode( node );
            return true;
        }
        node = node->next;
    }

    return false;
}

template <class T>
bool List<T>::removeAt( int position )
{
    if ( position < 0 || position > itemCount )
        return false;

    Node<T> *node = head;
    int iterPos = 0;
    while ( node != NULL ) {
        if ( iterPos == position ) {
            deleteNode( node );
            return true;
        }

        iterPos++;
        node = node->next;
    }

    return false;
}

template <class T>
int List<T>::size()
{
    return itemCount;
}

template <class T>
void List<T>::deleteNode( Node<T> *&node )
{
    Node<T> *next = node->next;
    Node<T> *prev = node->prev;

    if ( node == head ) {
        head = head->next;

        if ( head != NULL )
            head->prev = NULL;
    }
    else if ( node == tail ) {
        tail = tail->prev;

        if ( tail != NULL )
            tail->next = NULL;
    } else {
        prev->next = next;
        next->prev = prev;
    }
    delete node;
    itemCount--;
}

}

#endif

