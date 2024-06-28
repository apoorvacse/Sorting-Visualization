#include<iostream>
#include<windows.h>
using namespace std;
// use template function for wide range of data types
template< typename T>
T add(T a,T b){
  return a+b;
}
template< typename T>
T sub(T a,T b){
  return a-b;
}
template< typename T>
T multiply(T a,T b){
  return a*b;
}
template< typename T>
T divide(T a,T b){
  if(b!=0) return a/b;
  else cout<<" Cant be divisible by 0";
}
void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
template< typename T>
void print( T net){
  if(net<0) setColor(12);// red color
  else setColor(10);// greeen color
  cout<<"net is:"<<net<<endl;
}
int main(){
  double a,b;
  cout<<"      Enter 2 numbers: \n";
  cin>>a  >>b;
  cout<<"Enter the operation to be performed on numbers(+,-,*,/): \n";
  char operation;
  cin>>operation;
  setColor(10); // Set text color to green
  switch(operation){
    case '+':
            print(add(a,b));
             break;
    case '-':
            print(sub(a,b));
             break;
    case '*':
             print(multiply(a,b));
             break;
    case '/':
             print(divide(a,b));
             break;
    default:
           cout<<"invalid operatory!Try again.";
            
  }
   setColor(7); // Reset to default color
  return 0;
}
