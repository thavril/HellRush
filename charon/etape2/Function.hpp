//
// Function.hpp for funct in /home/najim-_m//projet/rush/charon/etape2
// 
// Made by mohamed najim-baby
// Login   <najim-_m@epitech.net>
// 
// Started on  Fri Dec 14 22:57:38 2012 mohamed najim-baby
// Last update Sat Dec 15 18:16:17 2012 mohamed najim-baby
//

#include <iostream>


template<typename T>
class Function;

// gestion 0 parametre
template<typename Ret>
class Function<Ret()>
{
public:
  class IA
  {
  public:
    virtual Ret	operator()() = 0;
  };
  
  template<class X>
  class	A : public IA
  {
    typedef Ret (*type)();
  public:
    A(X x) : _ptr(x) {}
    
    Ret		operator()()
    {
      _ptr();
    }
  private:
    X _ptr;
  };
  
  template<typename X>
  Function(X x) : _f(NULL)
  {
    _f = new A<X>(x);
  }

  template<typename X>
  void		operator=(X x)
  {
    if (_f)
      delete _f;
    _f = new A<X>(x);
  }

  Ret		operator()()
  {
    return _f->operator()();
  }
private:
  IA		*_f;
};

// gestion 1 parametre
template<typename Ret, typename Arg1>
class Function<Ret(Arg1)>
{
public:
  class IA
  {
  public:
    virtual Ret	operator()(Arg1) = 0;
  };
  
  template<class X>
  class	A : public IA
  {
    typedef Ret (*type)(Arg1);
  public:
    A(X x) : _ptr(x) {}
    
    Ret		operator()(Arg1 v)
    {
      _ptr(v);
    }
  private:
    X _ptr;
  };
  
  template<typename X>
  Function(X x) : _f(NULL)
  {
    _f = new A<X>(x);
  }

  template<typename X>
  void		operator=(X x)
  {
    if (_f)
      delete _f;
    _f = new A<X>(x);
  }

  Ret		operator()(Arg1 v)
  {
    return _f->operator()(v);
  }
private:
  IA		*_f;
};

// gestion 2 parametre
template<typename Ret, typename Arg1, typename Arg2>
class Function<Ret(Arg1, Arg2)>
{
public:
  class IA
  {
  public:
    virtual Ret	operator()(Arg1, Arg2) = 0;
  };
  
  template<typename X>
  class	A : public IA
  {
    typedef Ret (*type)(Arg1, Arg2);
  public:
    A(X x) : _ptr(x) {}
    
    Ret		operator()(Arg1 v, Arg2 z)
    {
      _ptr(v, z);
    }
  private:
    X _ptr;
  };
  
  template<typename X>
  Function(X x) : _f(NULL)
  {
    _f = new A<X>(x);
  }

  template<typename X>
  void		operator=(X x)
  {
    if (_f)
      delete _f;
    _f = new A<X>(x);
  }

  Ret		operator()(Arg1 v, Arg2 z)
  {
    return _f->operator()(v, z);
  }
private:
  IA		*_f;
};

