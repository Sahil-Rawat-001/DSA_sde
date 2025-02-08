//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    // this function let us know that if we can place this no. of cows
    bool canWePlace(vector<int> &stalls, int dist, int cows){
        
        int countCows = 1;
        
        int last = stalls[0];
        
        for(int i = 1; i < stalls.size(); i++){
            
            if( stalls[i] - last >= dist ){
                
                countCows++;
                last  = stalls[i];
            }
            
            if(countCows >= cows) return true;
        }
        return false;
    }

    int aggressiveCows(vector<int> &stalls, int k) {
        
        
        // sort
        sort(stalls.begin(),stalls.end());
        
        // the size of array
        int n = stalls.size();
        
        // defining range of our possible answers 
        int l = 1;
        int h = stalls[n-1] - stalls[0];
        
        
        // binary search
        while(l <= h){
            
            int m = l + (h-l) / 2;
            
            if( canWePlace(stalls, m, k) ){
                
                l = m + 1;
            } else {
                h = m - 1;
            }
        }
        
        return h;
        
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends