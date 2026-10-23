#include <cstddef>
#include <iostream>
#ifndef SORTINGALGO_H
#define SORTINGALGO_H

template<typename T>
void bubbleSort(T arr[], size_t arrSize){
    //step 1: fr i = 0 to N -1 repeat inner loop
    for(int i = 0; i < arrSize; i++){
        //step 2: inner loop that for K = i+1 to N-I repeat    //Time complexity N^2
            for(int j=i+1; j<arrSize; j++){
                //step 3 swap if the arr[j] > arr[i]
                if(arr[i] > arr[j]){
                    std::swap(arr[i], arr[j]);
                }
            }
    }     
}

template <typename T>
//array, current index, size of array
int routineSmallest(T arr[], int K, const int arrSize){
    int position, j;
    T smallest = arr[K];
    for(int j= K+1; j<arrSize; j++){                                 //Time complexity N
        if(arr[j] < smallest){
            smallest = arr[j];
            position = j;
        }
    }
    return position;
}

template <typename T>
void selectionSort(T arr[], size_t arrSize){
    int pos, temp, pass;
    for(int i=0; i<arrSize; i++){                                //Time complexity N^2 (from routineSmallest so N*N which is N^2)
        pos = routineSmallest(arr, i, arrSize);
        //swapping
        temp = arr[i];
        arr[i] = arr[pos];
        arr[pos] = temp;
        pass++;
        //for verification and count number of passes
    }
}

template <typename T>
void insertionSort(T arr[], size_t arrSize){
    int K = 0, J, temp;
    while(K < arrSize){
        temp = arr[K];                                    //Time complexity N^2     (from routineSmallest so N*N which is N^2)
        J = K-1;

        while(J >= 0 && temp <= arr[J]){
            arr[J+1] = arr[J];
            J--;
        }
        arr[J+1] = temp;
        K++;
    }
}

template <typename T>
void displayArr(T arr[], size_t arrSize){
    for(int i = 0; i < arrSize; i++){                   //time complexity N
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
}
//holds candidate names
std::string Candidates[5]={
    "Bo Dalton Capistrano",
    "Cornelius Raymon Agustín",
    "Deja Jayla Banaga",
    "Lalla Brielle Yabut",
    "Franklin Relano Castro"
};
// 
void countVotes(int arr[], int size) {
    int voteCounts[5] = {};
    //tallies the votes per candidate at element value - 1 
    for(int j = 0; j < size; j++) {    //time complexity N
        voteCounts[arr[j] - 1]++;
    }

    int highestCount = voteCounts[0];
    int winnerIndex = 0;

    //gets the highest vote count and declares winner
    for (int k = 1; k < 5; k++) {
        if(voteCounts[k] > highestCount) {         //time complexity N
            highestCount = voteCounts[k];
            winnerIndex = k;
        }
    }

    //print the tally
    std::cout << "\nVote Tally: \n";                        //time complexity N
    for(int k = 0; k < 5; k++) {
        std::cout << "Candidate " << (k + 1) << ":" << " (" << Candidates[k] << "): " << voteCounts[k] << " votes \n";
    }

    std::cout << "\nWinner: Candidate " << (winnerIndex + 1) << " " << Candidates[winnerIndex] << " with " << highestCount << " votes\n";
}
#endif
