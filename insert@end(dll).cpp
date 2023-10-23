#include<iostream>
using namespace std;
struct node
{
    struct node *prev;
    struct node *next;
    int data;
};
struct node *head=NULL;
void insertion_end(int);
void createlist(int);
void display();
int main ()
{
    createlist(5);
    createlist(10);
    createlist(15);
    display();
    insertion_end(20);
    display();
}
void createlist(int x)
{
   struct node *ptr,*temp;

   ptr = (struct node *)malloc(sizeof(struct node));

      if(head==NULL)
   {
       ptr->next = NULL;
       ptr->prev=NULL;
       ptr->data=x;
       head=ptr;
   }
   else
   {      temp = head;
          ptr->data=x;
          while(temp->next!=NULL)
          {
              temp = temp->next;
          }
          temp->next = ptr;
          ptr ->prev=temp;
          ptr->next = NULL;

   }

}


void insertion_end(int x)
{
   struct node *ptr,*temp;
   ptr = (struct node *)malloc(sizeof(struct node));

      if(head==NULL)
   {
       ptr->next = NULL;
       ptr->prev=NULL;
       ptr->data=x;
       head=ptr;
   }
   else
   {
       temp=head;
       ptr->data=x;
       ptr->next=NULL;
       while(temp->next!=NULL)
       {
            temp=temp->next;
       }
       temp->next=ptr;
       ptr->prev=temp;

   cout<<"\nNode inserted\n";
}
}

void display()
{
    struct node *ptr;
    cout<<"\n printing values...\n";
    ptr = head;
    while(ptr!= NULL)
    {
        cout<<"->"<<ptr->data;
        ptr=ptr->next;
    }
    cout<<"->"<<"NULL";
}
