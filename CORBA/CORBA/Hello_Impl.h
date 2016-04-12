#pragma once
#include "interface.hh"

class Hello_impl : public POA_test::test2 {
public:
	virtual void say_hello();
};