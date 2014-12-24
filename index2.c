/*
Возведение в целую степень
Колчин, 171
*/

#include <stdio.h>

double mypow(int number, int pow);


void main(void)
{
	// Число n возводим в степень p (может быть либо отрицательной либо положительой
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
		// Если _pow отрицательное число.
		_pow = -_pow;
		flag_positive = 0;
	}

	// имеем число Number и степень _pow
	// результат будем сохранять в переменную result
	double result = 1.0; 			// Иницилиализируем ее единицей, так как потом будет видно почему
	
	// Пока pow не ноль будем выполнять цикл.
	while(_pow)
	{
		// Если степень есть число нечетное, то домножаем result на a
		if(_pow&1)
			result *= number;				// вот почему result был 1 изначально
				
		number *= number;				// Теперь заменяем number на его квадрат
		_pow = _pow >> 1;				// А для _pow делаем побитовый сдвиг вправо.
	}

	// Вывод в зависимости от отрицательности или положительности степени
	return flag_positive?result:1.0/result;
}
