#pragma once
#include "Instruction.h"
#pragma once
#ifndef I_Ins
#define I_Ins
struct I_Instruction : Instruction {
	I_Instruction() { type = "I Type Instruction"; }
	void execute(std::string word) {
		rs1 = Helper::Decimal(word.substr(15, 4));
		rd = Helper::Decimal(word.substr(7, 4));
		imm = Helper::Decimal(word.substr(0, 12));
		perform();
	}
	void virtual perform() = 0;
};
#endif // !R_Ins

struct Addi : I_Instruction {
	Addi() { name = "ADD Immediate"; }
	void perform() {
		registers[rd] = registers[rs1] + imm;
	}
};
