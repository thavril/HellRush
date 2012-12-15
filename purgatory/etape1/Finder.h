#include "Machine.hpp"
#include <iostream>
#include <sstream>
#include <vector>

class		Finder
{
public:
	Finder(char *str);
	~Finder();
	int		start(const char *);
	int		findLetter(char);
	void	changeState(eAction, int);
	void	affTokens();
private:
	std::string		_string;
	int				_nbOccurences;
	std::string		_token;
	eState			_currentState;
	eAction			_currentAction;
};