//============================================================================
// Name        : externaltests.cpp
// Author      : Davi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>     // std::cout
#include <limits>
#include <stdio.h>// std::numeric_limits

extern "C"{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

lua_State *L;

int luaSum (int x, int y){

	lua_getglobal(L,"add");


	lua_pushnumber(L,x);


	lua_pushnumber(L,y);

	//std::cout<< "hi";
	//call the function with 2 arguments, return 1 result
	lua_call(L, 2, 1);

	int sum =0;
	sum=(int)lua_tointeger(L ,-1);
	lua_pop(L,1);

	return sum;
}
int main (int argc , char *argv[]) {

		//Hello world
	 	 //initialize Lua
		lua_State* _state;

		_state = luaL_newstate();

		// load Lua base libraries
		luaL_openlibs(_state);

		// run the script
		luaL_dofile(_state, "test.lua");

		// cleanup Lua
		lua_close(_state);

		//Adding numbers
		L = luaL_newstate();
		luaL_openlibs(L);
		luaL_dofile(L,"sumNumbers.lua");
		int sum = luaSum(3,8);

		lua_close(L);
		std::cout << sum << std::endl;

		return 0;
	}


