//https://www.geeksforgeeks.org/merge-sort/
// Space complexity:- O(n)
// Time complexity:-
// Best Case:- O(nlogn)
// Worst Case:- O(nlogn)
// Average case:- O(nlogn)

#include<bits/stdc++.h>

using namespace std;

void merge(vector<int>& v, int l, int mid, int r)
{
  vector<int> L1(mid-l+1,0);
  vector<int> L2(r-mid,0);
  int t=0;
  for(int i=l;i<=mid;i++)
  {
     L1[t++] = v[i];
  }
  t=0;
  for(int i=mid+1;i<=r;i++)
  {
     L2[t++] = v[i];
  }
  int i=0;
  int j=0;
  int k=l;
  while(i<(mid-l+1) && j<(r-mid))
  {
    if(L1[i]<L2[j])
      v[k++] = L1[i++];
    else
      v[k++] = L2[j++];
  }
  while(i<(mid-l+1))
  {
     v[k++] = L1[i++];
  }
  while(j<(r-mid))
  {
     v[k++] = L2[j++];
  }
}


void mergeSort(vector<int>& v, int l, int r)
{
  if(l<r)
  {
    int mid = l+(r-l)/2;
    mergeSort(v,l,mid);
    mergeSort(v,mid+1,r);
    merge(v,l,mid,r); 
  }
}

int main()
{

  vector<int> v{9,8,7,7,0,10,6,-1,2};
  int n = v.size();
  mergeSort(v,0,n-1);
  for(auto i:v)
  {
     cout<<i<<", ";
  }

return 0;
}