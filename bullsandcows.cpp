//match will count for bulls and unmatch will count for cows,we will keep the hashmap or freq array for secret char freq and  guess char freq,if both are diffrent then only update the arrays.Cows=sum(min(guess[i],secret[i]))
class Solution {
public:
    string getHint(string secret, string guess) {

        int bulls=0;
        int cows=0;
        vector<int>s(10,0);// 10 size intialize by 0
        vector<int> g(10,0);
        for(int i=0;i<secret.length();i++)
        {
            if(secret[i]==guess[i])
            {
               bulls++;
            }
            else
            {
               s[secret[i]-'0']++;//update the freq vector ,secret i is character and we have  to convert it into integer.
               g[guess[i]-'0']++;
            }



        }
        for(int i=0;i<10;i++)
        {
            cows+=min(s[i],g[i]);
        }
        string ans="";

        ans+=to_string(bulls);
        ans+='A';
        ans+=to_string(cows);
        ans+='B';
        return ans;

    }
};
