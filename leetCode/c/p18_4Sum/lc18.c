/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "../../../mylib/mylib.h"

#define COLUMN_SIZE 4

int* sortArray(int *array, int arraySize) {
	
	int temp;

	for(int i=0; i<arraySize-1; i++) {
		for(int j=i+1; j<arraySize; j++) {
			if(array[i] > array[j]) {
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}	

	return array;
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
		
    int currRow = 0;	
    int **answer = allocateMatrixInt(answer, currRow + 1, COLUMN_SIZE);

	nums = sortArray(nums, numsSize);

    for(int i=0; i<numsSize-3; i++) {
		if(i>0 && nums[i] == nums[i-1]) {
			continue;
		}
        for(int j=i+1; j<numsSize-2; j++) {
            for(int k=j+1; k<numsSize-1; k++) {
				for(int l=k+1; l<numsSize; l++) { 
                	if(nums[i] + nums[j] + nums[k] + nums[l] == target) {
		    			if(currRow > 0) 
            				answer = reallocateMatrixInt(answer, currRow + 1, COLUMN_SIZE);	
		    			answer[currRow][0] = nums[i];
                	    answer[currRow][1] = nums[j];
                	    answer[currRow][2] = nums[k];
						answer[currRow][3] = nums[l];
                	    currRow++;
                	}                
				}
            } 
        }
    }

    *returnSize = currRow - 1;
    
    return answer; 
}

int main(void) {

	// Test

	int nums[6] = {1,0,-1,0,-2,2};
	//int nums[5] = {2, 2, 2, 2, 2};
	int numsSize = sizeof(nums)/sizeof(int);
	int solRowSize = 3;
	//int solRowSize = 1;
	int target = 0;
	//int target = 8;
	int* returnSize;
	int** returnColumnSize;
	
	int** solution = allocateMatrixInt(solution, solRowSize, COLUMN_SIZE);

	solution = fourSum(nums, numsSize, target, returnSize, returnColumnSize);

	printMatrixInt(solution, solRowSize, COLUMN_SIZE);

	freeAllocatedMatrixInt(solution, solRowSize);
	
	return EXIT_SUCCESS;
}