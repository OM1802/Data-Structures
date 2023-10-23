#include<iostream>
using namespace std;
struct node
{
    struct node *prev;
    struct node *next;
    int data;
};
struct node *head=NULL;
void delete_at_end();
void createlist(int);
void display();
int main ()
{
    createlist(10);
    createlist(20);
    createlist(30);

    cout<<"list before Deletion"<<endl;
    display();
    delete_at_end();

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


void delete_at_end(){
   struct node *ptr;
   ptr = head;
   if(head==NULL)
   {
       cout<<"\n Underflow ! As List is empty \n"<<endl;
   }
   else if(head->next == NULL){
        head = NULL;
        free(head);
        cout<<endl<<"\n Only one node in the list, First/Last Node deleted...\n"<<endl;

   }
   else
   {
       while(ptr->next!=NULL){
        ptr = ptr->next;
       };
       ptr->prev->next = NULL;
       free(ptr);
       cout<<endl<<"\n Last Node deleted...\n"<<endl;
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
