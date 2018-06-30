#include<iostream>
using namespace std;
#include<string>
//#include "Colors.h"
#include<fstream>
#include<iomanip>
#include <map>
#include "Instruction.h"
#include "R_Instructions.h"
#include "I_Instructions.h"

map<string, Instruction*> instructions;
 
void init() {
	//R Type
	instructions.insert(make_pair("00000000000110011", new Add));
	instructions.insert(make_pair("01000000000110011", new Sub));
	instructions.insert(make_pair("00000001110110011", new And));
	instructions.insert(make_pair("00000001100110011", new Or));
	instructions.insert(make_pair("00000001000110011", new Xor));
	instructions.insert(make_pair("00000000100110011", new Slt));
	instructions.insert(make_pair("00000000110110011", new Sltu));
	instructions.insert(make_pair("01000001010110011", new Sra));
	instructions.insert(make_pair("00000001010110011", new Srl));
	instructions.insert(make_pair("00000000010110011", new Sll));

	//I,S,B-types
	instructions.insert(make_pair("0000010011", new Addi));
	instructions.insert(make_pair("0100010011", new Slti));
	instructions.insert(make_pair("0110010011", new Sltiu));
	instructions.insert(make_pair("1000010011", new Xori));
	instructions.insert(make_pair("1100010011", new Ori));
	instructions.insert(make_pair("1110010011", new Andi));
	instructions.insert(make_pair("0010010011", new Slli));
	instructions.insert(make_pair("1010010011", new Srli));
	instructions.insert(make_pair("1010010011", new Srai));  
	instructions.insert(make_pair("0100000011", new Lw));


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
	if (op == "0110011") return (word.substr(0, 7) + word.substr(17, 3) + op);
	else if (op == "0110111" || op == "1101111") return op;
	return (word.substr(17, 3) + op);

}
void readFile(string filename) {
	ifstream inp;
	string c;
	inp.open(filename);
	if (!inp.fail()) {
		while (!inp.eof()) {
			getline(inp, c);
			auto i = instructions.find(Key(c)); //testing for map2
			if (i == instructions.end())
			//Will be replaced by Helper::emitError(..)
			cout << "Instruction undefined\n";
			else
			i->second->execute(c);

		}
	}


	inp.close();
}


int main() {

	registers[1] = 0;
	registers[2] = 2;
	init();

	//for testing
	memory.push_back(583 & 255);
	memory.push_back(583 & 65280);
	memory.push_back(583 & 16711680);
	memory.push_back(583 & 4278190080);


	string file = "Text.txt";

	readFile(file);

	system("pause");
	return 0;
}