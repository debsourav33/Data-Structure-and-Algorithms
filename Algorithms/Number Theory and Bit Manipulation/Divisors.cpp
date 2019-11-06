#include<bits/stdc++.h>
using namespace std;

//{
#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d %d",&a,&b);
#define siii(a,b,c) scanf("%d %d %d",&a,&b,&c);

#define sl(a) scanf("%lld",&a)
#define sll(a,b) scanf("%lld %lld",&a,&b);
#define slll(a,b,c) scanf("%lld %lld %lld",&a,&b,&c);

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

const int N= 1e6+6;

int n;
vector<int> divs[N];
vector<i64> d;


void getDiv(i64 x){
    for(i64 i=1; i*i<=x; i++)
    {
        if(x%i==0){
            if(i*i==x)  d.pb(i);
            else  d.pb(i), d.pb(x/i);
        }
    }

    sort(all(d));
}



void sieve_div(int n){
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j+=i){
            divs[j].pb(i);
        }
    }

    for(int i=1;i<=n;i++)
        sort(all(divs[i]));
}


main(){
    si(n);

    sieve_div(n);

    fr1(100){
        cout<<i<<":";
        for(int j=0;j<divs[i].size();j++)
            cout<<" "<<divs[i][j];
        puts("");
    }
}
