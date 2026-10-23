#include<iostream>
#include<cstdlib>
#include<ctime>
#include "SortingAlgo.h"
#include<cstddef>

const int maxSize=100;

int main(){

    int unsortedArr[maxSize];
    //use time 0 as seed for random values
    srand(time(0));
    //populate the array with random values
    for(int i=0; i<maxSize; i++){
        unsortedArr[i]=(rand()%5)+1;   //ensure that the values will only be 1-5
    }


    std::cout<<"\n unsorted Array \n";
    displayArr(unsortedArr,maxSize);

    //sorts the unsorted Array
    std::cout<<"\n Insertion sort \n";
    bubbleSort(unsortedArr,maxSize);
    std::cout<<"\n Sorted Arrray \n";
    displayArr(unsortedArr,maxSize);

    // tallies the total votes and Declares winner 
    countVotes(unsortedArr,maxSize);
}
