#include <stdio.h>
#include "./libft/libft.h"
#include "ft_printf.h"

int	main(void)
{
	

	printf("%0d\n", -1234);	
	printf("%0x\n", 17);
	printf("%0f\n", 1.42);
	printf("%0X\n", 17);
	printf("%6u\n", 17);
	printf("%06u\n", 17);
	printf("%-6u\n", 17);
	printf("%.6u\n", 17);
	printf("%e\n", 1.42);
	printf("%#d\n", 42);
	printf("%.6e\n", 1.42);
	//printf("%#0x\n", 4);

	//char *s;
	//s = "qwer";
	//void *p;
	//p = 0;
	//ft_printf("%p\n", p);
	//printf("%p\n", p);
	//printf("%lu\n", sizeof(p));
	//ft_printf(" %%%% "); // is used to print a %% in printf");
	//write(1, "\n", 1);
	//write(1, "\n", 1);
	

	//printf(" %c ", '0');	
	//write(1, "\n", 1);
	//ft_printf(" %c ", '0');	
	//write(1, "\n", 1);
	//
	//printf(" %c ", '0' - 256);	
	//write(1, "\n", 1);
	ft_printf(" %c ", '0' - 256);	
	//write(1, "\n", 1);
	////
	//printf(" %c \n", '0' + 256);	
	//write(1, "\n", 1);
	//ft_printf(" %c \n", '0' + 256);	
	//write(1, "\n", 1);
	//
	//printf(" %c %c %c \n", '0', 0, '1' );	
	//write(1, "\n", 1);
	//ft_printf(" %c %c %c ", '0', 0, '1' );	
	//write(1, "\n", 1);

	//
	//printf(" %c %c %c ", ' ', ' ', ' ');	
	//write(1, "\n", 1);
	//ft_printf(" %c %c %c ", ' ', ' ', ' ');	
	//write(1, "\n", 1);

	//
	//printf(" %c", '0');	
	//write(1, "\n", 1);
	//ft_printf(" %c", '0');
	//write(1, "\n", 1);
}	
