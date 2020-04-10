#include<bits/stdc++.h>
using namespace std;
#define v32 vector<int>

//fft : a(x) = a0(x^2) +xa1(x^2)  divide and conquer
//reference : https://cp-algorithms.com/algebra/fft.html

//for modulo of the result see ntt.cpp


using cd = complex<double>;
const double PI = acos(-1);

int reverse(int num, int lg_n){
    //reverse the bits
    int res=0;
    for(int i=0;i<lg_n;i++){
        if(num & (1<<i)){
            res |= 1<<(lg_n-1-i);
        }
    }
    return res;
}

void fft(vector<cd> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}

v32 mutiply(v32 const &a,v32 const &b){
    vector<cd> fa(a.begin(),a.end()),fb(b.begin(),b.end());
    int n=1;
    while(n < a.size()+b.size()){
        n<<=1;
    }
    //n is a power of 2
    fa.resize(n);
    fb.resize(n);

    fft(fa,false);
    fft(fb,false);

    for(int i=0;i<n;i++)
        fa[i]*=fb[i];
    
    fft(fa,true);

    vector<int> result(n);
    for(int i=0;i<n;i++)   
        result[i]=round(fa[i].real());

    //Normalization in case of multiplying two large numbers
    // int carry=0;
    // for(int i=0;i<n;i++){
    //     result[i]+=carry;
    //     carry=result[i]/10;
    //     result[i]%=10;
    // }

    return result;
}

int32_t main(){
    ;
}