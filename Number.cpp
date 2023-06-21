///////////////////////////////////////////////////////////
// Number.cpp - class and methods of handling 
// number value in diffrent number systems
// 
// All function comments in Number.h
// 
// Mateusz Gasiorowski - AGH student
// Study subject: Jezyki Programowania
// 
///////////////////////////////////////////////////////////

using namespace std;

#include "Number.h"
// bin, oct, hex, albo float.

string Number::GetBin()
{
	if (datatype == 0)
	{
		/*
		* Nieaktualna metoda konwersji liczb na forme binarna
		* 
		bool binTab[32]{};
		int Value = IntValue;
		short sValue = 0;
		for (int i = 0; i < sizeof(binTab); i++)
		{
			binTab[i] = Value % 2;
			Value = Value / 2;
			if (Value == 0)
			{
				sValue = i;
				break;
			}
		}
		string output;
		for (int i = sValue; i >= 0; i--)
		{
			binTab[i] ? output += "1" : output += "0";
		}
		
		return output; */

		stringstream output;
		output << format("{:b}", GetInt());
		return output.str();
	}
	else
		return "NFN"; // Not Float Number
}
ANSWER_CODE_T Number::WriteBin(string input)
{
	if (datatype == 0)
	{
		for (int i = 0; i < input.length(); i++)
		{

			if (input[i] != '1' && (input[i] != '0'))
				if(input[0] != '-')
					return ANSWER_CODE_NAN;

		}
		errno = 0;
		char* pInput = &input[0];
		char* ppInput{};
		IntValue = strtol(pInput, &ppInput, 2);
		if (errno == ERANGE)
			return ANSWER_CODE_RANGE;

		return ANSWER_CODE_OK;
	}
	else
		return ANSWER_CODE_NIN;
}
string Number::GetOct()
{
	stringstream output;
	if (datatype == 0)
		output << oct << IntValue;
	else
		return "NFN"; // Not Float Number
	return output.str();
}
ANSWER_CODE_T Number::WriteOct(string input)
{
	if (datatype == 0)
	{
		for (int i = 0; i < input.length(); i++)
		{
			if ( ( isdigit(input[i]) == 0 ) || ( input[i] == '8' ) || ( input[i] == '9' ) )
				if (input[0] != '-')
					return ANSWER_CODE_NAN;	
		}
		char* pInput = &input[0];
		char* ppInput{};
		errno = 0;
		IntValue = strtol(pInput, &ppInput, 8);
		if (errno == ERANGE)
			return ANSWER_CODE_RANGE;
		return ANSWER_CODE_OK;
	}
	else
		return ANSWER_CODE_NIN;
}
string Number::GetHex()
{
	stringstream output;
	if (datatype == 0)
		output << "0x" << hex << IntValue;
	else
		output << hexfloat << FloatValue;
	return output.str();
}
ANSWER_CODE_T Number::WriteHex(string input)
{
	for (int i = 0; i < input.length(); i++)
	{
		if ( (isxdigit(input[i]) == 0) && ( input[i] != 'x' ) && ( input[i] != 'X' ) && (input[i] != 'p') && (input[i] != 'P') && (input[i] != '.') && (input[i] != '-') && (input[i] != '+') )
			return ANSWER_CODE_NAN;
	}
	char* pInput = &input[0];
	char* ppInput{};	
	errno = 0;
	if (datatype == 0)
		IntValue = strtol(pInput, &ppInput, 16);
	else
		FloatValue = strtod(pInput, &ppInput);

	if (errno == ERANGE)
		return ANSWER_CODE_RANGE;

	return ANSWER_CODE_OK;
}

string Number::GetDec()
{
	stringstream output;
	if (datatype == 0)
		output << IntValue;
	else
		output <<  FloatValue;
	return output.str();
}
ANSWER_CODE_T Number::WriteDec(string input)
{
	for (int i = 0; i < input.length(); i++)
	{
		if ((isdigit(input[i]) == 0) && (input[i] != '-') && ( (input[i] != '.') || (datatype == 0) ) )
			return ANSWER_CODE_NAN;
	}
	char* pInput = &input[0];
	char* ppInput{};
	errno = 0;
	if (datatype == 0)
		IntValue = strtol(pInput, &ppInput, 10);
	else
		FloatValue = strtod(pInput, &ppInput);
	if (errno == ERANGE)
		return ANSWER_CODE_RANGE;
	return ANSWER_CODE_OK;
}

ANSWER_CODE_T Number::WriteDef(string input)
{
	switch (NumSystem)
	{
	case Bin:
		return WriteBin(input);
		break;
	case Oct:
		return WriteOct(input);
		break;
	case Dec:
		return WriteDec(input);
		break;
	case Hex:
		return WriteHex(input);
		break;
	}
	return ANSWER_CODE_OK;
}
string Number::GetDef()
{
	switch (NumSystem)
	{
	case Bin:
		return GetBin();
		break;
	case Oct:
		return GetOct();
		break;
	case Dec:
		return GetDec();
		break;
	case Hex:
		return GetHex();
		break;
	}
	return "ERR";
}
ANSWER_CODE_T Number::WriteFloatValue(double Value)
{
	FloatValue = Value;
	return ANSWER_CODE_OK;
}
ANSWER_CODE_T Number::WriteIntValue(int Value)
{
	IntValue = Value;
	return ANSWER_CODE_OK;
}

NumberSystem Number::GetSystem()
{
	return NumSystem;
}

double Number::GetFloat()
{
	return FloatValue;
}
int Number::GetInt()
{
	return IntValue;
}

void Number::SetDataType(bool n)
{
	datatype = n;
}
void Number::SetDefNumSystem(NumberSystem NSys)
{
	NumSystem = NSys;
}