#include<bits/stdc++.h>
using namespace std;

struct edge{
    int ver;
    int cost;

    edge(int v, int c){
        ver = v;
        cost = c;
    }

    bool operator<(edge e1) const{
        return cost > e1.cost;
    }
};

int main(){
    int span = 0;
    
    //puts("Let's go");

    int n, m;
    scanf("%d %d",&n,&m);
    vector<edge> v[n+1];
   
    while(m--){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);

        v[a].push_back(edge(b,c));
        v[b].push_back(edge(a,c));
    }
   

    vector<int> vis(n+1,0);
    priority_queue<edge> q;

    vis[1] = 1;
    for(edge e: v[1])  q.push(e);
    
    while(!q.empty()){
        int node = q.top().ver, cost = q.top().cost;
        q.pop();
        
        if(vis[node])  continue;
        vis[node] = 1;

        span += cost;
        for(edge e: v[node])   q.push(e);
    }

    printf("%d\n",span);    
}
