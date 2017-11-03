//
// Created by Rounak on 28/10/17.
//

#ifndef LINEAR_LIST_CHAINNODE_H
#define LINEAR_LIST_CHAINNODE_H

#include "LinkedListChain.h"


template<class T>
class LinkedListChain;

template<class T>
class ChainNode {
public:
    friend class LinkedListChain<T>;

private:
    T data;
    ChainNode<T> *link;
};


#endif //LINEAR_LIST_CHAINNODE_H
