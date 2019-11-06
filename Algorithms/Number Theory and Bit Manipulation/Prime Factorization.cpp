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

i64 n;
vector<pll> factors;

void factorize(i64 n){
    factors.clear();

    for(i64 i=2; i*i<=n; i++){
        i64 fl=0, cnt=0;

        while(n%i==0){
            n/= i;
            cnt++;
            fl= 1;
        }


        if(fl)  factors.pb(mp(i,cnt));
    }

    if(n>1)  factors.pb(mp(n,1));
}


i64 curr[N];

void sieve_factorize(i64 n){
    fr1(n)  curr[i]= i;

    for(i64 i: primes){
        for(i64 j=i; j<=n; j+=i)
        {
            i64 cnt= 0;
            while(curr[j]%i ==0)
            {
                cnt++;
                curr[j]/= i;
            }

            factors[j].pb(mp(i,cnt));
        }

    }
}

void genDiv(int pos, i64 prev){
    if(pos==factors.size()){
        d.pb(prev);
        return;
    }

    genDiv(pos+1,prev);

    i64 curr= 1;
    fr(factors[pos].ss) {
        curr*= factors[pos].ff;
        genDiv(pos + 1, prev * curr);
    }
}

i64 nod(i64 n){
    i64 nods= 1;
    for(auto fac: factors[n])
        nods*= (1+fac.ss);

    return nods;
}

i64 sod(i64 n){
    factors.clear();
    factorize(n);

    i64 sods= 1;
    fr(factors.size()){
        i64 fact= factors[i].ff;
        i64 p= 1;

        for(i64 j=0;j<=factors[i].ss;j++)
            p*= fact;

        sods*= (p-1)/(fact-1);
    }

    return sods;
}

main(){
    sl(n);

    factorize(n);

    fr(factors.size())
        cout<<factors[i].ff<<": "<<factors[i].ss<<endl;

    cout<<"NOD: "<<nod(n)<<endl;
    cout<<"SOD: "<<sod(n)<<endl;
}
