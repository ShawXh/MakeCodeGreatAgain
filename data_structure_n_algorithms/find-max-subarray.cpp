#include <cstring>
#include <iostream>
#include <stdlib.h>

using namespace std;

int array[10] = {3,4,6,-3,2,1,-3,-4,2,3};
                     //0,1,2, 3,4,5, 6, 7,8,9.

int * find_max_crossing_subarray( int *a, int left, int right){
	int mid;
	mid = (left + right)/2;
	//cout << "mid= "<< mid << endl;
	int left_sum,sum,right_sum;
	int left_edge,right_edge;
	sum = 0;
	left_sum = -1000;
	for(int i=mid; i>=left; i--){
		sum += a[i];
		if(sum>left_sum){
			left_sum = sum;
			left_edge = i;
		}
	}
	//cout << "left-sum= " << left_sum <<endl;
	sum = 0;
	right_sum = -1000;
	for(int i=mid+1; i<=right; i++){
		sum += a[i];
		if(sum>right_sum){
			right_sum = sum;
			right_edge = i;
		}
	}
	//cout << "right-sum= " << right_sum << endl;
	int * ret = new int[3];
	ret[0] = left_edge;
	ret[1] = right_edge;
	ret[2] = left_sum + right_sum;
	
	return ret;
};

int * find_max_subarray( int *a,int left, int right){
	int mid;
	mid = (left + right)/2;
	if (left == right){
		int * ret = new int[3];
		ret[0] = left;
		ret[1] = right;
		ret[2] = a[left];
		return ret;
	}
	else{
		int * left_ret = new int[3];
		int * right_ret = new int[3];
		int * crossing_ret = new int[3];
		left_ret = find_max_subarray(a,left, mid);
		right_ret = find_max_subarray(a, mid+1, right);
		crossing_ret = find_max_crossing_subarray(a, left, right);
	//	cout << "crossing ret: "<< crossing_ret << endl;
		if (left_ret[2] > right_ret[2] &&
			left_ret[2] > crossing_ret[2]){
			return left_ret;
		}
		else if (right_ret[2] > left_ret[2] &&
			right_ret[2] > crossing_ret[2]){
			return right_ret;
		}
		else {
			return crossing_ret;
		}
	}
};


int main(){
	int *aws;
	aws = find_max_crossing_subarray(array,0,1);
	cout << aws[0]<<endl<< aws[1]<<endl << aws[2] << endl;


	int *awss;
	awss = find_max_subarray(array,0,9);
	cout << awss[0]<<endl<< awss[1]<<endl << awss[2] << endl;


	return 0;
}
