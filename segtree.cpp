#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
struct segtree{ //zero based indexing
    lli size;
    vector<lli> value;
    void init(lli n){
        size=1;
        while(size<n){
            size*=2;
        }
        value.assign(2*size, 0);
    }
    void build(vector<lli> &A , lli x , lli lx , lli rx){
        if(rx-lx <=1){
            if(lx < A.size()){
                value[x] = {A[lx]};
            }
            return;
        }
         lli m = (lx+rx)/2;
         build(A , 2*x + 1, lx , m);
         build(A , 2*x + 2 , m , rx);
         value[x] = __gcd(value[2*x+1],value[2*x+2]);
    }
    void build(vector<lli> &A){
        build(A, 0 , 0 , size);
    }
    void set(lli i , lli v , lli x , lli lx , lli rx){  //[lx , rx) i.e lx is included while rx is not
        if((rx - lx <= 1)){
            value[x]=v;
            return;
        }
        lli m = (lx+rx)/2;
        if(i < m){
            set(i , v , 2*x + 1 , lx , m );
        }
        else{
            set(i , v , 2*x + 2, m , rx);
        }
        
        value[x] = __gcd(value[2*x+1],value[2*x+2]);
        
    }
    void set(lli i , lli v){
        set(i ,v , 0 , 0 , size);
    }

    lli calc(lli l,lli r , lli x, lli lx, lli rx){ //[lx , rx) i.e lx is included while rx is not
        if(lx >= r || rx <= l)
           return 0 ;
        if(lx>=l && rx <=r)
            return value[x];
        lli m = (lx + rx)/2;
        lli s1 = calc(l , r , 2*x + 1, lx , m);
        lli s2 = calc(l , r , 2*x + 2 , m , rx);
        return (s1+s2);
    }

    lli calc(lli l,lli r){
        return calc(l , r, 0 , 0 , size);
    }
};