#include <stdio.h>

int main(int argv, char* args[])
{
	int number = 16 ;
	int bits = 16;                   // ������ ��������� 32
	
	


for(int i = 0; i < 6; ++i)
	{
	
	printf("\nNumber: ");
	scanf("%d", &number);
	printf("Base: ");
	scanf("%d", &bits);
	
	if (bits > 32){		// ������ ���� �����. � ��� ������� �� ����������.
		bits = 32;
		printf("Base can't be more than 32. Base: 32\n");
		}

	// ����� �������� bits = 5. �.�. ������� 5 ���. 
	// ������� ��� ��������� �� ����, ������ ��� ������ ����� �������� 4 ����
	// 5 ��� ���������� ��� �������� ����� �� -16 �� 15

	// ������ ������, ����� �� ����� �� �� ����� � number. ������������� ��� 
	// � n - ��������� ������ ����� ���������
	int _a = number<<(31-bits+1)>>(31-bits+1);
	
	// �������� �������� ����� _a � number
	int _b = abs(number - _a);			// ���� ��� ����, �� ��� ���, ����� �� ���
	
	// ����� ������
	printf("For number %d answer is %d\n\n", number, (((~_b)+1)>>31 ) + 1);
}
	

	return 0;
}
