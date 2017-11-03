//
// Created by Buğra Göçer on 01/11/2017.
//

#ifndef BST_PBBINARYNODE_H
#define BST_PBBINARYNODE_H

#include <cstdlib>

class PbBinaryNode
{
    public:
    int item;
    PbBinaryNode *left;
    PbBinaryNode *right;

    PbBinaryNode(int val,PbBinaryNode *left,PbBinaryNode *right);
    PbBinaryNode(int val);
};

#endif //BST_PBBINARYNODE_H

