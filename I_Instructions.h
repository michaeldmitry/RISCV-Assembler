#pragma once
#include<iostream>
using namespace std;
#include "Instruction.h"
#pragma once
#ifndef I_Ins
#define I_Ins
struct I_Instruction : Instruction {
	I_Instruction() { type = "I Type Instruction"; }
	void executeType(std::string word) {
		rs1 = Helper::Decimal(word.substr(12, 5));
		rd = Helper::Decimal(word.substr(20, 5));
		if (word[0] == '1')
		{
			imm = Helper::Decimal(Helper::toNeg(word.substr(0, 12)));
			imm = imm*-1;
			shift = Helper::Decimal(Helper::toNeg(word.substr(7, 5)));
			shift = shift*-1;
		}
		else
		{
			imm = Helper::Decimal(word.substr(0, 12));
			shift = Helper::Decimal((word.substr(7, 5)));
		}
		first7 = Helper::Decimal(word.substr(0, 7));
	//	cout << "RV32IC instruction: " << operation << " x" << rd << ", x" << rs1 << ", " << imm << endl << endl;
		perform();
	}
	void virtual perform() = 0;
};
#endif // !R_Ins

struct Addi : I_Instruction {
	Addi() { name = "ADD Immediate"; operation = "addi"; }
	void perform() {
		registers[rd] = registers[rs1] + imm;
		cout << "RV32IC instruction: " << operation << " x" << rd << ", x" << rs1 << ", " << imm << endl << endl;

	}
};


struct Slti : I_Instruction {
	Slti() { name = "SLT Immediate"; operation = "slti"; }
	void perform() {
		registers[rd] = registers[rs1] < imm;
			cout << "RV32IC instruction: " << operation << " x" << rd << ", x" << rs1 << ", " << imm << endl << endl;

	}
};

struct Sltiu : I_Instruction {
	Sltiu() { name = "SLTU Immediate"; operation = "sltui"; }
	void perform() {
		registers[rd] = abs(registers[rs1]) < abs(imm);
		cout << "RV32IC instruction: " << operation << " x" << rd << ", x" << rs1 << ", " << imm << endl << endl;

	}
};

struct Xori : I_Instruction {
	Xori() { name = "XOR Immediate"; operation = "xori"; }
	void perform() {
		registers[rd] = registers[rs1] ^ imm;
		cout << "RV32IC instruction: " << operation << " x" << rd << ", x" << rs1 << ", " << imm << endl << endl;

	}
};

struct Ori : I_Instruction {
	Ori() { name = "OR Immediate"; operation = "ori"; }
	void perform() {
		registers[rd] = registers[rs1] | imm;
		cout << "RV32IC instruction: " << operation << " x" << rd << ", x" << rs1 << ", " << imm << endl << endl;

	}
};

struct Andi : I_Instruction {
	Andi() { name = "AND Immediate"; operation = "andi"; }
	void perform() {
		registers[rd] = registers[rs1] & imm;
		cout << "RV32IC instruction: " << operation << " x" << rd << ", x" << rs1 << ", " << imm << endl << endl;


	}
};
struct Slli : I_Instruction {
	Slli() { name = "SLL Immediate"; operation = "slli"; }
	void perform() {
			registers[rd] = registers[rs1] << shift;
			cout << "RV32IC instruction: " << operation << " x" << rd << ", x" << rs1 << ", " << shift << endl << endl;

	}
};

struct Srli : I_Instruction {
	Srli() { name = "SRL Immediate"; operation = "srli"; }
	void perform() {
		
			registers[rd] = registers[rs1] >> shift;
			if (first7 == 0)
		cout << "srli x" << rd << ", x" << rs1 << ", " << shift << endl;
			else
				cout << "srai x" << rd << ", x" << rs1 << ", " << shift << endl;

	}
};

struct Srai : I_Instruction {
	Srai() { name = "SRAI Immediate"; operation = "srai"; }
	void perform() {
		
			registers[rd] = registers[rs1] >> shift;
			cout << "RV32IC instruction: " << operation << " x" << rd << ", x" << rs1 << ", " << shift << endl << endl;

	}
};

struct Lw : I_Instruction {
	Lw() { name = "LOAD WORD"; operation = "lw"; }
	void perform() {
		registers[rd] = memory[registers[rs1]+imm];
		for (int i = 1; i < 4;i++)
			registers[rd] += memory[registers[rs1] + imm+i];
		cout << "RV32IC instruction: " << operation << " x" << rd << ", " << imm << "(x" << rs1 << ")"<< endl;

	}
};