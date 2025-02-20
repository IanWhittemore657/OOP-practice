/ PSP1Assignment_IanWhittemore.cpp : Defines the entry point for the console application.
//

////By Ian Whittemore  1700870

#include "stdafx.h"
#include <iostream>
#include <cstdlib> 
#include<math.h>
using namespace std;

int elap(int n, int n2, int & n3, int & n4);

int guess(int a, int b, int random);

int BinaryToDecimal(int bi);

float DecimalToBinary(int dec);

float DecimalToOctal(int dec1);

float DecimalToHex(int dec2);

int main()
{
	int option;

	do
	{
		cout << "Please enter an option: \n 1: Calculate the elapsed time of the arrival and leaving time of an employee \n 2: Play a guessing game \n 3: Converstion of number systems \n 4: Please enter 4 to exit the program" << endl;

		cin >> option;

		switch (option)
		{
		case 1:

		{
			int n, n2;
			int n3 = 0, n4 = 0;
			int countFullday = 0;
			int totalHours = 0;
			int totalMinutes = 0;

			for (int i = 0; i <= 4; i++)
			{
				cout << "Please enter the arrival time and the time of leaving work" << endl;

				cin >> n >> n2;

				countFullday = countFullday + elap(n, n2, n3, n4);

				totalHours = totalHours + n3;
				totalMinutes = totalMinutes + n4;
			}

			cout << "How many full days of working : " << countFullday << endl;
			cout << "The total number of hours worked are : " << totalHours << ":" << totalMinutes << endl;
		}

		break;

		case 2:
		{
			int a;

			int trys = 0;

			int b = rand() % 50 + 1;

			int random = rand() % b + 1;

			do
			{
				cout << "Please enter a guess , You have : " << 10 - trys << " Left" << endl;

				cin >> a;

				trys = trys + guess(a, b, random);

			} while (!(a == random) || trys == 10);

			if (trys == 10)
			{
				cout << "Game over , The correct number was : " << random << endl;
			}

			else if (trys >= 8)
			{
				cout << "Poor performance" << endl;

			}
			else if (trys < 8 && trys > 4)
			{
				cout << "Satisfactory performance " << endl;
			}
			else
			{
				cout << "Excellent performance" << endl;
			}

		}

		break;

		case 3:
		{
			int choose;

			cout << "Please choose what you would like to convert : \n 1: Binary to Decimal \n 2: Decimal to Binary \n 3: Decimal to Octal \n 4: Decimal to Hexadecimal " << endl;

			cin >> choose;

			switch (choose)
			{
			case 1:
			{
				int bi;

				cout << "Please Enter a binary number" << endl;

				cin >> bi;

				cout << "Binary is : " << bi << " and to Decimal is : " << BinaryToDecimal(bi) << endl;

			}
			break;

			case 2:
			{
				int dec, bin;

				cout << "Please enter a decimal number" << endl;

				cin >> dec;

				cout << "Decimal is : " << dec << " and to Binary is : " << DecimalToBinary(dec) << endl;
			}

			break;

			case 3:
			{
				int dec1;

				cout << "Please enter a decimal number" << endl;

				cin >> dec1;

				cout << "Decimal is : " << dec1 << "  and to Octal is : " << DecimalToOctal(dec1) << endl;
			}
			break;

			case 4:
			{
				int dec2;

				cout << "Please enter a decimal number" << endl;

				cin >> dec2;

				cout << "Decimal is : " << dec2 << "  and to Hexadecimal is : " << DecimalToHex(dec2) << endl;
			}
			break;

			default:
				break;
			}

		}

		break;

		case 4:
		{


			cout << "Thank you for using my program \n By Ian Whittemore \n ID : 1700870" << endl;
			exit(0);
		}
		break;

		default:
			break;
		}






	} while (option <= 4);

	cout << "\n Thank you for using my program \n By Ian Whittemore \n ID : 1700870" << endl;



	return 0;
}

