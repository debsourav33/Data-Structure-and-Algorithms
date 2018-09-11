#include<bits/stdc++.h>
using namespace std;

//{
#define sets(a) memset(a, -1, sizeof(a))
#define clr(a) memset(a, 0, sizeof(a))
#define max(a,b) ((a)>(b)? (a):(b))
#define min(a,b) ((a)<(b)? (a):(b))
#define fr(n) for(int i=0;i<n;i++)
#define ull unsigned long long
#define ll long long
#define pb push_back
#define INF 10000007
#define all(v) v.begin(),v.end()
//}

vector<int> v[100005];
stack<int> topos;
int visited[100005], parent[100005], cycle=0;

void reset(){
    clr(visited);
    sets(parent);
}

void topsort(int u){
    visited[u]= 1;

    fr(v[u].size()){
        int node= v[u][i];
        if(node==parent[u]) continue;

        if(!visited[node]){
            parent[node]= u;
            topsort(node);
        }
    }

    topos.push(u);
    visited[u]= 2;
}

main(){
    reset();
    int a, b, n, edges;

    cin>>n>>edges;

    fr(edges){
        cin>>a>>b;

        v[a].pb(b);
        //v[b].pb(a);
    }

    for(int i=0;i<n;i++){
        if(visited[i]==0)
            topsort(i);
    }

    while(!topos.empty()){
        cout<<topos.top()<<" ";
        topos.pop();
    }
}
