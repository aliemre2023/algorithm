#include <bits/stdc++.h>

using namespace std;



/*
 * Complete the 'dnaComplement' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */
 
string reverseString(string s){
    string reversed_s(s.size(), ' ');
    for(int i = 0; i < s.size(); i++){
        reversed_s[s.size()-1-i] = s[i];
    }
    
    return reversed_s;
}

string replaceString(string s){
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'A') s[i] = 'T';
        else if(s[i] == 'T') s[i] = 'A';
        else if(s[i] == 'G') s[i] = 'C';
        else if(s[i] == 'C') s[i] = 'G';
        else cout << "Error: Undetermined char!";
    }
    return s;
}

string dnaComplement(string s) {
    string reversed_s = reverseString(s);
    string replaced_s = replaceString(reversed_s);
    
    return replaced_s;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = dnaComplement(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
