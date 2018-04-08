#include<iostream>
#include<string>

using namespace std;

string stack[15];
int top = -1;

string push(string value);
string pop();
string popBracket();

int main(void)
{
	string str;
	cin>>str;
	int size = str.size();
	int answer = 0;
	
	if(size&1)
	{
		cout<<0;
		return 0;
	}
	
	for(int i=0;i<size;i++)
	{
		bool isAdded = false;
		char chr = str.at(i);
		switch(chr)
		{
			case '(':
			push("(");
			break;	
			
			case '[':
			push("[");
			break;
			
			case ')':
			if(str.at(i-1) == '(')
			{
				pop();
				push("2");
				isAdded = true;
			}
			else if(stack[top] != "(" && stack[top] != "[")
			{
				cout<<"Bracket ";
				int pushIt = stoi(popBracket()) * 2;
				cout<<"pushIt : "<<pushIt<<'\n';
				push(to_string(pushIt));
			}
			if(stack[top-1] != "(" && stack[top-1] != "[")
			{
				int tmp = stoi(pop());
				tmp += stoi(pop());
				push(to_string(tmp));
			}			
			break;
			
			case ']':
			if(str.at(i-1) == '[')
			{	
				pop();
				push("3");
				isAdded = true;
			}
			else if(stack[top] != "(" || stack[top] != "[")
			{
				int pushIt = stoi(popBracket()) * 3;
				push(to_string(pushIt));
			}
			if(stack[top-1] != "(" && stack[top-1] != "[")
			{
				int tmp = stoi(pop());
				tmp += stoi(pop());
				push(to_string(tmp));
			}
			break;
		}
		
		cout<<"Stack : ";
		for(int i=0;i<=top;i++)
		{
			cout<<stack[i]<<' ';
		}
		cout<<'\n';
	}
	
	for(int i=0;i<=top;i++)
	{
		answer += stoi(stack[i]);
	}
	cout<<answer;
	
	return 0;
}

string push(string value)
{
	stack[++top] = value;
	return value;
}

string pop()
{
	return stack[top--];
}

string popBracket()
{
	string value = pop();
	--top;
	return value;
}
