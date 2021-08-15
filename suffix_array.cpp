#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
class suffix_array
{
    //$ is added here only, so first create suffix array then calculate size of string
    public:
    vector<lli> p,c;
    void init(string &t){
        t+='$';
        lli n = t.size();
        p.assign(n,0);
        c.assign(n,0);
    }
    void radix_sort(vector<lli> &p, vector<lli> &c){
        lli n = p.size();
        vector<lli> cnt(n, 0);
        for(lli i=0;i<=n-1;i++){
            cnt[c[i]]++;
        }
        vector<lli> pos(n);
        pos[0] = 0;
        for(lli i=1;i<=n-1;i++){
            pos[i] = pos[i-1]+cnt[i-1];
        }

        vector<lli> p_new(n);
        for(lli i=0;i<=n-1;i++){
            lli x = c[p[i]];
            p_new[pos[x]] = p[i];
            pos[x]++;
        }
        p = p_new;
    }
    void build_suffix_array(string t){
        lli n = p.size();
        {
            //k=0
            vector<pair<char,lli>> a(n);
            for(lli i=0;i<=n-1;i++){
                a[i] = {t[i],i};
            }
            sort(a.begin(),a.end());
            for(lli i=0;i<=n-1;i++){
                p[i] = a[i].second;
            }
            c[p[0]] = 0;
            for(lli i=1;i<=n-1;i++){
                if(a[i].first==a[i-1].first){
                    c[p[i]] = c[p[i-1]];
                }
                else{
                    c[p[i]] = c[p[i-1]]+1;
                }
            }
        }

        lli k = 0;
        {
            //k->k+1
            while((1<<k)<n){
                for(lli i=0;i<=n-1;i++){
                    p[i] = (p[i]-(1<<k)+n)%n;
                }
                radix_sort(p, c);
                vector<lli> c_new(n);
                c_new[p[0]] = 0;
                for(lli i=1;i<=n-1;i++){
                    pair<lli,lli> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n]};
                    pair<lli,lli> now = {c[p[i]], c[(p[i] + (1 << k)) % n]};
                    if(now==prev){
                        c_new[p[i]] = c_new[p[i-1]];
                    }
                    else{
                        c_new[p[i]] = c_new[p[i-1]]+1;
                    }
                }
                c= c_new;
                k++;
            }
        } 
    }    

};
