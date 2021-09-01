#include<bits/stdc++.h>

using namespace std;

void swap(int* x, int* y)
{
   int t = *x;
   *x = *y;
   *y = t;
}

int parent(int i)
{
  return (i-1)/2;
}

int left(int i)
{
   return 2*i+1;
}

int right(int i)
{
   return 2*i+2;
}

class heap{
  public:
     int cap;
     int sz;
     int* arr;
  heap(int n) 
  {  
     cap=n;
     sz = 0;
     arr = new int[cap];
  }
  
  // O(logn)
  void insertKey(int val)
  {
     if(sz==cap)
     {
        cout<<"Capacity reached!"<<endl;
        return;   
     }
     sz++; 
     arr[sz-1]=val;
     int i=sz-1;
     while((i!=0) && arr[parent(i)]>arr[i])
     {
        swap(&arr[parent(i)],&arr[i]);  
        i=parent(i);   
     } 
  }
   // O(1)
    int getMin()
    {
       if(sz==0)
	 return INT_MAX;
	return arr[0];
    }
    // O(logn)
    void decreaseKey(int ky, int val)
    {
        if(sz==0)
           cout<<"No key to decrease"<<endl;
        arr[ky] = val;
        int i=ky;
        while(i!=0 && arr[parent(i)]>arr[i]) 
        {
            swap(&arr[parent(i)],&arr[i]);
            i=parent(i);
        }
    }

    // O(logn)
    int extractMin()
    {
       if(sz==0)
           return INT_MAX;
       if(sz==1)
       {
           sz=0;
           return arr[0];
       }
       int temp = arr[0];
       arr[0] = arr[sz-1];
       sz--;
       this->heapify(0);
       return temp;
    } 
   //  O(logn)
    void deleteKey(int key)
    {
	if(sz==0)
	{
		cout<<"Already empty"<<endl;
		return;
	}
	 
        this->decreaseKey(key,INT_MIN);
        this->extractMin(); 
    } 
    // O(logn)
    void heapify(int i)
    {
        int parent = i;
        int left = 2*i+1;
        int right = 2*i+2;
        int smallest = i;
        if(left<sz && arr[left]<arr[i])
           smallest = left;
        if(right<sz && arr[right]<arr[smallest])
           smallest =right; 
        if(smallest!=i)
        {
            swap(&arr[i],&arr[smallest]);
            heapify(smallest);
        }
    }
     
};



int main()
{
   heap h(10);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout << h.extractMin() << " ";
    cout << h.getMin() << " ";
    h.decreaseKey(2, 1);
    cout << h.getMin();
  
  
   
  return 0;
}