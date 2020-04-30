#include <HID-Project.h>                    //include HID_Project library
#include <HID-Settings.h>

#define REVERSED true                      //flag pentru schimbarea orientarii potentiometrului

const int pinLed = LED_BUILTIN;
const int playButton = 2;
const int backButton = 3;
const int fwdButton = 4;
const int muteButton = 5;
const int brightUpButton = 6;
const int brightDownButton = 7;
const int winButton = 8;
const int copyButton = 9;
const int pasteButton = 10;

int val = 0;
int previousval = 0;
int val2 = 0;
int ledArray[] = {A5,A2}; //Array led-uri volum
int potent = A0;  //pinul corespunzator iesirii B a potentiometrului 
int potentNum = 0; // variabila in care retinem valoarea primita de la potentiometru

void setup() {
  pinMode(pinLed, OUTPUT);
  pinMode(playButton, INPUT_PULLUP);
  pinMode(fwdButton, INPUT_PULLUP);
  pinMode(backButton, INPUT_PULLUP);
  pinMode(muteButton, INPUT_PULLUP);
  pinMode(brightUpButton, INPUT_PULLUP);
  pinMode(brightDownButton, INPUT_PULLUP);
  pinMode(winButton, INPUT_PULLUP);
  pinMode(copyButton, INPUT_PULLUP);
  pinMode(pasteButton, INPUT_PULLUP);
  
  for(int i = 0; i < 2; i++)  // setarea tuturor led-urilor conectate la pinii A5 si A2 ca OUTPUT in cadrul buclei for 
  {
    analogWrite(ledArray[i], 2);
  }
  Serial.begin(9600);   
  pinMode(potent, INPUT); // declararea potentiometrului ca INPUT
  
  Consumer.begin();                         //initierea conexiunii cu dispozitivul
  delay(1000);                             
  for(int a = 0; a < 52; a++) {
    Consumer.write(MEDIA_VOLUME_DOWN);      //setarea volumului 
    delay(2);
  }
}

void loop() {
// if the play button is pressed
  if (!digitalRead(playButton)) {
    digitalWrite(pinLed, HIGH); // aprinderea LED-ului ce indica apasarea butonului
    Consumer.write(MEDIA_PLAY_PAUSE); // trimitere comanda HID
    delay(500); // wait
    digitalWrite(pinLed, LOW); // stingere LED conectat la port D13
  }

// toate butoanele urmaresc acelasi tipar
  if (!digitalRead(fwdButton)) {
    digitalWrite(pinLed, HIGH);
    Consumer.write(MEDIA_NEXT);
    delay(500);
    digitalWrite(pinLed, LOW);
  }

  if (!digitalRead(backButton)) {
    digitalWrite(pinLed, HIGH);
    Consumer.write(MEDIA_PREVIOUS);
    delay(500);
    digitalWrite(pinLed, LOW);
  }

  if (!digitalRead(brightDownButton)) {
    digitalWrite(pinLed, HIGH);
    Consumer.write(CONSUMER_BRIGHTNESS_DOWN); 
    delay(500);
    digitalWrite(pinLed, LOW);
  }

  if (!digitalRead(brightUpButton)) {
    digitalWrite(pinLed, HIGH);
    Consumer.write(CONSUMER_BRIGHTNESS_UP); 
    delay(500);
    digitalWrite(pinLed, LOW);
  }

  if (!digitalRead(muteButton)) {
    digitalWrite(pinLed, HIGH);
    Consumer.write(MEDIA_VOLUME_MUTE);
    delay(500);
    digitalWrite(pinLed, LOW);
  }

  if (!digitalRead(winButton)) {
    digitalWrite(pinLed, HIGH);
    Keyboard.press(KEY_LEFT_WINDOWS);
    Keyboard.press(KEY_D);
    Keyboard.releaseAll();
    delay(500);
    digitalWrite(pinLed, LOW);
  }

  if (!digitalRead(copyButton)) {
    digitalWrite(pinLed, HIGH);
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_C);
    Keyboard.releaseAll();
    delay(500);
    digitalWrite(pinLed, LOW);
  }

  if (!digitalRead(pasteButton)) {
    digitalWrite(pinLed, HIGH);
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_V);
    Keyboard.releaseAll();
    delay(500);
    digitalWrite(pinLed, LOW);
  }  

  potentNum = analogRead(potent);    // primeste valoarea de la potentiometru
  int num = map(potentNum,0,1023,0,3);

  switch(num)                           //switch statement - controlul LED-URILOR
  {
    case 0:
      analogWrite(ledArray[0], 1);
      analogWrite(ledArray[1], 200);
    break;

    case 1:
    if (num != 0) {
      analogWrite(ledArray[0], 200);
      analogWrite(ledArray[1], 1);
    }
    break;
  }
  
  val = analogRead(1);                      //citeste valoarea potentiometrului
  val = map(val, 0, 1023, 0, 101);          //mapare - 102 pasi
  if(REVERSED) {
    val = 101 - val;
  }
  if(abs(val - previousval) > 1) {          //verifica daca valoarea potentiometrului s-a modificat
    previousval = val;
    val /= 2;                               //impartire la 2 pentru stabilirea a 51 de pasi
    while(val2 < val) {
      Consumer.write(MEDIA_VOLUME_UP);      // creste volumul pana la valoarea dezirabila
      val2++;
      delay(2);
    }
    while(val2 > val) {
      Consumer.write(MEDIA_VOLUME_DOWN);    //scade volumul pana la valoarea dezirabila
      val2--;
      delay(2);
    }
  }
  delay(101);                               //asteapta 101 ms pana la efectuarea schimbarii valorii
}                                           
