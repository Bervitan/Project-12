#include <iostream>
#include <string>
#include "KPereodik.h"


void computeLPS(std::string pat, int* lps)       // Формирование lps 

{
	int i = 1;
	lps[0] = 0;
	int j = 0;

	while (i < pat.size())
	{
		if (pat[i] == pat[j])
		{
			j++;
			lps[i] = j;
			i++;
		}
		else
		{
			if (j != 0)
			{
				j = lps[j - 1];
			}
			else
			{

				lps[i] = 0;
				i++;
			}
		}
	}
}

void IsKPereodic(int K, const std::string& txt)         // Проверка на кратность
{
	if (K < 1)
	{
		std::cout << "\033[31m" << "Недопустимое значение K !" << "\033[0m" << std::endl; // Проверка корректности K
	}
	else
	{
		std::string pat;

		for (int i = 0; i < K; ++i)

			pat.push_back(txt[i]);
	
		int* lps = new int[pat.size()];

		computeLPS(pat, lps);
		int i = 0;
		int j = 0;
		int value = 0;

		while (i < txt.size())
		{
			if (pat[j] == txt[i])
			{
				j++;
				i++;
			}

			if (j == pat.size())
			{
				value++;
				j = lps[j - 1];
			}

			else if (i < txt.size() && pat[j] != txt[i])
			{
				if (j != 0)
				{
					j = lps[j - 1];
				}

				else
				{
					i = i + 1;
				}
			}
		}

		if (K * value == txt.size())

			std::cout << "Строка " << txt << " кратна " << K << std::endl;

		else std::cout << "Строка " << txt << " не кратна " << K << std::endl;

		delete[] lps;

	}
}
