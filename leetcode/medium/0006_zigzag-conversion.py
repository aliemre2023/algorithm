class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows == 1 or numRows >= len(s):
            return s
        
        array = [[] for _ in range(numRows)]
        tempRows = 0
        increase = True

        for i in range(len(s)):
            array[tempRows].append(s[i])
            
            if tempRows == 0:
                increase = True
            elif tempRows == numRows - 1:
                increase = False

            if increase:
                tempRows += 1
            else:
                tempRows -= 1
        result = ""
        for row in array:
            for char in row:
                result += char
        return result