#include "Instruction.h"
#pragma once
#ifndef R_Ins
#define R_Ins
struct R_Instruction :  Instruction {
	R_Instruction() { type = "R Type Instruction"; }
	void execute(std::string word) {
		//For Testing
		cout << type;
		rs1 = Helper::Decimal(word.substr(12, 4));
		rs2 = Helper::Decimal(word.substr(7, 4));
		rd = Helper::Decimal(word.substr(20, 4));
		perform();
	}
	void virtual perform() = 0;
};
#endif // !R_Ins

struct Add :  R_Instruction {
	Add() { name = "ADD"; }
	void perform() {
		//For Testing
		cout << name << endl;
		registers[rd] = registers[rs1] + registers[rs2];
	}
};
