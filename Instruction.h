#include "Helper.h"
#include <string>
#pragma once
#ifndef _Instruction
#define _Instruction
struct Instruction {
	int registers[32] = { 0 };
	std::string type;
	std::string name;
	int rs1;
	int rs2;
	int rd;
	int imm;
	void virtual execute(std::string word) = 0;
};
#endif // !_Instruction
