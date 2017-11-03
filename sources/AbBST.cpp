//
// Created by Buğra Göçer on 01/11/2017.
//

#include "../headers/AbBST.h"
#include <iostream>
#include <malloc/malloc.h>

#define ARRAYSIZE(arr) (sizeof(arr) / sizeof(arr[0]))

using namespace std;

void AbBST::insert(int val) {
    int index = 0;

    while (true) {
        extend(2 * index + 2);
        if (this->array[index].item == -1) {
            this->array[index].left =  2 * index+1;
            this->array[index].item = val;
            this->array[index].right = 2 * index+2;
            break;
        }

        if(val > this->array[index].item){//right
            index = (2 * index + 2);
        }else if(val <= this->array[index].item){//left
            index = (2 * index + 1);
        }
    }
}

void AbBST::extend(int index) {

    if (this->size > index){
        return;
    }

    size_t newSize = this->size * 2;
    AbBinaryNode *newArr = new AbBinaryNode[newSize];

    memcpy( newArr, this->array, this->size * sizeof(AbBinaryNode) );

    this->size = newSize;
    delete [] this->array;
    this->array = newArr;


}

int AbBST::getHeight(int root) {
    if (root == -1)
        return 0;

    int lh = getHeight(this->array[root].left);
    int rh = getHeight(this->array[root].right);

    return 1 + ((lh > rh) ? lh : rh);
}

void AbBST::print(){
    for (int i = 0; i < this->size; ++i) {
        cout << this->array[i].left << " - " << this->array[i].item << " - " << this->array[i].right << " || " << i << "\n";
    }
}

AbBST::AbBST(int size) {
    this->array = new AbBinaryNode[size];
    this->size = size;
}

int AbBST::isBST(int index) {
    static AbBinaryNode prev;

    if(this->array[index].item == -1) return 1;

    if(!isBST(this->array[index].left)) return 0;

    if(prev.item != -1 && (this->array[index].item <= prev.item) ) return 0;

    prev = this->array[index];

    return isBST(this->array[index].right);
}

int AbBST::getHeight() {
    return this->getHeight(0);
}
