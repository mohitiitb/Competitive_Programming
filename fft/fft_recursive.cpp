#include<bits/stdc++.h>
using namespace std;
#define v32 vector<int>

//fft : a(x) = a0(x^2) +xa1(x^2)  divide and conquer
//reference : https://cp-algorithms.com/algebra/fft.html


using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd>&a, bool invert){
    //n is a power of 2, if not add zero coefficiet to make one
    int n=a.size();
    if(n==1)
        return;
    vector<cd> a0(n/2),a1(n/2);
    for(int i=0;2*i<n;i++){
        a0[i]=a[2*i];
        a1[i]=a[2*i +1];
    }
    fft(a0,invert);
    fft(a1,invert);

    double ang=2*PI/n*(invert?-1:1);
    cd w(1),wn(cos(ang),sin(ang));

    for(int i=0;2*i<n;i++){
        a[i]=a0[i]+w*a1[i];
        a[i+n/2]=a0[i]-w*a1[i];
        if(invert){
            a[i]/=2;
            a[i+n/2]/=2;
            //happens at each level of recursion so the value is divided by n
        }
        w*=wn;
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