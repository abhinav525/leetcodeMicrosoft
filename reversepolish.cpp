//Normal-> 3 + 5 = 8 but in RPN ->3 5 + = 8,just another way of writing the functions.we will use stack ds inorder to evaluate the problem,we have to apply the operation of operand on first two numbers,and we have to pop the numbers out of stack and push the result in the stack.
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(string x :tokens)//Tokens are the smallest elements of a program, which are meaningful to the compiler. The following are the types of tokens: Keywords, Identifiers, Constant, Strings, Operators,
        {
            if(x=="+")
            {
                int a = s.top();//2
                s.pop();// to get the next number.
                int b=s.top();//3
                //a+b=5
                s.pop();
                s.push(a+b);
            }
            else if(x=="*")
            {
                int a = s.top();//2
                s.pop();// to get the next number.
                int b=s.top();//3
                //a*b=6
                s.pop();
                s.push(a*b);
            }
            else if(x=="-")
            {
                int a = s.top();//2
                s.pop();// to get the next number.
                int b=s.top();//3
                //b-a=1
                s.pop();
                s.push(b-a);
            }
            else if(x=="/")
            {
                int a = s.top();//2
                s.pop();// to get the next number.
                int b=s.top();//3
                //a/b=1
                s.pop();
                s.push(b/a);
            }
            else s.push(stoi(x));//string to integer conversion
        }
        return s.top();

    }
};
