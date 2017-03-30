#include <SpritzCipher.h>

#define hex_char(n) ((n) < 10 ? '0' + (n) : 'A' + ((n)-10))

const char salt[] = "xyzxyzxyzy"; //A String with 10 characters
char string[13] = "";
byte hash[32]; // byte hash
char hash_string[65]; // hex string hash 
//simulação de um sensor pra testes
void randomico(char *string)
{
    int randNumber = random(100); // Draw a number from 0 to 99
    itoa(randNumber, string, 10); // convert int into char array
    strcat(string, salt); // concatenate salt
}
//End of simulation
void bytes_to_hexstr(char *string, byte *bytes, int size)
{
    for (int i = 0; i < size; i++)
    {
        string[i*2] = bytes[i] < 16 ? '0' : hex_char((bytes[i] >> 4) & 0xF);
        string[i*2+1] = hex_char(bytes[i] & 0xF);
    }
    string[size*2] = 0;
}

void setup()
{
  Serial.begin(115200);
  while (!Serial);

  randomSeed(analogRead(0)); // Starts the list of random values
}

void loop()
{
    randomico(string); // generate random salted string into 'string' variable
    spritz_hash(hash, 32, (byte*)string, strlen(string)); // hash 'string' into 'hash' variable (hash only the character inside the string not the full char array)
    bytes_to_hexstr(hash_string, hash, 32); // convert byte hash into printable hex string

    // print out string and hash
    Serial.print(string);
    Serial.print(" -> ");
    Serial.println(hash_string);

    delay(1000);
}
