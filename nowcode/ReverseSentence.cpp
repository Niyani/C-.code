class Solution {
public:
    string ReverseSentence(string str) {
        if(str.empty()||str.length()==1) 
           return str;
        string result=str;
        reverse(result.begin(),result.end());
        string::iterator it=result.begin();
        string::iterator pre_it=result.begin();
        for(;it!=result.end();++it){
            if(*it==' '){
                reverse(pre_it,it);
                pre_it=it+1;
            }
        }
        reverse(pre_it,result.end());
        return result;

    }
};
