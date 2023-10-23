#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *head;

void lastinsert ();

void begin_delete();
void last_delete();

void display();

int main ()
{
    lastinsert();
    lastinsert();
    lastinsert();
    display();

    last_delete();
    display();

    begin_delete();
    display();
    return 0;
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

void begin_delete()
{
    struct node *ptr;
    if(head == NULL)
    {
        cout<<"\nUNDERFLOW, List is empty...\n";
    }
    else if(head->next == head)
    {
        head = NULL;
        free(head);
        cout<<"\nnode deleted from the beginning...\n";
    }

    else
    {   ptr = head;
        while(ptr -> next != head)
            ptr = ptr -> next;
        ptr->next = head->next;
        free(head);
        head = ptr->next;
        cout<<"\nnode deleted from the beginning...\n";

    }
}
void last_delete()
{
    struct node *ptr, *preptr;
    if(head==NULL)
    {
        cout<<"\nUNDERFLOW, List is empty...\n";
    }
    else if (head ->next == head)
    {
        head = NULL;
        free(head);
        cout<<"\nnode deleted from the end...\n";

    }
    else
    {
        ptr = head;
        while(ptr ->next != head)
        {
            preptr=ptr;
            ptr = ptr->next;
        }
        preptr->next = ptr -> next;
        free(ptr);
        cout<<"\nnode deleted from the end...\n";

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
