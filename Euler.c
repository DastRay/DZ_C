
#include "Euler.h"
#include <stdbool.h>

/*unsigned long long Problem_1(const int value_, const int* multiples_, const unsigned int size_)
{
	unsigned long long sum = 0;

	for (unsigned int number = 0; number < value_; ++number)
	{
		for (unsigned int i = 0; i < size_; ++i)
		{
			if (number % multiples_[i] == 0)
			{
				sum += number;
				break;
			}

		}
	}
	return sum;
}
*/




/*unsigned long long Problem_2(const unsigned int value_)
{
	unsigned long long sum = 0;
	unsigned int fib1 = 1;
	unsigned int fib2 = 2;

	while (fib2 < value_)
	{
		if (fib2 % 2 == 0)
		{
			sum += fib2;
		}

		unsigned int prom = fib1;
		fib1 = fib2;
		fib2 = fib1 + prom;
	}

	return sum;
}
*/


/*
bool prime(unsigned long long n)
{	
	unsigned long long i = 1;
	bool pr = false;
	int countD = 0;
	for (i = 1; i <= n; i++)
	{
		if (n % i == 0)
		{
			countD++;
		}
	}
	if (countD == 2)
	{
		pr = true;
	}
	return pr;
}
*/

unsigned long long Problem_3(const unsigned long long value_)
{
	unsigned long long delmax_ = 0;
	unsigned long long del_ = 1;

	while(del_ < value_)
	{	
		if (value_ % del_ == 0)
		{
			delmax_ = del_;
		}
		del_ += 1;
	}
	return delmax_;
}
