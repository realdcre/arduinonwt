import processing.serial.*;
//declare
PrintWriter output;
Serial udSerial;

int analogPin = A3; // potentiometer wiper (middle terminal) connected to analog pin 3
                    // outside leads to ground and +5V
int val = 0;  // variable to store the value read


void setup() {
  Serial.begin(74880);           //  setup serial
   udSerial = new Serial(this, Serial.list()[0], 74880);
  output = createWriter ("export.txt");
     void draw() {
    if (udSerial.available() > 0) {
      String SenVal = udSerial.readString();
      if (SenVal != null) {
        output.println(SenVal);
        }
    }
  }

  void keyPressed(){
    output.flush();
    output.close();
    exit(); 
  }

}
  

void loop() {
  val = analogRead(analogPin);  // read the input pin
  Serial.println(val);          // export value to serial
  

  
}
