class Solution {
    int char_to_int(char num){
        int re = -1;
        if(num == '0'){
            re = 0;
        } else if(num == '1'){
            re = 1;
        } else if(num == '2'){
            re = 2;
        } else if(num == '3'){
            re = 3;
        } else if(num == '4'){
            re = 4;
        } else if(num == '5'){
            re = 5;
        } else if(num == '6'){
            re = 6;
        } else if(num == '7'){
            re = 7;
        } else if(num == '8'){
            re = 8;
        } else if(num == '9'){
            re = 9;
        }
        return re;
    }
    
    public int myAtoi(String s) {
        int result = 0;
        boolean is_negative = false;
        String logical = "";
        
        int i = 0;
        while (i < s.length() && s.charAt(i) == ' ') {
            i++;
        }
        if (i < s.length() && (s.charAt(i) == '-' || s.charAt(i) == '+')) {
            is_negative = (s.charAt(i) == '-');
            i++;
        }
        for(; i < s.length(); i++){
            if(s.charAt(i) == '0' ||
               s.charAt(i) == '1' ||
               s.charAt(i) == '2' ||
               s.charAt(i) == '3' ||
               s.charAt(i) == '4' ||
               s.charAt(i) == '5' ||
               s.charAt(i) == '6' ||
               s.charAt(i) == '7' ||
               s.charAt(i) == '8' ||
               s.charAt(i) == '9'){
                logical += s.charAt(i);
            }
            else {
                break;
            }
        }

        for(int x = 0; x < logical.length(); x++){
            int ch2int = char_to_int(logical.charAt(x));
            if(ch2int == -1){
                continue;
            }
            if(result > (Integer.MAX_VALUE - ch2int) / 10) 
                return is_negative ? Integer.MIN_VALUE : Integer.MAX_VALUE;
            
            result = result * 10 + ch2int;
        }

        if(is_negative){
            result *= -1;
        }

        return result;
    }
}