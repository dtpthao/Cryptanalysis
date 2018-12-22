#include "Differential.hpp"


//es[a][b] = #{c in GF(2**m) | S(c xor a) xor S(c) = b}
float DiffCryptAnalys(int es[SIZE][SIZE])
{
	uint a, b, c, max = 0;
	es[0][0] = SIZE;
	for (a = 1; a < SIZE; a++) {
		for (c = 0; c < SIZE; c++) {
			b = Sbox[a ^ c] ^ Sbox[c];
			es[a][b] += 1;
			max = (max < es[a][b]) ? es[a][b] : max;
		}
	}
	cout << "maxes = " << max << endl;
	return (float)max / SIZE;
}


