#include<iostream>

//Global Declaration
#define maxCap 10
const size_t arrSize=10;

int stackArr[maxCap];
int top = -1,i, newData;

//prototype functions
void push();
void pop();
void Top();
bool isEmpty();
bool isFull();

void DisplayStack();

int main(){
    int choice;
    while(true){
        std::cout<<"============================================"<<std::endl;
        std::cout<<"stack Operations \n";
        std::cout<<"1.PUSH, 2.POP 3. TOP 4. isEmpty 5.isFull 6.DisplayStack "<<std::endl;
        std::cout<<"============================================"<<std::endl;

        std::cin>>choice;
        switch(choice){
            case 1: push();
            break;
            case 2: pop();
            break;
            case 3: Top();
            break;
            case 4: std::cout<<"is Stack empty? "<<isEmpty()<<std::endl;
            break;
            case 5: std::cout<<"is Stack Full? "<<isFull()<<std::endl;
            break;
            case 6: DisplayStack();
            break;
            default: std::cout<<"Invalid choice"<<std::endl;
            break;

        }
    }
   
}

//function definitions
bool isEmpty(){
    if(top ==   -1)return true;
    return false;

}
bool isFull(){
    if (top==maxCap -1) return true;

    return false;
}
void push(){

    if(isFull()){
        std::cout<<"stack Overflow \n";
        return;
    }
    std::cout<<"Enter A new value  \n";
    std::cin >> newData;
    stackArr[++top] = newData;

}

void pop(){
    if(isEmpty){
        std::cout<<"Stack Underflow \n";
    }
    std::cout<<"Popping: "<<stackArr[top]<<std::endl;
    top--;
}

void  Top(){
    if(isEmpty()){
        std::cout<<"The Stack is Empty"<<std::endl;
        return;
    }
    std::cout<<"top Element: "<<stackArr[top]<<std::endl;
}
// Display function
void DisplayStack() {
    if (isEmpty()) {
        std::cout << "Stack is empty." << std::endl;
        return;
    }
    for (i=top; i>=0; i-- ){
        std::cout<<stackArr[i]<<std::endl;
    }
    
}