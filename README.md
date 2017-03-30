# HashEmArduino-MQTT
Projeto criado para avaliação de uma abordagem de segurança em IoT, usando Arduino para gerar e os transmitir usando o protocolo MQTT.

Para usar estes código, é necessário instalar na sua IDE do Ardino a biblioteca "SpritzCipher.h" disponivél em: https://github.com/abderraouf-adjal/ArduinoSpritzCipher.

Este projeto desenvolverue uma técnica que fornece segurança a nível de confidencialidade aos dados transmitidos por dispositivos com recursos limitados em sistemas IoT, usando o protocolo MQTT para a transmissão dos dados.

Para validação da eficácia da técnica proposta para o uso do Hash, serão seguidas as seguintes etapas:

Avaliação da Segurança (Conficencialidade dos dados transmitidos): Nesta etapa foram gerados valores Hash e então feita a tentativa de quebrar esses valores Hash com ferramentas disponiveis na Internet.

https://hashkiller.co.uk/sha1-decrypter.aspx

https://hashtoolkit.com/reverse-sha1-hash/

http://md5decrypt.net/en/Sha1/

http://insidepro.com/

https://crackstation.net/

http://sha1.gromweb.com/

https://isc.sans.edu/tools/reversehash.html

http://crackerpassword.sourceforge.net/



Avaliação do consumo de recursos dos dispositivos (Consumo de memória e espaço de armazenamento do Arduino): Para isso foram executados os algoritimos e analisado quanto cada um consumiu de recursos do Hardware:

1.	Verificar quanta memória e espaço de armazenamento o dispositivo gasta para receber o valor e concatenar tudo (valor + Salt + contador) - Algoritmo "gerar_aleatorios".

2.	Verificar quanto de memória e espaço de armazenamento a execução da função Hash consome no dispositivo para gerar o Hash de uma String com 14 caracteres - Algoritmo "gerar_hash_basico".

3.	Constatar quanto o protocolo MQTT consome de memória e espaço de armazenamento do dispositivo para transmitir dados - Algoritmo "mqtt_basic_alterado".

4.	Testar quanto à concatenação e o Hash consomem juntos de memória e espaço de armazenamento do dispositivo - Algoritmo "abordagem_completa".



