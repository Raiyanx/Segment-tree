#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define FASTio ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

struct node{
    ll val;
    node* lc, rc;
};

node* build(int l, int r){
    if(l==r){
        node* me = new node();
        me->val= arr[l];
        me->lc=NULL;
        me->rc=NULL;
        return me;
    }

    node* me = new node();

    int mid=(l+r)/2;

    me->lc = build(l,mid);
    me->rc = build(mid+1,r);

    me->val=me->lc->val + me->rc->val;

    return me;
}

int main()
{
    FASTio
    
}

