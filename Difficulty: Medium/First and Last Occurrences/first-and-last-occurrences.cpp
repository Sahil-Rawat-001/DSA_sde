//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   
   int firstOcc(vector<int>& arr, int x){
       
        int l = 0;
        int h = arr.size() - 1;
        int ans = -1;
        
        while(l <= h){
            
            int m = l + (h-l) / 2;
            
            if(arr[m] == x){
                
              ans = m;
              h = m - 1;
            } else if (arr[m] < x){
              l = m + 1;
            } else{
              h = m - 1;
            }
        }
        
        return ans;
   }
    
    vector<int> find(vector<int>& arr, int x) {
        // code here
        
        int l = 0;
        int h = arr.size() - 1;
        int index2 = -1;
        
        while(l <= h){
            
            int m = l + (h-l) / 2;
            
            if(arr[m] == x){
                
              index2 = m;
              l = m + 1;
            } else if (arr[m] > x){
              h = m - 1;
            } else{
              l = m + 1;
            }
        }
        
        int index1 = firstOcc(arr,x);
        
        return {index1,index2};
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int x;
        cin >> x;
        cin.ignore();
        vector<int> ans;
        Solution ob;
        ans = ob.find(arr, x);
        cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends