//
// Created by Rounak on 12/10/17.
// File Provided by DSI Lab @ King's College London by TA Angelos & Chan. Prof. Kathleen.


/*
#	Formula Based Linear List Implementation
*/

#ifndef LINEARLIST_LINEARLIST_H
#define LINEARLIST_LINEARLIST_H


#include <iostream>

using namespace std;

template<class T>
class LinearList {

    //Public Function Definitions
public:
    LinearList(int MaxListSize = 10);                //Constructor, O(1)
    ~LinearList() { delete[] element; }                //Destructor
    bool IsEmpty() const { return length == 0; }    //IsEmpty, Theta(1)
    int Length() const { return length; }            //Length of List, Theta(1)
    bool Find(int k, T &x) const;                    //Return the k'th element of List in x,
    int Search(const T &x) const;                    //Return position of x
    LinearList<T> &Delete(int k, T &x);                //Delete k'th element and return it
    void Output(ostream &out) const;                //Output the list
    LinearList<T> &DeleteSimilar(); //Delete Duplicate Elements in the Array
    LinearList<T> &Insert(int k, const T &x); //Insertion

    //ASSUMED THE FOLLOWING METHODS WORK ONLY IF THE LIST IS SORTED OR ORDERED IN A DESCENDING FASHION
    int BinarySearchIterative(int x, int low,
                              int high); //Finds element x in list and returns poistion mid
    int
    BinarySearchRecursive(int x, int low, int high); //Function is same as iterative method. Practically this is faster
    //Private Class Members
private:
    int length;
    int MaxSize;
    T *element; //Dynamic 1D array
};

//Constructor, O(1)
template<class T>
LinearList<T>::LinearList(int MaxListSize)    //Constructor
{
    MaxSize = MaxListSize;
    element = new T[MaxSize];
    length = 0;
}

//Set x to the k'th element of the list
//Return false if no k'th, true otherwise, theta(1)
//Does an element exist at index k, if it does update the address of x to that element
template<class T>
bool LinearList<T>::Find(int k, T &x) const    //Find
{
    if (k < 1 || k > length)
        return false;
    x = element[k - 1];
    return true;
};

//Locate x, return position of x if found
//Return 0 if x not in list, O(n)
template<class T>
int LinearList<T>::Search(const T &x) const    //Search
{
    for (int i = 0; i < length; i++) {
        if (element[i] == x) {
            return ++i;
        }
    }
    return 0;
};

//Deletion of Duplicate Elements
template<class T>
LinearList<T> &LinearList<T>::DeleteSimilar() {
    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++) {
            if (element[i] == element[j]) {
                Delete(j, element[j]);
            }
        }
    }
    return *this;
};

//Set x to the k'th element and delete it
//Show OutOfBounds error if no k'th element, theta(n)
template<class T>
LinearList<T> &LinearList<T>::Delete(int k, T &x)    //Delete
{
    if (Find(k, x)) {
        //Move elements k+1, ..., down
        for (int i = k; i < length; i++)
            element[i - 1] = element[i];
        length--;
        return *this;
    } else {
        cout << "	Index out of bound error!\n";
        exit;
    }
};

template<class T>
LinearList<T> &LinearList<T>::Insert(int k, const T &x) {
    if (k < 0 || k > length) {
        cout << "Out of Bounds";
        exit;
    }
    if (length == MaxSize) {
        cout << "List is Full";
        exit;
    }
    for (int i = length - 1; i >= k; i--)
        element[i + 1] = element[i];
    element[k] = x;
    length++;
    return *this;
};

//OUTPUT THE LIST
template<class T>
void LinearList<T>::Output(ostream &out) const {
    for (int i = 0; i < length; i++) {
        out << element[i] << " ";
    }
};

template<class T>
int LinearList<T>::BinarySearchRecursive(int x, int low, int high) {
    if (high > low) {
        int mid = (low + high) / 2;
        int temp;
        if (element[mid] == x) {
            return ++mid;
        } else if (element[mid] < x) {
            return BinarySearchRecursive(x, mid + 1, high);
        } else {
            return BinarySearchRecursive(x, low, mid);
        }
    } else {
        return 0;
    }

}

template<class T>
int LinearList<T>::BinarySearchIterative(int x, int low, int high) {
    int mid = (low + high) / 2;
    while (low <= high) {
        if (element[mid] == x) {
            return ++mid;
        } else if (element[mid] < x) {
            low = mid + 1;
            mid = (low + high) / 2;
        } else {
            high = mid;
            mid = (low + high) / 2;
        }
    }
    return 0;
}


#endif
