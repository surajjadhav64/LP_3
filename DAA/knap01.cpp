#include<bits/stdc++.h>
using namespace std;

int knapsack(int n, int W, vector<int> &val, vector<int> &wt){
    vector<vector<int>> dp(n+1,vector<int>(W+1,0));
    
    for(int i=0;i<=n;i++){
        for(int w=0;w<=W;w++){
            if(i==0 || w==0){
                dp[i][w]=0;
            }
            else if(wt[i-1]<=w){
                dp[i][w]=max(val[i-1]+dp[i-1][w-wt[i-1]],dp[i-1][w]);
            }
            else{
                dp[i][w]=dp[i-1][w];
            }
        }
    }
    return dp[n][W];
}

int main(){
    int n;
    cout<<"Enter the number of items:";
    cin>>n;
    
    vector<int> val(n),wt(n);
    for(int i=0;i<n;i++){
        cin>>val[i]>>wt[i];
    }
    
    int W;
    cout<<"Enter the capacity:";
    cin>>W;
    
    int maxvalue = knapsack(n,W,val,wt);
    cout<<"The maxvalue:"<<maxvalue;
}



// Enter the number of items: 3
// Values and Weights:
// 60 10
// 100 20
// 120 30
// Enter the capacity: 50
// STEP-BY-STEP WORKING (Dry Run)

// | Item | Value | Weight |
// |------|--------|---------|
// | 1 | 60  | 10 |
// | 2 | 100 | 20 |
// | 3 | 120 | 30 |

// | Capacity | | **50** 

// We compute row by row (each row = including items up to i):

// | i | w (capacity) | Decision | dp[i][w] |
// |---|--------------|----------|-----------|
// | 0 | any          | No items | 0 |
// | 1 | 10           | fits     | 60 |
// | 2 | 20           | fits     | 100 |
// | 2 | 30           | both 1 & 2 fit → max(160,100) | 160 |
// | 3 | 50           | try (1,2,3) → best combo (2+3) | 220 |

// ✅ So the **maximum value = 220**

// Combination:
// - Item 2 (100, weight 20)
// - Item 3 (120, weight 30)

// Total weight = 20 + 30 = 50  
// Total value = 100 + 120 = **220**