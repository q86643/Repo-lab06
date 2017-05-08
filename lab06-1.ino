#include <Keypad.h>
const byte ROWS = 4; // 4 Rows
const byte COLS = 4; // 4 Columns
char keys[ROWS][COLS] = {
{'F', 'E', 'D', 'C'}, 
{'B','3','6', '9'},
{'A', '2', '5', '8'}, 
{'0', '1', '4', '7'}
};
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {13, 12, 11, 10};
Keypad keypad =
Keypad( makeKeymap(keys), rowPins,
colPins, ROWS, COLS );

const int buzzer = 5;

const int toneTable[7][5]={

    { 66, 131, 262, 523, 1046},  // C Do

    { 74, 147, 294, 587, 1175},  // D Re

    { 83, 165, 330, 659, 1318},  // E Mi

    { 88, 175, 349, 698, 1397},  // F Fa

    { 98, 196, 392, 784, 1568},  // G So

    {110, 220, 440, 880, 1760},  // A La

    {124, 247, 494, 988, 1976}   // B Si

};

char toneName[]="CDEFGAB";

char starTone[]="CCGGAAGFFEEDDCGGFFEEDGGFFEEDCCGGAAGFFEEDDC";

int starBeat[]={

    1,1,1,1,1,1,2, 1,1,1,1,1,1,2,

    1,1,1,1,1,1,2, 1,1,1,1,1,1,2,

    1,1,1,1,1,1,2, 1,1,1,1,1,1,2

};

 

int getTone(char symbol) {

    int toneNo = 0;

    for ( int ii=0; ii<7; ii++ ) {

        if ( toneName[ii]==symbol ) {

            toneNo = ii;

            break;

        }

    }

    return toneNo;

}

 

void setup() {
    Serial.begin(9600);

    pinMode(buzzer,OUTPUT);

    noTone(buzzer);

}

 

void loop() {

    int ii, length, toneNo;

    int duration;
     ii= keypad.getKey();
    // star
    if (ii != NO_KEY){
  tone(5,toneName[ii]);
  delay(500);
  noTone(5);
  }

    /*length = sizeof(starTone)-1;

    for ( ii=0; ii<length; ii++ ) {

        toneNo = getTone(starTone[ii]);

        duration = starBeat[ii]*333;

        tone(buzzer,toneTable[toneNo][3]);

        delay(duration);

        noTone(buzzer);

    }

    noTone(buzzer);

    delay(5000);*/

}

 
