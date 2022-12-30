1.) K-th element of two sorted Arrays


--> Given two sorted arrays arr1 and arr2 of size N and M respectively and an element K. 
--> The task is to find the element that would be at the k’th position of the final sorted array.
  
  
arr1[] = {2, 3, 6, 7, 9}
arr2[] = {1, 4, 8, 10}
k = 5
Output:
6
  
  
  
Naive Approach:


Important resource:   https://www.youtube.com/watch?v=nv7F4PiLUzo

TC = O(N) and SC = O(1)
  
--> Keep two pointers and while comparing and traversing keep a count variable and when count reaches K, return the value



  
