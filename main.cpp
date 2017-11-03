#include <iostream>
#include "headers/AbBST.h"
#include "headers/PbBST.h"

int main() {

    AbBST *ab = new AbBST(2);
    PbBST *pb = new PbBST();

    int dizi[5] = { 10 , 4 , 2 , 3 ,8};

    for (int i = 0; i < 5; ++i) {
        ab->insert(dizi[i]);
        pb->insert(&(pb->root),dizi[i]);
    }

    return 0;
}