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

int n, num, i, a[100005];

ll resetbit(ll a, ll i){
    return a & ~(1LL<<i);
}

ll setbit(ll a, ll i){
    return a | (1LL<<i);
}

bool check(ll mask, int i){
    return mask & (1LL<<i);
}

ll toggle(ll mask, int i){
    return mask ^ (1LL<<i);
}

bool is_even(ll num){
    return !(num & 1);
}

bool is_equal(ll a, ll b){
    return a^b ? 0:1 ;
}

int reset_last_1bit(int num){
    return num-= num & -num;
}

int no_of_one(int num){
    int cnt= 0;

    while(num){
        num-= num & -num;
        ++cnt;
    }

    return cnt;
}

bool is_pow_of_2(int num){
    int cnt= 0;

    while(num){
        num-= num & -num;
        ++cnt;
    }

    return cnt==1;
}

bool isPowerOfTwo(int num){
    return num && !(num & num-1);
}

bool match(ll a, ll b, ll i){
    bool as= a & (1LL<<i);
    bool bs= b & (1LL<<i);

    return as==bs;
}

main(){
    cout<<is_pow_of_2(4096)<<endl;
}
