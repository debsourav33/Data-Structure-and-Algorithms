#include<bits/stdc++.h>
#define ll long long
using namespace std;

int blockSize = 500;
vector<ll> sortedBlock[1000];
ll blockXorVal[1000];

void update(int block,int a[],int n)
{
  int startIndex = block*blockSize;
  int endIndex = (block+1)*blockSize;
  endIndex--;
  endIndex = min(endIndex,n);
  int prefXor = 0;
  sortedBlock[block].clear();
  for(int i=startIndex;i<=endIndex;i++)
  {
    prefXor^=a[i];
    sortedBlock[block].push_back(prefXor);
  }
  blockXorVal[block] = prefXor;
  sort(sortedBlock[block].begin(),sortedBlock[block].end());
}

int query(int index,int val,int a[])
{
  int ans = 0;
  int startBlock = 0;
  int endBlock = index/blockSize;
  int currXor = 0;
  while(startBlock<endBlock)
  {
    int neededVal = currXor^val;
    int tempAns = upper_bound(sortedBlock[startBlock].begin(),sortedBlock[startBlock].end(),neededVal)-lower_bound(sortedBlock[startBlock].begin(),sortedBlock[startBlock].end(),neededVal);
    ans+=tempAns;
    currXor^=blockXorVal[startBlock];
    startBlock++;
  }
  int startIndex = startBlock*blockSize;
  for(int i=startBlock*blockSize;i<=index;i++)
  {
    currXor^=a[i];
    if(currXor == val)
    {
      ans++;
    }
  }
  return ans;
}

int main()
{
 // freopen("testcase4.txt","r",stdin);
 // freopen("output4.txt","w",stdout);
  int n,q;
  scanf("%d %d",&n,&q);
  int a[n];
  for(int i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
  int totalBlocks = n/blockSize;
  for(int i=0;i<=totalBlocks;i++)
  {
    update(i,a,n-1);
  }
  while(q--)
  {
    int type,index,val;
    scanf("%d %d %d",&type,&index,&val);
    index--;
    if(type == 1)
    {
      a[index] = val;
      update(index/blockSize,a,n-1);
    }
    else
    {
      int ans = query(index,val,a);
      printf("%d\n",ans);
    }
  }
  return 0;
}
