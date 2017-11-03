//
// Created by Rounak on 12/10/17.
//

#include <iostream>

using namespace std;

#include "LinearList.h"


int main() {
    LinearList<int> list(10);
    for (int i = 1; i <= 10; i++) {

        list.Insert((i - 1), i);

    }
    list.Output(cout);
    int x = list.BinarySearchIterative(2222, 0, list.Length());
    if (x != 0) {
        cout << endl << "Position of element is : " << x << endl;
    } else {
        cout << endl << "Element not found" << endl;
    }


    return 0;
}