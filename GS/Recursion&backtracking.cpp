2.) Letter combination of a phone number


  
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]  
  

Important Resource:
https://www.youtube.com/watch?v=tWnHbSHwNmA


class Solution {
public:
    void solve(string digit, string output, int index, vector<string> &ans, string mapping[])
    {
        //base case
        if(index >= digit.size())
        {
            ans.push_back(output);
            return;
        }
        int number = digit[index] - '0';
        string value = mapping[number];
        
        for(int i=0; i < value.size(); i++)
        {
            output.push_back(value[i]);
            solve(digit, output, index+1, ans, mapping);
            output.pop_back();
        }
        
    }
    
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string output;//to store the output of the number
        if(digits.size() == 0)
            return ans;
        
        int index = 0;
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        solve(digits, output, index, ans, mapping);
        return ans;
        
        
    }
};
