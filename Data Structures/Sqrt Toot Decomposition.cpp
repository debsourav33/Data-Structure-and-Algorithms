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
const int sN= 1e5+5;

int n, m, k, Block, cnt[205][205][205], a[N];

void process_block(int no){
    int st= no*Block, endi= (no+1)*Block;
    endi= min(n,endi);

    for(int i=st;i<endi;i++){
        frj1(202){
            int mod= a[i]%j;

            cnt[no][j][mod]++;
        }
    }
}

void preprocess(){
    int no_of_blocks= cel(n,Block);

    fr(no_of_blocks)  process_block(i);
}

void query1(int x, int y, int m, int q){
    int st_block= x/Block, end_block= y/Block, ans= 0;

    for(int i=st_block; i<=end_block; i++){
        ans+= cnt[i][m][q];
    }

    int st= st_block*Block, endi= (end_block+1)*Block;
    endi= min(n,endi);

    //outii(st,endi);
    //outi(ans);

    for(int i=st; i<x;i++){
        if(a[i]%m==q)  ans--;
    }

    for(int i=y+1; i<endi;i++){
        if(a[i]%m==q)  ans--;
    }

    outi(ans);
}


main(){
    int x,y,m,q, opt;
    sii(n,opt);
    Block= (int) sqrt(n)+1;

    fr(n)  si(a[i]);

    preprocess();

    fr(opt){
        sii(x,y);
        sii(q,m);
        --x, --y;

        query1(x,y,m,q);
    }
}

