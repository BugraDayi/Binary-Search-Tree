#include <iostream>
#include "headers/AbBST.h"
#include "headers/PbBST.h"
#include <ctime>
#include <unistd.h>

int *pickUpRandomNumbers(int num ){

    int *arr = new int[num];
    srand(time(0));

    for (int i = 0; i < num; ++i) {
        arr[i] = rand() % 2000 + 1;
    }

    return arr;
}


void performanceAnalysis(){

    int analysisNumbers[]  = {4000, 6000, 8000, 10000, 12000, 14000, 16000, 18000, 20000};

    std::cout << "Array Size\t Array Based\t Pointer Based\n";

    for (int analysisNumber : analysisNumbers) {
        int *randomNumbers = pickUpRandomNumbers(analysisNumber);

        AbBST *ab = new AbBST(5);
        PbBST *pb = new PbBST();

        std::clock_t start;
        double duration;

        std::cout << analysisNumber << "\t\t";

        start = std::clock();

        for (int i = 0; i < analysisNumber; ++i){
            ab->insert(randomNumbers[i]);
        }

        duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC * 1000;

        std::cout<<duration<<"\t\t";

        start = std::clock();

        for (int i = 0; i < analysisNumber; ++i){
            pb->insert(&(pb->root),randomNumbers[i]);
        }

        duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC * 1000;

        std::cout<<duration<<"\n";

        delete (ab);
        delete (pb);
        delete (randomNumbers);
    }
}

void heightAnalysis(){

    int analysisNumbers[]  = {4000, 6000, 8000, 10000, 12000, 14000, 16000, 18000, 20000};

    std::cout << "Array Size\t Random Numbers\t Ascending Numbers\n";

    for (int analysisNumber : analysisNumbers) {
        int *randomNumbers = pickUpRandomNumbers(analysisNumber);

        PbBST *pb = new PbBST();
        PbBST *pb2 = new PbBST();


        std::cout << analysisNumber << "\t\t";

        for (int i = 0; i < analysisNumber; ++i){
            pb->insert(&(pb->root),randomNumbers[i]);
        }
        std::cout<< pb->getHeight(&(pb->root))<<"\t\t";


        for (int i = 0; i < analysisNumber; ++i){
            pb2->insert(&(pb2->root),i);
        }
        std::cout<< pb2->getHeight(&(pb2->root))<<"\n";

        delete (pb);
        delete (pb2);
        delete (randomNumbers);
    }
}



int main() {

    PbBST *pb = new PbBST();

    int dizi[] = { 3,4,5};

    for (int i : dizi) {
        pb->insert(&(pb->root), i);
    }

    performanceAnalysis();
    heightAnalysis();
    //std::cout << pb->medianOfBST(pb->root);
    return 0;
}