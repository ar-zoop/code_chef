#include <bits/stdc++.h>
using  namespace std;
 
class disjointSet{
    vector <int> parent, rank, size;
    public:
    disjointSet(int V){
        parent.resize(V+1);
        rank.resize(V+1, 0);
        for(int i=0; i<V+1; i++){
            parent[i]=i;
        }
        size.resize(V+1, 1);
    }
    int getParent(int u){
        if(parent[u]==u) return u;
        return parent[u] = getParent(parent[u]);
    }

    void unionByRank(int u, int v){
        int upu, upv;
        upu=getParent(u);
        upv=getParent(v);
        if(upu==upv){ cout<<"Cycle detected"; return;}
        if(rank[upu]>rank[upv]){
            parent[upv]=upu;
        }
        else if (rank[upv] > rank[upu])
        {
            parent[upu] = upv;
        }
        else{
            parent[upu] = upv;
            rank[upv]++;
        }
    }

    void unionBySize(int u, int v){
        int upu, upv;
        upu = getParent(u);
        upv = getParent(v);
        if (upu == upv)
        {
            cout << "Cycle detected";
            return;
        }
        if (size[upu] > size[upv])
        {
            parent[upv] = upu;
            size[upu]+=size[upv];
        }
        else if (size[upv] > size[upu])
        {
            parent[upu] = upv;
            size[upv]+=size[upu];
        }
        else
        {
            parent[upu] = upv;
            size[upv]+=size[upv];
        }
    }
};

void unionByRankCall(){
    disjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);
    // if 3 and 7 are in the same set
    if (ds.getParent(3) == ds.getParent(7))
        cout << "Same set" << endl;
    else
    {
        cout << "Different set" << endl;
    }
    ds.unionByRank(3, 7);
    // if 3 and 7 are in the same set
    if (ds.getParent(3) == ds.getParent(7))
        cout << "Same set"<<endl;
    else
    {
        cout << "Different set"<<endl;
    }
} 

void unionBySizeCall(){
    disjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    // if 3 and 7 are in the same set
    if (ds.getParent(3) == ds.getParent(7))
        cout << "Same set" << endl;
    else
    {
        cout << "Different set" << endl;
    }
    ds.unionBySize(3, 7);
    // if 3 and 7 are in the same set
    if (ds.getParent(3) == ds.getParent(7))
        cout << "Same set" << endl;
    else
    {
        cout << "Different set" << endl;
    }
}

int main(){
    unionBySizeCall();
}