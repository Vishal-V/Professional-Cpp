#include <bits/stdc++.h>
using namespace std;

set<string> s;
int counts = 0;

void subsequence(char in[], int i, char out[], int j){
    if(in[i] == '\0'){
        out[j] = '\0';
        s.insert(out);
        counts++;
        cout << out << endl;
        return;
    }

    out[j] = in[i];
    subsequence(in, i+1, out, j+1);
    out[j] = '\0';
    subsequence(in, i+1, out, j);
}

void bitwise_subsequences(int n, string input){
    int k = 0;
    while(n > 0){
        if(n & 1)
            cout << input[k];
        k++;
        n = n>>1;
    }
}

int num_bits(int n){
    int res = 0;
    for(;n>0;n=n>>1){
        if(n&1)
            res++;
    }
    return res;
}

int main() {
    char in[100], out[100];
    cin >> in;
    subsequence(in, 0, out, 0);
    cout << counts << endl;
}