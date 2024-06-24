class Solution(object):
    def reverse(self, x):
        
        s_x = str(x)
        sr_x = ""

        if x == 0 or x >= pow(2, 31)-1 or x <= -1*pow(2, 31):
            return 0

        if(int(x) > 0):
            while(s_x[-1] == "0"):
                s_x = s_x[:-1]
            sr_x += s_x[::-1]
        
        else:
            s_x = s_x[1:]
            while(s_x[-1] == "0"):
                s_x = s_x[:-1]
            s_x = s_x[::-1]
            sr_x += "-"
            sr_x += s_x

        x = int(sr_x) 
        if x == 0 or x >= pow(2, 31)-1 or x <= -1*pow(2, 31):
            return 0
        
        return x