/*
Exercise 1 – Pseudo Code
Begin
variable Arrival_Time
variable Leaving_Time
variable Amount_of_time
do
Input Arrival_Time
Input Leaving_Time
while Arrival_Time or Leaving_Time is less than four digits
Amount_of_time = Arrival_Time – Leaving_Time
If(Amount_of_time < 0)
Output: Incorrect times
Else
Output : Amount_of_time
End
*/

int elap(int n, int n2, int &ans1, int &ans2)
{
	int hour1, minute1, hour2, minute2;
	int count = 0;

	hour1 = n / 100;
	minute1 = n % 100;

	hour2 = n2 / 100;
	minute2 = n2 % 100;


	if (minute1 >= minute2)
	{
		--hour2;
		minute2 += 60;
	}

	ans1 = hour2 - hour1;
	ans2 = minute2 - minute1;


	cout << ans1 << ":" << ans2 << endl;

	if (ans1 >= 8)
	{
		cout << "Today has been a full working day!" << endl;

		return 1;
	}
	else
	{
		cout << "Has not been a full day" << endl;
	}

	return 0;

}

/*
Exercise 2 – Pseudo Code
Begin
variable random
variable Guessed_Number
random = math random function
Input Guessed_Number
While(random!= Guessed_Number)
If(random < Guessed_Number)
Output: Guess is too High, Try Again
Else
Output : Guess is too Low, Try Again
Input Guessed_Number
End While
Output : You are correct
End
*/

int guess(int a, int b, int random)
{

	int count = 0;

	if (a > random)
	{
		cout << "Your guess is to high please try again " << endl;
		return 1;
	}
	else if (a < random)
	{
		cout << "Your guess is to low ,please try again " << endl;
		return 1;
	}
	else if (a = random)
	{
		cout << "WELL DONE YOU GUESSED RIGHT " << endl;
		return 1;
	}

	return 0;
}

/*
Exercise 3 – Pseudo Code
Begin
variable character, decimal, binary, remainder, number, exp
do
input character
whille option 1-4
switch(character)
case 1
Input decimal
While (decimal! = 0)
remain = bi % 10;
bi /= 10;
num += remain * pow(2, p);
p++;
end while
Output: Decimal to binary
case 2
Input binary
While (binary! = 0)
remain = dec % 2;
dec /= 2;
bNum += remain * k;
k *= 10;
End while
If (Binary < 0)
Output: Cannot be converted
else
Output: Binary to decimal
case 3
input decimal
While (decimal! = 0)
remain = dec1 % 8;
dec1 /= 8;
octal += remain * o;
o *= 10;
End while
If (decimnal< 0)
Output: Cannot be converted
else
Output: octal to decimal
case4
input hex
While (decimal! = 0)
remain = dec2 % 16;
dec2 /= 16;
hex += remain * w;
w *= 10;
End while
If (decimnal< 0)
Output: Cannot be converted
else
Output: hex to decimal
End
*/

int BinaryToDecimal(int bi)
{
	int num = 0;
	int p = 0;
	int remain;

	while (bi != 0)
	{
		remain = bi % 10;
		bi /= 10;
		num += remain * pow(2, p);
		p++;
	}

	return num;
}

float DecimalToBinary(int dec)
{
	int bNum = 0;
	int remain;
	int k = 1;

	while (dec != 0)
	{
		remain = dec % 2;
		dec /= 2;
		bNum += remain * k;
		k *= 10;
	}

	return bNum;
}

float DecimalToOctal(int dec1)
{
	int octal = 0;
	int remain;
	int o = 1;

	while (dec1 != 0)
	{
		remain = dec1 % 8;
		dec1 /= 8;
		octal += remain * o;
		o *= 10;
	}

	return octal;
}

float DecimalToHex(int dec2)
{
	int hex = 0;
	int remain;
	int w = 1;

	while (dec2 != 0)
	{
		remain = dec2 % 16;
		dec2 /= 16;
		hex += remain * w;
		w *= 10;
	}

	return hex;
}
