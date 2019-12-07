#include<bits/stdc++.h>
using namespace std;
#define int long long
int prec(char x){
    if(x == '^'){
        return 3;
    }
    else if(x == '*' || x == '/'){
        return 2;
    }
    else if(x == '+' || x == '-'){
        return 1;
    }
    return -1;
}
bool check(char x){
    if(x == '^' || x == '*' || x == '/'|| x == '+'|| x == '-'){
        return true;
    }
    return false;
}
signed main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        stack<char> st;
        string ans;
        for(int i=0; i<s.size(); i++){
            char x = s[i];
            if(x != '(' && x != ')'){
                if(!check(x)){
                    ans.push_back(x);
                }
                else{
                    //keep popping and pushing the operators
                    //while the current precedence is lower and top is not an opening bracket
                    while(!st.empty() && st.top() != '(' && prec(st.top()) >= prec(x)){
                        ans.push_back(st.top());
                        st.pop();
                    }
                    st.push(x);
                }
            }
            else if(x == '('){
                st.push(x);
            }
            else if(x == ')'){
                //keep popping and pushing the element from the top of stack
                //until an opening parentheses comes
                while(!st.empty() && st.top() != '('){
                    ans.push_back(st.top());
                    st.pop();
                }
                if(!st.empty()){
                    st.pop();
                }
            }
        }
        //push the leftover operators
        while(!st.empty()){
            char x = st.top();
            if(check(x)){
                ans.push_back(x);
            }
            st.pop();   
        }
        cout<<ans<<endl;
    }
    return 0;
}