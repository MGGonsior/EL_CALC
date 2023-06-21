///////////////////////////////////////////////////////////
// Console.cpp - file containing all methods of 
// handling user interface and commands in
// electronics calculator
// 
// Mateusz Gasiorowski - AGH student
// Study subject: Jezyki Programowania
// 
///////////////////////////////////////////////////////////

using namespace std;
#include "Console.h"


Number ValueA;
Number ValueB;
Number ValueM;
Number lastAnswer;
bool datatype = 0;

///////////////////////////////////////////////////////////
// Menu console function 
// - Shows short description about all options
///////////////////////////////////////////////////////////
void  ConsoleMenu() 
{
	cout << "**************************************\n";
	cout << "*     Calculator for electronics     *\n";
	cout << "**************************************\n";
	cout << "* Choose number system:\n   'B' - BIN  'O' - OCT\n   'D' - DEC  'H' - HEX\n";
	cout << "* Choose data type: 'F' - Float 'I' - Integers (separete A,B,M)\n";
	cout << "* Write/read value A or B:\n   'A=' or 'B=' ('Number' or 'M'(emory) or 'ANS'(wer))\n";
	cout << "* Save in M(emory):\n   'M+' or 'M-'\n";
	cout << "* Read/Clear M(emory): 'M' / 'MCLR'\n";
	cout << "* Math:\n   '1' A+B  '2' A-B\n";
	cout << "   '3' A*B  '4' A/B\n";
}
///////////////////////////////////////////////////////////
//  Function to set number system
///////////////////////////////////////////////////////////
//		
// INPUT:
//		Nsys - name of number system as NumberSystem enum
// OUTPUT:
//		void
void ValuesSetSystem(NumberSystem Nsys)
{
	ValueA.SetDefNumSystem(Nsys);
	ValueB.SetDefNumSystem(Nsys);
	ValueM.SetDefNumSystem(Nsys);
	lastAnswer.SetDefNumSystem(Nsys);
}

///////////////////////////////////////////////////////////
//  Function to set all numbers type 
//  - Integral of floating point
///////////////////////////////////////////////////////////
//		
// INPUT:
//		in - 0 (integer) or 1 (floating point) 
// OUTPUT:
//		void
void ValuesSetDataType(bool in)
{
	ValueA.SetDataType(in);
	ValueB.SetDataType(in);
	ValueM.SetDataType(in);
	lastAnswer.SetDataType(in);
}

///////////////////////////////////////////////////////////
//  Shows a error code name as string
///////////////////////////////////////////////////////////
//		
// INPUT:
//		code - error number
// OUTPUT:
//		Name of error code
string ErrorHandling(ANSWER_CODE_T code)
{
	switch (code)
	{
	case ANSWER_CODE_NAN:
		return "NotAnNumber\n";
		break;
	case ANSWER_CODE_NIN:
		return "NotIntegerNumber\n";
		break;
	case ANSWER_CODE_RANGE:
		return "OverRange\n";
		break;
	}
	return "ERR\n";
}

