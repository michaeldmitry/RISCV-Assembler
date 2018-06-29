#include "Instruction.h"
#pragma once
#ifndef R_Ins
#define R_Ins
struct R_Instruction :  Instruction {
	R_Instruction() { type = "R Type Instruction"; }
	void execute(std::string word) {
		//For Testing
		//cout << type;
		rs1 = Helper::Decimal(word.substr(12, 5));
		rs2 = Helper::Decimal(word.substr(7, 5));
		rd = Helper::Decimal(word.substr(20, 5));

		perform();
	}
	void virtual perform() = 0;
};
#endif // !R_Ins

struct Add :  R_Instruction {
	Add() { name = "ADD"; }
	void perform() {
		
		cout << "add x" << rd << ", x" << rs1 << ", x" << rs2 << endl;
		registers[rd] = registers[rs1] + registers[rs2];
	}
};
struct Sub : R_Instruction {
	Sub() { name = "SUB"; }
	void perform() {
		cout << "sub x" << rd << ", x" << rs1 << ", x" << rs2 << endl;
		registers[rd] = registers[rs1] - registers[rs2];
	}
};

struct And : R_Instruction {
	And() { name = "AND"; }
	void perform() {
		registers[rd] = registers[rs1] & registers[rs2];
		cout << "and x" << rd << ", x" << rs1 << ", x" << rs2 << endl;
	}
};

struct Or : R_Instruction {
	Or() { name = "OR"; }
	void perform() {
		registers[rd] = registers[rs1] | registers[rs2];
		cout << "or x" << rd << ", x" << rs1 << ", x" << rs2 << endl;
	}
};

struct Xor : R_Instruction {
	Xor() { name = "XOR"; }
	void perform() {
		registers[rd] = registers[rs1] ^ registers[rs2];
		cout << "xor x" << rd << ", x" << rs1 << ", x" << rs2 << endl;
	}
};

struct Slt : R_Instruction {
	Slt() { name = "SLT"; }
	void perform() {
		registers[rd] = registers[rs1] < registers[rs2];
		cout << "slt x" << rd << ", x" << rs1 << ", x" << rs2 << endl;
	}
};

struct Sltu : R_Instruction {
	Sltu() { name = "SLTU"; }
	void perform() {
		registers[rd] = abs(registers[rs1]) < abs(registers[rs2]);
		cout << "sltu x" << rd << ", x" << rs1 << ", x" << rs2 << endl;
	}
};

struct Sra : R_Instruction {
	Sra() { name = "SRA"; }
	void perform() {
		if (registers[rs2] <= 31)
			registers[rd] = registers[rs1] >> registers[rs2];
		else
			registers[rd] = registers[rs1] >> 31;  //wrong

		cout << "sra x" << rd << ", x" << rs1 << ", x" << rs2 << endl;
	}
};

struct Srl : R_Instruction {
	Srl() { name = "SRL"; }
	void perform() {
		if (registers[rs2] <= 31)
			registers[rd] = registers[rs1] >> registers[rs2];
		else
			registers[rd] = registers[rs1] >> 31;  //wrong

		cout << "srl x" << rd << ", x" << rs1 << ", x" << rs2 << endl;
	}
};

struct Sll : R_Instruction {
	Sll() { name = "SLL"; }
	void perform() {
		if (registers[rs2] <= 31)
			registers[rd] = registers[rs1] << registers[rs2];
		else
			registers[rd] = registers[rs1] << 31;  //wrong

		cout << "sll x" << rd << ", x" << rs1 << ", x" << rs2 << endl;
	}
};
