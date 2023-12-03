holbertonschool-printf

main.h - header file where all function prototypes are stored.
_printf_sub_functs.c - c file where functions are written to write everything
_printf.c - c file where printf function is defined.

SYNOPSIS:
	int _printf(const char *format, ...);

DESCRIPTION:
	Formats input string and arguments and prints it.
	Returns the number of bytes printed.

	FORMATS:
		%%: prints '%'.
		%c: takes character as input.
		%s: takes string as input.
		%i: takes integer as input.
		%d: takes decimal as input.
		%b: converts input into binary. (W.I.P)

EXAMPLE:
	_printf("We %s 100%% sure.", "are");

	OUTPUT:
		We are 100% sure.
	
	RETURN VALUE:
		17

REPORTING BUGS:
	To report bugs, you can write to either Fuad Mammadov or Huseyn Israfilov on Slack.

AUTHORS:
	Huseyn Israfilov
	Fuad Mammadov
