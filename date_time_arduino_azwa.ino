#include <LiquidCrystal.h>
#include <Wire.h>
#include <DS1307RTC.h>
#include <TimeLib.h>


int Day; 
int Month; 
int Year;
int Sec;
int Minutes;
int Hours;


// for the 16x2 LCD
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup() {
   Serial.begin(9600);
  while (!Serial) ; // wait for serial
  delay(200);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  
  }


// Comment out below lines once you set the date & time.
// Following line sets the RIC to the date & time this sketch was compiled
  


// Following line sets the RIC wich an explicit date & time
// for example to set January 27 2017 at 12:56 you would call:
// Itc.adjust (DateTime (2017, 1, 27, 12, 56, 0)):

void loop () {
tmElements_t tm;
  RTC.read(tm);
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 0);
  // print the number of seconds since reset:
  lcd.print("date: ");
  lcd.print(tm.Day);
  lcd.print("/");
  lcd.print(tm.Month);
  lcd.print("/");
  lcd.print(tmYearToCalendar(tm.Year));
  lcd.setCursor(0, 1);
  lcd.print("time: ");
  print2digits(tm.Hour);
  lcd.print(":");
  print2digits(tm.Minute);
  lcd.print(":");
  print2digits(tm.Second);
}

void print2digits(int number) {
  if (number >= 0 && number < 10) {
    lcd.print('0');
  }
  lcd.print(number);
  }
  
