class disjointset{
    public:

    vector<int> rank;
    vector<int> size;
    vector<int> parent;
    disjointset(int n){
        rank.resize(n+1);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findparent(int u){
        if(u==parent[u]){
            return u;
        }
        return parent[u]=findparent(parent[u]);
    }
    void unionbyrank(int u,int v){
        int ult_u=findparent(u);
        int ult_v=findparent(v);
        if(ult_v==ult_u) return;
        if(rank[ult_u]>rank[ult_v]){
            parent[ult_v]=parent[ult_u];
        }
        else if(rank[ult_v]<rank[ult_u]){
            parent[ult_u]=parent[ult_v];
        }
        else{
            parent[ult_u]=parent[ult_v];
            rank[ult_v]++;
        }
    }
    void unionbysize(int u,int v){
        int ult_u=findparent(u);
        int ult_v=findparent(v);
        if(ult_v==ult_u) return;
        if(size[ult_u]>size[ult_v]){
            parent[ult_v]=parent[ult_u];
            size[ult_u]+=size[ult_v];
        }
        else{
            parent[ult_u]=parent[ult_v];
            size[ult_v]+=size[ult_u];
        }
    }
};
