#include "Membre.h"
#include "FileMessage.h"
#include "Relation.h"
#include "Reseau.h"

#include <iostream>

void testFile()
{
	Membre* fred = new Membre{ "Frederik", "Taleb", "761005" };
	Membre* carine = new Membre{ "Carine", "Croteau", "820310" };
	Membre* alexandre = new Membre{ "Alexandre", "Ouellet", "850614" };

	FileMessage messages{ fred, carine };

	bool test = messages.isFileMessage(fred->getId(), carine->getId());
	test = messages.isFileMessage(carine->getId(), fred->getId());
	test = messages.isFileMessage(fred->getId(), alexandre->getId());
	test = messages.isFileMessage(alexandre->getId(), fred->getId());

	messages.recevoirMessage(fred, "bonjour Carine");
	messages.recevoirMessage(carine, "hey Fred!");

	messages.AfficherMessages();

	delete fred;
	delete carine;
	delete alexandre;
}

void testRelation()
{
	Membre* fred = new Membre{ "Frederik", "Taleb", "761005" };
	Membre* carine = new Membre{ "Carine", "Croteau", "820310" };
	Membre* alexandre = new Membre{ "Alexandre", "Ouellet", "850614" };

	Relation relationsFred{ fred };
	relationsFred.ajouterLien(carine);
	relationsFred.ajouterLien(alexandre);

	bool test = relationsFred.isRelation(carine);

	relationsFred.supprimerLien(carine);

	test = relationsFred.isRelation(carine);

	relationsFred.supprimerLien(carine);
	relationsFred.supprimerLien(alexandre);

	delete fred;
	delete carine;
	delete alexandre;
}

int main()
{

}

