#define TEMP_SENSOR1 0
#define TEMP_SENSOR2 1


void setup() {
  Serial.begin(9600);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
}

int signalVoltage1, signalVoltage2;
int celsiusTemp1, celsiusTemp2;

String dataLabel1 = "SENSOR_01";
String dataLabel2 = "SENSOR_02";
bool label = true;


void loop() {

  while(label) {//runs ones
    //enables headers
    Serial.print(dataLabel1);
    Serial.print(",");
    Serial.print(dataLabel2);
    label=false;
   }
  
  signalVoltage1 = analogRead(TEMP_SENSOR1);
  signalVoltage2 = analogRead(TEMP_SENSOR2);

  celsiusTemp1 = (5 * signalVoltage1 * 100) / 1024;
  celsiusTemp2 = (5 * signalVoltage2 * 100) / 1024;

  Serial.print("\n");
  delay(3000);
  Serial.print(celsiusTemp1, DEC);
  Serial.print(",");
  Serial.print(celsiusTemp2, DEC); 
}
