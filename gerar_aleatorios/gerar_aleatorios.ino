String salt = "fkllrnjnfd";
int randNumber;
String valorConcat;

void setup(){
  
  Serial.begin(9600);  // inicia a comunicação serial
  randomSeed(analogRead(0)); // inicia a lista de valores aleatórios
}

void loop(){
  randNumber = random(100); // sorteia um número de 0 a 99
 
 valorConcat = String(randNumber) + salt;
  
  Serial.println(valorConcat);  // envia o valor de randNumber pela serial
  delay(500); // espera 500 ms
}
