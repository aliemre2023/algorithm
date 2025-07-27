#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'pointsBelong' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER x1
 *  2. INTEGER y1
 *  3. INTEGER x2
 *  4. INTEGER y2
 *  5. INTEGER x3
 *  6. INTEGER y3
 *  7. INTEGER xp
 *  8. INTEGER yp
 *  9. INTEGER xq
 *  10. INTEGER yq
 */
bool isTriangle(int x1, int y1, int x2, int y2, int x3, int y3){
    bool is_tri = true;
    
    double slope1 = (double)(y2 - y1) / (x2 - x1);
    double slope2 = (double)(y3 - y2) / (x3 - x2);
    double slope3 = (double)(y3 - y1) / (x3 - x1);
    
    if(slope1 == slope2 || slope3 == slope2 || slope1 == slope3) is_tri = false;
    
    return is_tri;   
}

double findArea(int x1, int y1, int x2, int y2, int x3, int y3){
    double area = ((double)1/2) * abs(x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2));
    return area;
}

bool isBelong(int x, int y, int x1, int y1, int x2, int y2, int x3, int y3){
    // total_area = area1 + area2 + area3
    
    double total_area = findArea(x1, y1, x2, y2, x3, y3);
    double area1 = findArea(x, y, x2, y2, x3, y3);
    double area2 = findArea(x, y, x1, y1, x3, y3);
    double area3 = findArea(x, y, x2, y2, x1, y1);
    
    if(total_area == area1 + area2 + area3) return true;
    return false; 
}

int pointsBelong(int x1, int y1, int x2, int y2, int x3, int y3, int xp, int yp, int xq, int yq) {
    cout << x1 << " " <<  y1 << " " <<  x2 << " " <<y2 << " " << x3 << " " << y3 << "\n";
    cout << xp << " - " << yp << "\n";
    cout << xq << " - " << yq << "\n";
    
    bool is_tri = isTriangle(x1, y1, x2, y2, x3, y3);
    if(!is_tri){
        return 0;
    }
    
    bool belong_p = isBelong(xp, yp, x1, y1, x2, y2, x3, y3);
    bool belong_q = isBelong(xq, yq, x1, y1, x2, y2, x3, y3);
    
    if(belong_p && belong_q) return 3;
    else if(belong_p) return 1;
    else if(belong_q) return 2;
    return 4;   
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string x1_temp;
    getline(cin, x1_temp);

    int x1 = stoi(ltrim(rtrim(x1_temp)));

    string y1_temp;
    getline(cin, y1_temp);

    int y1 = stoi(ltrim(rtrim(y1_temp)));

    string x2_temp;
    getline(cin, x2_temp);

    int x2 = stoi(ltrim(rtrim(x2_temp)));

    string y2_temp;
    getline(cin, y2_temp);

    int y2 = stoi(ltrim(rtrim(y2_temp)));

    string x3_temp;
    getline(cin, x3_temp);

    int x3 = stoi(ltrim(rtrim(x3_temp)));

    string y3_temp;
    getline(cin, y3_temp);

    int y3 = stoi(ltrim(rtrim(y3_temp)));

    string xp_temp;
    getline(cin, xp_temp);

    int xp = stoi(ltrim(rtrim(xp_temp)));

    string yp_temp;
    getline(cin, yp_temp);

    int yp = stoi(ltrim(rtrim(yp_temp)));

    string xq_temp;
    getline(cin, xq_temp);

    int xq = stoi(ltrim(rtrim(xq_temp)));

    string yq_temp;
    getline(cin, yq_temp);

    int yq = stoi(ltrim(rtrim(yq_temp)));

    int result = pointsBelong(x1, y1, x2, y2, x3, y3, xp, yp, xq, yq);

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
