#include "FileMessage.h"
#include <deque>
#include <iostream>

FileMessage::FileMessage(Membre* membre1, Membre* membre2)
{
	m_membres[0] = membre1;
	m_membres[1] = membre2;
}

bool FileMessage::isFileMessage(const std::string& id1,const std::string& id2)
{
	return m_membres[0]->getId() == id1 && m_membres[1]->getId() == id2 ||
		m_membres[0]->getId() == id2 && m_membres[1]->getId() == id1;
}

void FileMessage::recevoirMessage(Membre* de, std::string message)
{
	m_messages.push_back({ de, message });
}

void FileMessage::AfficherMessages()
{
	system("CLS");
	std::deque<Message> temp_messages{ m_messages };
	while (!temp_messages.empty())
	{
		std::cout << temp_messages.front().de->getNomComplet() << " : " << temp_messages.front().message << "\n";
		temp_messages.pop_front();
	}
}
