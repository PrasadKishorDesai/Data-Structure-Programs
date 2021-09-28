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

// to reverse the expression
string reverseExpression (string exp)
{
	string ans;
	for (int i = exp.length()-1; i >= 0; i--)
	{
		ans += exp[i];
	}
	return ans;
}

// to convert prefix expression to postfix
string PrefixToPostfix (string prefix)
{
	string postf;
	stack <string> s;
	string op1, op2, expression;
	
	string pref = reverseExpression(prefix);
	
	for (int i = 0; i < pref.length(); i++)
	{
		if (isOperand(pref[i]))
		{
			string op(1, pref[i]);
			s.push(op);
		}
		else if (isOperator(pref[i]))
		{
			op1 = s.top();
			s.pop();
			op2 = s.top();
			s.pop();
			
			expression = op1 + op2 + pref[i];
			s.push(expression);
		}
		else
		{
			cout << "Invalid character in PREFIX expression: " << pref[i] << endl;
			cout << "Cannot convert PREFIX to POSTFIX" << endl;
			return "";
		}
	}
	
	return s.top();
}

int main()
{
	// initializing variables and using STL for stack
	string postfix, prefix;
	
	cout << "Enter PREFIX expression: ";
	cin >> prefix;
	cout << endl;
	
	cout << "PREFIX expression is: " << prefix << endl;
	postfix = PrefixToPostfix(prefix);
	if (postfix != "")
	{
		cout << "POSTFIX expression is: " << postfix << endl;
	}
	
	return 0;
}
