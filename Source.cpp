#include<iostream>
using namespace std;
#include<string>
#include<fstream>
#include<iomanip>
#include <map>
#include "Instruction.h"
#include "R_Instructions.h"


map<string, Instruction*> instructions;
void init() {
	//R Type
	instructions.insert(make_pair("000000000110011", new Add));


}


//void executeRFuntion(int n,int rs1,int rs2,int rd)
//{
//	if (n == 0) //add
//	{
//		registers[rd] = registers[rs1] + registers[rs2];
//		cout << "add $" <<rd<<", $"<<rs1<<", $"<<rs2<< endl;
//	}
//	else if (n == 256)//sub
//	{
//		registers[rd] = registers[rs1] - registers[rs2];
//		cout << "sub $" << rd << ", $" << rs1 << ", $" << rs2 << endl;
//	}
//	else if (n == 7)//and
//	{
//		registers[rd] = registers[rs1] & registers[rs2];
//		cout << "and $" << rd << ", $" << rs1 << ", $" << rs2 << endl;
//	}
//
//	else if (n == 6)//or
//	{
//		registers[rd] = registers[rs1] | registers[rs2];
//		cout << "or $" << rd << ", $" << rs1 << ", $" << rs2 << endl;
//	}
//
//	else if (n == 4)//xor
//	{
//		registers[rd] = registers[rs1] ^ registers[rs2];
//		cout << "xor $" << rd << ", $" << rs1 << ", $" << rs2 << endl;
//	}
//	else if (n == 2)//slt
//	{
//		registers[rd] = registers[rs1] < registers[rs2];
//		cout << "slt $" << rd << ", $" << rs1 << ", $" << rs2 << endl;
//	}
//	else if (n == 3)//sltu
//	{
//		registers[rd] = abs(registers[rs1]) < abs(registers[rs2]);
//		cout << "sltu $" << rd << ", $" << rs1 << ", $" << rs2 << endl;
//	}
//	else if (n == 261)//sra
//	{
//		if (registers[rs2]<=31)
//		registers[rd] = registers[rs1] >> registers[rs2];
//		else
//		registers[rd] = registers[rs1] >> 31;
//
//		cout << "sra $" << rd << ", $" << rs1 << ", $" << rs2 << endl;
//	}
//	else if (n == 5)//srl
//	{
//		if (registers[rs2] <= 31)
//		registers[rd] = registers[rs1] >> registers[rs2];
//		else
//		registers[rd] = registers[rs1] >> 31;
//
//		cout << "srl $" << rd << ", $" << rs1 << ", $" << rs2 << endl;
//	}
//	else if (n == 1)//sll
//	{
//		if (registers[rs2] <= 31)
//			registers[rd] = registers[rs1] << registers[rs2];
//		else
//			registers[rd] = registers[rs1] << 31;
//
//		cout << "sll $" << rd << ", $" << rs1 << ", $" << rs2 << endl;
//	}
//	else if (n == 8)//mul
//	{
//		registers[rd] = registers[rs1] * registers[rs2];
//		cout << "mul $" << rd << ", $" << rs1 << ", $" << rs2 << endl;
//	}
//
//
//	for (int i = 0; i < 32; i++)
//		cout << "x" << i <<setw(7)<< registers[i] << endl;
//	cout << "-------------------------------------------------------------------" << endl;
//}

//void divideR(string word)
//{
//	string op, rs1, rs2, rd, funct3, funct7;
//	string fun;
//	int opD, rs1D, rs2D, rdD, funct3D, funct7D;
//	int funD;
//
//	op = word.substr(25, 7);
//	rs1 = word.substr(12, 5);
//	rs2 = word.substr(7, 5);
//	rd = word.substr(20, 5);
//	funct3 = word.substr(17, 3);
//	funct7 = word.substr(0, 7);
//	fun =  funct7+funct3 ;
//
//	opD=toDecimal(op);
//	rs1D=toDecimal(rs1);
//	rs2D=toDecimal(rs2);
//	rdD=toDecimal(rd);
//	funD=toDecimal(fun);
//
//	executeRFuntion(funD, rs1D, rs2D, rdD);
//
//}
//void whichFormat(string word)
//{
//	string op;
//	op = word.substr(25, 7);
//
//	if (op == "0110011")
//		divideR(word);
//	//else if (op == "000011" || op == "000010")
//		//divideJ(word);
//	//else
//		//divideI(word);
//
//}

string Key(string word) {
	string op = word.substr(25, 7);
	if (op == "0110011") return (word.substr(0, 6) + word.substr(17, 2) + op);
	else if (op == "0110111" || op == "1101111") return op;
	return (word.substr(12, 2) + op);
}
void readFile(string filename) {
	ifstream inp;
	string c;
	inp.open(filename);
	if (!inp.fail()) {
		while (!inp.eof()) {
			getline(inp, c);
			auto i = instructions.find(Key(c));
			if (i == instructions.end())
				//Will be replaced by Helper::emitError(..)
				cout << "Instruction undefined\n";
			else
			i->second->execute(c.substr(6, 26));
		}
	}
	inp.close();
}


int main() {
	/*registers[1] = -60;
	registers[2] = 2;*/

	init();
	string file = "text.txt";
	readFile(file);

	system("pause");
	return 0;
}