class Solution {
    void swap(vector<int> &num, int i , int j){
        if (i == j) return;
        
        int tmp = num[i];
        num[i] = num[j];
        num[j] = tmp;
    }
    
    void reverse(vector<int> &num, int start, int end){
        if(start >= end) return;
        
        while(start < end){
            swap(num, start, end);
            start++;
            end--;
        }
    }
    
public:
    void nextPermutation(vector<int> &num) {
        int n = (int)num.size();
        
        if(1 == n) return;
        
        int p = 0, l = 0;
        for(int i = n - 1; i > 0; --i){
            if(num[i] > num[i-1]){
                p = i - 1;
                l = i;
                
                while(num[l] > num[p] && l < n) ++l;
                
                --l;
                swap(num, p, l);
                reverse(num, p+1, n-1);
                return;
            }
        }
        
        reverse(num, 0, n-1);
    }
};
