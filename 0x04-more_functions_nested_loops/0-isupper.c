#include "main.h"

/**
 * Main - check uppercase charater
 * _isupper - uppercase letters
 *
 * Return 0
 */

int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}
