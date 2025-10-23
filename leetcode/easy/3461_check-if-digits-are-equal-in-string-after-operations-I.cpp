bool pascal(int n, string the_string)
{
    vector<vector<long long>> arr(2, vector<long long>(n, 0));
    long long num1 = 0;
    long long num2 = 0;
    for (int line = 0; line < n; line++)
    {
        for (int i = 0; i <= line; i++)
        {
            if (line == i || i == 0) arr[1][i] = 1;
            else arr[1][i] = arr[0][i - 1]%10 + arr[0][i]%10;

            if(line+1 == n){
                num1 += (arr[1][i]%10 * (the_string[i] - '0')) % 10;
                num2 += (arr[1][i]%10 * (the_string[i+1] - '0')) % 10;
            }    
        }
        arr[0] = arr[1];
    }

    num1 %= 10;
    num2 %= 10;
    return num1 == num2;
}
class Solution {
public:

    bool hasSameDigits(string s) {
        return pascal(s.size()-1, s);
    }
};