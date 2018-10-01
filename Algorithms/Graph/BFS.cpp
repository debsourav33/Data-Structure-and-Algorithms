#include<bits/stdc++.h>
using namespace std;

//{
#define cel(n,k) ((n-1)/k+1)
#define sets(a) memset(a, -1, sizeof(a))
#define clr(a) memset(a, 0, sizeof(a))
#define max(a,b) ((a)>(b)? (a):(b))
#define min(a,b) ((a)<(b)? (a):(b))
#define fr(n) for(int i=0;i<n;i++)
#define fr1(n) for(int i=1;i<=n;i++)
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
int n, vis[100005], level[100005], edges, parent[100005], c[100005], d[100005], cycle=0;

void reset(){
    clr(vis);
    clr(level);
    sets(parent);
}

void bfs(int source){
    queue<int> q;
    q.push(source);
    vis[source]= 1;

    while(!q.empty()){
        int u= q.front();
        q.pop();

        int mark[100005];
        clr(mark);

        for(int i=0;i<v[u].size();i++){
            int node= v[u][i];

            if(!mark[c[node]]){
                d[u]++;
                mark[c[node]]= 1;
            }

            if(!vis[node]){
                vis[node]= 1;
                level[node]= level[u]+ 1;
                parent[node]= u;

                q.push(node);
            }

        }

    }

}


void print_parent(int node){
    if(node==-1)
        return;

    print_parent(parent[node]);
    cout<<node<<" ";
}

main(){
    reset();
    int a, b;

    cin>>n>>edges;

    fr1(n){
        cin>>c[i];
    }

    fr1(edges){
        cin>>a>>b;

        v[a].pb(b);
        v[b].pb(a);
    }

    fr1(n){
        if(vis[i]==0)
            bfs(i);
    }

    int col, maxi=0;

    fr1(n){
        cout<<d[i]<<endl;
        if(d[i]>maxi){
            maxi= d[i];
            col= c[i];
        }

        if(d[i]==maxi){
            if(c[i]<col)
                col= c[i];
        }
    }

    cout<<col<<endl;
}
