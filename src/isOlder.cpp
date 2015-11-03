/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/


int isOlder(char *dob1, char *dob2) {
	int date1, month1, year1, date2, month2, year2;
	if (dob1[10] != '\0' || dob2[10] != '\0')
		return -1;
	for (int i = 0; i < 10; i++){
		if (i == 2 || i == 5){
			if (dob1[i] != '-' || dob2[i] != '-')
				return -1;
		}
		else if (dob1[i]<'0' || dob1[i]>'9' || dob2[i]<'0' || dob2[i]>'9')
			return -1;
	}
	date1 = (dob1[0] - '0') * 10 + (dob1[1] - '0');
	month1 = (dob1[3] - '0') * 10 + (dob1[4] - '0');
	year1 = (dob1[6] - '0') * 1000 + (dob1[7] - '0') * 100 + (dob1[8] - '0') * 10 + (dob1[9] - '0');

	date2 = (dob2[0] - '0') * 10 + (dob2[1] - '0');
	month2 = (dob2[3] - '0') * 10 + (dob2[4] - '0');
	year2 = (dob2[6] - '0') * 1000 + (dob2[7] - '0') * 100 + (dob2[8] - '0') * 10 + (dob2[9] - '0');

	if (year1<0 || month1 > 12 || date1 > 31 || month1 < 1 || date1<1)
		return -1;
	else if ((month1 == 4 || month1 == 6 || month1 == 9 || month1 == 11) && date1>30)
		return -1;
	else if (month1 == 2 && (year1 % 400 == 0 || ((year1 % 100 != 0) && (year1 % 4) == 0)) && date1 > 29)
		return -1;
	else if (month1 == 2 && (year1 % 400 != 0 && ((year1 % 100 == 0) || (year1 % 4) != 0)) && date1 >= 29)
		return -1;

	if (year2<0 || month2 > 12 || date2 > 31 || month2 < 1 || date2<1)
		return -1;
	else if ((month2 == 4 || month2 == 6 || month2 == 9 || month2 == 11) && date2>30)
		return -1;
	else if (month2 == 2 && (year2 % 400 == 0 || ((year2 % 100 != 0) && (year2 % 4) == 0)) && date2 > 29)
		return -1;
	else if (month2 == 2 && (year2 % 400 != 0 && ((year2 % 100 == 0) || (year2 % 4) != 0)) && date2 == 29)
		return -1;

	if ((year1 == year2) && (month1 == month2) && (date1 == date2))
		return 0;
	if (year1 != year2){
		return year1 > year2 ? 2 : 1;
	}
	else if (month1 != month2){
		return month1 > month2 ? 2 : 1;
	}
	else if (date1 != date2){
		return date1 > date2 ? 2 : 1;
	}
	else
		return 0;
}
