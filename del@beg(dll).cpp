#include<iostream>
using namespace std;
struct node
{
    struct node *prev;
    struct node *next;
    int data;
};
struct node *head=NULL;
//void insertion_beginning(int);
void delete_at_beg();
void createlist(int);
void display();
int main ()
{
    createlist(10);
    createlist(20);
    createlist(30);

    cout<<"list before Deletion"<<endl;
    display();
    delete_at_beg();

    cout<<"list after Deletion"<<endl;
    display();
    return 0;
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
       //cout<<"\nIf part executed...";
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
          //cout <<"\nElse part is executed...";

   }

}


void delete_at_beg()
{
   struct node *ptr;
   ptr = head;
   if(head==NULL)
   {
       cout<<"\n Underflow ! As List is empty \n"<<endl;
   }
   else if(head->next == NULL){
    head = NULL;
    free(ptr);
    cout<<endl<<"\n First Node deleted...\n"<<endl;
   }
   else
   {
       head = head->next;
       head->prev = NULL;
       free(ptr);
       cout<<endl<<"\n First Node deleted...\n"<<endl;
   }
}

void display()
{
    struct node *ptr;

    //cout<<endl<<"printing values..."<<endl;
    if(head == NULL){        cout <<"\n\n List is empty, no element to display...\n\n";
    }
    else{
    ptr = head;

    cout<<"NULL"<<"<-";
    while(ptr!= NULL)//ptr->next!=NULL
    {
        cout<<ptr->data<<"->";
        ptr=ptr->next;
    }
    cout<<"NULL";
    }

}
