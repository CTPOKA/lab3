#include <iostream>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int n = 2;

int fun(int* arr);

int main()
{
	setlocale(LC_ALL, "Russian");
	string answ = "y";
	while (answ == "y") {
		printf(" Введите размер квадратной двумерной матрицы:\n");
		cin >> n;
		printf(" Введите элементы матрицы:\n");
		int maxn = 0;
		int* arr = new int[n * n];
		for (int i = 0; i < n * n; i++) {
			cin >> arr[i];
			maxn = max(maxn, arr[i]);
		}
		maxn = log10(maxn);
		int tmp;
		string str = "";
		printf(" Матрица:\n");
		for (int i = 0; i < n; i++) {
			str += " |";
			for (int j = 0; j < n; j++) {
				tmp = arr[j + i * n];
				str += to_string(tmp);
				if (j < n - 1)
					str += ", ";
				for (int k = 0; k < maxn - log10(tmp); k++)
					str += " ";
			}
			str += "|\n";
		}
		printf("%s",str.c_str());
		printf("\n Сумма диагональных элементов матрицы: %d", fun(arr));
		printf("\nПродолжить? (y/n)\n");
		cin >> answ;
		printf("\n");
	}
}

int fun(int* arr)
{

	int res = 0;
	__asm__ __volatile__(
		R"(mov eax, 0
		mov ebx, %1
		mov ecx, n
		mov edx, 0

		_loop:
		dec ecx
			js _end
			add eax, dword ptr[ebx + ecx * 4]
			sub ecx, edx
			jz _skip
			add eax, dword ptr[ebx + edx * 4]
			_skip:
		add ecx, edx
			add ebx, n
			add ebx, n
			add ebx, n
			add ebx, n
			inc edx
			jmp _loop
			_end :

		mov %0, eax
			)"
                                : "=r" (res), "r" (arr));
}


