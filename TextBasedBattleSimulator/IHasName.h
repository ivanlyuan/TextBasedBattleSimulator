#pragma once

#include<string>

using std::string;

class IHasName
{
public:
	string GetName();
protected:
	string name;
};