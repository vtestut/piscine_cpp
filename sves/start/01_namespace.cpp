#include <stdio.h>
#include <iostream>

int global = 1;
int func(void) { return 111; }

namespace Foo {
	int     global = 2;
	int     func( void ) { return 222; }
}

namespace Bar {
	int     global = 5;
	int     func( void ) { return 555; }
}

namespace Muf = Bar;

int main (void)
{
	printf("global		=	[%d]\n", ::global);
	printf("func()		=	[%d]\n\n", ::func());

	printf("Foo::global	=	[%d]\n", Foo::global);
	printf("Foo::func()	=	[%d]\n\n", Foo::func());

	printf("Bar::global	=	[%d]\n", Bar::global);
	printf("Bar::func()	=	[%d]\n\n", Bar::func());

	printf("Muf::global	=	[%d]\n", Muf::global);
	printf("Muf::func()	=	[%d]\n", Muf::func());

	printf("_______________________________\n\n");

	char	cin_buffer[255];

	std::cout << "Meme chose mais avec iostream\n" << std::endl;

	std::cout << "global		= 	[" << global << "]\n";
	std::cout << "func()		= 	[" << func() << "]\n\n";

	std::cout << "Foo::global	= 	[" << Foo::global << "]\n";
	std::cout << "Foo::func()	= 	[" << Foo::func() << "]\n\n";

	std::cout << "Bar::global	= 	[" << Bar::global << "]\n";
	std::cout << "Bar::func()	= 	[" << Bar::func() << "]\n\n";

	std::cout << "Muf::global	= 	[" << Muf::global << "]\n";
	std::cout << "Muf::func()	= 	[" << Muf::func() << "]\n\n";

	std::cout << "________________________________\n\n";

	std::cout << "choose between 1 & 2 : ";
	std::cin >> cin_buffer;
	std::cout << "\nyou chosed : " << cin_buffer << "\n\n";

	if (*cin_buffer == '1')
		return (std::cout << "Failed" << std::endl << std::endl, 0);
	else if (*cin_buffer == '2')
		return (std::cout << "Won" << "\n\n", 0);
	else
		return std::cout << "Cheater\n\n" , 1;
	return 0;
}