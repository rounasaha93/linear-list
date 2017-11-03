//
// Created by Rounak on 28/10/17.
//

#include "LinkedListChain.h"
#include <iostream>

using namespace std;

int mainoffload2() {
    LinkedListChain<int> chain;

    //INSERTION CHECKS
    chain.Insert(0, 12);
    chain.Insert(1, 23);
    chain.Insert(2, 24);
    chain.Insert(3, 25);
    chain.Insert(4, 26);
    chain.Insert(5, 27);
    chain.OutputStream(cout);

    //FIND CHECK
    int x = INT_MIN;
    chain.find(1, x);
    cout << endl;
    cout << "X is : " << x << endl;

    //DELETE CHECK
    chain.Delete(5, x);
    cout << endl;
    cout << "X is : " << x << endl;
    chain.OutputStream(cout);

    //LENGTH CHECK
    cout << "Length of list is : " << chain.length() << endl;


    //SEARCH CHECK
    x = 24;
    int pos = chain.search(x);
    cout << "Position of searched key " << x << " is : " << pos << endl;
    return 0;

}