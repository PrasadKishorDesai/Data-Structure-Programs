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

// to convert infix expression to postfix
string InfixToPostfix (string inf, stack <char> s)
{
	string postf;
	
	for (int i = 0; i < inf.length(); i++)
	{
		if (isOperand(inf[i]))
		{
			postf += inf[i];
		}
		else if (inf[i] == '(')
		{
			s.push(inf[i]);
		}
		else if (inf[i] == ')')
		{
			while ((!s.empty()) && (s.top() != '('))
			{
				postf += s.top();
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
					s.push(inf[i]);
				}
				else
				{
					while ((!s.empty()) && (precedence(inf[i]) <= precedence(s.top())))
					{
						postf += s.top();
						s.pop();
					}
					s.push(inf[i]);
				}
			}
		}
		else
		{
			cout << "Invalid character in INFIX expression: " << inf[i] << endl;
			cout << "Cannot convert INFIX to POSTFIX" << endl;
			return "";
		}
	}
	while (!s.empty())
	{
		postf += s.top();
		s.pop();
	}
	return postf;
}

int main()
{
	// initializing variables and using STL for stack
	string infix, postfix;
	stack <char> s;
	
	cout << "Enter INFIX expression: ";
	cin >> infix;
	cout << endl;
	
	cout << "INFIX expression is: " << infix << endl;
	postfix = InfixToPostfix(infix, s);
	if (postfix != "")
	{
		cout << "POSTFIX expression is: " << postfix << endl;
	}
	
	return 0;
}
