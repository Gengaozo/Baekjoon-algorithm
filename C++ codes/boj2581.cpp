#include<iostream>

using namespace std;

int main(void)
{
	int m,n;
	int sum = 0;
	int min = 10001;
	
	cin>>m>>n;
	
	for(int i=m;i<=n;++i)
	{
		
		if(i==1)
		{
			continue;
		}
		
		bool isPrime = true;
		for(int j=2;j<i;++j)
		{
			if(i % j == 0)
			{
				isPrime = false;
				break;
			}
		}
		
		if(isPrime)
		{
			sum += i;
			if(i<min)
			{
					min = i;
			}
		}
	}
	
	if(min==10001)
	{
		cout<<-1<<endl;
		return 0;
	}
	
	cout<<sum<<'\n'<<min<<endl;
	return 0;
}
