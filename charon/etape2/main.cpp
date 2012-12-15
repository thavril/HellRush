//
// main.cpp for main in /home/najim-_m//projet/rush/charon/etape2
// 
// Made by mohamed najim-baby
// Login   <najim-_m@epitech.net>
// 
// Started on  Fri Dec 14 23:08:23 2012 mohamed najim-baby
// Last update Sat Dec 15 18:17:52 2012 mohamed najim-baby
//

#include <iostream>
#include <string>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include "Function.hpp"

class		Test
{
public:
  void		operator()(std::string const & v)
  {
    std::cout << "je suis la class Test, operator(), v = " << v << std::endl;
  }

};

void		function1_1paramet(std::string const & c)
{
  std::cout << "je suis la function1_1paramet c = " << c << std::endl;
}

void		function2_1paramet(std::string const & c)
{
  std::cout << "je suis la fonction2_1paramet 2 c = " << c << std::endl;
}

void		function1_2paramet(int v, float z)
{
  std::cout << "je suis la function1_2paramet v = " << v << " z = " << z << std::endl;
}

void		function3_0paramet()
{
  std::cout << "je suis function3_0paramet, je ne prend pas de parametre" << std::endl;
}

int		main()
{
  Function<void (std::string const &)> f = boost::bind(&function1_1paramet, _1);

  f("ca marche hehe");
  f = &function2_1paramet;
  f("toujours fonctionnel, bogoss et tout ca ...");

  Function<void (int v, float z)> f2 = &function1_2paramet;

  f2(10, 15.5);

  Test t;
  Function<void (std::string const &)> f3 = t;
  f3("lol");

  f3 = boost::bind(&Test::operator(), &t, "caller depuis boost encapsuler dans Function");
  f3("prout");

  // test de malade !
  Function<void ()> f4 = boost::bind(&function1_1paramet, "appel de functon encapsuler derriere boost avec parametre alors que Function n'en a pas hihi");

  f4();
  f4 = &function3_0paramet;
  f4();
}
