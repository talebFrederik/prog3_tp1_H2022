#pragma once

#include <string>

class Membre
{
private:
	std::string m_prenom;
	std::string m_nom;
	std::string m_dateNaissance;
	std::string m_id;
public:
	Membre(std::string, std::string, std::string);
	std::string getId();
	std::string getNomComplet();
};

