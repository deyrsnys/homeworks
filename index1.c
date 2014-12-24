#include <stdio.h>

// �������� ������������� �����.

// ���������� �������:
void DecimalToBinary(unsigned int);
void DecToBin(unsigned int n);
void DecToBin2(unsigned int n); 


void main(void){
	// ��������� ����� �� ���������� �� � �������� ��������� ��������� ��������
	int n;
	printf("Enter a number: ");
	scanf("%d", &n);

	// ������������� ������� ��� ��������
	printf("Without Recursion: ");
	DecimalToBinary(n);
	
	// ������������� ������� � ���������
	printf("\n\nWith Recursion: ");
	DecToBin(n);

	// ��� ���� ������
	printf("\n\nAnother way: ");
	DecToBin2(n);
	printf("\n\n");
	
}

void DecimalToBinary(unsigned int n){
  	// ��� ���������
	
		// ��������� ��������� � str
	char* str = (char*)malloc(32);
	
		// ���� n �� ����� ���� ��������� ����. 
	do{	
		// �������� ��������� ����� ��������� ������������� ����� � ���������� ��� � str	
		sprintf(str,"%s%d",str,n&1);
		// �������� �� 1 ������� ������.
			/* ���� n = 5, �� � �������� ������������� n ��������� 101
				���� ������� 101 �� ���� ������� ������, �� ������� �������� ����� 10.
			*/
		n = n >> 1;			
	}while(n);

		// � ����� �������� �������� ������ �����, �� � �������� �������.
		// ���������� ������� ������ � �������� �������.
		
		// ��� �����, ��������� ��������� �� ����� ������
	char *p = str;			// ������� ��������� �� ������ � �����������
	
	// ���� ����� ���� ������			
	while(*p)
	{
		p++;
	} 
	// ������ ��������� ��������� �� ����� ������.
	
	// ������� ������ � �������� �������						
	do {
		p--;
		printf("%c",*p);		
	} while(p != str );

	// �������� ��������� ������������ ������.
	p = NULL;
	free(str);
	str = NULL;	

}

void DecToBin(unsigned int n){
	// � ���������
	if(!n)
		return;
	DecToBin(n>>1);
	printf("%d",n&1);

}

void DecToBin2(unsigned int n){
	for( int i = 31; i >=0; i-- )
	{
		printf("%d",(n>>i)&1);
	}
}
