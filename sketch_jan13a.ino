char veri;  // these are the variables
int yesilPin = 9;
int sariPin = 10;
int kirmiziPin = 11;
#define Buton 8
int buton_durumu = 0; 


void setup() {
  Serial.begin(9600);  // start the serial communication with 9600 baudrate
  pinMode(Buton, INPUT); // button(input)
   
  pinMode(kirmiziPin, OUTPUT); // set the kirmiziPin the output
  pinMode(sariPin, OUTPUT);   // set the sariPin the output
  pinMode(yesilPin, OUTPUT);  // set the yesilPin the output
}

void loop() {
  if(Serial.available()) {   // Control the data on serial port
    veri = Serial.read();    // read the data coming from HC06
    Serial.print("Gelen veri: "); // write the information on the serial monitor 
    Serial.println(veri); // write the data
  
  }

  buton_durumu = digitalRead(Buton);
  if(buton_durumu == 1){ //if the button durumu is '1' 
    digitalWrite(yesilPin, HIGH);   // closed
    digitalWrite(sariPin, HIGH);    // closed
    digitalWrite(kirmiziPin, HIGH); // closed
  }
  else if(veri == '1'){   // if the data is 1
    digitalWrite(yesilPin, LOW);  // set the green led open (leds one side is connected to the 5V so if we want to set the leds open we should have LOW output)
    digitalWrite(sariPin, HIGH);    // set the yellow led is closed
    digitalWrite(kirmiziPin, HIGH); // set the red led is closed
  }
  else if(veri == '2'){  // if the data is 2
    digitalWrite(yesilPin, HIGH);   // setthe green led is closed
    digitalWrite(sariPin, LOW);   // set the yellow led is open
    digitalWrite(kirmiziPin, HIGH); // set the red led is closed
  }
  else if(veri == '3'){  // if the data is 3
    digitalWrite(yesilPin, HIGH);   // green led is closed
    digitalWrite(sariPin, HIGH);    // yellow led is closed
    digitalWrite(kirmiziPin, LOW); // red led is open
  }
  else if(veri == '4'){  // if the data is 4 (from the reset button)
    digitalWrite(yesilPin, HIGH);   // closed
    digitalWrite(sariPin, HIGH);    // closed
    digitalWrite(kirmiziPin, HIGH); // closed
  }
  

}
