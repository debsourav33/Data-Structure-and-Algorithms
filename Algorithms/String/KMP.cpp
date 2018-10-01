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

string text, p;
int pi[1000006];

void prefix_function(){
    int now;

    pi[0]= now= -1;

    for(int i=1; i<p.length();i++){
        while(now!=-1 && p[i]!=p[now+1])
            now= pi[now];

        if(p[i]==p[now+1])    pi[i]= ++now;
        else    pi[i]= -1;
    }
}

int kmp(){
    int match=0, now;
    now= -1;

    fr(text.length()){
        while(now!=-1 && text[i]!=p[now+1])
            now= pi[now];

        if(text[i]==p[now+1])  ++now;
        else  now= -1;

        if(now==p.length()-1){
            match++;
            now= pi[now];
        }
    }

    return match;
}


main(){
    cin>>text>>p;

    prefix_function();
    cout<<kmp()<<endl;
}
