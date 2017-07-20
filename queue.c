#include<stdio.h>
#include<string.h>
int fro=0,rear=-1;

void push(int arr[],int value){
	arr[++rear]=value;				//increase rear and push value
}

void pop(int arr[]){
	if(size()==0)	//underflow check
	{
		puts("-1");
		return;
	}
	printf("%d\n",arr[fro++]);		//pop value and increase front in queue
}

int size(){
	return rear-fro+1;
}

int empty(){
	if(size()==0)return 1;		//if queue is empty, returns 1.
	else return 2;
}

void front(int arr[]){
	if(empty()==1)				//if queue is empty, print "-1" and return
	{
		puts("-1");
		return;
	}
	printf("%d\n",arr[fro]);
}

void back(int arr[]){
	if(empty()==1)				//if queue is empty, print "-1" and return
	{
		puts("-1");
		return;
	}
	printf("%d\n",arr[rear]);
}

int main(){
	
	int arr[10000],value,repeat,i;
	char command[6];
	//values declaration
	
	scanf("%d",&repeat);
	
	for(i=0;i<repeat;i++)	//repeat
	{
		scanf("%s",command);	//command input
		
		switch(command[0])				//recognize command with first char
		{
			case 'p':
				if(command[1]=='u'){	//push and pop has same first char, so compared second char
				scanf("%d",&value);		//input push value
				push(arr,value);
				}
				else
				pop(arr);
				break;
			case 's':
				printf("%d\n",size(front));
				break;
			case 'e':
				if(empty()==1)puts("1");
				else puts("0");
				break;
			case 'f':
				front(arr);
				break;
			case 'b':
				back(arr);
				break;
		}
	}
}
