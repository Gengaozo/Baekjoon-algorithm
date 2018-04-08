#include<iostream>

using namespace std;

int main(void)
{
	int cnt;
	int* numbers;
	int answer = 0;
	
	cin>>cnt;					//수 갯수 입력 
	numbers = new int[cnt];		//동적 할당 
	
	for(int i=0;i<cnt;i++)		//모든 수를 순회 
	{
		//j가 2부터 시작해서 순회하는 수 직전까지 더해짐.
		//순회하는 수 / j가 한번이라도 나눠떨어지면 소수 아님. 
		bool isAnswer = true;
		cin>>numbers[i];	//수 입력 
		
		if(numbers[i] != 1)
		{
			for(int j=2;j<numbers[i];j++)
			{
				if(numbers[i]%j == 0)
				{
					isAnswer = false;				//한번이라도 나누어 떨어지면 false 
					break; 
				}
			 }
			if(isAnswer)			//플래그가 true거나 수가 2이면 소수. 
			{
				++answer;
			}
		}
	}
	
	cout<<answer;
	
	delete[] numbers;
	return 0; 
}
