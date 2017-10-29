//
// Created by Rounak on 28/10/17.
//

#ifndef LINEAR_LIST_LINKEDLISTCHAIN_H
#define LINEAR_LIST_LINKEDLISTCHAIN_H

#include "ChainNode.h"
#include <iostream>

using namespace std;

template<class T>
class ChainNode;

template<class T>
class LinkedListChain {
public :
    LinkedListChain() { first = 0; }

    ~LinkedListChain();

    bool isEmpty() const { return first == 0; }

    int length() const;

    bool find(int k, T &x) const; //Search for Position K and return data in position K

    int search(T &x) const; //Search for Element X and return Position

    LinkedListChain<T> &Insert(int k, const T &x);

    LinkedListChain<T> &Delete(int k, T &x);

    void OutputStream(ostream &out) const;

private :
    ChainNode<T> *first;

};

//Desctructor
template<class T>
LinkedListChain<T>::~LinkedListChain() {
    ChainNode<T> *current_node;
    while (current_node) {
        current_node = first->link;
        delete first;
        first = current_node;
    }
}

//Counts the Length of the List
//If the Lenght is required again and again please implement so by using a pointer leng and increase / decrease it during addtion / deletion for a saner state of mind
template<class T>
int LinkedListChain<T>::length() const {
    ChainNode<T> *current_node = first;
    int len = 0;
    while (current_node) {
        len++;
        current_node = current_node->link;
    }
    return len;
}

//Finds for element present at kth position and returns it in x
template<class T>
bool LinkedListChain<T>::find(int k, T &x) const {
    if (k < 1 || isEmpty()) {
        return false;
    }
    ChainNode<T> *current_node = first;
    int pos = 1;
    while (current_node && pos < k) {
        current_node = current_node->link;
        pos++;
    }

    if (current_node) {
        x = current_node->data;
        return true;
    }
    return false;
}

//Searches for Element
template<class T>
int LinkedListChain<T>::search(T &x) const {
    ChainNode<T> *current_node = first;
    int posCurrentNode = 1;
    while (current_node && current_node->data != x) {
        current_node = current_node->link;
        posCurrentNode++;
    }

    if (current_node) {
        return posCurrentNode;
    }
    return INT_MIN;
}

//Insertion of Element in the list
template<class T>
LinkedListChain<T> &LinkedListChain<T>::Insert(int k, const T &x) {
    int index;
    if (k < 0 || k > length() + 1) {
        cout << "Index is Out of Bounds. Insertion Cannot take place." << endl;
        return *this;
    }

    ChainNode<T> *current_node = first;

    for (index = 1; index < k && current_node; index++) {
        current_node = current_node->link;
    }

    //Check Validity of the kth Position
    if (k > 0 && !current_node) {
        cout << "Index is Out of Bounds. Insertion Cannot take place." << endl;
        return *this;
    }


    ChainNode<T> *newNode = new ChainNode<T>;
    newNode->data = x;
    if (k >= 1) {
        newNode->link = current_node->link;
        current_node->link = newNode;
    } else {
        //Insertion as First Element
        newNode->link = first;
        first = newNode;
    }


    return *this;
}

//Deletion of Element in the List
template<class T>
LinkedListChain<T> &LinkedListChain<T>::Delete(int k, T &x) {
    if (k < 0) {
        cout << "Index Out Of Bounds";
        return *this;
    }
    ChainNode<T> *current_node;
    current_node = first;
    int pos = 1;
    while (current_node && pos < k) {
        current_node = current_node->link;
        pos++;
    }

    if (!current_node || !current_node->link) {
        cout << "Index Out Of Bounds";
        return *this;
    }

    if (k) {
        ChainNode<T> *nodeToBeDeleted = current_node->link;
        x = nodeToBeDeleted->data;
        current_node->link = nodeToBeDeleted->link;
        delete nodeToBeDeleted;
    } else {
        //Deleting the First Node
        x = current_node->data;
        first = current_node->link;
        delete current_node;
    }

    return *this;
}

//Printing the Current List
template<class T>
void LinkedListChain<T>::OutputStream(ostream &out) const {
    if (!isEmpty()) {
        ChainNode<T> *current;
        for (current = first; current; current = current->link)
            out << current->data << "  ";
    } else {
        cout << "List is Empty" << endl;
    }
    cout << endl;
}


#endif //LINEAR_LIST_LINKEDLISTCHAIN_H
