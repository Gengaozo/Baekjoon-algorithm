#include<iostream>
/*
4948 베르트랑 공준 
n이 주어졌을 때 n보다 크고 2n보다 작거나 같은 소수의 개수 (적어도 한개)

테스트케이스 여러줄 
입력 마지막 0 (종료 조건) 
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
		if(n==0)	//종료 조건 
			break;
			
		size = n*2; 
		cnt = 0;
			
		delete[] primes;
		primes = NULL;
		primes = new bool[size+1];
		//배열 삭제 후 동적 할당 
		
		for(int i=1;i<=size;i++)
			primes[i] = true;
		
		sieve(primes,size);	//에라토스테네스의 체 
		
		for(int i=n+1;i<=size;i++)	//n보다 큰 수므로 +1 
		{
			if(primes[i])
			{
				++cnt;	//소수 배열을 탐색해 소수 발견 
			}
		}
		cout<<cnt<<"\n";	//endl은 느리다. 공백 문자로 대신하자. 
	}
	
	delete[] primes;		//메모리 해제는 필수
	return 0;
}

void sieve(bool primes[], int size)
{
	primes[1] = false;			//1은 따로 처리해주자. 
	for(int i=2;i*i<=size;i++)	//제곱되어 사이즈가 되면 그 배수는 사이즈 초과다. 
	{
		if(primes[i])
		{
			for(int j=i*i;j<=size;j+=i)	//소수의 배수를 거짓으로 만들어주자. 
			{
				primes[j] = false;
			}
		}
	}
	//마치 피라미드를 쌓아올리듯 n*n, n*(n+1) 식으로 소수로 만들어버린다. 
}
