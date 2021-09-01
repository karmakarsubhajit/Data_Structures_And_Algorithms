// https://www.geeksforgeeks.org/quick-sort/

#include <bits/stdc++.h>

using namespace std;

// Space complexity:-  O(logn) due to recursive stack
// Time complexity:-
// Average Case:- O(nlogn)
// Best Case:- O(nlogn)
// Worst Case:- O(n^2)

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}
int partition(vector<int>& v, int low, int high)
{
  int pivot = v[high];
  int i=low-1;
  for(int j=low;j<=high-1;j++)
  {
     if(v[j]<pivot)
     {
        i++;
        swap(&v[i], &v[j]);
     }
  }
  swap(&v[i+1],&v[high]);
  return i+1;
}

void quickSort(vector<int>& v, int low, int high)
{
   if(low<high)
   {
      int pi = partition(v,low,high);
      quickSort(v,low,pi-1); 
      quickSort(v,pi+1,high); 
   }
}

int main()
{
  vector<int> v{9,2,1,4,7,-1};
  int n = v.size();
  quickSort(v,0,n-1);
  for(auto i:v)
     cout<<i<<", ";


  return 0;
}