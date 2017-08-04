#ifndef DEFINE_HPP
#define DEFINE_HPP

#include <string>

extern bool g_debug;

extern const char * g_user;

extern const char * g_pass;

void setCredentials(std::string & username, std::string & password);

#endif
