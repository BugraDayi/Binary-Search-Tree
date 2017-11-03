//
// Created by Buğra Göçer on 01/11/2017.
//

#include "../headers/PbBST.h"

void PbBST::insert(PbBinaryNode **root, int val) {

    if(*root == nullptr)
        *root = new PbBinaryNode(val);
    else if((*root)->item <= val)
        insert(&((*root)->right), val);
    else if((*root)->item > val)
        insert(&((*root)->left), val);
}

PbBST::PbBST() {
    this->root = nullptr;
}

int PbBST::getHeight(PbBinaryNode  **root) {
    if (*root == nullptr)
        return 0;

    int lh = getHeight(&(*root)->left);
    int rh = getHeight(&(*root)->right);

    return 1 + ((lh > rh) ? lh : rh);
}

int PbBST::isBST(PbBinaryNode *root) {
    static PbBinaryNode* prev  = nullptr;

    if(root== nullptr) return 1;

    if(!isBST(root->left)) return 0;

    if(prev!= nullptr && (root->item <= prev->item) ) return 0;

    prev = root;

    return isBST(root->right);
}