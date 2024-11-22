/*
 El Primos: 
 Ferhat Kunduracı (SchumacherFarad, ferhatkundurac), 
 Umut Özil (umut373), 
 Ali Emre Kaya (aliemre2023)
*/

#include <bits/stdc++.h>
#include <vector>
#include <math.h>

using namespace std;
#define int long long
int32_t main(){
    vector<int> ns(1000);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        ns[temp-1]++;
    }
    double sum = 0.0;
    for (int i = 0; i < 1000; i++)
    {
        sum += ns[i]*pow(2, -(i+1));
        if(sum >1.0){
            cout << "NO";
            return 0;
        }
    }
    cout<< "YES";
    return 0;
}