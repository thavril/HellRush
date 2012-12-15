
#include <string>
#include <iostream>
#include "FunctionSignature.hpp"

int		funct1()
{
  std::cout << "function 1" << std::endl;
  return 1;
}

int		funct2(std::string const & value)
{
  std::cout << "funct2, value = " << value << std::endl;
  return 2;
}

int		funct3(std::string const & value, int nb)
{
  std::cout << "funct3, value = " << value << " nb = " << nb << std::endl;
  return 3;
}

int		funct4(std::string const & value, int nb, float nb2)
{
  std::cout << "funct4, value = " << value << " nb " << nb << " nb2 = " << nb2 << std::endl;
  return 4;
}

int		funct5(std::string const & value, std::string const & value2, int nb, float nb2)
{
  std::cout << "funct5, value = " << value << " value2 " << value2 << " nb " << nb << " nb2 " << nb2;
  return 5;
}

int		funct6(std::string const & value, std::string const & value2, std::string const & value3, int nb, int nb2, float nb3)
{
  std::cout << "funct fatal 6, value " << value << " value2 = " << value2 << " value3 = " << value3 << " nb " << nb << " nb2 " << nb2 << " nb3 " << nb3;
  return 6;
}

int		main()
{
  FunctionSignature<int ()>::type v = &funct1;
  FunctionSignature<int (std::string const &)>::type v2 = &funct2;
  FunctionSignature<int (std::string const &, int)>::type v3 = &funct3;
  FunctionSignature<int (std::string const &, int, float)>::type v4 = &funct4;
  FunctionSignature<int (std::string const &, std::string const &, int, float)>::type v5 = &funct5;
  FunctionSignature<int (std::string const &, std::string const &, std::string const &, int, int, float)>::type v6 = &funct6;
  
  std::cout << v() << std::endl;
  std::cout << v2("toto") << std::endl;
  std::cout << v3("toto", 5) << std::endl;
  std::cout << v4("toto", 5, 25.5) << std::endl;
  std::cout << v5("toto", "tata", 5, 25.5) << std::endl;
  std::cout << v6("toto", "tata", "titi", 5, 6, 25.5) << std::endl;
  return (0);
}
