#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'getSmallestString' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER k
 */

string getSmallestString(string s, int k) {
    string returned;
    int numchar = s[0] - 'a';
    for(int i  =0; i < s.size(); i++){
        numchar = s[i] - 'a';
        if(numchar < 13){
            if(k - numchar > 0){
                returned +='a';
                
                k = k - numchar;
                
            }
            else{
                int dist =  numchar - k;
                k = 0;
                returned += (dist + 'a');    
            }
            
        }
        else{
            if(k - (26 - numchar) >= 0){
                returned +='a';
                
                k = k - (26 - numchar);
                
            }
            else{
                int dist =  numchar - k;
                k = 0;
                returned += (dist + 'a');    
            }
        }
        
        
    }
    
    
    return returned;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    string result = getSmallestString(s, k);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
