# Segment-tree

Segment tree is one of well known advanced strutures used for queries and point updates to an array. Given an array, one can perform two operations both of which take O(logn) time where n is the length of the array. As we shall see, using Lazy segment tree and Persistent segment tree we are able to acomplish a lot more. But let us go through the basics of Segment tree for now.

### Range Query
One can find, for example, the sum, min, or max of a given range ``[l,r]`` where ``1 <= l <= r <= n``. Usually, just by going through all the values, one can find the range query is O(n) time. Even though this might not seem bad, if there involves a lot of queries, this quickly turns out too much for the computer to handle. The Segment tree enables one to execute a range query in O(logn) which is indeed a lot faster.


### Point Update
One can update a definite value of the array. In some languages like C, adopting the unit cost model, updating an array value takes O(1) time. But even though accessing a value and updating it might take constant time, we might need to do a range query again with the new value if the range contains it. This turns out to be O(n) again by the usual way which is inefficient. The segment tree structure allows us to do both range query and update in O(logn) time.


### Internal Structure
We first define nmax to be the maximum size of the array. We then take n (the length of the array) as input and build the segment tree. Building the tree takes O(nlogn) time. But after that, we are able to perform queries and updates in O(logn) time.

The segment tree is a binary tree, where each node represents a given range of the array. 
