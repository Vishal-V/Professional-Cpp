#include <iostream>
using namespace std;

int * createArray(int size){
    int * arr = new int[size];
    cout << "The address of array: " << arr << endl;
    return arr;
}

int power(int a, int b){

    if(b==0)
        return 1;
    
    int value = power(a, b/2);
    value *= a;

    if(b&1)
        value *= a;

    return value;
}

int fib(int n){
    if(n==0||n==1)
        return n;
    else 
        return fib(n-1) + fib(n-2);
}

int arrFib(int n){
    int * num = new int[n];
    num[0] = 0;
    num[1] = 1;

    for(int i=2;i<=n;i++)
        num[i] = num[i-1] + num[i-2];
    return num[n];
}

void printPerm(char * input, int i, int& count){
    if(input[i] == '\0'){
        cout << input << endl;
        count++;
        return;
    }

    for(int j=i;input[j]!='\0';j++){
        swap(input[i], input[j]);
        count++;
        printPerm(input, i+1, count);
        swap(input[i], input[j]);
    }
}

int main(){
    // int value = power(4,4);
    // cout << value << endl;
    // cout << "Recursive fib of 5: " << fib(9) << endl;
    // cout << "Iterative fib of 5: " << arrFib(9) << endl;

    char input[100];
    cout << "Enter string: ";
    cin >> input;
    int * count;
    *count = 0;
    printPerm(input, 0, *count);
    cout << *count << endl;

    return 0;
}