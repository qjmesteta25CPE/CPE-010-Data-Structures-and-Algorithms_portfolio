#ifndef QUEUELL_H
#define QUEUELL_H


//create a class node
template<typename T>
class qNode{
    public:
    T data;
    qNode* next;
};

//new node  creator
template <typename T>
qNode<T>* new_node(T newData){
    //allocate a space for the new node
    qNode<T>* newNode=new qNode<T>;
    //store the newData to newNode
    newNode -> data=newData;
    //point newNode to NULL
    newNode->next =nullptr;

    return newNode;

}

//enqueue
template<typename T>
void enqueue(T newData, qNode<T>** frontPtr, qNode<T>** backPtr){
    //create a new node
    qNode<T>* newNode= new_node(newData);
    //check if the queue is empty
    if((*frontPtr)==nullptr && (*backPtr)==nullptr){
        (*frontPtr) = newNode;
        (*backPtr) = newNode;
        return;
    }
    //if not then insert at the back
    (*backPtr)->next= newNode;
    (*backPtr) = newNode;
}
//dequeue
template<typename T>
void dequeue(qNode<T>** frontPtr, qNode<T>** backPtr){
    //check if the queue is empty
        if((*frontPtr)== nullptr && (*backPtr)==nullptr){
            std::cout<<"The queue is empty \n";
            return;
        }
    //create a temporary variable to store the node to be deleted
    qNode<T>* deleteTemp=nullptr;
    //assign the current front to the delete temp
    deleteTemp=(*frontPtr);
    //check if the queuehas only 1 item
    if((*frontPtr)->next == nullptr &&(*backPtr)->next == nullptr){
        //means only 1 item is inside the queue
        (*frontPtr) = nullptr;
        (*backPtr) = nullptr;
        delete deleteTemp;
        return;
    }

    
    (*frontPtr)=(*frontPtr)->next;
    deleteTemp->next=nullptr;
    //delete NA Node
    delete deleteTemp;
}

//displayall
template<typename T>
void displayall(qNode<T>** frontPtr, qNode<T>** backPtr){

    if((*frontPtr)==nullptr && (*backPtr)==nullptr){
        std::cout << "The queue is empty\n";
        return;
    }

    qNode<T>* temp = *frontPtr;

    std::cout << "Queue: ";

    while(temp != nullptr){
        std::cout << temp->data << " ";
        temp = temp->next;
    }

    std::cout << std::endl;
}
    

//is empty
template<typename T>
void isEmpty(qNode<T>** frontPtr, qNode<T>** backPtr){
    if((*frontPtr) == nullptr && (*backPtr) == nullptr){
        std::cout << "The queue is empty.\n";
    }
    else{
        std::cout << "The queue is not empty.\n";
    }
}

#endif
