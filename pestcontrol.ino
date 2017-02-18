int ledPinA = 2;
int ledPinB = 3;
int piezoPin = 4; 
int state = 0;
int flag = 0; 
 
void setup() {
 pinMode(ledPinA, OUTPUT);
 pinMode(ledPinB, OUTPUT);
 pinMode(piezoPin, OUTPUT);
 digitalWrite(ledPinA, LOW);
 digitalWrite(ledPinB, LOW);
 digitalWrite(piezoPin, LOW);
 
 Serial.begin(9600); // Default connection rate for my BT module
}
 
void loop() {

 if(Serial.available() > 0){
 state = Serial.read();
 flag=0;
 }

 if (state == '0') {
 digitalWrite(ledPinB, HIGH);
 digitalWrite(ledPinA, LOW);
 if(flag == 0){

/*Tone needs 2 arguments, but can take three
1) Pin#
2) Frequency - this is in hertz (cycles per second) which determines the pitch of the noise made
3) Duration - how long the tone plays
*/
tone(piezoPin, 30000, 4000 );
//tone(piezoPin, 1000, 500);
//delay(1000);
  
 Serial.println("LED 1: On");
 delay(500);
 flag = 1;
 }
 }

 else if (state == '1') {
 digitalWrite(ledPinB, HIGH);
 digitalWrite(ledPinA, LOW);
 if(flag == 0){
 Serial.println("LED2: on");
 tone(piezoPin, 900000, 4000 );
 delay(500);
 flag = 1;
 }
 }
 else if (state == '2') {
 digitalWrite(ledPinA, HIGH);
 digitalWrite(ledPinB, LOW);
 if(flag == 0){
 Serial.println("LED1: on");

 delay(500);
 flag = 1;
 }
 }
}
