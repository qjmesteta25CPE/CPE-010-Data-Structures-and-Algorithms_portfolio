#include <iostream>
#include "queueArr.h"

using namespace std;

int main() {

   int main(){
    int choice;
    while(true){
        std::cout<<"============================================"<<std::endl;
        std::cout<<"stack Operations \n";
        std::cout<<"1.Enqueue,2.Dequeue, 3.front,4.back,5.isEmpty,6.Isfull,7. size,8. clear, 9. Display "<<std::endl;
        std::cout<<"============================================"<<std::endl;

        std::cin>>choice;
        switch(choice){
            case 1: Enqueue();
            break;
            case 2: Dequeue();
            break;
            case 3: front();
            break;
            case 4: back();
            break;
            case 5: std::cout<<"is Stack empty? "<<isEmpty()<<std::endl;
            break;
            case 6: std::cout<<"is Stack Full? "<<isFull()<<std::endl;
            break;
            case 7: std:: cout<<"Stack size is: "<<size()<<std::endl;
            break;
            case 8: DisplayStack();
            break;
            default: std::cout<<"Invalid choice"<<std::endl;
            break;

        }
    }
   
}