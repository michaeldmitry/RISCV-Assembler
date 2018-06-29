#include "Helper.h"
#include <string>
#pragma once
#ifndef _Instruction
#define _Instruction
int registers[32] = { 0 };

struct Instruction {
	std::string type;
	std::string name;
	int rs1;
	int rs2;
	int rd;
	int imm;
	int shift;
	int first7;
	void virtual execute(std::string word) = 0;
};
#endif // !_Instruction
