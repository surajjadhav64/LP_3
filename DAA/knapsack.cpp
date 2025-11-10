#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Items{
    double value;
    double weight;
};

bool cmp(Items &a, Items &b){
    double r1 = a.value/a.weight;
    double r2 = b.value/b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int n, double W, vector<Items> &items){
    sort(items.begin(),items.end(),cmp);
    
    double totalvalue = 0.0;
    for(int i=0;i<n;i++){
        if(items[i].weight <= W){
            W-=items[i].weight;
            totalvalue+=items[i].value;
        }
        else{
            totalvalue += items[i].value * (W/items[i].weight);
            break;
        }
    }
    return totalvalue;
}

int main(){
    int n ;
    cout<<"Enter the number of items:";
    cin>>n;
    
    vector<Items> items(n);
    for(int i=0;i<n;i++){
        cin>>items[i].value>>items[i].weight;
    }
    
    double W;
    cout<<"Enter the capacity:";
    cin>>W;
    
    double maxvalue = fractionalKnapsack(n,W,items);
    cout<<"The maxvalue:"<<maxvalue;
}



// Input:
// Number of items: 3
// Values and Weights:
// Value   Weight
// 60      10
// 100     20
// 120     30
// Capacity: 50

// Step 1: Compute value/weight ratio
// Item	Value	Weight	Ratio (v/w)
// 1	60	      10	  6.0
// 2	100	      20	  5.0
// 3	120	      30	  4.0
// Step 2: Sort by ratio (descending)

// Order = Item1 → Item2 → Item3

// Step 3: Fill the Knapsack

// Capacity = 50

// Step	Item	Weight Taken	Remaining Capacity	Value Added	  Total Value
// 1	1	     10 (full)	        40	             60	              60
// 2	2	     20 (full)	        20	             100	          160
// 3	3	     20/30 (fractional)	 0	        120 * (20/30) = 80	  240

// ✅ Maximum Value = 240