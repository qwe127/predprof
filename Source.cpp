#include <iostream>

void perest(int** m, int d)
{
	m[0][d]++;
	if (m[0][d] > d * 2)
	{
		int i{ d };
		while (m[0][i] > i * 2 && i > 0)
			m[0][--i]++;
		while (i < d)
		{
			m[0][i + 1] = m[0][i] + 1;
			i++;
		}
	}
	for (int i{ 0 }; i <= d; i++)
		m[1][i] = 0;
	for (int k{ 1 }, i{ 1 }; k <= d * 2 + 1; k++)
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
	for (int i{ 0 }; i < d * 2; i++)
		std::cout << masc[i];
	std::cout << " ";
}

int main()
{
	int N, M, max{ 1 };
	std::cin >> N >> M;
	if (N % 2 != 0)
	{
		std::cout << "NO";
		return 0;
	}

	for (int i{ 0 }; i < N / 2; i++)
	{
		max *= M;
	}
	int **mas = new int*[3];
	for (int i{ 0 }; i < 3; i++)
	{
		mas[i] = new int[N / 2];
	}
	for (int i{ 0 }; i < N / 2; i++)
	{
		mas[0][i] = i;
		mas[1][i] = N - 1 - i;
		mas[2][i] = 0;
	}
	char* masc = new char[N / 2];

	for (; mas[0][0] != 1;)
	{
		for (int j{ 0 }; j < max; j++)
		{
			vivod(mas, N / 2, masc);
			plus(mas[2], M, N / 2 - 1);
		}
		for (int j{ 0 }; j < N / 2; j++)
			mas[2][j] = 0;
		perest(mas, N / 2 - 1);
	}
	std::cin >> N;
	return 0;
}