#include <string>
#pragma once
#ifndef HelperClass
int registers[32] = { 0 };

struct Helper {
	static int Decimal(std::string sub) {
		int decimalNumber = 0;
		int remainder;
		int j = 0;
		for (int i = sub.size() - 1; i >= 0; i--) {
			remainder = sub[i];
			remainder = remainder - 48;
			decimalNumber += (remainder*pow(2, j));
			j++;
		}
		return decimalNumber;
	}
	static void emitError(string error) {
		cout << error << endl;
		exit(-1);
	}
	static void printRegisters(int rs1, int rs2, int rd) {
		/*cout << rang::bg::green << "Op-Code\n";
		cout << rang::bg::magenta << "RS1\n";
		cout << rang::bg::yellow << "RS2\n";
		cout << rang::bg::red << "RD\n";
		cout << rang::bg::blue << "Immediate\n";
		cout << rang::bg::cyan << "Funct3\n";
		cout << rang::bg::gray << "Funct7\n";*/

		for (int i = 0; i < 32; i++) {
			if (i == rd)
				cout << rang::style::bold << rang::bg::red;
			else if (i == rs1)
				cout << rang::style::bold << rang::bg::magenta;
			else if (i == rs2)
				cout << rang::style::bold << rang::bg::yellow;
			else
				cout << rang::style::reset << rang::bg::reset;
			cout << "x" << setw(7) << i << setw(7) << registers[i] << endl;
		}

		cout << "------------------------------------------" << endl;
	}
};
#endif