// https://www.geeksforgeeks.org/insertion-sort/

#include <bits/stdc++.h>

// Space complexities:- O(1)

//Time complexities
// Best case:- O(n)
// Average case:- O(n^2)
// Worst case:- O(n^2)


using namespace std;

void insertionSort(vector<int>& arr)
{
    
    for(int i=1;i<arr.size();i++)
    {
       int temp = arr[i];
       int j = i-1;
       while(j>=0 && arr[j]>temp)
       {
          arr[j+1] = arr[j];
          j--;  
       }    
       arr[j+1] = temp;
    }
}

int main()
{
    vector<int> v{10,1,2,4,9};
    int n = v.size();
    insertionSort(v);
    for(auto i:v)
        cout<<i<<" ";

    return 0;
}
