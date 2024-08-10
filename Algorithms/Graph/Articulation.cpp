/*
Articulation Point/Bridge Algorithm:

Varibales: Discovery time array, Low time array

1. Start dfs
2. Increment global time variable and initiate discovery time to that time
3. Initiate low to discovery time for any node for which dfs is called
4. Recursively call dfs for each child and go back to step 2
5. For each call returned for a child, update low to
   low[u] = min(low[u], low[child])
6. If for any child v, d[u] stays <= low[u], u is an Articulation Point  
   If for any child v, d[u] stays < low[u], u-v is a Bridge
*/



#include<bits/stdc++.h>
using namespace std;

#define clr(a) memset(a,0,sizeof(a))
#define sets(a) memset(a,-1,sizeof(a))
#define pb push_back

vector<int> v[1000];
int visited[1000], brid[1000][1000], t, AP[1000], d[1000], low[1000], parent[1000];

void reset(){
    clr(visited);
    clr(d);
    clr(AP);
    clr(brid);
    sets(parent);
    t=0;
}

void dfs(int u){
    visited[u]= 1;
    low[u]= d[u]= ++t;
    int child= 0;

    for(int i=0;i<v[u].size();i++){
        int node= v[u][i];
        if(node==parent[u]) continue;

        if(!visited[node]){
            child++;
            parent[node]= u;

            dfs(node);
            low[u]= min(low[u],low[node]);

            if(parent[u]==-1 && child>1)
                AP[u]= 1;
            if(parent[u]!=-1 && d[u]<=low[node])
                AP[u]= 1;
        }

        else {
            low[u]= min(low[u],d[node]);
        }
    }
}

void bridge(int u){
    visited[u]= 1;
    low[u]= d[u]= ++t;

    for(int i=0;i<v[u].size();i++){
        int node= v[u][i];
        if(node==parent[u]) continue;

        if(!visited[node]){
            parent[node]= u;

            bridge(node);
            low[u]= min(low[u],low[node]);

            if(d[u]<low[node]){
                brid[u][node]= 1;
            }
        }

        else{
            low[u]= min(low[u],d[node]);
        }
    }
}

main(){
    reset();

    int a, b, n, edges;
    cin>>n>>edges;

    for(int i=0;i<edges;i++){
        cin>>a>>b;

        v[a].pb(b);
        v[b].pb(a);
    }

    for(int i=0;i<n;i++)
        if(visited[i]==0)
            dfs(i);

    for(int i=0;i<n;i++)
        if(AP[i])
            cout<<i<<endl;


//    for(int i=0;i<n;i++)
//        if(!visited[i])
//            bridge(i);
//
//    for(int i=0;i<n;i++)
//        for(int j=0;j<n;j++){
//            if(brid[i][j])
//                cout<<i<<"-"<<j<<endl;
//        }

}

