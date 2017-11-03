cmake_minimum_required(VERSION 3.8)
project(BST)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp sources/AbBinaryNode.cpp headers/AbBinaryNode.h sources/AbBST.cpp headers/AbBST.h sources/PbBST.cpp headers/PbBST.h sources/PbBinaryNode.cpp headers/PbBinaryNode.h)
add_executable(BST ${SOURCE_FILES})