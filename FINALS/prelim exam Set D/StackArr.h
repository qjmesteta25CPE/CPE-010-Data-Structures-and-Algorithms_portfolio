#ifndef STACKARR_H
#define STACKARR_H

#include<iostream>
int top = -1,i, newData;
template<typename T>
class StackArray{
    private:

    T* A_arr;
    std::size_t A_capacity;
    std::size_t A_size;

    int A_top;

    public:
    StackArray(std::size_t capacity = 10);

    ~StackArray();

    StackArray(const StackArray& other);
    StackArray& operator=(const StackArray& other);
    bool isFull();
    bool isEmpty();
    size_t Size();
    T Top();
    T pop();
    T push(T value);
    void DisplayStack();
    void DisplayArray();
    void CompareValues();
    void Clear();
};
//Constrictor & Destructor
template<typename T>
StackArray<T>::StackArray(std::size_t capacity){
    A_arr = new T[capacity];
    A_capacity = capacity;
    //default size,front,and back
    Clear();
}

template<typename T>
StackArray<T>::~StackArray(){
    delete[] A_arr;
}

template<typename T>
StackArray<T>::StackArray(const StackArray &other){
    A_capacity = other.A_capacity;
    A_size = other.A_size;
    A_top = other.A_top;

    // Allocate new array memory
    A_arr = new T[A_capacity];

    // Deep copy existing elements
    for (std::size_t i = 0; i < A_capacity; i++) {
        A_arr[i] = other.A_arr[i];
    }
}
template<typename T>
StackArray<T>& StackArray<T>::operator=(const StackArray &other){
    //Prevent copying self
    if (this == &other){
        return *this;
    }
    //Delete old pointer to prevent memory leaks
    delete[] A_arr;

    A_capacity = other.A_capacity;
    A_size = other.A_size;
    A_top = other.A_top;

    // Allocate new array memory
    A_arr = new T[A_capacity];

    // Deep copy existing elements
    for (std::size_t i = 0; i < A_capacity; i++) {
        A_arr[i] = other.A_arr[i];
    }

    return *this;
}


//Operations
template <typename T>
bool StackArray<T>::isFull(){
    return A_size == A_capacity;
} 

template <typename T>
bool StackArray<T>::isEmpty(){
    return A_size == 0;
}

template <typename T>
size_t StackArray<T>::Size() {
    // RETURN CURRENT SIZE OF QUEUE
    return A_size;
}

template <typename T>
T StackArray<T>::Top() {
    // Check if the queue is empty
    if (isEmpty()) {
        std::cout << "Queue is Empty\n";
        return T();
    }
    // Return the front
    return A_arr[A_top];
}

template <typename T>
T StackArray<T>:: pop(){
    if(isEmpty){
        std::cout<<"Stack Underflow \n";
    }
    std::cout<<"Popping: "<<StackArray[top]<<std::endl;
    top--;
}
template<typename T>
T StackArray<T>:: push(T value){

}

// Display function
template <typename T>
void DisplayStack() {
    if (isEmpty()) {
        std::cout << "Stack is empty." << std::endl;
        return;
    }
    for (i=top; i>=0; i-- ){
        std::cout<<StackArray[i]<<std::endl;
    }
}
//add a function to display array on a normal sequence from index 0 to the end 
template <typename T>
void DisplayArray(){
    if(isEmpty()){
        std::cout<<"Array is Empty"<<std::endl;
        return;
    }
    std::cout<<"The Array Contents is: ";
    for( i = 0; i<A_size;i++){
        std::cout<<StackArray[i]<<std::endl;
    }
}
//add a funciton that compares the values of the array on normal sequence if it matches the element compared sequence of the stack
template<typename T>
void CompareValues(){
    if (DisplayArray == DisplayStack) {
        std::cout<<"The Element is Symmetrical."<<std::endl;
    }
}
#endif