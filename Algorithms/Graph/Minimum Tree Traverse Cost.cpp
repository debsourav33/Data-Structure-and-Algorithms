#include<bits/stdc++.h>
using namespace std;

//{
#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d %d",&a,&b);
#define siii(a,b,c) scanf("%d %d %d",&a,&b,&c);

#define sl(a) scanf("%lld",&a)
#define sll(a,b) scanf("%lld %lld",&a,&b);
#define slll(a,b,c) scanf("%lld %lld %lld",&a,&b,&c);

#define outi(a) printf("%d\n",a)
#define outii(a,b) printf("%d %d\n",a,b)
#define outis(a) printf(" %d",a)

#define outl(a) printf("%lld\n",a)
#define outll(a,b) printf("%lld %lld\n",a,b)
#define outls(a) printf(" %lld",a)

#define cel(n,k) ((n-1)/k+1)
#define sets(a) memset(a, -1, sizeof(a))
#define clr(a) memset(a, 0, sizeof(a))
#define fr(n) for(int i=0;i<n;i++)
#define fr1(n) for(int i=1;i<=n;i++)
#define frj(n) for(int j=0;j<n;j++)
#define frj1(n) for(int j=1;j<=n;j++)
#define pb push_back
#define all(v) v.begin(),v.end()
#define mp make_pair
#define ff first
#define ss second
#define INF 10000007
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long i64;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
//}

const int maxn= 1e5+5;

i64 subtree[maxn], n, T[maxn], tot[maxn], L[maxn], Dist[maxn], maxi[maxn];
i64 self_cost[maxn];
vector<int> v[maxn];
vector<i64> costs[maxn];

void dfs(int u, int p, i64 c){
    T[u]= p;

    Dist[u]= c;
    maxi[u]= Dist[u];

    fr(v[u].size()){
        int nd= v[u][i];
        if(nd==p) continue;

        i64 cst= costs[u][i];
        self_cost[nd]= cst;

        dfs(nd,u,c+cst);

        maxi[u]= max(maxi[u],maxi[nd]);
    }
}

i64 total= 0, traverse;

i64 dfs2(int u, int p){
    traverse+= 1;
    if(traverse==n)  return -1;

    fr(v[u].size()){
        int nd= v[u][i];
        i64 cst= self_cost[nd];

        if(nd==p) continue;

        total+=cst;

        i64 ret_cost= dfs2(nd,u);
        if(ret_cost==-1)  return -1;
        else total+=cst;
    }

    return 0;
}



bool cmp(int a, int b){
    return maxi[a]<maxi[b];
}

main(){
    int a,b;
    i64 w;
    sl(n);

    fr(n-1){
        sii(a,b);
        sl(w);

        v[a].pb(b);
        v[b].pb(a);

        costs[a].pb(w);
        costs[b].pb(w);
    }

    dfs(1,-1,0);

    //fr1(n)  outii(i,maxi[i]);
    fr1(n)  sort(all(v[i]),cmp);
    dfs2(1,-1);

    outl(total);
}

/*
8
 1 2 3
 1 3 3
 2 4 15
 2 5 16
 3 6 5
 3 7 21
 6 8 20
*/
