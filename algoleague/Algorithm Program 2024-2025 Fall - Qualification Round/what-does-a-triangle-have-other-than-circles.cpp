#pragma GCC optimize("O3") 
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define PI 3.141592653589793

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int q; 
    cin >> q;
    for (int i = 0; i < q; i++) {
        double x1, y1, x2, y2, x3, y3; 
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;


        double a = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2)); 
        double b = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2)); 
        double c = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)); 

        double semi_per = (a + b + c) / 2.0;

        double area = sqrt(semi_per * (semi_per - a) * (semi_per - b) * (semi_per - c));

     
        double ins_r = area / semi_per; 


        double incenter_x = (a * x1 + b * x2 + c * x3) / (a + b + c);
        double incenter_y = (a * y1 + b * y2 + c * y3) / (a + b + c);
        
        //cout << "İç çemberi merkezi:( "" << incenter_x << ", " << incenter_y << ")\n";
   
        //rler
        double r_A = sqrt(pow(x1 - incenter_x, 2) + pow(y1 - incenter_y, 2)) - ins_r;
        double r_B = sqrt(pow(x2 - incenter_x, 2) + pow(y2 - incenter_y, 2)) - ins_r;
        double r_C = sqrt(pow(x3 - incenter_x, 2) + pow(y3 - incenter_y, 2)) - ins_r;
        //cout << r_A << " " << r_B << " " << r_C << "\n";


        double angle_A = acos((b*b + c*c - a*a) / (2*b*c));
        double angle_B = acos((a*a + c*c - b*b) / (2*a*c));
        double angle_C = acos((a*a + b*b - c*c) / (2*a*b));

        // cember alanlar
        double area_big_c = PI * pow(ins_r, 2);
        double area_A = PI * pow(r_A, 2) * (angle_A / (2 * PI));
        double area_B = PI * pow(r_B, 2) * (angle_B / (2 * PI));
        double area_C = PI * pow(r_C, 2) * (angle_C / (2 * PI));

        cout << fixed << setprecision(2);
        double result = area - (area_big_c + area_A + area_B + area_C);
        cout << result << "\n";
    }

    return 0;
}
