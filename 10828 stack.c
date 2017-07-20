//https://www.acmicpc.net/problem/10828
//baekjoon Online Judge
#include<stdio.h>

int tp=-1;

void push(int arr[],int value)
{
	arr[++tp]=value;
}

void pop(int arr[])
{
	if(size()==0)
	{
		puts("-1");
		return;
	}
	printf("%d\n",arr[tp--]);
}

int size()
{
	return tp+1;
}

void empty()
{
	if(size()==0)puts("1");
	else puts("0");
}

int top(int arr[])
{
	if(size()==0)
	{
	puts("-1");
	return;
	}	
	printf("%d\n",arr[tp]);
}

int main()
{
	int arr[10000];
	unsigned int i,repeat;
	char command[6];
	
	scanf("%d",&repeat);				//repeating
	for(i=0;i<repeat;i++)
	{
		scanf("%s",command);
		switch(command[0])
		{
			case 'p':
				if(command[1]=='u')			//push
				{
					int value;
					scanf("%d",&value);
					push(arr,value);
				}
				else pop(arr);				//pop. if stack is empty, output -1
				break;
			case 's':
				printf("%d\n",size());		//print size of stack
				break;
			case 'e':
				empty();					//if stack is empty, print 1. if not, print 0.
				break;
			case 't':
				top(arr);					//print value that is on top of stack. if stack is empty, print -1
				break;
		}
	}
}
