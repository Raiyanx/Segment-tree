# Segment-tree

Segment tree is one of well known advanced strutures used for queries and updates to an array. Given an array, one can perform who operations both of which take O(logn) time where n is the length of the array.

(i) A range query. For example finding the sum of all the elements of a given range ``[l,r]`` where ``1 <= l <= r <= n``. Usually one can find the range query is O(n) time. Even though this might not seem bad, if there involves a lot of queries, this quickly turns out too much for the computer to handle. The Segment tree enables one to execute a range query in O(logn) which is indeed fast.

(ii) Updating an array value. In some languages, updating an array takes O(n) time. In other cases like C, adopting the unit cost model it takes O(1) time. But even though accessing a value and updating it might take constant time, we might need to do a range query again with the new value if the range contains it. This turns out to be O(n) again by the usual way. The segment tree structure allows us to do both range query and update in O(logn) time.
