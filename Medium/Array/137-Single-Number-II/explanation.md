# Single Number II

**Difficulty:** Medium | **Language:** python

# Solution: Single Number II

## Approach Summary
The provided solution uses a frequency counting approach, leveraging a hash map (dictionary) to track how many times each integer appears in the input array. By iterating through the array once to populate the dictionary and then scanning the dictionary for the entry with a count of one, we can reliably identify the unique element. While this approach is intuitive and efficient for general counting problems, it uses linear extra space to store the frequency map.

## Step-by-Step Explanation

1.  **Initialize a dictionary:** We create an empty dictionary called `freq` to serve as our record-keeper. The dictionary will store the number from the array as the "key" and its corresponding appearance count as the "value."
2.  **Count the occurrences:** We loop through each number in the input list `nums`. For every number encountered:
    *   If the number is already in the dictionary, we increment its current count by 1.
    *   If the number is not in the dictionary, we add it with an initial count of 1.
3.  **Identify the unique number:** After the entire list has been processed, the dictionary contains the counts for every distinct number. We then iterate through the dictionary's key-value pairs. Since the problem guarantees that one element appears exactly once while others appear three times, we simply look for the key that has a value of 1.
4.  **Return the result:** Once the value `1` is found, we return the associated key as our answer.

## Complexity Analysis

*   **Time Complexity:** O(N), where N is the number of elements in the array. We perform one pass over the array to build the frequency map and one pass over the map to find the unique element. In the worst case, the number of unique elements is proportional to N.
*   **Space Complexity:** O(N). Because we store each unique element in the dictionary, the space requirement grows linearly with the number of unique elements in the input array.

*Note: While this solution satisfies the functional requirements, the problem constraints often aim for an O(1) space solution using bitwise manipulation (tracking bits that appear once vs. twice). This dictionary-based approach uses linear space.*
