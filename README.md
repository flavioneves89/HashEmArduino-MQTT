# HashEmArduino-MQTT
Projeto criado para avaliação de uma abordagem de segurança em IoT, usando Arduino para gerar e transmitir dados usando o protocolo MQTT

Para usar estes código, é necessário instalar na sua IDE do Ardino a biblioteca "SpritzCipher.h" disponivél em: https://github.com/abderraouf-adjal/ArduinoSpritzCipher.

Este projeto tem como objetivo desenvolver e especificar uma técnica que forneça segurança a nível de confidencialidade aos dados transmitidos por dispositivos com recursos limitados em sistemas IoT, usando o protocolo MQTT.

Para validação da eficácia da técnica proposta para o uso do Hash, serão seguidas as seguintes etapas:

Avaliação da Segurança (Conficencialidade dos dados transmitidos): Nesta etapa foram gerados valores Hash.

Avaliação do consumo de recursos dos dispositivos (Consumo de memória e espaço de armazenamento do Arduino): Para isso foram executados os algoritimos e analisado quanto cada um consumia de recursos do Hardware:

1.	Verificar quanta memória e espaço de armazenamento o dispositivo gasta para receber o valor e concatenar tudo (valor + Salt + contador);
2.	Será feito um teste para verificar quanto de memória e espaço de armazenamento a execução da função Hash consome no dispositivo;
3.	Constatar quanto o protocolo MQTT consome de memória e espaço de armazenamento do dispositivo para transmitir dados;
4.	Testar quanto à concatenação e o Hash consomem juntos de memória e espaço de armazenamento do dispositivo;
5.	Verificar quanto os três consomem de memória e espaço de armazenamento do dispositivo para capturar dados de um dispositivo, gerar o valor Hash e enviar para o Broker MQTT.

