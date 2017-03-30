String salt = "fkllrnjnfd";
int randNumber;
String valorConcat;

void setup(){
  
  Serial.begin(9600);  // Initiates serial communication
  randomSeed(analogRead(0)); // Starts the list of random values
}

void loop(){
  randNumber = random(100); // Draw a number from 0 to 99
 
 valorConcat = String(randNumber) + salt;
  
  Serial.println(valorConcat);  // Sends the value of randNumber to the serial
  delay(500); // espera 500 ms
}
