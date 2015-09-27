#include <stdio.h>

static int MergeCount(int *arr, int start, int end){
  int acc = 0;
  if (end - start <= 1) return acc;
  int mid = (start + end)/2;
  int leftCount = MergeCount(arr, start, mid);
  int rightCount = MergeCount(arr, mid, end);
  if (mid < end && mid >= 1){
      if (arr[mid -1] > arr[mid]){
        acc++;
        int compare = arr[mid -1];
        for(int i = mid + 1; i < end; i++){
          if (compare > arr[mid]){
            acc++;
          }
        }
    }
  }
  return acc + leftCount + rightCount; 
}

int main(){
  int A[] = {1, 2, 5, 3, 4};
  printf("MergeCount: %d\n", MergeCount(A, 0, 1));
}
