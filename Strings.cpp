1.) Remove outermost parantheses

--> This is an interesting question and needs further revision
--> while revising, it is better to do a dry run
--> for further doubts, visit this https://www.youtube.com/watch?v=OGaiCn1eHMA

Input: s = "(()())(())"
Output: "()()()"
	
Input: s = "(()())(())(()(()))"
Output: "()()()()(())"
	
	
Input: s = "()()"
Output: ""
	
	
	

class Solution {
public:
    string removeOuterParentheses(string s) {

        int count = 0;
        string ans = "";
        for(int i=0; i < s.size(); i++)
        {
            if(s[i] == 41)//if it is closing bracket, then decrease the count;
                count--;
            
            if(count != 0)//if the count is not zero, then add that character into the string
                ans+=s[i];
            
            if(s[i] == 40)//if it is opening bracket, then increase the count
                count++;
        }
        return ans;
    }
};




2.) Reverse words in a string

--> This is an interesting qs, but needs further revision
--> while revising, go through this video, https://www.youtube.com/watch?v=vhnRAaJybpA&t=411s
--> tc = o(n) and sc = o(n), using extra space is the main disadvantage here


Input: s = "the sky is blue"
Output: "blue is sky the"
	
	
	
Input: s = "  hello world  "
Output: "world hello"
	
	


class Solution {
public:
    string reverseWords(string s) {
        string result;//the answer which we are going to return 
	
        int i=0;//i denotes where the word starts and j denotes where the word ends
        int n = s.length();
        
        while(i < n)
        {
            while(i < n && s[i] == ' ')//we traverse and exclude all the extra spaces before a word
                i++;
            if(i >= n)//since j = i+1, we shud make sure that j doesnt go out of range, so if i >= n, then break
                break;
            int j = i+1;
            
            while(j < n && s[j] != ' ')// this j pointer points to a location to the end of a word 
                j++;
            string sub = s.substr(i, j-i);// so now i points to the begining of a word and j points to the end of a word
            
            if(result.length() == 0)// if the result string is already empty, then make it equal to sub
                result = sub;
            else
                result = sub + " " + result;// new result = new string + some space + older result
            i = j+1;//move the i to the next words beginning
        }
        
        
        
        return result;
    }
};


3.) Largest odd in a string(return a substring)
    
    
--> interesting qs
--> You are given a string num, representing a large integer. Return the largest-valued odd 
integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.
	
Input: num = "52"
Output: "5"
	
	
Input: num = "4206"
Output: ""
	
	
Input: num = "35427"
Output: "35427"
Explanation: "35427" is already an odd number.


class Solution {
public:
    string largestOddNumber(string num) {
        for(int i = num.length() - 1; i >= 0; i--)//we start from the last digit of the string,
		if(int(num[i]) % 2 != 0)//if it is even, move left, 
            //if it is odd, then return the substring starting from 0 to i+1
            //i.e if we encounter an odd integer, then we return the substring from 0 till that index
			return num.substr(0, i+1);

	    return "";//else return null string
        
    }
};



4.) Longest Common Prefix

--> I solved it using O(N^2), but can be optimised


Input: strs = ["flower","flow","flight"]
Output: "fl"
	
Input: strs = ["dog","racecar","car"]
Output: ""
	


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        for(int i=0; i < strs[0].size(); i++)//for traversing all characters in first string
        {
            char ch = strs[0][i];
            
            bool match = true;
            
            for(int j=1; j < strs.size(); j++)
            {
                if(strs[j].size() < i || ch != strs[j][i])// if match not found or size of j is greater then i, then break
                {
                    match = false;//if match is not found, then break from the inner loop
                    break;
                }
            }
            if(match == false)
                break;
            else
                ans.push_back(ch);
        }
        return ans;
    }
};



--> But also solved using better approach of sorting which is bit efficient than the former
--> first sort it so that all the similar words are next to each so we dont need to check them, it is enough if we check the string in extreme corners


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n =strs.size();
		string ans; 
        
		sort(strs.begin(), strs.end());//sort it so that all the similar words are next to each so we dont need to check them, it is enough if we check the string in extreme corners
        
		string a = strs[0];//leftmost string after sorting
		string b = strs[n-1];//rightmost string after sorting
        
		for(int i =0; i< a.size(); i++){
			if(a[i] == b[i]){
				ans.push_back(a[i]);
			}
            else 
                break;
		}
        
		return ans;
    }
};



5.) Isomorphic Strings

--> Two strings s and t are isomorphic if the characters in s can be replaced to get t.
	
	
Input: s = "egg", t = "add"
Output: true
	
Input: s = "foo", t = "bar"
Output: false
	
Input: s = "paper", t = "title"
Output: true
	

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m = s.size();
        int n = t.size();
        
        if(m != n)
            return false; //if size of two strings are not equal then return false
        
        int m1[256] = {0};//create two character arrays
        int m2[256] = {0};
        
        for(int i=0; i < n; i++)
        {
            if(m1[s[i]] == 0 and m2[t[i]] == 0)//if it is not already mapped and u r visiting that for the first time i.e it is unvisited
            {
                m1[s[i]] = t[i];//then create the map from x->y
                m2[t[i]] = s[i];//and then create the map from y->x
            }
            else if(m1[s[i]] != t[i])//if already hashed value is mapped to some other variable then return false i.e if the map is not x->y then return false
                return false;
        }
        return true;//else return true
        
    }
};



