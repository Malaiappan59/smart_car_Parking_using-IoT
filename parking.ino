#include<ESP8266WiFi.h>;

#include<WiFiClient.h>;

#include"ThingSpeak.h";

const char* ssid="Sundar";

const char* password="56j1reu54v";

WiFiClient client;

unsigned long myChannelNumber =1842871 ;
int field1=1;
int field2=2;

const char* myWriteAPIKey="BYPH6ELX5ROACRSP";

const char* myReadAPIKey="PQSLUOMGO0TNCV9T";

int led1=D2;

int led2=D3;

int ir1=D0;

int ir2=D1;

void setup(){

Serial.begin(9600);

delay(10);

pinMode(ir1,INPUT);

pinMode(ir2,INPUT);

pinMode(led1,OUTPUT);

pinMode(led2,OUTPUT);

WiFi.begin(ssid,password);

ThingSpeak.begin(client);

}

void loop(){

int s1=digitalRead(ir1);

int s2=digitalRead(ir2);

Serial.print(s1);

Serial.print(s2);

if(s1==0){

digitalWrite(led1,LOW);

}

else{

digitalWrite(led1,HIGH);

}

if(s2==0){

digitalWrite(led2,LOW);

}

else{

digitalWrite(led2,HIGH);

}

ThingSpeak.writeField(myChannelNumber,1,s1,myWriteAPIKey);

ThingSpeak.writeField(myChannelNumber,2,s2,myWriteAPIKey);

 

}
