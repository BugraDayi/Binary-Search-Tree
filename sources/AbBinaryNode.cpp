//
// Created by Buğra Göçer on 01/11/2017.
//

#include "../headers/AbBinaryNode.h"


AbBinaryNode::AbBinaryNode(int val, int left, int right) {

    this->item = val;
    this->left = left;
    this->right = right;
}

AbBinaryNode::AbBinaryNode(){
    this->item = -1;
    this->left = -1;
    this->right = -1;
}