#include <iostream>
#include <initializer_list>
#include <algorithm>
#include <vector>
#include <string>
#include <memory>
using namespace std;

int addition(initializer_list<int> lst){
    int summed = 0;
    for(int val : lst){
        summed += val;
    }
    return summed;
}

bool cmp(int a, int b){
    return a < b;
}

void func(char* str){
    cout << "char* version" << endl;
}

void func(int i) {
    cout << "int version" << endl;
}

int main(){
    vector<int> v = {3,2,1};
    v.push_back(0);
    sort(v.begin(), v.end(), cmp);
    for(int val : v){
        cout << val << endl;
    }
    int * arr = new int[3];
    for(int i=0;i<3;i++)
        arr[i] = i;
    cout << addition({1,2,3}) << endl;

    typedef struct {
        string name;
        int id;
        long salary;
    }Employee;

    auto emps = make_unique<Employee[]>(10); // C++14 onwards
    unique_ptr<Employee[]> emp1(new Employee[10]); // Prior to C++14

    auto emps1 = make_shared<Employee>;
    shared_ptr<Employee[]> emps2(new Employee[10]); 

    delete[] arr;
    arr = nullptr;

}
