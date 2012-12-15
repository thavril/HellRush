#include "Finder.h"

int			main(int ac, char **av)
{
	if (ac < 2)
		return 0;
	Finder		*finder = new Finder(av[1]);
	finder->start("mechant");
	finder->affTokens();

	return 0;
}