#include <iostream>
#include <vector>

using namespace std;

vector<int> lps_construct(string pattern){
    vector<int> lps(pattern.size(), 0);

    int len = 0;
    lps[0] = 0;

    int i = 1;
    while(i < pattern.size()){
        if(pattern[i] == pattern[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len != 0){
                len = lps[len-1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

int search(string pattern, string txt){
    vector<int> lps = lps_construct(pattern);
    int count = 0;

    int i = 0;
    int j = 0;
    while(i < txt.size()){
        if(txt[i] == pattern[j]){
            i++;
            j++;

            if(j == pattern.size()){
                count++;
                j = lps[j - 1];
            }
        }
        else{
            if(j != 0){
                j = lps[j - 1];
            }
            else{
                i++;
            }
        }
    }
    return count;
}

int main(){
    string txt; cin >> txt;
    string pattern; cin >> pattern;

    int count = search(pattern, txt);
    cout << count;

    return 0;
}
