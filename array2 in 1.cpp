#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<double> nums_sum;
    int size = nums1.size()+nums2.size();
    nums1.push_back(1e9);
    nums2.push_back(1e9);
    int p=0;
    int q=0;
    for(int i=1;i<=size;i++){
        if(nums1[p]<=nums2[q]){
            nums_sum.push_back(nums1[p]);
            if(p<(int)nums1.size()){
				p++;
			}
        }
        else{
            nums_sum.push_back(nums2[q]);
            if(q<(int)nums2.size()){
				q++;
			}
        }
    }

    for (int i = 0; i < size; i++)
    {
        cout << nums_sum[i] <<'\n';
    }
    

    if(size%2!=0){
        return nums_sum[size/2];
    }
    else{
        return (nums_sum[size/2]+nums_sum[size/2-1])/2.0;
    }
}

int main(){
    vector<int>nums1={1,3,7,9,108};
    vector<int>nums2={2,4,5,11};
    cout << findMedianSortedArrays(nums1,nums2);
}

