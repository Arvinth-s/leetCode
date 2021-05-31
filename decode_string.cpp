//OM NAMO NARAYANA
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        stack<int> val;
        st.push("");
        bool last_int=false;
        for(char ch:s){
            
            
            if(ch-'0' <= 9){
                if(last_int){
                    val.top()=val.top()*10+ch-'0';
                }else{
                    val.push(ch-'0');
                }
            
                
                last_int = true;
                
            }else if(ch=='[' || ch==']'){ 
                if(ch==']'){
                    string str_temp="";
                    int val_temp=val.top();
                    val.pop();
                    for(int i=0;i<val_temp; i++)str_temp += st.top();
                    st.pop();
                    
                    if(st.empty()){
                        st.push(str_temp);
                    }else{
                        st.top() += str_temp;
                    }
                }else{
                    st.push("");
                }
                
                
                last_int = false;

            }else{
                st.top().push_back(ch);
                last_int = false;
            }
        }
        
        return st.top();
    }
};