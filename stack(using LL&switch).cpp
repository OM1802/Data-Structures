#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
class Stack {
private:
    Node* top;
public:
    Stack() {
        top = nullptr;
    }
    void Push(int val) {
        Node* newNode = new Node;
        newNode->data = val;
        newNode->next = top;
        top = newNode;
        cout<<"ELEMENT PUSHED SUCCESSFULLY \n";
    }
    void Pop() {
        if (IsEmpty()) {
            cout << "STACK EMPTY: UNDERFLOW CONDITION IDENTIFIED!" << endl;
        } else {
            Node* temp = top;
            top = top->next;
            cout<<"ELEMENT POPPED SUCCESSFULLY \n";
            cout << "The deleted/popped element is: " << temp->data << endl;
            free(temp);
        }
    }
    void Traverse() {
        if (IsEmpty()) {
            cout << "Stack is empty" << endl;
        } else {
            cout << "Stack elements are:" << endl;
            Node* current = top;
            while (current != nullptr) {
                cout << current->data << "\n";
                current = current->next;
            }
             
        
        }
    }

    bool IsEmpty() {
        return top == nullptr;
    }
};
int main(){
    Stack stack;
    int ch,val;
    do{
        
    
    cout<<"PLEASE PRESS 1 TO USE PUSH OPERATION \n";
    cout<<"PLEASE PRESS 2 TO USE POP OPERATION \n";
    cout<<"PLEASE PRESS 3 TO DISPLAY THE STACK \n";
    cout<<"PLEASE PRESS 4 TO EXIT \n";
    cin>>ch;
    switch(ch){
            case 1:
                cout << "Enter value to push: ";
                cin >> val;
                stack.Push(val);
                break;

            case 2:
                stack.Pop();
                break;

            case 3:
                stack.Traverse();
                break;

            case 4:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (ch != 4);
        

        
            
    
    return 0;
}