#include<iostream>
using namespace std;

int recur(int n){
    if(n<=1){
        return n;
    }
    return recur(n-1)+recur(n-2);
}

void non_recur(int n){
    int a=0,b=1;
    cout<<a<<" "<<b<<" ";
    for(int i=2;i<n;i++){
        int c = a+b;
        cout<<c<<" ";
        a=b;
        b=c;
    }
}

int main(){
    int n;
    cout<<"Enter the the number: ";
    cin>>n;

    cout<<"Fibonacci Series:"<<endl;
    cout<<"Fibonacci Recursive:";
    for(int i=0;i<n;i++){
        cout<<recur(i)<<" ";
    }
    cout<<endl;

    cout<<"Fibonacci Non-Recursive:";
    non_recur(n);
    cout<<endl;

    cout<<"\nTime and Space Complexity Analysis:"<<endl;
    cout<<"Recursive -> Time: O(2^n), Space: O(n)"<<endl;
    cout<<"Non-Recursive -> Time: O(n), Space: O(1)"<<endl;
}





