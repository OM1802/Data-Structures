/*
develop a program to reverse an array of characters without using any 
built-in string function. check for whether the given array contain a palindrome sequence or not? 
display the proper representation of array before and after reverse along with proper message
*/
//SOLUTION:-
#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"ENTER THE NO. OF ELEMENTS: \n";
    cin>>n;
    string S[n];
    cout<<"ENTER THE ELEMENTS FOR THE ARRAY: \n";
    for(int i=0; i<n;i++){
        cin>>S[i];
    }
    cout<<"ARRAY BEFORE REVERSE IS: \n";
    for(int i=0; i<n;i++){
        cout<<S[i]<<endl;
    }
    string reverseArr[n];
    for(int j=0,i=n-1; j<n,i>0; j++,i--){
        reverseArr[j]=S[i];
    }
    cout<<"ARRAY AFTER REVERSAL IS: \n";
    for(int j=0; j<=n;j++){
        cout<<reverseArr[j]<<endl;
    }
    for( int i=0; i<n;i++){
        if(S[i]==reverseArr[i]){
            cout<<"THERE IS PALINDROME SEQUENCE IN ARRAY AT "<<i+1<<" POSITION"<<endl;
            i++;
        }
        else{
            cout<<"THERE IS NO PALINDROME AT"<<i+1<<" POSITION"<<endl;
        }
    }
    return 0;
}