6.) Rotate string

-->Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
--> A shift on s consists of moving the leftmost character of s to the rightmost position.

Example 1:

Input: s = "abcde", goal = "cdeab"
Output: true
	
	
Example 2:

Input: s = "abcde", goal = "abced"
Output: false
	
	
class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        int m = goal.size();
        
        if(n != m)
            return false;
        
        string temp = s + s;// add the s to s itself and check if goal is present in it or not
        if(temp.find(goal) != string::npos)//npos is returned if match is not found
            return true;// if npos is not returned then it means a match is found and return true
        return false;
        
    }
};




7.) Valid Anagrams

--> Given two strings s and t, return true if t is an anagram of s, and false otherwise.
	
--> An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false

-->first approach is sort and check the equality of two string, if they are equal then return true else false
--> other approach is maintain a comman hash table, for every string1 visit increase the count by 1 and for every string2 visit decrease by 1 at the end if the count is 0, then return true else false
 

	
first approach using sort:

class Solution {
public:
    bool isAnagram(string s, string t) {
        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        if(s == t) //if they are equal then return true
            return true;
        return false;//if they are not equal, then return false
    }
};



Second Approach:(better solution)

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        
        int n = s.size();
        int count[26] = {0};
        
        for(int i=0; i < n; i++)
        {
            count[s[i] - 'a']++;//if the character in string s is encountered, increase the count by 1
            count[t[i] - 'a']--;//if the character in string s is encountered, decrease the count by 1
        }
        
        for(int i=0; i < 26; i++)
            if(count[i] != 0)// if anagram count shud be 0, if count is not zero return false
                return false;
        return true;//else return true

    }
};



8.) SORT CHARACTERS BY FREQUENCY


--> https://www.youtube.com/watch?v=vltY5jxqcco   important resource


Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.

 

Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.
	
--> first we push the element of the string into the pair of vector
--> and then sort it based on count
--> and then insert that sorted vector elements into a string which we are going to return as the final answer



class Solution {
public:
    string frequencySort(string s) {
        string ans = "";
        vector<pair<int, char>> vec{'z'+1, {0, 0}};//we create an array of (122+1) size and fill it full with null value and 123 because 123 characters are required to store all uppercase and lowercase alphabets
        for(char c: s)
            vec[c] = {vec[c].first+1, c};// we adding the incremented count of occurence and the character i.e each time we see a character we move to the index of that character and increment the count by 1
        
        sort(vec.begin(), vec.end());// and then we sort the vec according to the count
        
        for(auto p: vec)
        {
            ans = string(p.first, p.second) + ans;//for eg string(2, a) gives us the output 'aa' i.e we are pushing back the values into another stirgn which we are going to return as the answer
        }
        
        return ans;
    }
};



9.) Maximum nesting depth of the parantheses

--> https://www.youtube.com/watch?v=kUp-gqHzk6c  --important resouuse link
--> the basic idea is to keep track of the parantheses and return the highest parantheses count


Example 1:

Input: s = "(1+(2*3)+((8)/4))+1"
Output: 3
Explanation: Digit 8 is inside of 3 nested parentheses in the string.
	
	
Example 2:

Input: s = "(1)+((2))+(((3)))"
Output: 3

	
	
	
class Solution {
public:
    int maxDepth(string s) {// the basic idea is to keep track of the parantheses and return the highest parantheses count
        int count = 0;
        int maxi = 0;
        for(int i=0; i < s.size(); i++)
        {
            if(s[i] == '(')// if we encounter a open parantheses (
            { 
                count++;//then we increase the count
                maxi = max(count, maxi);//and keep a maxi variable to keep track of the highest parantheses count
            }
            else if(s[i] == ')')//if we encounter a open parantheses )
            {
                count--;//then we decrease the count
                maxi = max(count, maxi);//and keep a maxi variable to keep track of the highest parantheses count
            }
            else
                continue;// if the character is not either the two brackets, then move to the next indec
        }
        return maxi;//return the mamimum count
        
    }
};




10.) Roman to Integer

--> https://www.youtube.com/watch?v=bCA1otebP58&t=178s    important result
-->



class Solution {
public:
    int romanToInt(string str) {
        map<char, int> roman;
        roman.insert(make_pair('I', 1));
        roman.insert(make_pair('V', 5));
        roman.insert(make_pair('X', 10));
        roman.insert(make_pair('L', 50));
        roman.insert(make_pair('C', 100));
        roman.insert(make_pair('D', 500));
        roman.insert(make_pair('M', 1000));//make entries into the map where it contains the values and the roman letter
        
        int num, sum = 0;
        
        for(int i=0; i < str.size();)//iterate the string str
        {
            if(i==(str.size()-1) || roman[str[i]] >= roman[str[i+1]])//if it reaches the last character or current is greater than the next, then dont do anything
            { 
                num = roman[str[i]];//juz make it current value from the map
                i++;//move one position right
            }
            else //if(roman[str[i]] < roman[str[i+1]])
            {
                num = roman[str[i+1]] - roman[str[i]];// for eg IV then 5 - 1, if the next is greater than the current, then calculate the value of next-current from the map
                i = i + 2;//move two positions to the right
            }
            sum = sum + num;//add it to the sum
        }
       return sum; //finally return sum
    }
    
};
