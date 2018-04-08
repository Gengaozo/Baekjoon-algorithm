#include<iostream>
/*
4948 ����Ʈ�� ���� 
n�� �־����� �� n���� ũ�� 2n���� �۰ų� ���� �Ҽ��� ���� (��� �Ѱ�)

�׽�Ʈ���̽� ������ 
�Է� ������ 0 (���� ����) 
*/
using namespace std;

void sieve(bool primes[], int size);

int main(void)
{
	int n, size, cnt;
	bool* primes = NULL;
	
	while(true)
	{
		cin>>n;
		if(n==0)	//���� ���� 
			break;
			
		size = n*2; 
		cnt = 0;
			
		delete[] primes;
		primes = NULL;
		primes = new bool[size+1];
		//�迭 ���� �� ���� �Ҵ� 
		
		for(int i=1;i<=size;i++)
			primes[i] = true;
		
		sieve(primes,size);	//�����佺�׳׽��� ü 
		
		for(int i=n+1;i<=size;i++)	//n���� ū ���Ƿ� +1 
		{
			if(primes[i])
			{
				++cnt;	//�Ҽ� �迭�� Ž���� �Ҽ� �߰� 
			}
		}
		cout<<cnt<<"\n";	//endl�� ������. ���� ���ڷ� �������. 
	}
	
	delete[] primes;		//�޸� ������ �ʼ�
	return 0;
}

void sieve(bool primes[], int size)
{
	primes[1] = false;			//1�� ���� ó��������. 
	for(int i=2;i*i<=size;i++)	//�����Ǿ� ����� �Ǹ� �� ����� ������ �ʰ���. 
	{
		if(primes[i])
		{
			for(int j=i*i;j<=size;j+=i)	//�Ҽ��� ����� �������� ���������. 
			{
				primes[j] = false;
			}
		}
	}
	//��ġ �Ƕ�̵带 �׾ƿø��� n*n, n*(n+1) ������ �Ҽ��� ����������. 
}
