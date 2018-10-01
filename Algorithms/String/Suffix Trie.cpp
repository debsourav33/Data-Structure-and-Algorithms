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
#define null NULL

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
//}

struct node{
    int leaf;
    node* child[26];

    node(){
        leaf= 0;
        fr(26)
            child[i]= null;
    }
};

struct SuffixTrie{
    node* root= new node();

    void insert(char str[], int i, node* root){
        if(i==strlen(str)){
            root->leaf= 1;
            return;
        }

        int id= str[i]- 'a';

        if(root->child[id]==null){
            node* t= new node();
            root->child[id]= t;
        }

        insert(str,i+1,root->child[id]);
    }

    bool query(char str[], int i, node* root){
        if(root==null)
            return false;

        if(i==strlen(str))
            return 1; //pattern check
            //return root->leaf; //suffix check

        int id= str[i]- 'a';
        query(str,i+1,root->child[id]);
    }
};

main(){
    SuffixTrie T;
    char str[200005];
    int n,q;

    cin>>str;
    int len= strlen(str);

    fr(len){
        T.insert(str,i,T.root);
    }

    cin>>q;
    fr(q){
        cin>>str;
        cout<<T.query(str,0,T.root)<<endl;
    }
}
