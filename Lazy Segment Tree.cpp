#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define FASTio ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const int nmax = ; /// The max value of the size of the array
long long tree[4*nmax];  /// The segment tree array
long long lazy[4*nmax];  /// Stores the value of the lazy
ll x[nmax]; /// The original array

void build(int id, int l, int r) /// Builds the segment tree
{
    lazy[id] = flag;
    /// We're doing this because there can be multiple test cases
    /// Set the value of the flag which represents there is no lazy
    /// or some value that doesn't affect. e.g. 0 for the sum problem
    if(l==r)
    {
        tree[id]=x[l];
        return;
    }

    int mid=(l+r)/2;
    build(2*id,l,mid);
    build((2*id)+1, mid+1 , r);

    tree[id]= op( tree[2*id] , tree[(2*id)+1] ) ; /// op =  operator

    return;
}
void propagate(int id, int l, int r) /// This will send the lazy to the two childs
{
    tree[id] += p( (r-l+1) , lazy[id] ) ;
    /// Here r-l+1 is the range length and the function p represents
    /// how the lazy will be added to the tree
    if(l != r)   /// This means that the node isn't a leaf
    {
    lazy[2*id] +///= lazy[id];
    lazy[2*id +1] +///= lazy[id];  ///Often these are additions but be careful
    }
    lazy[id] = flag;
}
ll query(int id, int l , int r , int a, int b)  ///Finds something for example the sum
{
    propagate(id, l, r);
    if(b<l || r<a )
    {
        return identity; /// identity i.e. the element such that op( a , identity ) = a
    }
    if(a<=l && r<=b)
    {
        return tree[id];
    }

    int mid=(l+r)/2;
    ll p = query((2*id),l,mid,a,b) ;
    ll q = query((2*id)+1,mid+1,r,a,b);
    return op ( p , q ); /// Op = operator
}
void update(int id, int l, int r, int a, int b, ll k)
{
    propagate(id, l , r);

    if(b<l || r<a )
    {
        return;
    }
    if(a<=l && r<=b)
    {
        lazy[id] ///+= k;  /// usually this for sums
        propagate(id, l , r);
        return;
    }

    int mid = (l+r)/2 ;
    update(2*id , l , mid, a , b , k);
    update(2*id +1 , mid+1 , r , a , b , k);

    tree[id] = op( tree[2*id] , tree[2*id +1] );
    return;
}

int main()
{
    FASTio
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n,q;
        cin>>n>>q;
        build(1,1,n);
        while(q--)
        {
           int type;
           cin>>type;
           if(type==0)
           {
               int p,q,v;
               cin>>p>>q>>v;
               update(1,1,n,p,q,v); /// Updates the range [p,q] using value v
           }
           else
           {
               int p,q;
               cin>>p>>q;
               cout<< query(1,1,n,p,q)<<"\n";  /// queries the range [p,q]
           }
        }
    }
}

