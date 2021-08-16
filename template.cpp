#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef long double lld;
typedef priority_queue <lli , vector<lli>, greater<lli> > min_heap;
typedef priority_queue <lli> max_heap;
const lli  M = 1e9 + 7;
const lli M1 = 998244353;
const lli M2 = 1000000000000000001;
lli mod(lli x){   return (x%M);}
lli mod_minus(lli a, lli b){ lli ans= (mod(a)-mod(b)); if(ans<0) ans=mod(ans+M); return ans;}
lli mod_mul(lli a,lli b){  return mod(mod(a)*mod(b));}
lli mod_add(lli a,lli b){ return mod(mod(a)+mod(b));}
#define FOR(i,l,u) for(lli i=l;i<=u;i++)
#define FAST ios_base :: sync_with_stdio (false); cin.tie (NULL)
lli ceill(lli a,lli b)
{
    if(a%b==0)
    return a/b;
    else
    return a/b +1;
}

lli extended_gcd(lli a ,lli b,lli &x,lli &y){
    if(a==0){
        x=0;y=1;return b;}
    lli x1,y1,ans = extended_gcd(b%a,a,x1,y1);
    x = y1-(b/a)*x1;y = x1;
    return ans;
}
lli power_mod(lli a,lli b,lli m)
{
    lli ans =1;
    while(b!=0)
    {
        if(b%2==1)
        ans=(ans*a)%m;
        a=a*a;
        a%=m;
        b/=2;
    }
    return ans;
}
lli mod_inverse(lli a,lli m)
{
    return power_mod(a,m-2,m);
}
void mod_inverse_array(lli inv[],lli u,lli m)
{
    inv[1]=1;
    FOR(i,2,u){
        inv[i]=((-(m/i)*inv[m%i]%m)+m)%m;
    }
}
lli N_C_r_mod_m(lli N,lli r,lli factorial[], lli inv[])
{
    lli a = factorial[N],b = mod_inverse(factorial[N-r],M),c = mod_inverse(factorial[r],M);
    return mod_mul(a,mod_mul(b,c));
}
void prime_factorization(lli n,unordered_map<lli,lli> &m)
{
    lli i=2;
    while(n%i==0)
    {
        m[i]++;
        n=n/i;
    }
    for(i=3;i*i<=n;i+=2)
    {
        while(n%i==0)
        {
            m[i]++;
            n=n/i;
        }
    }
    if(n!=1)   
    m[n]++;
}

void linear_sieve(vector<lli> &pr,lli lp[],lli N)
{
    for (lli i=2; i<=N; ++i) {
    if (lp[i] == 0) {
        lp[i] = i;
        pr.push_back (i);
    }

    for (lli j=0; j<(lli)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
        lp[i * pr[j]] = pr[j];
    }
}
bool isPowerOfTwo (lli x)
{
    return x && (!(x&(x-1)));
}

int main()
{
    FAST;
    // #ifndef ONLINE_JUDGE
    // // for getting input from input.txt
    // freopen("input.txt", "r", stdin);
    // // for writing output to output.txt
    // freopen("output.txt", "w", stdout);
    // #endif
    // g++ -o output prac.cpp
    // .\output
    lli t=1;//cin>>t;
    while(t--)
    {
        solve();
    }
    
}
