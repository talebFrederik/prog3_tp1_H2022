

#include <iostream>
#include "Membre.h"

int main()
{
	Membre fred{ "Frederik", "Taleb", "761005" };
	std::cout << fred.getId() << "\n" << fred.getNomComplet();
}

