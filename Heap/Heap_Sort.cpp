#include<bits/stdc++.h>

using namespace std;

void swap(int* a, int* b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void heapify(vector<int>& v, int n, int i)
{
  int largest = i; 
  int left = 2*i+1;
  int right = 2*i+2;
  if(left<n && v[left]>v[i])
    largest = left;
  if(right<n && v[right]>v[largest])
    largest = right;
  if(largest!=i)
  {
     swap(&v[i], &v[largest]);
     heapify(v,n,largest);
  } 
}

// Time complexity:- O(nlogn)

void heapSort(vector<int>& v, int n)
{
    // To build heap
    // O(n) time
    for(int i=n/2-1;i>=0;i--)
    {
        heapify(v,n,i);
    }
 
     // To do heap sort
    // O(nlogn) time
    for(int i=n-1;i>0;i--)
    {
       swap(&v[0],&v[i]);
       heapify(v,i,0);
    }
}

int main()
{
  vector<int> v {4,3,3,0,-1};  
  int n = 5;
  heapSort(v,n);
  for(auto i:v)
     cout<<i<<", ";
  cout<<endl;
  return 0;
}