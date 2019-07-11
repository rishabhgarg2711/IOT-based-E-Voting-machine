#include<SoftwareSerial.h>
#include<LiquidCrystal.h>
#include<Keypad.h>

LiquidCrystal lcd(13,12,11,10,9,8);
SoftwareSerial my(2,3);

const byte ROWS=4;
const byte COLS=2;
char keys[ROWS][COLS]={
  {'2','A'},{'5','B'},{'8','C'},{'E','D'}
};
byte rowPins[ROWS]={4,5,6,7};
byte colPins[COLS]={A1,A0};
Keypad key=Keypad(makeKeymap(keys),rowPins,colPins,ROWS,COLS);

int a=0;
int b=0;
int c=0;
int total=0;

void res(){
  total=a+b+c;
    lcd.clear();
    lcd.print("Cong=");
      lcd.print(c);
      lcd.print(" BJP=");
      lcd.print(b);
      lcd.setCursor(0,1);
      lcd.print("AAP=");
      lcd.print(a);
      lcd.print(" TOT=");
      lcd.print(total);
    if(a>b)
    {
      if(a>c){
        if(a==b||a==c)
        lcd.print(",Tie");
       lcd.print(",AW");
      }
      else{
        if(c==b||c==a)
        lcd.print(",Tie");
        lcd.print(",CW");
      }
    }
    else if(b>c){
      if(b==a||b==c)
        lcd.print(",Tie");
        lcd.print(",BW");
    }
    else{
      if(c==a||c==b)
        lcd.print(" Tie");
      lcd.print(" CW");
    }
    while(1)
    {
       String in="";
      boolean sre=false;
      while(my.available())
      {
         in=my.readString();
          sre=true;
       }
       if(sre)
      {
      reset();
      return;
      }
    char key1=key.getKey();
  if(key1){
    reset();
    return;
          }
    }
}

void reset(){
  lcd.clear();
  a=0;
  b=0;
  c=0;
  total=0;
}

void vote()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Vote casted");
  }
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  my.begin(115200);
  lcd.begin(16,2);
}

void loop() {
  // put your main code here, to run repeatedly:
   lcd.setCursor(0,0);
 
    
      String in="";
     boolean sre=false;
     while(my.available()){
      in=my.readString();
      sre=true;
     }
     if(sre){
      if(in=="1")
        c++;
      if(in=="2")
        b++;
      if(in=="3")
        a++;
     }
      lcd.print("Cong= C");
      lcd.print("  BJP= B");
      lcd.setCursor(0,1);
      lcd.print("AAP= A");
    
      char key1=key.getKey();
      if(key1)
       {
        if(key1=='A'){
          vote();
          delay(500);
           a++;
        }
         
        else if(key1=='B'){
          vote();
          delay(500);
           b++;
        }
        else if(key1=='C'){
          vote();
          delay(500);
           c++;
        }
        else if(key1=='D')
          reset();
        else if(key1=='E')
            res();
       }
  
}
