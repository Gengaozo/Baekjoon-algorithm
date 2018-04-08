#include<iostream>

using namespace std;

int* stack;
int* row;
int top = -1;
int n;
	
void push(int value);
int pop();
bool check();

int main(void)
{
	cin>>n;
	stack = new int[n];
	row = new int[n];
	int pushIt = 1;
	int index = 0;
	string answer = "";
	
	for(int i=0;i<n;i++)
	{
		stack[i] = 0;
		cin>>row[i];
	}
	
	while(index != n)
	{
		if(top == -1)	//pop할 것이 아무것도 없으면 push 
		{
			push(pushIt++);
			answer += "+\n";
		}
		else if(stack[top] != row[index] && pushIt <= n)	//push할 수가 있고, pop할시 올바른 자리가 아니면 push 
		{
			push(pushIt++);
			answer += "+\n";
		}
		else if(stack[top] == row[index])	//pop할 시 올바른 자리면 pop 
		{
			pop();
			++index;
			answer += "-\n";
		}
		else	//아니면 불가 
		{
			answer = "NO";
			break;
		}
	}
	
	cout<<answer;
	return 0;
}

void push(int value)
{
	if(top < n-1)
		stack[++top] = value;
	else
		return;
}

int pop()
{
	return stack[top--];
}
