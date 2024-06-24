class Solution {
    public String intToRoman(int num) {
        int curr_dividor;
        String curr_char;
        int times;
        String roman = "";

        int[] dividors = {1000, 900, 500, 400,
                          100, 90, 50, 40,
                          10, 9, 5, 4, 1};
        String[] chars = {"M", "CM", "D", "CD",
                          "C", "XC", "L", "XL",
                          "X", "IX", "V", "IV", "I"};
        
        for (int i = 0; i < dividors.length; i++) {
            curr_dividor = dividors[i];
            curr_char = chars[i];

            if ((num / curr_dividor) != 0) {
                times = num / curr_dividor;
                for (int j = 0; j < times; j++) {
                    roman += curr_char; 
                }
                num %= curr_dividor;
            }
        }
        return roman;
    }
}
