#include <iostream>
#include "queueArr.h"

using namespace std;

int main() {

    // Create a queue with a capacity of 5
    QueueArray<int> q(5);

    cout << " Initial Queue " << endl;
    cout << "Empty: " << q.Empty() << endl;
    cout << "Full : " << q.Full() << endl;
    cout << "Size : " << q.Size() << endl;

    // Enqueue elements
    cout << "\n Enqueue " << endl;
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);
    q.Enqueue(50);

    cout << "Front: " << q.Front() << endl;
    cout << "Back : " << q.Back() << endl;
    cout << "Size : " << q.Size() << endl;
    cout << "Full : " << q.Full() << endl;

    // Dequeue elements
    cout << "\n Dequeue " << endl;
    cout << "Removed: " << q.Dequeue() << endl;
    cout << "Removed: " << q.Dequeue() << endl;

    cout << "Front: " << q.Front() << endl;
    cout << "Back : " << q.Back() << endl;
    cout << "Size : " << q.Size() << endl;

    // Copy Constructor
    cout << "\n Copy Constructor " << endl;
    QueueArray<int> copyQueue(q);

    cout << "Front: " << copyQueue.Front() << endl;
    cout << "Back : " << copyQueue.Back() << endl;
    cout << "Size : " << copyQueue.Size() << endl;

    // Copy Assignment Operator
    cout << "\n Copy Assignment Operator " << endl;
    QueueArray<int> assignQueue;
    assignQueue = q;

    cout << "Front: " << assignQueue.Front() << endl;
    cout << "Back : " << assignQueue.Back() << endl;
    cout << "Size : " << assignQueue.Size() << endl;

    // Clear Queue
    cout << "\n Clear Queue " << endl;
    q.Clear();

    cout << "Empty: " << q.Empty() << endl;
    cout << "Size : " << q.Size() << endl;

    return 0;
}