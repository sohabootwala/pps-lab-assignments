#include <stdio.h>
int main()
{
int year, month, day, i;
int total = 0; /* days passed since 1 Jan of year 1 */
int start; /* weekday of the 1st: 0 = Sun ... 6 = Sat */
int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char *names[] = {"January", "February", "March", "April", "May", "June",
"July", "August", "September", "October", "November", "December"};
printf("Enter the year: ");
scanf("%d", &year);
/* Step 1: if leap year, February has 29 days */
if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
days[1] = 29;
/* Step 2: count the days in all the years before this year */
for (i = 1; i < year; i++)
{
if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0))
total = total + 366;
else
total = total + 365;
}
/* Step 3: 1 Jan of year 1 was a Monday, so add 1 and take the remainder by 7 */
start = (total + 1) % 7;
/* Step 4: print every month */
for (month = 0; month < 12; month++)
{
printf("\n %s %d\n", names[month], year);
printf(" Su Mo Tu We Th Fr Sa\n");
for (i = 0; i < start; i++) printf(" ");
/* blank spaces before the 1st */
for (day = 1; day <= days[month]; day++)
{
printf("%4d", day);
start++;
if (start == 7) {
/* Saturday finished, go to next line */
printf("\n");
start = 0;
}
}
if (start != 0)
printf("\n");
}
return 0;
}
