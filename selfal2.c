#include<stdio.h>

int number[10001];

int gen(int n)
{
	int tmp=n;
	while(tmp)
	{
		n+=tmp%10;
		tmp/=10;
	}
	return n;
}

int main()
{
	int i,selfnumber,res=0;
	for(i=0;i<=10000;i++)
	{
		number[i]=i;
	}
	
	for(i=0;i<=10000;i++)
	{
		selfnumber=gen(i);
		if(selfnumber<=10000)
		number[selfnumber]=0;
	}
	for(i=0;i<=10000;i++)
	{
		if(number[i]!=0)
		printf("%d\n",number[i]);
		res+=number[i];
	}
	printf("%d\n",res);
}
