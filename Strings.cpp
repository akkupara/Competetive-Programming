1.) Remove outermost parantheses

--> This is an interesting question and needs further revision
--> while revising, it is better to do a dry run
--> for further doubts, visit this https://www.youtube.com/watch?v=OGaiCn1eHMA



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


class Solution {
public:
    string reverseWords(string s) {
        string result;
        int i=0;
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
