class Solution {
public:
    
  int mergeSort(vector<int> &arr, int array_size)
{
      vector<int> temp(array_size);
	return _mergeSort(arr,temp, 0, array_size - 1);
}
int _mergeSort(vector<int> &arr, vector<int> &temp, int left, int right)
{
	int mid, count = 0;
	if (right > left) {

		mid = (right + left) / 2;
		count += _mergeSort(arr,temp, left, mid);
		count += _mergeSort(arr,temp, mid+1 , right);
        //merging time
		count += merge( arr,temp, left, mid , right);
	}
	return count;
}
  int merge(vector<int> &arr,vector<int> &temp, int left, int mid,
		int right)
{
	int i, j, k;
	int count = 0;
	i = left;
	j = mid+1; 
	k = left;
      
      while(i<=mid){
          while(j<=right && arr[i] > 2LL*temp[j])
              j++;
          count+=(j-mid-1); 
          i++;
          
      }
    i=left,j=mid+1;
	while ((i <= mid) && (j <= right)) {
		if (arr[i] <= arr[j]) {
			temp[k++] = arr[i++];
		}
		else {
			temp[k++] = arr[j++];
		}
	}

	while (i <= mid)
		temp[k++] = arr[i++];
	while (j <= right)
		temp[k++] = arr[j++];
	// for (i = left; i <= right; i++)
	// 	arr[i] = temp[i];
  
	return count;
}  
    
    
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, nums.size());
    }
};