#include<bits/stdc++.h>
using namespace std;
#define loop(a,b,c) for(int a=b;a<c;a++)
#define ll long long int

const int N=1e5+5;
const int MOD=1e9+7;

bool isInt(string a){
        return (a[0]>=48 && a[0]<=57) ? true : false;
    }
    
    string decodeString(string s) {
        stack<char> st;
        string str = "";
        for(auto a : s){
            if(a == ']')
            {
                while(st.top() != '['){
                    str = st.top() + str;
                    st.pop();
                }
                st.pop(); // popping the [ from the stack.
                string num = "";
                while(!st.empty() && isdigit(st.top())){
                    num = st.top() + num;
                    st.pop();
                }
                int no = stoi(num);
                // Creating a new string by appending the same strings.
                num = "";
                for(int i=0; i<no; i++){
                    num = str + num;
                }
                str = "";
                for(auto i : num){
                    st.push(i);
                }
            }
            else
            {
                st.push(a);
            }
        }
        string res = "";
        while(!st.empty()){
            res = st.top() + res;
            st.top();
        }
        return res;
    }

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    string s = "3[a]2[bc]";
    // cin>>s;
    cout<<decodeString(s)<<endl;
    return 0;

}