#include "Helper.h"
#include <string>
#pragma once
#ifndef _Instruction
#define _Instruction

struct Instruction {
	std::string type;
	std::string name;
	std::string operation;

	int rs1;
	int rs2;
	int rd;
	int imm;
	int shift;
	int first7;

	void execute(std::string word){
		/*
		cout << rang::style::bold << "Type:" << type << "\tName:" << name << endl;
		*/
		cout << word << endl;
		executeType(word);
		Helper::printRegisters(rs1, rs2, rd);
	}
	void virtual executeType(std::string word) = 0;
};
#endif // !_Instruction
