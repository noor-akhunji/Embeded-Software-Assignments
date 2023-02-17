//Assignment_1 ESP32 Pulse generator
const int led_1 = 15; // ESP32 GPIO PIN 15 
const int led_2 = 21; // ESP32 GPIO PIN 21
const int btn_1 = 22; // ESP32 GPIO PIN 22 
const int btn_2 = 23; // ESP32 GPIO PIN 23
 void setup() {
  Serial.begin(115200); //BaudRate for Serial Moniter Visulization of output
   pinMode(15, OUTPUT); // GPIO PIN 15 is for led_1 output
   pinMode(21, OUTPUT); // GPIO PIN 21 is for Led_2 output
   pinMode(22, INPUT); // GPIO PIN 22 is for Led_2 input
   pinMode(23, INPUT); // GPIO PIN 23 is for Led_2 input
 }
 // mod_a is for noemal pulse run
 void mod_a(int pin, int puls_a, int time_inc, int pause_b, int d) {
   // First led_2 blink for 50 microseconds
   digitalWrite(led_2, HIGH);
   delayMicroseconds(50); 
   digitalWrite(led_2, LOW);
   delayMicroseconds(50);
   // The loop is consist of 12 pulses = 1 waveform
   for(int i = 0; i < 12; i ++) {
     digitalWrite(pin, HIGH);
     delayMicroseconds(puls_a);
     // Increase the pulse duration with 50 microseconds
     puls_a = puls_a + time_inc;
     Serial.println(puls_a);
     digitalWrite(pin, LOW);
     // It will Pause between every pulse
     delayMicroseconds(pause_b);
   }
   // After loop it will delay waveform for given time
   digitalWrite(pin, LOW);
   delayMicroseconds(d);
   Serial.println("Mode A");
 }
// mod_b is for modified pulse run
  void mod_b(int pin, int puls_a, int time_inc, int pause_b, int d) {
   // First led_2 blink for 50 microseconds
   digitalWrite(led_2, HIGH);
   delayMicroseconds(50);
   digitalWrite(led_2, LOW);
   delayMicroseconds(50);
   // The loop is consist of 12 pulses = 1 waveform
   for(int i = 0; i < 12; i ++) {
     digitalWrite(pin, HIGH);
     delayMicroseconds(puls_a);
     // Decrease the pulse duration with 50 microseconds
     puls_a = puls_a - time_inc;
     Serial.println(puls_a);
     digitalWrite(pin, LOW);
     // It will Pause between every pulse
     delayMicroseconds(pause_b);
   }
   // After loop it will delay waveform for given time
   digitalWrite(pin, LOW);
   delayMicroseconds(d);
   Serial.println("Mode B");
 }
 
 void loop() {
  // If button 1 is pressed then disablke pulses
  if(digitalRead(btn_1)==HIGH)
  {
   digitalWrite(led_1, LOW);
   digitalWrite(led_2, LOW);
  }
  // If button 2 is pressed then change pulse to Modified pulse
  else if(digitalRead(btn_2)==HIGH)
  {
   mod_b(led_1,650, 50, 1100, 3000);
  }
  //if none of the buttons is pressed then pulse running continiously
  else
  {
    mod_a(led_1,100, 50, 1100, 3000); 
   }
 }
