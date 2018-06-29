#include "Instruction.h"
#pragma once
#ifndef R_Ins
#define R_Ins
struct R_Instruction :  Instruction {
	R_Instruction() { type = "R Type Instruction"; }
	void executeType(std::string word) {
		cout << left << rang::bg::cyan << setw(7) << "Fn7";
		cout << rang::bg::yellow << setw(5) << "RS2";
		cout << rang::bg::magenta << setw(5) << "RS1";
		cout << rang::bg::cyan << setw(3) << "Fn3";
		cout << rang::bg::red << setw(5) << "RD";
		cout << rang::bg::green << setw(6) << "Op-Code\n" << rang::bg::reset;

		rs1 = Helper::Decimal(word.substr(12, 5));
		rs2 = Helper::Decimal(word.substr(7, 5));
		rd = Helper::Decimal(word.substr(20, 5));
		cout << "RV32IC instruction: " << operation << " x" << rd << ", x" << rs1 << ", x" << rs2 << endl << endl;
		perform();
	}
	void virtual perform() = 0;
};
#endif // !R_Ins

struct Add : R_Instruction {
	Add() { name = "ADD"; operation = "add"; }
	void perform() {
		registers[rd] = registers[rs1] + registers[rs2];
	}
};
struct Sub : R_Instruction {
	Sub() { name = "SUB"; operation = "sub"; }
	void perform() {
		registers[rd] = registers[rs1] - registers[rs2];
	}
};

struct And : R_Instruction {
	And() { name = "AND"; operation = "and"; }
	void perform() {
		registers[rd] = registers[rs1] & registers[rs2];
	}
};

struct Or : R_Instruction {
	Or() { name = "OR"; operation = "or"; }
	void perform() {
		registers[rd] = registers[rs1] | registers[rs2];
	}
};

struct Xor : R_Instruction {
	Xor() { name = "XOR"; operation = "xor"; }
	void perform() {
		registers[rd] = registers[rs1] ^ registers[rs2];
	}
};

struct Slt : R_Instruction {
	Slt() { name = "SLT"; operation = "slt"; }
	void perform() {
		registers[rd] = registers[rs1] < registers[rs2];
	}
};

struct Sltu : R_Instruction {
	Sltu() { name = "SLTU"; operation = "sltu"; }
	void perform() {
		registers[rd] = abs(registers[rs1]) < abs(registers[rs2]);
	}
};

struct Sra : R_Instruction {
	Sra() { name = "SRA"; operation = "sra"; }
	void perform() {
			registers[rd] = registers[rs1] >> (registers[rs2]& 31);
	}
};

struct Srl : R_Instruction {
	Srl() { name = "SRL"; operation = "srl"; }
	void perform() {
		registers[rd] = registers[rs1] >> (registers[rs2] & 31);
	}
		
};

struct Sll : R_Instruction {
	Sll() { name = "SLL"; operation = "sll"; }
	void perform() {
			registers[rd] = registers[rs1] << (registers[rs2]&31);

	}
};
