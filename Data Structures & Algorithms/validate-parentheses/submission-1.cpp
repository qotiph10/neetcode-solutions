class Solution {
public:
    bool isValid(string s) {
        stack<char> open;
        for(auto i:s){
            if(i == '{' || i == '[' || i == '('){
                open.push(i);
            }else if(i == '}' || i == ']' || i == ')'){
                if(open.empty() || (i == '}' && open.top() != '{') || (i == ']' && open.top() != '[') || (i == ')' && open.top() != '(')){
                    return 0;
                }
                else{
                    open.pop();
                }
            }
        }
        if(open.empty()) return 1;

        return 0;
    }
};
