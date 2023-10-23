// Array Concatenation (Append B into A)
#include <iostream>
using namespace std;
#define size 20

void displayArr(int arr[], int n){
for( int i = 0; i < n; i++ ){
cout << arr[ i ] << ", ";
}
cout << endl;
}

void ConcatenateArray(int A[], int &n, int B[], int m )
{
if( (size - n) >= m )
{
for( int i = n, j=0; j < m; i++, j++ )
{
A[i] = B[j];
n++;
}
}
}

int main() {
int A[size] = {1,2,3,4,5};
int B[size] = {6,7,8,9};
int n1 = 5;
int n2 = 4;

cout << "First Array: ";
displayArr( A, n1 );

cout << "Second Array: ";
displayArr( B, n2 );

ConcatenateArray( A, n1, B, n2 );
cout << "Array A after concatenating Array B:" << endl;
displayArr( A, n1 );

return 0;
}