#pragma once
#include<iostream>
using namespace std;
#include "Instruction.h"
#pragma once
#ifndef I_Ins
#define I_Ins
struct I_Instruction : Instruction {
	I_Instruction() { type = "I Type Instruction"; }
	void execute(std::string word) {
		rs1 = Helper::Decimal(word.substr(12, 5));
		rd = Helper::Decimal(word.substr(20, 5));
		imm = Helper::Decimal(word.substr(0, 12));
		shift = Helper::Decimal(word.substr(7, 5));
		first7 = Helper::Decimal(word.substr(0, 7));
		perform();
	}
	void virtual perform() = 0;
};
#endif // !R_Ins

struct Addi : I_Instruction {
	Addi() { name = "ADD Immediate"; }
	void perform() {
		registers[rd] = registers[rs1] + imm;
		cout << "addi x" << rd << ", x" << rs1 << ", x" << imm << endl;

	}
};


struct Slti : I_Instruction {
	Slti() { name = "SLT Immediate"; }
	void perform() {
		registers[rd] = registers[rs1] < imm;
		cout << "slti x" << rd << ", x" << rs1 << ", x" << imm << endl;

	}
};

struct Sltiu : I_Instruction {
	Sltiu() { name = "SLTU Immediate"; }
	void perform() {
		registers[rd] = abs(registers[rs1]) < abs(imm);
		cout << "sltiu x" << rd << ", x" << rs1 << ", x" << imm << endl;

	}
};

struct Xori : I_Instruction {
	Xori() { name = "XORI Immediate"; }
	void perform() {
		registers[rd] = registers[rs1] ^ imm;
		cout << "xori x" << rd << ", x" << rs1 << ", x" << imm << endl;

	}
};

struct Ori : I_Instruction {
	Ori() { name = "ORI Immediate"; }
	void perform() {
		registers[rd] = registers[rs1] | imm;
		cout << "ori x" << rd << ", x" << rs1 << ", x" << imm << endl;

	}
};

struct Andi : I_Instruction {
	Andi() { name = "ANDI Immediate"; }
	void perform() {
		registers[rd] = registers[rs1] & imm;
		cout << "andi x" << rd << ", x" << rs1 << ", x" << imm << endl;

	}
};
struct Slli : I_Instruction {
	Slli() { name = "SLLI Immediate"; }
	void perform() {
			registers[rd] = registers[rs1] << shift;
		cout << "slli x" << rd << ", x" << rs1 << ", x" << imm << endl;
	}
};

struct Srli : I_Instruction {
	Srli() { name = "SRLI Immediate"; }
	void perform() {
		
			registers[rd] = registers[rs1] >> shift;
			if (first7 == 0)
		cout << "srli x" << rd << ", x" << rs1 << ", x" << imm << endl;
			else
				cout << "srai x" << rd << ", x" << rs1 << ", x" << imm << endl;

	}
};

struct Srai : I_Instruction {
	Srai() { name = "SRAI Immediate"; }
	void perform() {
		
			registers[rd] = registers[rs1] >> shift;
		cout << "srai x" << rd << ", x" << rs1 << ", x" << imm << endl;
	}
};
