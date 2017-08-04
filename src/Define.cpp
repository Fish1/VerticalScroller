#include "Define.hpp"

bool g_debug = false;

const char * g_user = nullptr;

const char * g_pass = nullptr;

void setCredentials(std::string & username, std::string & password)
{
	char * user = new char[username.size() + 1];

	for(unsigned int index = 0; index < username.size(); ++index)
	{
		user[index] = username.at(index);
	}

	user[username.size()] = '\0';

	g_user = user;

	char * pass = new char[password.size() + 1];
	
	for(unsigned int index = 0; index < password.size(); ++index)
	{
		pass[index] = password.at(index);
	}

	pass[password.size()] = '\0';

	g_pass = pass;
}
