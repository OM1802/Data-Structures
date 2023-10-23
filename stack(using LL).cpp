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

    stack.Push(10);
    stack.Push(15);
    stack.Pop();
    stack.Push(7);
    stack.Push(8);
    stack.Push(19);
    stack.Push(17);
    stack.Pop();
    stack.Traverse();
    return 0;
}