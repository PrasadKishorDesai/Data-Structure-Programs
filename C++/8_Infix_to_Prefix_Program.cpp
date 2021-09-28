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

// to assign the precedence values
int precedence (char c)
{
	if (c == '^')
		return 3;
	else if (c == '*' || c== '/')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}

// to reverse the expression
string reverseExpression (string exp)
{
	string ans;
	for (int i = exp.length()-1; i >= 0; i--)
	{
		if (exp[i] == '(')
			ans += ')';
		else if (exp[i] == ')')
			ans += '(';
		else 
			ans += exp[i];
	}
	return ans;
}

// to convert infix expression to prefix
string InfixToPrefix (string infix, stack <char> s)
{
	string pref;
	string inf = reverseExpression(infix);
	
	for (int i = 0; i < inf.length(); i++)
	{
		if (isOperand(inf[i]))
		{
			pref += inf[i];
		}
		else if (inf[i] == '(')
		{
			s.push(inf[i]);
		}
		else if (inf[i] == ')')
		{
			while ((!s.empty()) && (s.top() != '('))
			{
				pref += s.top();
				s.pop();
			}
			if (s.top() == '(')
			{
				s.pop();
			}
		}
		else if (isOperator(inf[i]))
		{
			if (s.empty())
			{
				s.push(inf[i]);
			}
			else
			{
				if (precedence(inf[i]) > precedence(s.top()))
				{
					s.push(inf[i]);
				}
				else if ((precedence(inf[i]) == precedence(s.top())) && (inf[i] == '^'))
				{
					while ((precedence(inf[i]) == precedence(s.top())) && (inf[i] == '^'))
					{
						pref += s.top();
						s.pop();
					}
					s.push(inf[i]);
				}
				else if (precedence(inf[i]) == precedence(s.top()))
				{
					s.push(inf[i]);
				}
				else
				{
					while ((!s.empty()) && (precedence(inf[i]) < precedence(s.top())))
					{
						pref += s.top();
						s.pop();
					}
					s.push(inf[i]);
				}
			}
		}
		else 
		{
			cout << "Invalid character in INFIX expression: " << inf[i] << endl;
			cout << "Cannot convert INFIX to PREFIX" << endl;
			return "";
		}
	}
	
	// adding remaining operators to prefix expression
	while (!s.empty())
	{
		pref += s.top();
		s.pop();
	}
	
	pref = reverseExpression(pref);
	return pref;
}

int main()
{
	// initializing variables and using STL for stack
	string infix, prefix;
	stack <char> stack;
	
	cout << "Enter INFIX expression: ";
	cin >> infix;
	cout << endl;
	
	cout << "INFIX expression is: " << infix << endl;
	prefix = InfixToPrefix(infix, stack);
	if (prefix != "")
	{
		cout << "PREFIX expression is: " << prefix << endl;
	}
	
	return 0;
}
