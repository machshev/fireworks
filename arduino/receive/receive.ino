#include <PinChangeInterruptHandler.h>
#include <RFReceiver.h>


// Listen on digital pin 2
RFReceiver receiver(2);
uint8_t relay_pin = 6;
uint8_t PULSES = 10;
uint8_t TOTAL_TIME = 500; // ms
uint8_t RATIO = 2; // off time to on time
uint8_t PLUSE_DUR = TOTAL_TIME / PULSES;
uint8_t ON_TIME = 30;//PLUSE_DUR / (RATIO + 1); // ms
uint8_t OFF_TIME = 3; //ON_TIME * RATIO; // ms


void setup() {
  pinMode(relay_pin, OUTPUT);

  Serial.begin(9600);
  receiver.begin();
}

void loop() {
  for(uint8_t i=1; i<PULSES+1; i++){
    digitalWrite(relay_pin, HIGH);
    delay(ON_TIME);

    digitalWrite(relay_pin, LOW);
    delay(OFF_TIME);
  }
  while(true);


  char msg[MAX_PACKAGE_SIZE];
  byte senderId = 0;
  byte packageId = 0;
  // byte len = receiver.recvPackage((byte *)msg, &senderId, &packageId);

  Serial.println("");
  Serial.print("Package: ");
  Serial.println(packageId);
  Serial.print("Sender: ");
  Serial.println(senderId);
  Serial.print("Message: ");
  Serial.println(msg);
}