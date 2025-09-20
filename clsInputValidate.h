#include "clsDate.h"
#pragma once
class clsInputValidate
{
public:
	static bool IsNumberBetween(int NumBetween, int From, int To)
	{

		for (int i = 1; i < To; i++)
		{
			if (NumBetween == i)
			{
				return true;
			}

		}
		return false;
	}

	static bool IsNumberBetween(double NumBetween, double From, double To)
	{
		double Fractional = NumBetween - int(NumBetween);

		for (double i = 1; i < To; i = i + Fractional)
		{
			if (i == NumBetween)
			{
				return true;
			}

		}

		return false;
	}

	static bool IsDateBetween(clsDate Date, clsDate DateFrom, clsDate DateTo)
	{
		if (clsDate::IsDate1BeforeDate2(DateTo, DateFrom))
		{
			clsDate::SwapDates(DateFrom, DateTo);
		}

		if (clsDate::IsDate1BeforeDate2(Date, DateFrom) && clsDate::IsDate1AfterDate2(Date, DateTo))
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	static int ReadIntNumber(string InvalidMessage)
	{
		int X;
		cin >> X;
		
		while (cin.fail())
		{
							
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << InvalidMessage << endl;
			X = ReadIntNumber(InvalidMessage);
		}
		return X;
	}

	static int ReadIntNumberBetween(int From, int To, string InvalidMessage)
	{

		int y = 0;
		cin >> y;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\nInvalid Number, Enter Again\n" << endl;
			y = ReadIntNumberBetween(From, To, InvalidMessage);
		}

		while (y < From || y > To)
		{
			cout << InvalidMessage << endl;
			cin >> y; 
		}
		return y;

	}


};

