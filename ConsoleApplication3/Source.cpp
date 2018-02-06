#include <stdio.h>
#include <iostream>
#include <time.h>
#include <stdarg.h>

using namespace std;

int t2(int a = 5, char b = '-');
void addRD(int d, int &k)
{
	k = 10 * k + d;
}

int sumNumber(int num, ...);

void up_and_down(int n)
{
	cout << "Level: " << n << endl;

	if (n < 4)
	{
		up_and_down(n + 1);
		cout << "Level: " << n << endl;
	}
}

long fact(int n)
{
	long ans;
	for (ans = 1; n > 1; n--)
		ans *= n;
		
	return ans;
}

long rfact(int n)
{
	long ans;
	if (n > 0)
		ans = n*rfact(n - 1);
	else
		ans = 1;
	return ans;
}

void rand(char * mas,int size)
{
	srand(time(0));
	for (int i = 0; i < size; i++)
	{
		*mas = 1 + rand() % 9 + '0';
		mas++;
	}
}

int sum(char *ch,int size)
{
	int s = 0;
	for (int i = 0; i < size; i++)
	{
		s += (int)*ch;
		ch++;
	}
	return s;
}

int rsum(char *ch, int size,int *s)
{
	if (size >= 0)
	{
		size--;
		s += rsum(ch + size, size,s);
		
	}
	else
		size = *ch+size;
	return size;
}

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	short int z;
	do
	{
		cout << "Kakoe zadanie?" << endl;
		cin >> z;
		switch (z)
		{
		case 1:
		{
			t2('*');//нельзя передавать 1 параметр, если в функции несколько параметров
			cout << endl;
		}
		break;
		case 2:
		{
			int k, d;
			cout << "k:";
			cin >> k;

			for (size_t i = 0; i < 2; i++)
			{
				while (1)
				{
					cout << "d: ";
					cin >> d;
					if (d >= 0 && d <= 9)
					{
						addRD(d, k);
						break;
					}
					else
					{
						cout << "!!!" << endl;
					}
				}
				cout << "k = " << k << endl;
			}
		}
		break;
		case 3:
		{
			int sum = sumNumber(9, 1, 6, 8, 9, 12, 56,  120, 34);
			cout << sum << endl;
			cout << endl;
		}
		break;
		case 4:
		{
			  
			up_and_down(1);
			cout << "Level: "  << endl;
		}
		break; 

		case 5:
		{
			int num;
			while(scanf("%d", &num) == 1)
			{
				if (num < 0)
				{
					cout << "Please do not enter - number" << endl;
				}
				else if (num > 12)
				{
					cout << "The input type must be less 13" << endl;
				}
				else
				{
					long resultR = fact(num);
					cout << "num= " << num << "rsult = " << resultR << endl;
				}
			}
		}
		break;

		case 6:
		{
			/*11.	Написать рекурсивную функцию :
			a.вычисления суммы цифр натурального числа;
			b.вычисления количества цифр натурального числа.*/
			char ch[5];
			rand(ch, 5);
			int s=0;
			s = rsum(ch, 5, &s);
		}
		break;

		}

	} while (z <= 0);



	system("pause");
}
int t2(int a, char b)
{
	for (int i = 0; i < a; i++)
	{
		cout << b;
	}
	return 0;
}

int sumNumber(int num, ...)
{
	double sum = 0.0;
	
	va_list arg;
	//инициализируем указатель arg
	va_start(arg, num);
	//суммируем ряды
	
	int t;
	for (; num; num--)
	{
		t = va_arg(arg, int);
		sum += t;
	}
	va_end(arg);

	return sum;
}