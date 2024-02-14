//used outputs: D4, 7, 12, 13
// D4:  yellow
// D7:  red main
// D12: red ersatz
// D10: green

#define YELLOW  4
#define GREEN   10
#define RED     7
#define E_RED   12

#define OFF   0
#define HP0   1
#define HL1   2
#define HL10  4
#define HP0E  8
#define HL4   32
#define HL7   64

void showSignal(int light, int delayt, bool blink){
  if(blink){
    resetSignal();
    delay(delayt/2);
    digitalWrite(light, LOW);
    delay(delayt/2);
  } else {
    if(digitalRead(light) != LOW){
      resetSignal();
      digitalWrite(light, LOW);
      delay(delayt);
    } else {
      delay(delayt);
    }
  }
  
}

void resetSignal(){
  int pins[] = {GREEN, YELLOW, RED, E_RED};

  for(byte i = 0; i <=3; i++){
    digitalWrite(pins[i], HIGH);
  }
}

void setup() {
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(E_RED, OUTPUT);
}

void loop() {
  
  
  for(byte i = 0; i <= 128; i++){
    switch(i){
      case 0:
        resetSignal();
        break;
      case 1:
        showSignal(RED, 2000, false);
        break;
      case 2 ... 3:
        showSignal(GREEN, 1000, false);
        break;
      case 4 ... 7:
        showSignal(YELLOW, 1000, false);
        break;
      case 8 ... 31:
        showSignal(E_RED, 200, false);
        break;
      case 32 ... 63:
        showSignal(GREEN, 600, true); //should be blink
        break;
      case 64 ... 128:
        showSignal(YELLOW, 600, true); //should also blink
        break;
      default:
        resetSignal();
    }
    
  }

}
