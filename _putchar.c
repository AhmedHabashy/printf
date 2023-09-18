#include "main.h"
/**
*_putchar - prints c on the screen
*@c: char to be printed
*Return: 1 on success , (-1) on fail
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}
