#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *head;

void beginsert ();
void lastinsert ();
void display();

int main() {
lastinsert();
lastinsert();
lastinsert();

display();

return 0;
}

void beginsert()
{
    struct node *ptr,*temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if(ptr == NULL)
    {
        cout<<"\nOVERFLOW, Memory not available...\n";
    }
    else
    {
        cout<<"\nEnter the node data?";
        cin>>item;
        ptr -> data = item;
        if(head == NULL)
        {
            head = ptr;
            ptr -> next = head;
        }
        else
        {
            temp = head;
            while(temp->next != head)
                temp = temp->next;
            ptr->next = head;
            temp -> next = ptr;
            head = ptr;
        }
        cout<<"\nnode inserted at the beginning\n";
    }

}
void lastinsert()
{
    struct node *ptr,*temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if(ptr == NULL)
    {
        cout<<"\nOVERFLOW, Memory not available...\n";
    }
    else
    {
        cout<<"\nEnter node Data?";
        cin>>item;
        ptr->data = item;
        if(head == NULL)
        {
            head = ptr;
            ptr -> next = head;
        }
        else
        {
            temp = head;
            while(temp -> next != head)
            {
                temp = temp -> next;
            }
            temp -> next = ptr;
            ptr -> next = head;
        }

        cout<<"\nnode inserted at the end\n";
    }

}

void display()
{
    struct node *ptr;
    ptr=head;
    if(head == NULL)
    {
        cout<<"\nList is Empty, nothing to print...\n";
    }
    else
    {
        cout<<"\n printing list ... \n";
        cout<<"head ->";
        while(ptr -> next != head)
        {
            cout<<ptr -> data;
            cout<<"->";
            ptr = ptr -> next;
        }
        cout<<ptr -> data;
        cout<<"-> pointing to head back";
    }

}
