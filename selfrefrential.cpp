#include <iostream>     //self refrential structure
using namespace std;
struct Student{
    int marks;
    char grade;
    struct Student *link;
};
int main()
{
    struct Student s1;
    //initialization for 1st student
    s1.link=NULL;
    s1.marks=100;
    s1.grade='A';
    
    struct Student s2;
    //initialization for 2nd student
    s2.link=NULL;
    s2.marks=50;
    s2.grade='C';
    
    s1.link = &s2;  //linking both objects
    cout<<"MARKS OF s1: "<<s1.marks<<endl;
    cout<<"GRADE OF s1: "<<s1.grade<<endl;
    cout<<"MARKS OF s2: "<<s1.link->marks<<endl;
    cout<<"GRADE OF s2: "<<s1.link->grade<<endl;
    return 0;
}