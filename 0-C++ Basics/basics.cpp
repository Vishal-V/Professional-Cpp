#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#define my_sizeof(type) (char *)(&type+1)-(char *)(&type)
using namespace std;

char * reverse(char * str, int length){
    char * temp;
    int j = length;
    for(int i = 0; str[i]!='\0';)
        temp[j--] = str[i++];
    return temp;
}

char * better_reverse(char * str, int length){
    int start = 0, end = length-1;
    while(start < end){
        swap(*(str + start), *(str + end));
        start++;
        end--;
    }
    return str;
}

char * itoa(int num, char * buffer, int base){
    char * str;
    int i = 0;
    bool isNeg = false;
    if(!num){
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }
    if(num < 0 && base == 10){
        isNeg = true;
        num = -num;
    }
    while(num > 0){
        int rem = num % base;
        str[i++] = (rem > 9)?(rem-10) + 'a' : rem + '0';
        num = num/base;
    }
    if(isNeg)
        str[i++] = '-';
    str[i] = '\0';
    return reverse(str, i);
}

void change(int a[], int &b){
    a[0] = 100;
    b = 20;
}

int main(int argc, char * argv[]){
    int * a = new int[20];
}