/*
 Insertion in singly linked list 
1. Insert at the beginning  O(1)
2. Insert at the end (with help of traversing) O(n)
3. Insert at any position (with help of traversing) O(n)
4. Delete at the beginning  O(1)
5. Delete at the end  O(n)
*/
#include<iostream>
using namespace std;
struct node{
    int data;
    struct node *next;
};
struct node *start=NULL;
void delAtbegn();
void createlist(int);
void insertAtbegn(int);
void insertAtend(int);
void insertAtanyLoc(int,int); //(data,loc);
void transverse();
void delAtend();

int main(){
    createlist(10);
    createlist(20);
    createlist(30);

    cout << "Initial linked list: ";
    transverse();
    cout << endl;

    delAtbegn();
    cout<<"Linked list after deleting at the beginning: ";
    transverse();
    cout << endl;

    insertAtbegn(5);
    cout << "Linked list after inserting 5 at the beginning: ";
    transverse();
    cout << endl;

    insertAtend(40);
    cout << "Linked list after inserting 40 at the end: ";
    transverse();
    cout << endl;

    insertAtanyLoc(25, 2);
    cout << "Linked list after inserting 25 at position 2: ";
    transverse();
    cout << endl;

    delAtend();
    cout << "Linked list after deleting at the end: ";
    transverse();
    cout << endl;

    return 0;
    

}
void delAtend(){
    struct node *t1, *t2;
    t1=start;
    if(start==NULL){
        cout<<"LIST IS EMPTY"<<endl;
        return;
    }
    else{
        while(t1->next !=NULL){
            t2=t1;
            t1=t1->next;

        }
        free(t1);
        t2->next=NULL;
    }

}

void delAtbegn(){
    struct node *temp;
    temp=start;
    if(start==NULL){
        cout<<"LIST IS EMPTY"<<endl;
        return;
    }
    else{
        temp=start->next;
        free(start);
        start=temp;
    }

}

 void createlist(int x){
    struct node *ptr, *temp; //new node, traversing
    temp=start;
    ptr=(struct node*)malloc(sizeof(struct node)); //dynamically allocating single memory with malloc
    ptr->data=x;
    ptr->next=NULL;
    if(start==NULL){ //link is empty, this is the first node
    start=ptr;
    } 
    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=ptr;
    }
 }

 void insertAtbegn(int x){
    struct node *t;

    t=(struct node*) malloc (sizeof(struct node));
    t->data=x;
    t->next=NULL;

    if(start==NULL){
        start=t;
        start->next=NULL;
        return;
    }
    else{
        t->next=start;
        start=t;
    }
 }
 void insertAtend(int x){
    struct node *t = new struct node;
    t->data = x;
    t->next = NULL;

    if (start == NULL) {
        start = t;
        start->next = NULL;
        return;
    }
    struct node *temp = start;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = t;
}

void insertAtanyLoc(int x, int loc) {
    struct node *t = new struct node;
    t->data = x;
    t->next = NULL;

    if (start == NULL) {
        start = t;
        start->next = NULL;
        return;
    }

    if (loc == 1) {
        t->next = start;
        start = t;
        return;
    }

    struct node *temp = start;
    for (int i = 1; i < loc - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Invalid position. Insertion not possible." << endl;
    }
    else {
        t->next = temp->next;
        temp->next = t;
    }
}

 void transverse(){
    struct node *t;
    t=start;
    if(t==NULL){
        cout<<"LINKED LIST IS EMPTY \n";
        return;
    }
    while(t->next != NULL){
        cout<<t->data<<"->";
        t=t->next;
    }
    cout<<t->data<<"->NULL";
 }

 
