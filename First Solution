def selection_sort(nums):
    for i in range(len(nums)):
        # Find the minimum element in the remaining unsorted array
        min_idx = i
        for j in range(i+1, len(nums)):
            if nums[j] < nums[min_idx]:
                min_idx = j
        # Swap the found minimum element with the first element
        nums[i], nums[min_idx] = nums[min_idx], nums[i]

def wiggle_sort(nums):
    # Step 1: Sort the array using selection sort
    selection_sort(nums)
    
    # Step 2: Find the middle index
    mid = len(nums) // 2 if len(nums) % 2 == 0 else len(nums) // 2 + 1
    
    # Step 3: Reverse the first half and the second half
    first_half = nums[:mid][::-1]
    second_half = nums[mid:][::-1]
    
    # Step 4: Merge the two halves element by element
    nums[::2], nums[1::2] = first_half, second_half

# Example usage:
nums1 = [1, 5, 1, 1, 6, 4]
wiggle_sort(nums1)
print("Example 1 Output:", nums1)  

nums2 = [9,1, 3, 2, 2, 3, 1,9 ,7]
wiggle_sort(nums2)
print("Example 2 Output:", nums2)  
