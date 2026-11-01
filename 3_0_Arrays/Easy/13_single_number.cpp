/*

Brute Force:->
for(int i=0;i<n;i++){
    int num=arr[i];
    int cnt=0;
    for(int j=0;j<n;j++){
        if(arr[j]==num){
            cnt++;
        }
    }
    if(cnt==1) return num;
}

Better:->
class Solution {
public:
    int singleNumber(vector<int>& arr) {
        int n = arr.size();

        ---- int maxi = arr[0];
        for(int i=0;i<n;i++){
            if(arr[i]>maxi){
                maxi = arr[i];
            }
        } ---- only if u use hash array

        map<int,int> mpp;

        for(int i=0;i<n;i++){
            mpp[arr[i]]++;
        }

        for(int i=0;i<n;i++){
            if(mpp[arr[i]]==1){
                return arr[i];
            }
        }

        ---- for(auto it:mpp){
            if(it.second==1){
                return it.first;
            }
        } ---- if mpp is used

        return -1;
    }
};

Optimal:->
using XOR operators

*/