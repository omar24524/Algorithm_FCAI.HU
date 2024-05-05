#include <stdio.h>
#include <stdlib.h>
void wiggleSort(int* nums, int numsSize) {
    for (int i = 0; i < numsSize - 1; i++) {
        if ((i % 2 == 0 && nums[i] >= nums[i + 1]) || (i % 2 != 0 && nums[i] <= nums[i + 1])) {
            int temp = nums[i];
            nums[i] = nums[i + 1];
            nums[i + 1] = temp;
        }
    }
}

void wiggleSortRec(int* nums, int numsSize, int counter) {
    if (counter >= numsSize - 1) return;

    if ((counter % 2 == 0 && nums[counter] >= nums[counter + 1]) || (counter % 2 != 0 && nums[counter] <= nums[counter + 1])) {
        int temp = nums[counter];
        nums[counter] = nums[counter + 1];
        nums[counter + 1] = temp;
    }
    wiggleSortRec(nums, numsSize, counter + 1);
}
int main()
{
    int n;
    printf("Enter the number of elements !\n");
    scanf("%d",&n);
    int arr[n];
    for(int i=0; i<n; i++)
    {
        printf("element num #%d: ",i+1);
        scanf("%d",&arr[i]);
    }
    // selectionSort(arr,n);
    wiggleSort(arr,n);
    // wiggleSortRec(arr,n,0);
    for(int i=0; i<n; i++)
    {
        printf("%d, ",arr[i]);
    }
    return 0;
}
