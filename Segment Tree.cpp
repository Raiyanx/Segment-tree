#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
#define FASTio ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

const int nmax=2e5+10;
int n;
int x[maxn];

struct node {
    ll total;
} tree[maxn * 4];

void merge(node &cur, node l, node r) {
  cur.total = l.total + r.total;
}

void build(int id=1, int l=1, int r=n) {
    if(l==r){
        tree[id]=x[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);

    merge(tree[id], tree[l], tree[r]);
}

void update(int x, int id = 1, int l = 1, int r = n) {
    if(l==r){
        tree[id]=x;
        return;
    }

    int mid=(l+r)/2;
    if(k<=mid) update(x,2*id,l,mid);
    else update(x,2*id,l,mid);

    merge(tree[id], tree[l], tree[r]);
}

node query(int a, int b, int id = 1, int l = 1, int r = n) {
    if(b<l || r<a) return identity;
    if(a<=l && r<=b) return tree[id];

    int mid=(l+r)/2;
    node p=query(a,b,2*id,l,mid);
    node q=query(a,b,2*id+1,mid+1,r);
    node res;
    merge(res,p,q);
    return res;
}

int main()
{
    FASTio

    

    return 0;    
}