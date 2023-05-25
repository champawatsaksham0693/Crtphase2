/*
    Alternating String for example = xyxyxyxyxyxy or yxyxyxyxyx
    We have given an String S = "abaaacdcbd"

    We have to perform operation on it and convert into alternating string
    and return maximum lenghth of alternating string 
    also find the minimum number of characters 
    Time Comlexity = O(N*26*26)
    Space Complexity = O(1)

    Solution :- 
    pehle humko do charcter nikalne hai fir usse alternating string banayenge then un occurrence ko remove karenge jo given me nahi hai or jo maximum lenghth ki string banegi uski length ko return kar denge 

*/#include<bits/stdc++.h>
using namespace std;
 
int main(){
    string s;
    cout<<"Enter the String:"<<endl;
    cin>>s;
    int ans = 0;
    char ans1, ans2;
    for(char ch1='a';ch1<='z';ch1++){
        for(char ch2='a';ch2<='z';ch2++){
            if(ch1==ch2) continue;
            char kyaLenaHai = ch1;
            int kitneIncludeKie = 0;
            for(int i=0;i<s.size();i++){
                if(s[i]==kyaLenaHai){
                    kitneIncludeKie++;
                    kyaLenaHai=(kyaLenaHai==ch1?ch2:ch1);
                }else if(s[i]==ch1 or s[i]==ch2){
                    kitneIncludeKie = -1e9;
                    break;
                }
            }
 
            if(kitneIncludeKie>ans){
                ans = kitneIncludeKie;
                ans1 = ch1;
                ans2 = ch2;
            }
        }
    }
    cout<<"Maximum length of the String is:"<<ans<<endl;
    cout<<"New string is:"<<endl;
    while(ans--){
        cout<<ans1;
        swap(ans1, ans2);
    }
}