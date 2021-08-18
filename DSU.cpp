class DSU{
    public:
    vector<int> p, r ; //p-> parent , r->rank
    void init(int n){
        p.assign(n+1,0); r.assign(n+1 , 1);
        //asign parent of each node to itself initially
        FOR(i,1,n){
            p[i]=i;
        }
    }
    int get(int a){
         //path compression
         if(p[a]!=a){
             return (p[a] = get(p[a]));
         }
         return p[a];
    }
    void unite(int a , int b){
        a = get(a);
        b = get(b);
        if(a==b){
            return;
        }
        if(r[a]==r[b])  //union by rank
           r[a]++;
        if(r[a]>r[b]){
            p[b]=a ;
        }
        else{
            p[a]=b ; 
        }
    }
};