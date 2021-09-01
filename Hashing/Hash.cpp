https://www.geeksforgeeks.org/c-program-hashing-chaining/

#include<bits/stdc++.h>

using namespace std;



class Hash{
  public:
    vector<vector<int>> v;
    int bucket;
    Hash(int h)
   {
       bucket = h;
       v.resize(bucket);      
   }
    // O(1)
   int computeHash(int x)
   {
       return x%bucket;
   }
    // O(1)  on average and  O(n) in worst
   void insert(int p)
   {
      int i = this->computeHash(p);
      v[i].push_back(p);
   }
   // O(1) on average O(n) in worst
   int search(int p)
   {
       int i = this->computeHash(p);
       for(auto item:v[i])
       {
          if(item==p)
            return 1;
       }
       return 0; 
   }
    // O(1) on average O(n) in worst
   void deleteVal(int p)
   {
      int i = this->computeHash(p);
      vector<int> :: iterator it;
      for(it = v[i].begin();it!=v[i].end();it++)
      {
        if(*it==p) 
        {
            v[i].erase(it);
            break; 
        }   
      }
   }
   void display()
   {
      for(int i=0;i<bucket;i++)
      {
         cout<<endl;
         cout<<i<<" "; 
         for(auto p:v[i])
         {
            cout<<"-->"<<p;
         } 
      }
   }
};


int main()
{
   Hash h(8);
   h.insert(5);
   h.insert(2);
   h.insert(10);
   h.insert(3);
   h.insert(26);
   
   cout<<h.search(26)<<endl;
   cout<<h.search(0)<<endl;
   
   h.display(); 
    cout<<endl;
   h.deleteVal(10);
   h.display(); 
   
   return 0;
}



