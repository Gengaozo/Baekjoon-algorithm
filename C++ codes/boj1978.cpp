#include<iostream>

using namespace std;

int main(void)
{
	int cnt;
	int* numbers;
	int answer = 0;
	
	cin>>cnt;					//�� ���� �Է� 
	numbers = new int[cnt];		//���� �Ҵ� 
	
	for(int i=0;i<cnt;i++)		//��� ���� ��ȸ 
	{
		//j�� 2���� �����ؼ� ��ȸ�ϴ� �� �������� ������.
		//��ȸ�ϴ� �� / j�� �ѹ��̶� ������������ �Ҽ� �ƴ�. 
		bool isAnswer = true;
		cin>>numbers[i];	//�� �Է� 
		
		if(numbers[i] != 1)
		{
			for(int j=2;j<numbers[i];j++)
			{
				if(numbers[i]%j == 0)
				{
					isAnswer = false;				//�ѹ��̶� ������ �������� false 
					break; 
				}
			 }
			if(isAnswer)			//�÷��װ� true�ų� ���� 2�̸� �Ҽ�. 
			{
				++answer;
			}
		}
	}
	
	cout<<answer;
	
	delete[] numbers;
	return 0; 
}
