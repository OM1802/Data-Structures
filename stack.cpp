#include<iostream>
using namespace std;
int stack[100],n,top=-1;
void Push(int);
void Pop();
void Traverse();
int main(){
    cout<<"ENTER NO. OF ELEMENTS TO STORE IN STACK; \n";
    cin>>n;
     Push(5);
     Push(15);
     Push(25);
     Push(35);
     Push(45);
     Push(55);
     Traverse();
     Pop();
     Traverse();
     
    
    
}
    void Push(int val){
    if(top==(n-1)){
        cout<<"STACK FULL:OVERFLOW CONDITION IDENTIFIED! \n";
    }
    else{
        top=top+1;
        stack[top]=val;
    }
}
void Pop() {
   if(top<=-1)
   cout<<"STACK EMPTY:UNDERFLOW CONDITION IDENTIFIED! \n"<<endl;
   else {
      cout<<"The popped element is: "<< stack[top] <<endl;
      top--;
   }
}
void Traverse() {
   if(top>=0) {
      cout<<"Stack elements are: \n"<<endl;
      for(int i=top; i>=0; i--)
      cout<<stack[i]<<"\n ";
      cout<<endl;
   } else
   cout<<"Stack is empty";
}