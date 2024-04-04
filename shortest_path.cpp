vi shortpath(n,1e18);
    shortpath[0]=0;
    set<pair<int,int>> st;
    st.insert({0,0});
    while(!st.empty()){
        auto i=st.begin();
        int steps=i->first;
        int node=i->second;
        st.erase(i);
        for(auto it:adj[node]){
            if(shortpath[it.first]>steps+it.second){
                st.erase({shortpath[it.first],it.first});
                shortpath[it.first]=steps+it.second;
                st.insert({shortpath[it.first],it.first});

            }
        }
    }
