#include "Util.h"

bool Util::integer_verifier(string string)
{
	int number;
	try
	{
		number = stoi(string);
		return true;
	}
	catch (const exception& e)
	{
		return false;
	}
}

bool Util::float_verifier(string string)
{
	float number;
	try
	{
		number = stof(string);
		return true;
	}
	catch (const exception& e)
	{
		return false;
	}
}

bool Util::mark_position_verifier(string string)
{
	int number;
	try
	{
		number = stoi(string);
		return number > 0 && number < 4 ;
	}
	catch (const exception& e)
	{
		return false;
	}
}

bool Util::mark_verifier(string string)
{
	for (int i = 0; i >= string.size(); ++i)
	{
		if(string[i] == ',')
		{
			return false;
		}
	}

	float number;
	try
	{
		number = stof(string);
		return number >=1 && number <=7;
	}
	catch (const exception& e)
	{
		return false;
	}
}

bool Util::rut_validator(string rut)
{
	if(rut.size() == 12)
	{
		const regex expReg("\\d{2}.\\d{3}.\\d{3}-[K-K-k-k-z0-9]");
		return regex_match(rut, expReg);
	}
	if(rut.size() == 11)
	{
		const regex expReg("\\d{1}.\\d{3}.\\d{3}-[K-K-k-k-z0-9]");
		return regex_match(rut, expReg);
	}
	return false;
}

string Util::strip(string message)
{
	message.erase(remove_if(message.begin(),
		message.end(), ::isspace), message.end());
	return message;
}

string Util::to_upper_case(string message)
{
	transform(message.begin(), message.end(), message.begin(), ::toupper);
	return message;
}

float Util::approximation(float value)
{
	return (abs(trunc(value * 10) - value * 10) < 0.5 ? trunc(value * 10) : trunc(value * 10) + 1) / 10;
}

float Util::approximation(float value, int multiplier)
{
	return (abs(trunc(value * multiplier) - value * multiplier) < 0.5 ? trunc(value * multiplier)
		: trunc(value * multiplier) + 1) / multiplier;
}

void Util::timer(int seconds)
{
	Sleep(seconds * 1000);
}