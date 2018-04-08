#include<iostream>

using namespace std;

void goldbach(bool primes[], int key);

void sieve(bool primes[], int size);

int main(void)
{
	const int size = 10001;
	bool primes[size];
	
	for(int i=2;i<=size;i++)
		primes[i] = true;
	
	sieve(primes,size);
	
	int n,t;
	cin>>t;
	
	while(t--)
	{
		cin>>n;
		goldbach(primes,n);
	}
	
	return 0;
}

void goldbach(bool primes[], int key)
{
	int i,j,mid = key >> 1; //2 ³ª´©±â 
	
	for(i=j=mid;i>0;i--,j++)
	{
		if(primes[i] && primes[j])
		{
			cout<<i<<" "<<j<<'\n';
			return;
		}
	}
}

void sieve(bool primes[], int size)
{
	primes[0] = false;
	primes[1] = false;
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
