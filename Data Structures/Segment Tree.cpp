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

int n, a[100005], sum[400020];

void build(int at, int L, int R){
    if(L==R){
        sum[at]= a[L];
        return;
    }

    int mid= (L+R)/2;

    build(at*2,L,mid);
    build(at*2+1,mid+1,R);

    sum[at]= sum[at*2]+ sum[at*2+1];
}

void update(int at, int L, int R, int pos, int val){
    if(L==R){
        sum[at]= val;
        return;
    }

    int mid= (L+R)/2;
    if(pos<=mid)
        update(at*2, L, mid, pos, val);
    else
        update(at*2+1, mid+1, R, pos, val);

    sum[at]= sum[at*2]+ sum[at*2+1];
}

int query(int at, int L, int R, int l, int r){

    if(r<L || l>R)  return 0;
    if(l<=L && r>=R)  return sum[at];

    int mid= (L+R)/2;

    int x= query(at*2, L, mid, l, r);
    int y= query(at*2+1, mid+1, R, l, r);

    return x+y;
}

main(){
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    build(1,1,n);

    update(1,1,n,4,11);

    cout<<query(1,1,n,2,7)<<endl;
}
