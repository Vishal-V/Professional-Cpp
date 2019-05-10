#include <bits/stdc++.h>
using namespace std;

int fastpower(int a, int b){
    if(b == 0)
        return 1;
    int res = fastpower(a, b/2);
    res *= res;

    if(b&1)
        res *= a;
    return res;
}

bool cmp(string a, string b){
    if(a.length() == b.length())
        return a > b;
    return (a.length() < b.length());
}

set<string> s;

void substring(char in[], int i, char out[], int j){
    // Base case
    if(in[i] == '\0'){
        out[j] = '\0';
        s.insert(out);
        return;
    }

    out[j] = in[i];
    substring(in, i+1, out, j+1);
    out[j] = '\0';
    substring(in, i+1, out, j);
}

void perm(char in[], int i){
    // Base case
    if(in[i] == '\0'){
        cout << in << endl;
        return;
    }

    for(int j=i;in[j] != '\0'; j++){
        swap(in[i], in[j]);
        perm(in, i+1);
        swap(in[j], in[i]);
    }
}

void replacePI(char s[], int i){
    // Base case
    if(s[i+1] == '\0'){
        return;
    }

    if(s[i]=='p' && s[i+1]=='i'){
        int j = i;
        while(s[j]) j++;
        while(j > i+1){
            s[j+2] = s[j];
            j--;
        }
        s[i] ='3';
        s[i+1]='.';
        s[i+2]='1';
        s[i+3] = '4';
    }

    if(s[i] != 'p')
        replacePI(s, i+1);
}

int BinSrchIter(int a[], int l, int x){
    int low = 0, high = l, mid = 0;
    while(low < high){
        mid = (low + high)/2;
        if(x == a[mid]) return mid;
        else if(x < a[mid]) high = mid-1;
        else low = mid+1;
    }
    return 0;
}

int brec(int a[], int s, int e, int x){
    if(e==s){
        if(a[e]==x) return e;
        else return 0;
    }
    else{
        int mid = (e+s)/2;
        if(a[mid] == x) return mid;
        else if(x < a[mid]) return brec(a, s, mid, x);
        else return brec(a, mid+1, e, x);
    }
}

void merge(int a[], int x[], int y[], int s, int e){
    int mid = (e+s)/2;
    int i=s, j=mid+1, k=s;
    while(i<=mid && j<=e){
        if(x[i] < y[j])
            a[k++] = x[i++];
        else
            a[k++] = y[j++];
    }

    while(i<=mid) a[k++] = x[i++];
    while(j<=e) a[k++] = y[j++];

}

void mergesort(int a[], int s, int e){
    // Base case
    if(s==e || s > e)
        return;
    
    int mid = (e+s)/2;
    int x[e-s+1], y[2*(e-s+1)];
    for(int i=0;i<=mid;i++)
        x[i] = a[i];
    for(int j=mid+1;j<=e;j++)
        y[j] = a[j];
    
    mergesort(x, s, mid);
    mergesort(y, mid+1, e);

    merge(a, x, y, s, e);
}

int main(){
    // int arr[] = {5,4,3,2,1};
    // int length = sizeof(arr)/sizeof(arr[0]), x;

    // mergesort(arr, 0, length - 1);

    // for(int i=0;i<length;i++)
    //     cout << arr[i] << " ";   
    // cout << "\n" << "Enter the number to search for: ";
    // cin >> x;
    // int index = brec(arr, 0, length, x);
    // if(index)
    //     cout << x << " found at index " << index << endl;
    int a, b;
    cin >> a >> b;
    int res = fastpower(a,b);
    cout << res << endl;
}