#include<iostream>
#include<vector>
using namespace std;

vector<int> new_vector_int(int length, int data){
    int *tmp = new int [length];
    for (int i=0; i<length; i++) tmp[i] = data;
    vector<int> tmpvec(tmp, tmp+length);
    return tmpvec;
}

void mergesort(vector<int>& nums, vector<int>& index, int lb, int rb) {
    if (lb == rb) return;
    if (rb - 1 == lb){
         if (nums[lb] > nums[rb]) {
              swap(nums[lb], nums[rb]);
              swap(index[lb], index[rb]);
         }
         return;
    }
    
    int m = (lb + rb) / 2;
    mergesort(nums, index, lb, m);
    mergesort(nums, index, m+1, rb);

    int i=lb, j=m+1;
    vector<int> tmp = new_vector_int(rb-lb+1, 0);
    vector<int> idxtmp = new_vector_int(rb-lb+1, 0);
    int k=0;
    for (int k=0; k<rb-lb+1; k++){
        if (i==m+1 && j!=rb+1) {
            tmp[k] = nums[j];
            idxtmp[k] = index[j];
            j++;
        }
        else if (j==rb+1 && i!=m+1) {
            tmp[k] = nums[i];
            idxtmp[k] = index[i];
            i++;
        }
        else if (nums[i]<nums[j]){
            tmp[k] = nums[i];
            idxtmp[k] = index[i];
            i++;
        }
        else{
            tmp[k] = nums[j];
            idxtmp[k] = index[j];
            j++;
        }
    }
    for (int i=0; i<rb-lb+1; i++){
        nums[lb+i] = tmp[i];
        index[lb+i] = idxtmp[i];
    }
}

void swap(int & n1, int & n2){
    int tmp = n1;
    n1 = n2;
    n2 = tmp;
}

void print_vector(vector<int> vec){
    for (int i=0; i<vec.size(); i++) printf("%d ", vec[i]);
    printf("\n");
}

int main(){
    int n1=1, n2=2;

    int numsint[] = {5,4,8,1,9,3,2};
    vector<int> nums(numsint, numsint+7);
    int indexint[] = {0,1,2,3,4,5,6};
    vector<int> index(indexint, indexint+7);

    mergesort(nums, index, 0, 6);
    print_vector(nums);
    print_vector(index);

    return 0;
}
