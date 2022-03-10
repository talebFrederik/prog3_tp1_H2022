#pragma once

#include "Membre.h"

#include <string>
#include <deque>

struct Message
{
	Membre* de{};
	std::string message{};
};

class FileMessage
{
private:
	Membre* m_membres[2];
	std::deque<Message> m_messages;
public:
	FileMessage(Membre*, Membre*);
	bool isFileMessage(const std::string&,const std::string&);
	void recevoirMessage(Membre*, std::string);
	void AfficherMessages();
};

