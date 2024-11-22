/*
 El Primos: 
 Ferhat Kunduracı (SchumacherFarad, ferhatkundurac), 
 Umut Özil (umut373), 
 Ali Emre Kaya (aliemre2023)
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> findThreeElementSums(int n) {
    vector<int> triplets;
    for (int i = 1; i*i <= n; ++i) {
        if (n % i == 0) {
            for (int j = i; j*j <= n/i; ++j) {
                if (n % j == 0) {
                    int k = n / (i * j);
                    if (k >= j && (i * j * k) == n) {
                        triplets.push_back(i+j+k);
                    }
                }
            }
        }
    }

    return triplets;
}

void checkduplicates(vector<int> triplets){
    sort(triplets.begin(),triplets.end());
    int size = triplets.size();
    for(int i = 1; i < size; i++){
        if(triplets[i] == triplets[i-1]){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    return;
}
int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    
    int q;
    int n;
    cin >> q;
    for(int i=0; i<q; i++){
        cin >> n;
        checkduplicates(findThreeElementSums(n));
    }
	return 0;
}
