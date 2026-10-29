#include<iostream>
#include<stack>
int main(){

    std::stack<int> stack1;
    std::stack<int> stack2;
    std::cout<<"Testing the stack STL \n";
    //is empty
    std::cout<<"is the stack empty?: "<< stack1.empty()<<std::endl;
    //push
    stack1.push(10);
    std::cout<<"the element at the top of the stack is: "<<stack1.top()<<std::endl;
    stack2.push(15);
    std::cout<<"the element at the top of the stack is: "<<stack2.top()<<std::endl;
    stack1.push(9);
    std::cout<<"the element at the top of the stack is: "<<stack1.top()<<std::endl;
    stack1.push(8);
    std::cout<<"the element at the top of the stack is: "<<stack1.top()<<std::endl;
    stack1.push(7);
    std::cout<<"the element at the top of the stack is: "<<stack1.top()<<std::endl;
    stack1.pop();
    std::cout<<"the element at the top of the stack is: "<<stack1.top()<<std::endl;
    std::cout<<"is the stack empty?: "<< stack1.empty()<<std::endl;
    std::cout<<"the size of the stack is: "<<stack1.size()<<std::endl;
    std::cout<<"Emplace: "<<stack1.emplace(11);
    stack1.swap(stack2);
    
}
