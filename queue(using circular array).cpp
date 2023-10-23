#include <iostream>
using namespace std;

int queue[100], front = -1, rear = -1, choice, n;

void enqueue() {
    int item;
    cout << "ENTER THE ELEMENT TO INSERT: " << endl;
    cin >> item;
    if ((rear + 1) % n == front) {
        cout << "OVERFLOW CONDITION IDENTIFIED! INSUFFICIENT MEMORY TO STORE AN ELEMENT IN CIRCULAR QUEUE!!" << endl << endl;
    } else if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % n;
    }
    queue[rear] = item;
    cout << "ELEMENT ENQUEUED SUCCESSFULLY!" << endl << endl;
}

void dequeue() {
    int item;
    if (front == -1 && rear == -1) {
        cout << "UNDERFLOW CONDITION IDENTIFIED!" << endl << endl;
    } else {
        item = queue[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % n;
        }
        cout << "ELEMENT DEQUEUED SUCCESSFULLY" << endl;
        cout << "THE DEQUEUED ELEMENT IS: " << item << endl << endl;
    }
}

void display() {
    if (front == -1 && rear == -1) {
        cout << "THE QUEUE IS EMPTY" << endl;
    } else {
        cout << "FRONT->|";
        for (int i = front; i != rear; i = (i + 1) % n) {
            cout << queue[i] << "|";
        }
        cout << queue[rear] << "|<-REAR" << endl << endl;
    }
}

int main() {
    cout<<"Enter the size of the circular queue: "<<endl<<endl;
    cin>>n;
    cout<<"\n";
    
    do {
        cout<< "----------------------------------------------" << endl;
        cout<< "PLEASE CHOOSE AN OPTION FROM THE GIVEN MENU:- |" << endl;
        cout<< "----------------------------------------------" << endl;
        cout<< "PLEASE PRESS 1 TO USE ENQUEUE OPERATION" << endl;
        cout<< "PLEASE PRESS 2 TO USE DEQUEUE OPERATION" << endl;
        cout<< "PLEASE PRESS 3 TO DISPLAY THE QUEUE" << endl;
        cout<< "PLEASE PRESS 4 TO EXIT" << endl;
        cin>>choice;
        switch (choice) {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                cout<< "Exiting program." << endl;
                cout<<"PROGRAM OVER.";
                break;

            default:
                cout << "Invalid choice. Please try again." << endl<<endl;
        }
    } while (choice != 4);

    return 0;
}
