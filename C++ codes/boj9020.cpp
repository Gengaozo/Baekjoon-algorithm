#include<iostream>

using namespace std;

void sieve(bool primes[], int size);
int nextPrime(bool primes[], int iter, int size);

int main(void)
{
	int n, t;
	cin>>t;
	bool* primes = new bool[10001];
	
	for(int i=2;i<=10000;i++)
	{
		primes[i] = true;
	}
	
	sieve(primes,10000);
	
	
	while(t--)
	{
		cin>>n;
		
		int a = 1, b;
		int part1,part2;			//답 
		
		while(true)
		{
			a = b = nextPrime(primes,a,n);
			if(a+b > n) break;
			//b가 한도 이상으로 증가하면 루프가 끝나고, a가 증가 
			if(a+b == n)				//가장 빠른 경우 
			{
				part1 = a;
				part2 = b;
				break;
			}
			
			//루프 종료 조건. 최대한 차이가 적은 소수를 찾고 더 진행하지 못하도록 함 
			
			while(a+b != n)		//b부터 증가시키기 (한도 이상으로 증가하면 a를 증가) 
			{
				b = nextPrime(primes,b,n);
				if(b == 0)
				{
					break;
				}
			}
			if(a+b == n)		//가장 차이 적은 소수 찾기 
			{
				part1 = a;
				part2 = b;
			}
		}
		
		cout<<part1<<" "<<part2<<'\n';
	}
	
	delete[] primes;
	return 0;
}

void sieve(bool primes[], int size)
{
	primes[1] = false;	//1은 따로 처리
	
	//에라토스테네스의 체 
	for(int i=2;i*i<=size;++i)
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

int nextPrime(bool primes[], int iter, int size)
{	
	if(iter>size) return 0;
	for(int i=iter+1;i<=size;++i)
	{
		if(primes[i])
		{
			return i;
		}
	}
}
