#include<bits/stdc++.h>
using namespace std;

class DSU {
    
public:    
    vector<int> parents;
    vector<int> size;
    
    int findParent(int i) {
        if(i==parents[i]) return i;
        return parents[i] = findParent(parents[i]);
    }
    
    void merge(int a,int b) {
        int p1 = findParent(a);
        int p2 = findParent(b);
        
        if(p1!=p2) {
            if(size[p1]>size[p2]) {
                parents[p2] = p1;
                size[p1] += size[p2];
            } else {
                parents[p1] = p2;
                size[p2] += size[p1];
            }
        }
    }
    
    DSU(int n) {
        parents.resize(n);
        size.resize(n);
        for(int i=0;i<n;i++) parents[i] = i;
        for(int i=0;i<n;i++) size[i] = 1;
    }
    
};
