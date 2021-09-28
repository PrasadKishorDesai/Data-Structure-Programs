#include <iostream>
#include <stack>
#include <string>

using namespace std;

// to check whether the character is operand
bool isOperand (char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return true;
	return false;
}

// to check whether the character is operator
bool isOperator (char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
		return true;
	return false;
}

// to convert postfix expression to prefix
string PostfixToPrefix (string postf)
{
	string pref;
	stack <string> s;
	string op1, op2, expression;
	
	for (int i = 0; i < postf.length(); i++)
	{
		if (isOperand(postf[i]))
		{
			string op(1, postf[i]);
			s.push(op);
		}
		else if (isOperator(postf[i]))
		{
			op2 = s.top();
			s.pop();
			op1 = s.top();
			s.pop();
			
			expression = postf[i] + op1 + op2;
			s.push(expression);
		}
		else
		{
			cout << "Invalid character in POSTFIX expression: " << pref[i] << endl;
			cout << "Cannot convert POSTFIX to PREFIX" << endl;
			return "";
		}
	}
	
	return s.top();
}

int main()
{
	// initializing variables and using STL for stack
	string postfix, prefix;
	
	cout << "Enter POSTFIX expression: ";
	cin >> postfix;
	cout << endl;
	
	cout << "POSTFIX expression is: " << postfix << endl;
	prefix = PostfixToPrefix(postfix);
	if (prefix != "")
	{
		cout << "PREFIX expression is: " << prefix << endl;
	}
	
	return 0;
}
