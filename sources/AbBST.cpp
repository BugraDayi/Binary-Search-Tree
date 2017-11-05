//
// Created by Buğra Göçer on 01/11/2017.
//

#include "../headers/AbBST.h"
#include <iostream>

using namespace std;

void AbBST::insert(int val) {
    int index = 0;
    while (true) {

        extend(index * 3);

        if (this->array[index].item == -1) {
            this->array[index].left = -1;
            this->array[index].item = val;
            this->array[index].right = -1;

            this->length++;
            break;
        } else if (val > this->array[index].item && this->array[index].right == -1) {//right

            this->array[index].right = this->length;

            this->array[this->length].left = -1;
            this->array[this->length].item = val;
            this->array[this->length].right = -1;


            this->length++;
            break;

        } else if (val <= this->array[index].item && this->array[index].left == -1) {//left

            this->array[index].left = this->length;

            this->array[this->length].left = -1;
            this->array[this->length].item = val;
            this->array[this->length].right = -1;


            this->length++;
            break;

        } else {
            index++;
        }

    }
}

void AbBST::extend(int index) {

    if (this->size > index) {
        return;
    }

    int newSize = this->size * 2;
    auto *newArr = new AbBinaryNode[newSize];

    for (int i = 0; i < this->size; ++i) {
        newArr[i] = this->array[i];
    }

//    memcpy( newArr, this->array, this->size * sizeof(AbBinaryNode) );

    this->size = newSize;
    delete this->array;
    this->array = newArr;
}


int AbBST::getHeight(int root) {
    if (root == -1)
        return 0;

    int lh = getHeight(this->array[root].left);
    int rh = getHeight(this->array[root].right);

    return 1 + ((lh > rh) ? lh : rh);
}

void AbBST::print() {
    for (int i = 0; i < this->size; ++i) {
        cout << this->array[i].left << " - " << this->array[i].item << " - " << this->array[i].right << " || " << i
             << "\n";
    }
}

AbBST::AbBST(int size) {
    this->array = new AbBinaryNode[size];
    this->size = size;
}


int AbBST::getHeight() {
    return this->getHeight(0);
}

AbBST::~AbBST() {
    delete (this->array);
}
