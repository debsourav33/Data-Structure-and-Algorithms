#include<bits/stdc++.h>
using namespace std;

//{
#define cel(n,k) ((n-1)/k+1)
#define sets(a) memset(a, -1, sizeof(a))
#define clr(a) memset(a, 0, sizeof(a))
#define max(a,b) ((a)>(b)? (a):(b))
#define min(a,b) ((a)<(b)? (a):(b))
#define fr(n) for(int i=0;i<n;i++)
#define pb push_back
#define all(v) v.begin(),v.end()
#define mp make_pair
#define ff first
#define ss second
#define INF 10000007

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
//}

vector<int> v[100005];
int visited[100005], parent[100005], n, edges, cycle=0;

void reset(){
    clr(vis);
    sets(parent);
}

void dfs(int u){
    vis[u]= 1;

    fr(v[u].size()){
        int node= v[u][i];
        if(nd==parent[u]) continue;

        if(!vis[nd]){
            parent[nd]= u;
            dfs(nd);
        }

        if(vis[nd]==1){
            cycle= 1;
            return;
        }
    }

    vis[u]= 2;
}

main(){
    reset();
    int a, b;

    cin>>n>>edges;

    fr(edges){
        cin>>a>>b;

        v[a].pb(b);
        v[b].pb(a);
    }

    fr(n){
        if(vis[i]==0)
            dfs(i);
    }

    cout<<cycle<<endl;
}
