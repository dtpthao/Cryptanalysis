#ifndef _LINEAR_H
#define _LINEAR_H

#include "common.hpp"

inline uchar popcount(uchar n) {
	return std::bitset<CHAR_BIT * sizeof n>(n).count();
}

float LineCryptAnalys(int cs[SIZE][SIZE]);

#endif // !_LINEAR_H

