class Solution {
public:
    vector<int> par;
    vector<int> rank;  //height of longest sub stree

    int find(int u){
      if(par[u]==u)  return u;

      return par[u] = find(par[u]);
    }

    void unions(int u, int v){
      u = find(u);
      v = find(v);

      //pick the longer tree's parent 
      if(rank[u]==rank[v]){
        par[u] = v;
        rank[v]++; //new rank of v = new child u (1) + rank[u]
      }
      else if(rank[u] < rank[v]){
        par[u] = v; //no need to update rank as rank[v] >= new child u (1) + rank[u]
      }
      else{
        par[v] = u;
      }
    }
}
