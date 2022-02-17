# Segment-tree

Segment tree is one of well known advanced strutures used for queries and point updates to an array. Given an array, one can perform two operations both of which take O(logn) time where n is the length of the array. Using Segment tree and Lazy segment tree we are able to acomplish a lot.

### Range Query
One can find, for example, the sum, min, or max of a given range ``[l,r]`` where ``1 <= l <= r <= n``. Usually, just by going through all the values, one can find the range query in O(n) time. Even though this might not seem bad, if there involves a lot of queries, this quickly turns out too much for the computer to handle. The Segment tree enables one to execute a range query in O(logn) which is indeed a lot faster.


### Point Update
One can update a definite value of the array. In some languages like C, adopting the unit cost model, updating an array value takes O(1) time. But even though accessing a value and updating it might take constant time, we might need to do a range query again with the new value if the range contains it. This turns out to be O(n) again by the usual way which is inefficient. The segment tree structure allows us to do both range query and update in O(logn) time.


### Internal Structure
We first define nmax to be the maximum size of the array. We then take n (the length of the array) as input and build the segment tree. Building the tree takes O(nlogn) time. But after that, we are able to perform queries and updates in O(logn) time.

The segment tree is a binary tree, where each node represents a given range of the array. The root node, for example represents the whole array. The leaves of the tree represent the single element ranges of the array. And for any given node, its two children represent left and right halves of that range. The height of the tree turns out to be O(logn).


### Working Mechanism
Segment tree is useful for types of problems where we are able to merge two ranges. For example, if we know the sum of ranges ``[l,x]`` and ``[x+1,r]``, then we can know the sum of the range of ``[l,r]`` easily. This also works with gcd, minimum and maximum related problems. And the way segment tree implements this is by first setting the leaves of the tree equal to the elements of the array, and then recursively work upwards to the root by merging two children of a node and storing it in that node. The whole tree is kept in an array tree[] of "nodes" itself. A node is basically a struct which contains information of the range it represents. 

For point updates, we walk down on the tree to the leaf representing that point and after updating it, recursively update each node above it upto the root. Since the height of the tree is O(logn), this takes O(logn) time.

For range queries, we find the result recursively. Let us assume that we need to find a query on the range ``[l,r]``. We call the query function on the root. Then, whenever we find a node describing the range ``[l1,r1]``, if it is inside ``[l,r]``, we take the value in the node instead of going downwards. If it is outside, we return the identity value. Otherwise, we divide ``[l1,r1]`` into two by calling the function on the children and then recursively compute it. This working mechanism turns out to be O(logn). 


## Lazy Segment Tree
A regular segment tree allows us to perform range queries and point updates. But what if we want to perform range updates? If the range is of size m, then it would take O(mlogn) time to update all of them using just regular segment tree. This turns out to be very bad when we are dealing with a lot of queries. 

Turns out, we are able to perform range updates too in O(logn) time. And the way to do it would be lazy segment tree. In a lazy segment tree, it performs the range update "lazily". Each node in the array tree[] now has a corresponding entry in the array lazy[]. And whenever we perform a range update, say we want to update a range ``[l,r]`` which has a corresponding single node with index n. Then instead of trying to update the nodes under that node, we rather store the lazy value in ``lazy[n]``. And if it isnt a single node, we can divide and work recursively. This allows us to perform the range update and also the range query in O(logn) time. 





