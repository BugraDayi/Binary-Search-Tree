//
// Created by Buğra Göçer on 01/11/2017.
//

#ifndef BST_PBBST_H
#define BST_PBBST_H
#include "../headers/PbBinaryNode.h"

class PbBST {
public:

    PbBinaryNode *root;

    void insert(PbBinaryNode **root, int val);
    int getHeight(PbBinaryNode  **root);
    int isBST(PbBinaryNode *root);
    PbBST();


};

#endif //BST_PBBST_H
