// Fractional Knapsack
void knapsack(int n, float weight[], float profit[], float capacity) {
    float ratio[n], tp=0;
    
    // Calculate profit/weight ratio
    // Sort items by ratio (descending)
    
    for(int i=0; i<n; i++) {
        if(weight[i] > capacity) break;
        else {
            tp += profit[i];
            capacity -= weight[i];
        }
    }
    // Add fractional part if remaining capacity
}
// Greedy: Sorting followed by optimal local choices
