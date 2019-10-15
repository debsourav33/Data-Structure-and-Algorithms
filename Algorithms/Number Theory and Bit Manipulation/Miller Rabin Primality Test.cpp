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

#define lefts 2*at
#define rights 2*at+1

const int N= 1e5+5;

i64 multiply( i64 a , i64 b , i64 mod ){
    a = a%mod;

    i64 res = 0;

    while (b){

        if (b&1){
            res =(res + a)%mod;
        }

        a = (2*a)%mod;
        b = b >> 1;
    }

    return res;
}

i64 fastexpo(i64 b, i64 e, i64 M){
    i64 ans=1;

    while(e){
        if(e&1)  ans= multiply(ans,b,M) % M;

        if(b<1e9)  b= (b*b) % M;
        else  b= multiply(b,b,M);

        e/= 2;
    }

    return ans;
}

bool millerrabin( i64 n , i64 d ){

    i64 a=2+rand()%(n-4); // find any random number [2,n-2]

    // find x = pow(a,d)%n;

    i64 x = fastexpo(a,d,n);

    if ( x==1 or x== n-1 ) return true;

    while ( d != n-1 ){

        if(x>1e9)  x= multiply(x,x,n);
        else  x= (x*x%n);

        d = d*2;

        if ( x==1 ) return false;

        if ( x==n-1 ) return true;

    }

    return false;
}

bool primality( i64 n , i64 k ){

    if ( n <=4 and n != 2 and n!= 3 ){

        return false;
    }

    if ( n == 2 or n==3){

        return true;
    }

    //n-1 is odd
    // find d such that n-1 is d*2^r;

    i64 d = n-1;

    while (d%2== 0)
        d = d/2;

    for (i64 i=1;i<=k;i++){

        if (millerrabin(n,d)) {
            continue;
        }
        else{
            return false;
        }
    }

    return true;
}

//for a= 2.7e13
//n=10,000, k=3, time= 3s... k=2, time=2s
//n=1,000, k=10, time= 2s... k=20, time=4s... k=1, time<1s... k=4 time<2s
//n=500, k=20, time= 2s... k=20, time=4s... k=1, time<1s... k=4 time<2s
main(){
    int opt;
    si(opt);

    fr(opt) {
        i64 a;
        sl(a);

        bool isprime= primality(a, 1);

        if(isprime)  puts("YES");
        else  puts("NO");
    }
}