///////////////////////////////////////////////////////////
//  Runs console-type UI
///////////////////////////////////////////////////////////
void RunConsole()
{
	string strinput = "";
	ConsoleMenu();
	while (1)
	{
		cout << "> ";
		cin >> strinput;
		if (strinput == "B" || strinput == "b")
		{
			if (datatype == 0)
			{
				ValuesSetSystem(Bin);
				cout << "Selected system: BIN\n";
				cout << "A=" << ValueA.GetDef() << "   B=" << ValueB.GetDef() << endl;
			}
			else
				cout << "Not float number system";
		}
		else if (strinput == "O" || strinput == "o")
		{
			if (datatype == 0)
			{
				ValuesSetSystem(Oct);
				cout << "Selected system: OCT\n";
				cout << "A=" << ValueA.GetDef() << "   B=" << ValueB.GetDef() << endl;
			}
			else
				cout << "Not float number system";
		}
		else if (strinput == "D" || strinput == "d")
		{
			ValuesSetSystem(Dec);
			cout << "Selected system: DEC\n";
			cout << "A=" << ValueA.GetDef() << "   B=" << ValueB.GetDef() << endl;
		}
		else if (strinput == "H" || strinput == "h")
		{
			ValuesSetSystem(Hex);
			cout << "Selected system: HEX\n";
			cout << "A=" << ValueA.GetDef() << "   B=" << ValueB.GetDef() << endl;
		}
		else if (strinput == "F" || strinput == "f")
		{
			datatype = 1;
			ValuesSetDataType(1);
			if ( ( lastAnswer.GetSystem() != Hex ) || ( lastAnswer.GetSystem() != Dec ) )
				ValuesSetSystem(Dec);
			cout << "Selected NumType: Floats\nCompatible number systems: DEC HEX\n";
			cout << "A=" << ValueA.GetDef() << "   B=" << ValueB.GetDef() << endl;
		}
		else if (strinput == "I" || strinput == "i")
		{
			datatype = 0;
			ValuesSetDataType(0);
			cout << "Selected NumType: Integers\nCompatible all number systems\n";
			cout << "A=" << ValueA.GetDef() << "   B=" << ValueB.GetDef() << endl;
		}
		else if (strinput == "A=M" || strinput == "a=m")
		{
			ANSWER_CODE_T response;
			response = ValueA.WriteDef(ValueM.GetDef());
			if (response == ANSWER_CODE_OK)
			{
				cout << "A=" << ValueA.GetDef() << endl;
			}
			else
			{
				cout << ErrorHandling(response);
			}
		}
		else if (strinput == "B=M" || strinput == "b=m")
		{
			ANSWER_CODE_T response;
			response = ValueB.WriteDef(ValueM.GetDef());
			if (response == ANSWER_CODE_OK)
			{
				cout << "B=" << ValueB.GetDef() << endl;
			}
			else
			{
				cout << "ERROR: " << ErrorHandling(response);
			}
		}
		else if (strinput == "A=ANS" || strinput == "a=ans")
		{
			ANSWER_CODE_T response;
			response = ValueA.WriteDef(lastAnswer.GetDef());
			if (response == ANSWER_CODE_OK)
			{
				cout << "A=" << ValueA.GetDef() << endl;
			}
			else
			{
				cout << ErrorHandling(response);
			}
		}
		else if (strinput == "B=ANS" || strinput == "b=ans")
		{
			ANSWER_CODE_T response;
			response = ValueB.WriteDef(lastAnswer.GetDef());
			if (response == ANSWER_CODE_OK)
			{
				cout << "B=" << ValueB.GetDef() << endl;
			}
			else
			{
				cout << "ERROR: " << ErrorHandling(response);
			}
		}
		else if (strinput == "A=" || strinput == "a=")
		{
			cout << "A=" << ValueA.GetDef() << endl;
		}
		else if (strinput == "B=" || strinput == "b=")
		{
			cout << "B=" << ValueB.GetDef() << endl;
		}
		else if ( (strncmp(strinput.c_str(), "A=", 2) == 0 ) || ( strncmp(strinput.c_str(), "a=", 2) == 0) )
		{
			strinput.erase(0,2);
			ANSWER_CODE_T response;
			response = ValueA.WriteDef(strinput);
			if (response == ANSWER_CODE_OK)
			{
				cout << "A=" << ValueA.GetDef() << endl;
			}
			else
			{
				cout << "ERROR: " << ErrorHandling(response);
			}
		}
		else if ( (strncmp(strinput.c_str(), "B=", 2) == 0 ) || ( strncmp(strinput.c_str(), "b=", 2) == 0) )
		{
			strinput.erase(0,2);
			ANSWER_CODE_T response;
			response = ValueB.WriteDef(strinput);
			if (response == ANSWER_CODE_OK)
			{
				cout << "B=" << ValueB.GetDef() << endl;
			}
			else
			{
				cout << "ERROR: " << ErrorHandling(response);
			}
		}
		else if (strinput == "M+" || strinput == "m+")
		{
			ANSWER_CODE_T response;
			if (datatype == 0)
				response = ValueM.WriteIntValue(ValueM.GetInt() + lastAnswer.GetInt());
			else
				response = ValueM.WriteFloatValue(ValueM.GetFloat() + lastAnswer.GetFloat());

			if (response == ANSWER_CODE_OK)
			{
				cout << "M=" << ValueM.GetDef() << endl;
			}
			else
			{
				cout << "ERROR: " << ErrorHandling(response);
			}
		}
		else if (strinput == "M-" || strinput == "m-")
		{
			ANSWER_CODE_T response;
			if (datatype == 0)
				response = ValueM.WriteIntValue(ValueM.GetInt() - lastAnswer.GetInt());
			else
				response = ValueM.WriteFloatValue(ValueM.GetFloat() - lastAnswer.GetFloat());

			if (response == ANSWER_CODE_OK)
			{
				cout << "M=" << ValueM.GetDef() << endl;
			}
			else
			{
				cout << "ERROR: " << ErrorHandling(response);
			}
		}
		else if (strinput == "M" || strinput == "m")
		{
			cout << "M=" << ValueM.GetDef() << endl;
		}
		else if (strinput == "MCLR" || strinput == "mclr")
		{
			ANSWER_CODE_T response;
			if (datatype == 0)
				response = ValueM.WriteIntValue(0);
			else
				response = ValueM.WriteFloatValue(0);
			if (response == ANSWER_CODE_OK)
			{
				cout << "M=" << ValueM.GetDef() << endl;
			}
			else
			{
				cout << "ERROR: " << ErrorHandling(response);
			}
		}
		else if (strinput == "1")			//	A+B
		{
			ANSWER_CODE_T response;
			if (datatype == 0)
				response = lastAnswer.WriteIntValue(ValueA.GetInt() + ValueB.GetInt());
			else
				response = lastAnswer.WriteFloatValue(ValueA.GetFloat() + ValueB.GetFloat());
			if (response == ANSWER_CODE_OK)
			{
				cout << "Ans=" << lastAnswer.GetDef() << endl;
			}
			else
			{
				cout << "ERROR: " << ErrorHandling(response);
			}
		}
		else if (strinput == "1")			//	A+B
		{
			ANSWER_CODE_T response;
			if (datatype == 0)
				response = lastAnswer.WriteIntValue(ValueA.GetInt() + ValueB.GetInt());
			else
				response = lastAnswer.WriteFloatValue(ValueA.GetFloat() + ValueB.GetFloat());
			if (response == ANSWER_CODE_OK)
			{
				cout << "Ans=" << lastAnswer.GetDef() << endl;
			}
			else
			{
				cout << "ERROR: " << ErrorHandling(response);
			}
		}
		else if (strinput == "2")			//	A-B
		{
			ANSWER_CODE_T response;
			if (datatype == 0)
				response = lastAnswer.WriteIntValue(ValueA.GetInt() - ValueB.GetInt());
			else
				response = lastAnswer.WriteFloatValue(ValueA.GetFloat() - ValueB.GetFloat());
			if (response == ANSWER_CODE_OK)
			{
				cout << "Ans=" << lastAnswer.GetDef() << endl;
			}
			else
			{
				cout << "ERROR: " << ErrorHandling(response);
			}
		}
		else if (strinput == "3")			//	A*B
		{
			ANSWER_CODE_T response;
			if (datatype == 0)
				response = lastAnswer.WriteIntValue(ValueA.GetInt() * ValueB.GetInt());
			else
				response = lastAnswer.WriteFloatValue(ValueA.GetFloat() * ValueB.GetFloat());
			if (response == ANSWER_CODE_OK)
			{
				cout << "Ans=" << lastAnswer.GetDef() << endl;
			}
			else
			{
				cout << "ERROR: " << ErrorHandling(response);
			}
		}
		else if (strinput == "4")			//	A/B
		{
			ANSWER_CODE_T response;
			if (datatype == 0 && ValueB.GetInt() != 0)
				response = lastAnswer.WriteIntValue(ValueA.GetInt() / ValueB.GetInt());
			else if (ValueB.GetFloat() != 0.0)
				response = lastAnswer.WriteFloatValue(ValueA.GetFloat() / ValueB.GetFloat());
			else
			{
				cout << "ERROR: DIV/0" << endl;
				continue;
			}
			if (response == ANSWER_CODE_OK)
			{
				cout << "Ans=" << lastAnswer.GetDef() << endl;
			}
			else
			{
				cout << "ERROR: " << ErrorHandling(response);
			}
		}
		else
			cout << "Unknown Command" << endl;
	}
}
