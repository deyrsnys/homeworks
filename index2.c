/*
���������� � ����� �������.
������, 171
*/

#include <stdio.h>

double mypow(int number, int pow);


void main(void)
{
	// ����� n �������� � ������� p (����� ���� ���� ������������� ���� ������������
	int n;
	int p;

	printf("\nEnter a number: ");
	scanf("%d",&n);
	printf("Enter a power: ");
	scanf("%d", &p);

	printf("Result %.6lf\n\n",mypow(n,p));	
}


double mypow(int number, int _pow){
	
	int flag_positive = 1;
	if (_pow < 0)
	{
		// ���� _pow ������������� �����.
		_pow = -_pow;
		flag_positive = 0;
	}

	// ����� ����� Number � ������� _pow
	// ��������� ����� ��������� � ���������� result
	double result = 1.0; 			// ���������������� �� ��������, ��� ��� ����� ����� ����� ������
	
	// ���� pow �� ���� ����� ��������� ����.
	while(_pow)
	{
		// ���� ������� ���� ����� ��������, �� ��������� result �� a
		if(_pow&1)
			result *= number;				// ��� ������ result ��� 1 ����������
				
		number *= number;				// ������ �������� number �� ��� �������
		_pow = _pow >> 1;				// � ��� _pow ������ ��������� ����� ������.
	}

	// ����� � ����������� �� ��������������� ��� ��������������� �������
	return flag_positive?result:1.0/result;
}
