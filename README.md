# Next Permutation

Tag： leetcode

---
**Problem Statement**
>Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers. 

>If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order). 

>The replacement must be in-place, do not allocate extra memory. 

>Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1



The hard point of this problem is the definition of next permutation. The description of how to generate next permutatio itself is an algorithm to solve this problem.

From *wikipedia*, there's a simple algorithm. But we need to give some remarks to analyze it.
>1. Find the largest index $k$ such that $a[k] < a[k + 1]$. If no such index exists, the permutation is the last permutation.
2. Find the largest index $l$ greater than $k$ such that $a[k] < a[l]$.
3. Swap the value of $a[k]$ with that of $a[l]$.
4. Reverse the sequence from $a[k + 1]$ up to and including the final element $a[n]$.

The reason why we search from right to left, because that's the first place to decrease the value of permutation.

If we get to the beginning, that means what we deal is the minimum permutation. 

Otherwise, if we get the largest $k$ such that $a[k] < a[k+1]$, that means:
> - $a[k+1]$ to $a[n]$ is in decreasing order
- $a[k]$ is also one element in the **range** *from* $a[n]$ *to* $a[k]$.

These mean we've get the last permutation when we fix {$a[1], a[2], ..., a[k]$}.

So the next permutation should begin with {$a[1], a[2], ..., a[k-1], a[k']$}, where $a[k']$ is the next larger element than $a[k]$.
After that, we start our permutation from $$a[1], a[2], ..., a[k-1], a[k'], a[k+2], ..., a[n]$$, where $$a[1], a[2], ..., a[k-1], a[k']$$ is in increasing order.

So, in order to get the next permutation, first we need to find the next larger element than $a[k]$. The method we use is **step 2**:
> Find the largest index $l$ greater than $k$ such that $a[k] < a[l]$.

Then, we need to swap the two elements $a[k]$ and $a[l]$. Now:
> 1. the next permutation's begining part {$a[1], a[2], ..., a[k]$} has been reached right places.

> 2. the new $a[l]$ is just less than $a[l-1]$ and greater than $a[l+1]$. So, {$a[k+1], ..., a[n]$} is in decreasing order.

So, the last step, we need to reverse the remaining parts, {$a[k+1], ..., a[n]$}, to get the right next permutation.

---

The complete code is [here](permutation_sequence.cpp)
