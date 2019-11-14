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


const int N= 1e5+5;

#define lefts 2*at
#define rights 2*at+1

int n, a[N], sum[4*N];

void merge(int at){
    sum[at]= sum[lefts]+ sum[rights];
}

void build(int at, int L, int R){
    if(L==R){
        sum[at]= a[L];
        return;
    }

    int mid= (L+R)/2;

    build(lefts,L,mid);
    build(rights,mid+1,R);

    merge(at);
}

void update(int at, int L, int R, int pos, int val){
    if(L==R){
        sum[at]= val;
        return;
    }

    int mid= (L+R)/2;
    if(pos<=mid)
        update(lefts, L, mid, pos, val);
    else
        update(rights, mid+1, R, pos, val);

    merge(at);
}

int query(int at, int L, int R, int l, int r){

    if(r<L || l>R)  return 0;
    if(l<=L && r>=R)  return sum[at];

    int mid= (L+R)/2;

    int x= query(lefts, L, mid, l, r);
    int y= query(rights, mid+1, R, l, r);

    return x+y;
}

main(){
    int n, q;
    sii(n,q);

    fr(n)
        sl(a[i]);

    build(1,0,n-1);

    //update(1,1,n,4,11);

    int x, a, b;
    fr(q) {
        si(x);

        if(!x){
            sii(a,b);
            printf("%d\n",query(1,0,n-1,a-1,b-1));
        }
        else{
            sii(a,b);
            update(1,0,n-1,a-1,b);
        }
    }

}
