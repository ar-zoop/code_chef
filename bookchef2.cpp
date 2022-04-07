#include<bits/stdc++.h>
#include <stdlib.h>
using namespace std;
struct  node
{
  int ind;
  int pri;
  string post;
  
};
//bool com(node a,node b)
//{
//    //????????????????
//  return a.pri>b.pri;
//}
int compare (const void * a, const void * b)
{

  node *orderA = (node *)a;
  node *orderB = (node *)b;

  return ( orderA->pri - orderB->pri );
}
node a[100000];
int main()
{
  int n,m;
  cin>>n>>m;
  int d[100000];
  int pos,pi;
  string s;
  for(int i=0;i<n;i++)
  {
      cin>>pos;             //taking id of special friends
      d[pos]=1;
  }
  for(int i=0;i<m;i++)
  {
 
      cin>>a[i].ind>>a[i].pri;
      cin>>a[i].post;
  }
qsort (a, m, sizeof(node), compare);
for (int i=0;i<m;i++)
	printf("%d ",a[i].pri);
for(int i=0;i<m;i++)
{
   if(d[a[i].ind])
   {
      cout<<a[i].post<<endl;                //print special id
   }
}
for(int i=0;i<m;i++)
{
    if(!d[a[i].ind])
    {
      cout<<a[i].post<<endl;              //print non-special id
    }
}
    return 0;
}
