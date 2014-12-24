/*
¬озведение в велую степень.
 олчин, 171
*/

#include <stdio.h>

double mypow(int number, int pow);


void main(void)
{
	// „исло n возводим в степень p (может быть либо отрицательной либо положительой
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
		// ≈сли _pow отрицательное число.
		_pow = -_pow;
		flag_positive = 0;
	}

	// имеем число Number и степень _pow
	// результат будем сохран€ть в переменную result
	double result = 1.0; 			// »ницилиализируем ее единицей, так как потом будет видно почему
	
	// ѕока pow не ноль будем выполн€ть цикл.
	while(_pow)
	{
		// ≈сли степень есть число нечетное, то домножаем result на a
		if(_pow&1)
			result *= number;				// вот почему result был 1 изначально
				
		number *= number;				// “еперь замен€ем number на его квадрат
		_pow = _pow >> 1;				// ј дл€ _pow делаем побитовый сдвиг вправо.
	}

	// ¬ывод в зависимости от отрицательности или положительности степени
	return flag_positive?result:1.0/result;
}
