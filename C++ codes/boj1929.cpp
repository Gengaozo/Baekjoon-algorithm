#include<iostream>

using namespace std;

void sieve(bool primes[], int size);

int main(void)
{
	int m,n;
	cin>>m>>n;
	
	bool* primes = new bool[n+1];
	
	for(int i=2;i<=n;i++)
	{
		primes[i] = true;
	}
	primes[1] = false;		//따로 처리해주자. 
	
	sieve(primes,n);
	
	for(int i=m;i<=n;i++)
	{
		if(primes[i])
		{
			cout<<i<<"\n";
		}
	}
	
	return 0;
}

void sieve(bool primes[], int size)
{
	for(int i=2;i*i<=size;i++)
	{
		if(primes[i])
		{
			for(int j=i*i;j<=size;j+=i)
			{
				primes[j] = false;
			}
		}
	}
}
