#include "Finder.h"

Finder::Finder(char *str)
{
	_string = str;
	_nbOccurences = 0;
}

Finder::~Finder()
{
}

int			Finder::findLetter(char c)
{
	int i = _token.find(c);
	if (i == std::string::npos)
		i = EDGE_MAX - 1;
	return i;
}

void		Finder::changeState(eAction action, int pos)
{
	switch(action)
	{
		case(MA):
			_currentState = gStateTable[_currentState][pos];
			break;
		case(HR):
			_nbOccurences++;
			_currentState = S0;
			break;
		case(ACTION_ERROR):
			_currentState = S0;
			break;
	}
}

int			Finder::start(const char *token)
{
	_token = token;
	_currentState = S0;
	for (unsigned int i(0); i < _string.size(); i++)
	{
		_currentAction = gActionTable[_currentState][findLetter(_string[i])];
		changeState(_currentAction, findLetter(_string[i]));
		if (_currentAction == HR)
			i--;
	}
	_currentAction = gActionTable[_currentState][0];
	if (_currentAction == HR)
		_nbOccurences++;
	return 0;
}

void		Finder::affTokens()
{
	for (int i(0); i < _nbOccurences; i++)
		std::cout << _token << std::endl;
}