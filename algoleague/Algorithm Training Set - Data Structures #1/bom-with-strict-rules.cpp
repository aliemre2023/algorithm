// Josephus Problem
#include <iostream>
using namespace std;
 
// Header files, namespaces to use
// ordered set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
#define ordered_set                              \
    tree<int, null_type, less<int>, rb_tree_tag, \
         tree_order_statistics_node_update>
 
// Function to find the child who
// will get killed in the ith step
void orderOfExecution(int N, int K){
 
    // Create an ordered set
    ordered_set V;
 
    // Push elements in the range
    // [1, N] in the set
    for (int i = 1; i <= N; ++i)
        V.insert(i);
 
    // Stores the position to be removed
    int pos = 0;
 
    // Iterate until the size of the set
    // is greater than 1
    while (V.size() > 1) {
 
        // Update the position
        pos = (pos + K) % (int)V.size();
 
        // Print the removed element
        cout << *(V.find_by_order(pos)) << ' ';
 
        // Erase it from the ordered set
        V.erase(*(V.find_by_order(pos)));
 
        // Update position
        pos %= (int)V.size();
    }
 
    // Print the first element of the set
    cout << *(V.find_by_order(0));
}
 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    //k += 1;
    
    orderOfExecution(n, k);
    
    return 0;
}
