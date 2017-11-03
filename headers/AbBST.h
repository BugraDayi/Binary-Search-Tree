//
// Created by Buğra Göçer on 01/11/2017.
//


#ifndef BST_ABBST_H
#define BST_ABBST_H
#include "../headers/AbBinaryNode.h"

class AbBST {
public:

    int size = 0;
    AbBinaryNode *array;

    void insert(int val);

    void extend(int val);

    int getHeight();

    int isBST(int );

    int getHeight(int root);

    AbBST(int size) ;

    void print();
};

#endif //BST_ABBST_H
