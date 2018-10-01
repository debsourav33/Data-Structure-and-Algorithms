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

ll resetbit(ll a, ll i){
    return a & ~(1LL<<i);
}

ll setbit(ll a, ll i){
    return a | (1LL<<i);
}

bool match(ll a, ll b, ll i){
    bool as= a & (1LL<<i);
    bool bs= b & (1LL<<i);

    return as==bs;
}

ll and_in_range(ll a, ll b){
    ll mm=-1;
    ll limit= 63;

    fr(limit){
        if(!match(a,b,i))
            mm= i;
    }
    mm++;

    ll andi= b;
    fr(mm){
      andi= resetbit(andi,i);
    }

    return andi;

}

ll or_in_range(ll a, ll b){
    ll mm=-1;
    ll limit= 63;

    fr(limit){
        if(!match(a,b,i))
            mm= i;
    }
    mm++;

    ll ori= b;
        fr(mm){
          ori= setbit(ori,i);
        }

    return ori;

}

main(){
    ll a,b;
    cin>>a>>b;
    cout<<or_in_range(a,b)<<endl;
}
