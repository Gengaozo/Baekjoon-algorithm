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
		int part1,part2;			//�� 
		
		while(true)
		{
			a = b = nextPrime(primes,a,n);
			if(a+b > n) break;
			//b�� �ѵ� �̻����� �����ϸ� ������ ������, a�� ���� 
			if(a+b == n)				//���� ���� ��� 
			{
				part1 = a;
				part2 = b;
				break;
			}
			
			//���� ���� ����. �ִ��� ���̰� ���� �Ҽ��� ã�� �� �������� ���ϵ��� �� 
			
			while(a+b != n)		//b���� ������Ű�� (�ѵ� �̻����� �����ϸ� a�� ����) 
			{
				b = nextPrime(primes,b,n);
				if(b == 0)
				{
					break;
				}
			}
			if(a+b == n)		//���� ���� ���� �Ҽ� ã�� 
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
	primes[1] = false;	//1�� ���� ó��
	
	//�����佺�׳׽��� ü 
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
