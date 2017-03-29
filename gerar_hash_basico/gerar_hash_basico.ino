#include <SpritzCipher.h>


/* Data to input */

const byte testData[14] = {'g', 't','f', 'k', 'l', 'l','f', 'k', 'l', 'l', 'r', 'n', 'j', 'n'};

/* Test vectors */
/* Data = 'testData' hash test vectors */
const byte testVector[32] =
{ 0xff, 0x8c, 0xf2, 0x68, 0x09, 0x4c, 0x87, 0xb9,
  0x5f, 0x74, 0xce, 0x6f, 0xee, 0x9d, 0x30, 0x03,
  0xa5, 0xf9, 0xfe, 0x69, 0x44, 0x65, 0x3c, 0xd5,
  0x0e, 0x66, 0xbf, 0x18, 0x9c, 0x63, 0xf6, 0x99
};


void testFunc(const byte ExpectedOutput[32], const byte *data, byte dataLen)
{
  byte hashLen = 32; /* 256-bit */
  byte digest[hashLen]; /* Output buffer */
  byte digest_2[hashLen]; /* Output buffer for chunk by chunk API */
  spritz_ctx hash_ctx; /* the CTX for chunk by chunk API */
  unsigned int i;

  /* Print input */
  for (i = 0; i < dataLen; i++) {
    Serial.write(data[i]);
  }
  Serial.println();

  spritz_hash_setup(&hash_ctx);
  /* For easy test: code add a byte each time */
  for (i = 0; i < dataLen; i++) {
    spritz_hash_update(&hash_ctx, data + i, 1);
  }
  spritz_hash_final(&hash_ctx, digest_2, hashLen);

  spritz_hash(digest, hashLen, data, dataLen);

  for (i = 0; i < sizeof(digest); i++) {
    if (digest[i] < 0x10) { /* To print "0F" not "F" */
      Serial.write('0');
    }
    Serial.print(digest[i], HEX);
  }

  /* Check the output */
  if (spritz_compare(digest, ExpectedOutput, sizeof(digest)) || spritz_compare(digest_2, ExpectedOutput, sizeof(digest_2))) {
    /* If the output is wrong "Alert" */
    digitalWrite(LED_BUILTIN, HIGH); /* Turn pin LED_BUILTIN On (Most boards have this LED connected to digital pin 13) */
    Serial.println("\n** WARNING: Output != Test_Vector **");
  }
  Serial.println();
}

void setup() {
  /* Initialize serial and wait for port to open */
  Serial.begin(9600);
  while (!Serial) {
    ; /* Wait for serial port to connect. Needed for Leonardo only */
  }

  /* initialize digital pin LED_BUILTIN (Most boards have this LED connected to digital pin 13) as an output */
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
  Serial.println("[Spritz spritz_hash*() test]\n");

 
  testFunc(testVector, testData, sizeof(testData));

  delay(5000); /* Wait 5s */
  Serial.println();
}
