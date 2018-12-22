#include "Linear.hpp"


//cs[a][b] = #{x in GF(2**m) | (W(x & a) + W(S(x) & b)) mod 2 == 0} - 2**(m-1)
float LineCryptAnalys(int cs[SIZE][SIZE])
{
	uint a, b, x, tmp;
	int max = -(SIZE >> 1);
	cs[0][0] = SIZE >> 1;
	for (a = 1; a < SIZE; a++) {
		for (b = 1; b < SIZE; b++) {
			cs[a][b] -= SIZE >> 1;
			for (x = 0; x < SIZE; x++) {
				tmp = popcount(x & a) + popcount(Sbox[x] & b);
				if (!(tmp & 1)) cs[a][b]++;
				max = (max < cs[a][b]) ? cs[a][b] : max;
			}
		}
	}
	cout << "maxcs = " << max << endl;
	return (float)max*max / (1 << (2 * (M - 1)));
}

