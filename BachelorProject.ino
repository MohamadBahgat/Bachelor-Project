#define CUSTOM_SETTINGS
#define INCLUDE_TEXT_TO_SPEECH_SHIELD
#define INCLUDE_TERMINAL_SHIELD
#include <OneSheeld.h>
#include <LiquidCrystal.h>

// initialize the LCD pins with the Arduino pins that is connected to.
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
// String screenData; // the data "msg" that will be written on the LCD
String data; // data that will be taken from the sensors
String outputMsg;
String directions;
String azimuthAngle;
bool outputSwitching = true;
// Method to write the msg on the LCD in a correct and arranged way
void writeOnLCD(String screenData) {
  if (screenData.length() > 16) {
    lcd.clear();
    lcd.setCursor(0, 0);
    // (note: line 1 is the second row, since counting begins with 0):
    for (int i = 0; i <= 16; i++) {
      lcd.print(screenData[i]);
    }
    // set the cursor to column 0, line 1 after writting the char number 16
    lcd.setCursor(0, 1);
    for (int j = 16 ; j <= screenData.length() - 1 ; j++) {
      lcd.print(screenData[j]);
    }
  }
  else {
    lcd.clear();
    lcd.print(screenData);
  }
}

// Method to sort an Array
void sort(int a[], int size) {
  for (int i = 0; i < (size - 1); i++) {
    for (int o = 0; o < (size - (i + 1)); o++) {
      if (a[o] > a[o + 1]) {
        int t = a[o];
        a[o] = a[o + 1];
        a[o + 1] = t;
      }
    }
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  lcd.begin(16, 2); // set up the LCD's number of columns and rows:
  //  writeOnLCD("Hey, Wake Up!");  // Print a Welcoming message on the LCD.
  //  delay(6000); // wait for 6 seconds
  //  writeOnLCD("Bachelor Project");
  //  delay(4000); // wait for 4 seconds
  //  writeOnLCD("Estimation of Li-ght Directivity");
  OneSheeld.begin();  // Turn on OneSheeld

}


//int getMin(int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8){
//  int minimum = min(n1,(min(n2,(min(n3,min(n4,min(n5,min(n6,min(n7,n8)))))))));
//  return minimum;
//}

void loop() {
  // put your main code here, to run over and over again:
  //screenData = msg; // LCD data
  //WriteOnLCD(); // print it on the screen
  //screenData = ""; // reset it
  //delay(4000); // wait 4 seconds
  //TextToSpeech.say("Hello"); // say the msg as a voice
  //Terminal.println("Write what you want to be heared as a voice: ");
  //msg = ""; // reset it
  int a1 , a2, a3, a4, a5, a6, a7, a8 ;
  a1 = analogRead(A8);
  a2 = analogRead(A9);
  a3 = analogRead(A10);
  a4 = analogRead(A11);
  a5 = analogRead(A12);
  a6 = analogRead(A13);
  a7 = analogRead(A14);
  a8 = analogRead(A15);
  int arrAz[8] = {a1 , a2, a3, a4, a5, a6, a7, a8};
  sort(arrAz, 8);

  azimuthAngle = "new";

  if (arrAz[0] == a1) {
    azimuthAngle = "Azimuth angle = 0 Degree";
//    if (arrAz[1] == a8 && a8 + 20 >= a1) {
//      azimuthAngle = azimuthAngle + ", 315 Degree";
//    } else if (arrAz[1] == a2 && a2 + 20 >= a1) {
//      azimuthAngle = azimuthAngle + ", 45 Degree";
//    }
  }
  else if (arrAz[0] == a2) {
    azimuthAngle = "Azimuth angle = 45 Degree";
//    if (arrAz[1] == a1 && a1 + 20 >= a2) {
//      azimuthAngle = azimuthAngle + ", 0 Degree";
//    } else if (arrAz[1] == a3 && a3 + 20 >= a2) {
//      azimuthAngle = azimuthAngle + ", 90 Degree";
//    }
  }
  else if (arrAz[0] == a3) {
    azimuthAngle = "Azimuth angle = 90 Degree";
//    if (arrAz[1] == a2 && a2 + 20 >= a3) {
//      azimuthAngle = azimuthAngle + ", 45 Degree";
//    } else if (arrAz[1] == a4 && a4 + 20 >= a3) {
//      azimuthAngle = azimuthAngle + ", 135 Degree";
//    }
  }
  else if (arrAz[0] == a4) {
    azimuthAngle = "Azimuth angle = 135 Degree";
//    if (arrAz[1] == a3 && a3 + 20 >= a4) {
//      azimuthAngle = azimuthAngle + ", 90 Degree";
//    } else if (arrAz[1] == a5 && a5 + 20 >= a4) {
//      azimuthAngle = azimuthAngle + ", 180 Degree";
//    }
  }
  else if (arrAz[0] == a5) {
    azimuthAngle = "Azimuth angle = 180 Degree";
//    if (arrAz[1] == a4 && a4 + 20 >= a5) {
//      azimuthAngle = azimuthAngle + ", 135 Degree";
//    } else if (arrAz[1] == a6 && a6 + 20 >= a5) {
//      azimuthAngle = azimuthAngle + ", 225 Degree";
//    }
  }
  else if (arrAz[0] == a6) {
    azimuthAngle = "Azimuth angle = 225 Degree";
//    if (arrAz[1] == a5 && a5 + 20 >= a6) {
//      azimuthAngle = azimuthAngle + ", 180 Degree";
//    } else if (arrAz[1] == a7 && a7 + 20 >= a6) {
//      azimuthAngle = azimuthAngle + ", 270 Degree";
//    }
  }
  else if (arrAz[0] == a7) {
    azimuthAngle = "Azimuth angle = 270 Degree";
//    if (arrAz[1] == a6 && a6 + 20 >= a7) {
//      azimuthAngle = azimuthAngle + ", 225 Degree";
//    } else if (arrAz[1] == a8 && a8 + 20 >= a7) {
//      azimuthAngle = azimuthAngle + ", 315 Degree";
//    }
  }
  else if (arrAz[0] == a8) {
    azimuthAngle = "Azimuth angle = 315 Degree";
//    if (arrAz[1] == a7 && a7 + 20 >= a8) {
//      azimuthAngle = azimuthAngle + ", 270 Degree";
//    } else if (arrAz[1] == a1 && a1 + 20 >= a8) {
//      azimuthAngle = azimuthAngle + ", 0 Degree";
//    }
  }

  int s1 , s2, s3, s4, s5, s6, s7, s8 ;
  s1 = analogRead(A0);
  s2 = analogRead(A1);
  s3 = analogRead(A2);
  s4 = analogRead(A3);
  s5 = analogRead(A4);
  s6 = analogRead(A5);
  s7 = analogRead(A6);
  s8 = analogRead(A7);

  int arr[8] = {s1 , s2, s3, s4, s5, s6, s7, s8};
  sort(arr, 8);

  directions = "new";
  if (arr[0] == s1) { // Max is sensor 1
    directions = "North";
  }
  else if (arr[0] == s2) { // Max is sensor 2
    if (s2 + 75 < s1 && s2 + 75 < s3) {
      directions = "45 Degree North-East";
    }
    else if (s8 - 10 <= s2 && s2 <= s8 + 10) {
      //Serial.println(String(s8-10)+ "  ,  " + String(s8+10));
      directions = "North";
    }
    else if (s4 - 10 <= s2 && s2 <= s4 + 10) {
      directions = "East";
    }
    else if (s1 <= s3) {
      directions = "North-East";
    }
    else {
      directions = "East";
    }
  }
  else if (arr[0] == s3) { // Max is sensor 3
    directions = "East";
  }
  else if (arr[0] == s4) { // Max is sensor 4
    if (s4 + 75 < s3 && s4 + 75 < s5) {
      directions = "45 Degree South-West";
    }
    else if (s2 - 10 <= s4 && s4 <= s2 + 10) {
      directions = "East";
    }
    else if (s6 - 10 <= s4 && s4 <= s6 + 10) {
      directions = "South";
    }
    else if (s3 <= s5) {
      directions = "East";
    }
    else {
      directions = "South-East";
    }
  }
  else if (arr[0] == s5) { // Max is sensor 5
    directions = "South";
  }
  else if (arr[0] == s6) { // Max is sensor 6
    if (s6 + 75 < s5 && s6 + 75 < s7) {
      directions = "45 Degree South-West";
    }
    else if (s4 - 10 <= s6 && s6 <= s4 + 10) {
      directions = "South";
    }
    else if (s8 - 10 <= s6 && s6 <= s8 + 10) {
      directions = "West";
    }
    else if (s5 <= s7) {
      directions = "South-West";
    }
    else {
      directions = "West";
    }
  }
  else if (arr[0] == s7) { // Max is sensor 7
    directions = "West";
  }
  else if (arr[0] == s8) { // Max is sensor 8
    if (s8 + 75 < s7 && s8 + 75 < s1) {
      directions = "45 Degree North-West";
    }
    else if (s6 - 10 <= s8 && s8 <= s6 + 10) {
      directions = "West";
    }
    else if (s2 - 10 <= s8 && s8 <= s2 + 10) {
      directions = "North";
    }
    else if (s7 <= s1) {
      directions = "West";
    }
    else {
      directions = "North-West";
    }
  }
  else directions = "Error";

  for (int i = 0; i < 2; i++) {
    if (outputSwitching) {
      String outPut = "smallest value: " + String(arr[0]);
      TextToSpeech.say(directions);
      Serial.println("\n");
      writeOnLCD(directions);
      Serial.println(outPut);
      outputSwitching = !outputSwitching;

      Serial.println("S1 value: " + String(s1));
      Serial.println("S2 Value: " + String(s2));
      Serial.println("S3 Value: " + String(s3));
      Serial.println("S4 Value: " + String(s4));
      Serial.println("S5 Value: " + String(s5));
      Serial.println("S6 Value: " + String(s6));
      Serial.println("S7 Value: " + String(s7));
      Serial.println("S8 Value: " + String(s8));
      delay(5000);
    }
    else {
      String outPut = "smallest value: " + String(arrAz[0]);
      TextToSpeech.say(azimuthAngle);
      Serial.println("\n");
      writeOnLCD(azimuthAngle);
      Serial.println(outPut);
      Serial.println(azimuthAngle);
      outputSwitching = !outputSwitching;

      Serial.println("A1 value: " + String(a1));
      Serial.println("A2 Value: " + String(a2));
      Serial.println("A3 Value: " + String(a3));
      Serial.println("A4 Value: " + String(a4));
      Serial.println("A5 Value: " + String(a5));
      Serial.println("A6 Value: " + String(a6));
      Serial.println("A7 Value: " + String(a7));
      Serial.println("A8 Value: " + String(a8));
      delay(5000);

    }
  }



  //Serial.println("\n");

  //Terminal.println(s1);

  //    Terminal.println("S1 value: " + String(s1));
  //    Terminal.println("S2 value: " + String(s2));
  //    Terminal.println("S3 Value: " + String(s3));
  //    Terminal.println("S4 Value: " + String(s4));
  //    Terminal.println("S5 Value: " + String(s5));
  //    Terminal.println("S6 Value: " + String(s6));
  //    Terminal.println("S7 Value: " + String(s7));
  //    Terminal.println("S8 Value: " + String(s8));
  int avg = (1024-s1+1024-s2+1024-s3+1024-s4+1024-s5+1024-s6+1024-s7+1024-s8+1024-a1+1024-a2+1024-a3+1024-a4+1024-a5+1024-a6+1024-a7+1024-a8)/16;
  Serial.println("The Avg = "+String(avg));
  writeOnLCD("The Avg = "+String(avg));
  TextToSpeech.say("The Average light in this place is "+String(avg));
  Serial.println("\n");
  delay(5000);
}
