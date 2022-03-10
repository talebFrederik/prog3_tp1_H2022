#pragma once

#include <string>
#include <deque>

class FileMessage
{
private:
	std::string m_ids[2];
	std::deque<std::string> m_messages;
public:
	FileMessage();
	bool isFileMessage(std::string&, std::string&);
	void AfficherMessages();
};

