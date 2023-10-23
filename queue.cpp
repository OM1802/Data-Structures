#include<iostream>
using namespace std;
int queue[100];
    int front=-1, rear=-1,choice,n;

void Enque(){
    int item;
    cout<<"ENTER THE ELEMENT TO BE INSERTED: \n";
    cin>>item;
    if(rear==(99)){
        cout<<"OVERFLOW CONDITION IDENTIFIED!"<<endl;
    }
    else if(front==-1 & rear==-1){
        front++;
        rear++;
    }
    else{
        rear=rear+1;
    }
    queue[rear]=item;
    cout<<"ELEMENT ENQUED SUCCESSFULLY \n";
}
void Dequeue(){
    int item;
    if(front==-1){
        cout<<"UNDERFLOW CONDITION IDENTIFIED!"<<endl<<endl;
    }
    else{
        item=queue[front];
        if(front==rear){
            front==-1;
            rear=-1;
        }
        else{
            front+=1;
        }
        cout<<"ELEMENT DEQUEUED SUCCESSFULLY \n";
        cout<<"THE DEQUEUED ELEMENT IS: "<<item<<endl<<endl;
    }
    
}
void Display(){
    if(front==-1){
        cout<<"THE QUEUE IS EMPTY \n";
    }
    else{
        cout<<"FRONT->|";
        for(int i=front; i<=rear;i++){
            cout<<queue[i]<<"|";
        }
    }
    cout<<"<-REAR"<<endl<<endl;
}
int main(){
    int choice;
    do{
    cout<<endl<<endl;
    cout<<"PLEASE CHOOSE AN OPTION FROM THE GIVEN MENU:- "<<endl;
    cout<<"**********************************************"<<endl;
    cout<<"PLEASE PRESS 1 TO USE ENQUE OPERATION \n";
    cout<<"PLEASE PRESS 2 TO USE DEQUEUE OPERATION \n";
    cout<<"PLEASE PRESS 3 TO DISPLAY THE QUEUE \n";
    cout<<"PLEASE PRESS 4 TO EXIT \n"<<endl<<endl;
    cin>>choice;
    switch(choice){
        case 1:
                Enque();
                break;

            case 2:
                Dequeue();
                break;

            case 3:
                Display();
                break;

            case 4:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
    }
    
    }while(choice!=4);
    return 0;
    
   
    
    
}