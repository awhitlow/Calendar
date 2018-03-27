#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
//function prototypes
int get_year();
int get_starting_day();
void print_heading(int);
string read_month_name();
int read_num_days();
int print_month(int, int, string);
ifstream myfile;
int main()
{
    //Declare variables
    int year;
    int starting_day;
    string month;
    int num_days;
    int loop_num;
    myfile.open("infile.txt");
    //Call function to enter calendar year
    year = get_year();
    //Call function to get the starting day of the week
    starting_day = get_starting_day();
    //Call function to print the calendar header
    print_heading(year);
    //Loop through each month
    loop_num = 0;
    while (loop_num < 12)
    {
        //Call function to read the month's name
        month = read_month_name();
        //Call function to read in the number of days in month
        num_days = read_num_days();
        //Call function to print out calendar
        starting_day = print_month(starting_day, num_days, month);
        loop_num ++;
    }
    return 0;
}
//Function to get user input for the year
int get_year()
{
    int year;
    cout << "Enter the year: " << endl;
    cin >> year;
    return year;
}
//Function to get user input for the starting day of the week
int get_starting_day ()
{
    int starting_day;
    cout << "Enter the start date (0 = Sun, 1 = Mon, 2 = Tues, 3 = Wed, 4 = Thurs, 5 = Fri, 6 = Sat): " << endl;
    cin >> starting_day;
    return starting_day;
}
//Function to print out the calendar heading
void print_heading(int year)
{
    cout << setw(25) << "YEAR -- " << year << endl << endl;
}
//Function to read in the month name from file
string read_month_name()
{
    string month_name;
    myfile >> month_name;
    return month_name;
}
//Function to read in the amount of days in each month from file
int read_num_days()
{
    int num_days;
    myfile >> num_days;
    return num_days;
}
//Function to print out each month of calendar
int print_month(int dayOfWeek, int num_days, string month_name)
{
    //Variable for the day of week to get returned to main function as the starting day for next month
    int startDate;
    cout << endl << endl << setw(25) << month_name << endl << endl;
    cout << "SUN:" << '\t' << "MON:" << '\t' << "TUES:" << '\t' << "WED:" << '\t' << "THURS:" << '\t'<< "FRI:" << '\t' << "SAT:" << endl;
    //For each number up until the day of week entered by user, cout a tab
    for (int i=0; i<dayOfWeek; i++)
    {
        cout << '\t';
    }
    //Cout each date of the month
    for (int i=1; i<=num_days; i++)
    {
        cout << i << '\t';
        //Increase the day of the week by one to keep track of when the week ends
        dayOfWeek++;
        //If the day of week reaches 6 (Saturday), cout and end of line character
        if(dayOfWeek > 6)
        {
            cout << endl << endl;
            //reset the day of week to 0 (Sunday)
            dayOfWeek=0;
        }
    }
    //Set the day of week as the starting day of week for next month
    startDate = dayOfWeek;
    return startDate;
}

/*
Enter the year:
2017
Enter the start date (0 = Sun, 1 = Mon, 2 = Tues, 3 = Wed, 4 = Thurs, 5 = Fri, 6
 = Sat):
2
                 YEAR -- 2017



                  January

SUN:    MON:    TUES:   WED:    THURS:  FRI:    SAT:
                1       2       3       4       5

6       7       8       9       10      11      12

13      14      15      16      17      18      19

20      21      22      23      24      25      26

27      28      29      30      31

                 February

SUN:    MON:    TUES:   WED:    THURS:  FRI:    SAT:
                                        1       2

3       4       5       6       7       8       9

10      11      12      13      14      15      16

17      18      19      20      21      22      23

24      25      26      27      28

                    March

SUN:    MON:    TUES:   WED:    THURS:  FRI:    SAT:
                                        1       2

3       4       5       6       7       8       9

10      11      12      13      14      15      16

17      18      19      20      21      22      23

24      25      26      27      28      29      30

31

                    April

SUN:    MON:    TUES:   WED:    THURS:  FRI:    SAT:
        1       2       3       4       5       6

7       8       9       10      11      12      13

14      15      16      17      18      19      20

21      22      23      24      25      26      27

28      29      30

                      May

SUN:    MON:    TUES:   WED:    THURS:  FRI:    SAT:
                        1       2       3       4

5       6       7       8       9       10      11

12      13      14      15      16      17      18

19      20      21      22      23      24      25

26      27      28      29      30      31

                     June

SUN:    MON:    TUES:   WED:    THURS:  FRI:    SAT:
                                                1

2       3       4       5       6       7       8

9       10      11      12      13      14      15

16      17      18      19      20      21      22

23      24      25      26      27      28      29

30

                     July

SUN:    MON:    TUES:   WED:    THURS:  FRI:    SAT:
        1       2       3       4       5       6

7       8       9       10      11      12      13

14      15      16      17      18      19      20

21      22      23      24      25      26      27

28      29      30      31

                   August

SUN:    MON:    TUES:   WED:    THURS:  FRI:    SAT:
                                1       2       3

4       5       6       7       8       9       10

11      12      13      14      15      16      17

18      19      20      21      22      23      24

25      26      27      28      29      30      31



                September

SUN:    MON:    TUES:   WED:    THURS:  FRI:    SAT:
1       2       3       4       5       6       7

8       9       10      11      12      13      14

15      16      17      18      19      20      21

22      23      24      25      26      27      28

29      30

                  October

SUN:    MON:    TUES:   WED:    THURS:  FRI:    SAT:
                1       2       3       4       5

6       7       8       9       10      11      12

13      14      15      16      17      18      19

20      21      22      23      24      25      26

27      28      29      30      31

                 November

SUN:    MON:    TUES:   WED:    THURS:  FRI:    SAT:
                                        1       2

3       4       5       6       7       8       9

10      11      12      13      14      15      16

17      18      19      20      21      22      23

24      25      26      27      28      29      30



                 December

SUN:    MON:    TUES:   WED:    THURS:  FRI:    SAT:
1       2       3       4       5       6       7

8       9       10      11      12      13      14

15      16      17      18      19      20      21

22      23      24      25      26      27      28

29      30      31
Process returned 0 (0x0)   execution time : 7.164 s
Press any key to continue.
*/


