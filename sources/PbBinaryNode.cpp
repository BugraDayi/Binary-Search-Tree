//
// Created by Buğra Göçer on 01/11/2017.
//

#include "../headers/PbBinaryNode.h"

PbBinaryNode::PbBinaryNode(int val, PbBinaryNode *left, PbBinaryNode *right) {
    this->item = val;
    this->right = right;
    this->left = left;
}

PbBinaryNode::PbBinaryNode(int val) {
    this->item = val;
    this->left = nullptr;
    this->right = nullptr;
}
