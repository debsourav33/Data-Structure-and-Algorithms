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
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long i64;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
//}

#define lefts 2*at
#define rights 2*at+1

const int N= 1e6+5;

i64 sum[4*N], left_max[4*N], right_max[4*N], maxi[4*N], lazy[4*N], st[4*N], endi[4*N];
i64 num[N];

struct node{
    i64 s, l, r, m;

    node(i64 _l, i64 _r, i64 _m, i64 _s){
        l= _l;
        r= _r;
        m= _m;
        s= _s;
    }
};

void marge(int at){
    left_max[at]= max(left_max[lefts], sum[lefts]+left_max[rights]);
    right_max[at]= max(right_max[rights], sum[rights]+right_max[lefts]);
    maxi[at]= max( max(maxi[lefts],maxi[rights]), right_max[lefts]+left_max[rights]);
    sum[at]= sum[lefts]+ sum[rights];

    st[at]= st[lefts];
    endi[at]= endi[rights];
}

void build(int at, int l, int r){
    if(l==r){
        left_max[at]= num[l];
        right_max[at]= num[l];
        maxi[at]= num[l];
        sum[at]= num[l];

        st[at]= l;
        endi[at]= r;
        lazy[at]= 0;

        return;
    }

    int mid= (l+r)/2;

    build(2*at,l,mid);
    build(2*at+1,mid+1,r);
    marge(at);
}

void upd(int at, i64 x){
    i64 cnt= endi[at]- st[at]+1;
    lazy[at]= x;

    sum[at]= cnt*x;
    right_max[at]= max(x,sum[at]);
    left_max[at]= max(x,sum[at]);
    maxi[at]= max(x,sum[at]);
}

void propagate(int at){
    upd(lefts, lazy[at]);
    upd(rights, lazy[at]);

    lazy[at]= 0;
}

void update(int at, int l, int r, int x, int y, i64 val){
    if(x<=l && r<=y){
        lazy[at]= val;
        i64 cnt= endi[at]- st[at] +1;

        sum[at]= cnt*val;
        right_max[at]= max(val,sum[at]);
        left_max[at]= max(val,sum[at]);
        maxi[at]= max(val,sum[at]);

        return;
    }

    if(x>r || y<l)  return;

    if(lazy[at]) propagate(at);

    int mid= (l+r)/2;

    update(lefts,l,mid,x,y,val);
    update(rights,mid+1,r,x,y,val);
    marge(at);
}

node query(int at, int l, int r, int x, int y){
    if(l>=x && r<=y)  return node(left_max[at], right_max[at], maxi[at], sum[at]);
    if(l>y || r<x)  return node(-INF,-INF,-INF,-INF);

    if(lazy[at]) propagate(at);

    int mid= (l+r)/2;

    node a= query(lefts,l,mid,x,y);
    node b= query(rights,mid+1,r,x,y);

    i64 le= max(a.l, a.s+ b.l);
    i64 ri= max(b.r, b.s+ a.r);
    i64 ma= max(max(a.m,b.m), a.r+b.l);
    i64 su= a.s+ b.s;

    return node(le,ri,ma,su);
}

main(){
    int n;
    si(n);

    fr(n)  sl(num[i]);

    i64 q, x, y;
    i64 opt, c;

    build(1,0,n-1);

    sl(q);
    while(q--){
        puts("2 for query...");
        sl(opt);

        if(opt==1){
            slll(x,y,c);

            update(1,0,n-1,x-1,y-1,c);
            puts("Updated");
        }
        else {
            sll(x, y);

            node ans = query(1,0,n-1,x-1, y-1);
            printf("%lld\n", ans.m);
        }
    }
}

/*
 7
 1 4 -2 3 -6 2 2

 5

 2
 1 4
 1
 2 4 3
 1 4

 */
