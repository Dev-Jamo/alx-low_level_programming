#include "main.h"

/**
 * clear_bit - sets the value of a given bit to 0
 * @n: points to the number
 * @index: index of the bit to clear
 *
 * Return: 1 if it works, or -1 if there's an error
 */
int clear_bit(unsigned long int *n, unsigned int index)
{

	if (index > 63)
		return (-1);

	*n = (~(1UL << index) & *n);
	return (1);
}
