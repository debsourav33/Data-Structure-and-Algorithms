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

const int N= 1e5+5;

int n, phi[N], mark[N];

void sievephi(int n){
    fr1(n)  phi[i]= i;

    mark[1]= 1;
    phi[1]= 1;

    for(int i=2;i<=n;i++){
        if(mark[i])  continue;

        for(int j=i;j<=n;j+=i){
            mark[j]= 1;
            phi[j]= phi[j]- phi[j]/i;
        }
    }
}

i64 totient(i64 n){
    i64 phi= n;
    factorize(n);

    for(pll p: factors){
        phi= phi-phi/p.ff;
    }

    return phi;

}

main(){
    si(n);

    sievephi(n);

    fr1(30){
        cout<<i<<": "<<phi[i]<<endl;
    }
}
