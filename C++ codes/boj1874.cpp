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
		if(top == -1)	//pop�� ���� �ƹ��͵� ������ push 
		{
			push(pushIt++);
			answer += "+\n";
		}
		else if(stack[top] != row[index] && pushIt <= n)	//push�� ���� �ְ�, pop�ҽ� �ùٸ� �ڸ��� �ƴϸ� push 
		{
			push(pushIt++);
			answer += "+\n";
		}
		else if(stack[top] == row[index])	//pop�� �� �ùٸ� �ڸ��� pop 
		{
			pop();
			++index;
			answer += "-\n";
		}
		else	//�ƴϸ� �Ұ� 
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
