//
// Created by Rounak on 12/10/17.
//

#include <iostream>

using namespace std;

#include "LinearList.h"


int mainoff() {
    LinearList<int> list(10);
    for (int i = 1; i <= 10; i++) {

        if (i == 2 || i == 6) {
            list.Insert((i - 1), 3);
        } else {
            list.Insert((i - 1), rand());
        }

    }
    list.Output(cout);
    list.DeleteSimilar();
    cout << endl;
    list.Output(cout);
    return 0;
}