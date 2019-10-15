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

const int maxn= 2e5+5;

#define lefts 2*at
#define rights 2*at+1

int lazy[4*maxn], maxi[4*maxn], n, l[maxn], r[maxn], a[maxn];

void marge(int at){
    maxi[at]= max(maxi[lefts],maxi[rights]);
}

void build(int at, int l, int r){
    if(l==r){
        maxi[at]= a[l];
        return;
    }

    int mid= (l+r)/2;

    build(lefts,l,mid);
    build(rights,mid+1,r);
    marge(at);
}

void upd(int at, int x){
    lazy[at]+= x;
    maxi[at]+= x;

}

void propagate(int at){
    upd(lefts, lazy[at]);
    upd(rights, lazy[at]);

    lazy[at]= 0;
}

void update(int at, int l, int r, int x, int y, int val){
    if(x<=l && r<=y){
        lazy[at]+= val;
        maxi[at]+= val;
        return;
    }

    if(x>r || y<l)  return;

    if(lazy[at]) propagate(at);

    int mid= (l+r)/2;

    update(lefts,l,mid,x,y,val);
    update(rights,mid+1,r,x,y,val);
    marge(at);
}

int query(int at, int l, int r, int x, int y){
    if(x<=l && r<=y){
        return maxi[at];
    }

    if(x>r || y<l)  return -1e9;

    if(lazy[at]) propagate(at);

    int mid= (l+r)/2;
    int a= query(lefts,l,mid,x,y);
    int b= query(rights,mid+1,r,x,y);

    return max(a,b);
}

main(){
    int q,x,y,l,r;
    sii(n,q);
    fr(n)  si(a[i]);

    build(1,0,n-1);

    while(q--){
        si(x);

        if(x==1){
            sii(x,y);
            --x, --y;
            outi(query(1,0,n-1,x,y));
        }
        else{
            siii(l,r,x);
            --l, --r;
            update(1,0,n-1,l,r,x);
        }
    }


}
