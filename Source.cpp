#include <iostream>

void perest(int** m, int d)
{
	m[0][d]++;
	int i{ d };
	while (m[0][i] > i << 1 && i > 0)
		m[0][--i]++;				// заполнение 1 строчки
	while (i < d)
	{
		m[0][i + 1] = m[0][i] + 1;
		i++;
	}
	for (int i{ 0 }; i <= d; i++)
		m[1][i] = 0;
	d <<= 1;
	d++;
	for (int k{ 1 }, i{ 1 }; k <= d; k++)	// заполнение 2 строчки
	{
		if (m[0][i] == k)
			i++;
		else
		{
			int j = i - 1;
			while (m[1][j] != 0)
				j--;
			m[1][j] = k;
		}
	}
}

void plus(int* m, int a, int d)
{
	m[d]++;
	while (m[d] >= a && d >= 0)
	{
		m[d] = 0;
		m[--d]++;
	}
}

void vivod(int** m, int d, char* masc)
{
	for (int i{ 0 }; i < d; i++)
	{
		switch (m[2][i])
		{
		case 0:
			masc[m[0][i]] = '(';
			masc[m[1][i]] = ')';
			break;
		case 1:
			masc[m[0][i]] = '[';
			masc[m[1][i]] = ']';
			break;
		case 2:
			masc[m[0][i]] = '<';
			masc[m[1][i]] = '>';
			break;
		case 3:
			masc[m[0][i]] = '{';
			masc[m[1][i]] = '}';
			break;
		}
	}
	d <<= 1;
	for (int i{ 0 }; i < d; i++)
		std::cout << masc[i];
	std::cout << " ";
}

int main()
{
	int N, M;
	unsigned long long int max{ 1 };
	std::cin >> N >> M;
	if (N % 2 != 0)
	{
		std::cout << "NO";
		return 0;
	}

	for (int i{ 0 }; i < N >> 1; i++)
	{
		max *= M;	//M в степени N/2 - кол-во вариантов кмпановки по виду
	}
	int **mas = new int*[3];
	for (int i{ 0 }; i < 3; i++)
	{
		mas[i] = new int[N >> 1];
	}
	for (int i{ 0 }; i < N >> 1; i++)
	{
		mas[0][i] = i;				//номера элементов, где находятся открывающие скобки
		mas[1][i] = N - 1 - i;		//номера элементов, где находятся закрывающие скобки
		mas[2][i] = 0;				//вид скобки
	}
	char* masc = new char[N];

	for (; mas[0][0] != 1;)
	{
		for (unsigned long long j{ 0 }; j < max; j++)
		{
			vivod(mas, N >> 1, masc);
			plus(mas[2], M, (N >> 1) - 1);
		}
		for (int j{ 0 }; j < N >> 1; j++)
			mas[2][j] = 0;
		perest(mas, (N >> 1) - 1);
	}
	std::cin >> N;
	return 0;
}