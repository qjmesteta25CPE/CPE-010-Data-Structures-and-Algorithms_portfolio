#include<iostream>
#include<queue>

void display(std::queue<char> copyQ);
int i;

int main (){
    //create an object
    std::queue<char> myQ;

    //use the enqueue operation
    myQ.push('J');
    myQ.push('E');
    myQ.push('S');
    myQ.push('S');
    myQ.push('E');
    std::cout<<"Current front is: "<< myQ.front()<<std::endl;
    std::cout<<"Current back is: "<< myQ.back()<<std::endl;
    //use the dequeue operation
    myQ.pop();
    display(myQ);
    myQ.pop();
    display(myQ);
    myQ.pop();
    display(myQ);
    myQ.pop();
    display(myQ);
    myQ.pop();
    display(myQ);

    std::cout<<"is the queue empty? "<<myQ.empty()<<std::endl;
    return 0;
}

void display(std::queue<char> copyQ){
    //create a copy 
    std::queue<char>temp = copyQ;
    //loop until empty
    while(!temp.empty()){
        //display the front
        std::cout<<" "<<temp.front()<<" ";
        //dequeue the front
        temp.pop();
    }
    //add a new line
    std::cout<<std::endl;



}