#include "Differential.hpp"
#include "Linear.hpp"

void printTable(int es[SIZE][SIZE])
{
	const int sub = 16;
	for (int i = sub, a; i <= SIZE; i += sub) {
		for (int j = sub, b = 0; j <= SIZE; j += sub) {
			printf("    |");
			for (b = j - sub; b < j; b++) printf(" %3X", b);
			cout << endl;
			printf("____|");
			for (b = j - sub; b < j; b++) printf("____");
			cout << endl;
			for (a = i - sub; a < i; a++) {
				printf("%3X |", a);
				for (b = j - sub; b < j; b++)
					printf(" %3d", es[a][b]);
				cout << endl;
			}
			cout << endl;
		}
		//cout << endl << endl;
	}
}

int main()
{
	int es[SIZE][SIZE] = { 0 };
	int cs[SIZE][SIZE] = { 0 };
	float pDmax, pLmax;
	pDmax = DiffCryptAnalys(es);
	pLmax = LineCryptAnalys(cs);
	//printTable(es);
	//printTable(cs);
	printf("pDmax = %f\n", pDmax);
	printf("pLmax = %f\n", pLmax);

	system("pause");
	return 0;
}