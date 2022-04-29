//* How to use the DHT-22 sensor with Arduino
//   Temperature and humidity sensor and
//   I2C LCD1602
 //  SDA --> A4
 //  SCL --> A5
 //DHT 22 out-->D7

//Libraries
#include <DHT.h>;
//I2C LCD:
// #include <LiquidCrystal_I2C.h>

#include <rgb_lcd.h>
#include <Wire.h>

// LiquidCrystal_I2C lcd(0x27,16,2); // set the LCD address to 0x27 for a 16 chars and 2 line display,Pls check your lcd.

rgb_lcd lcd;

//Constants
#define DHTPIN 7     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino

//Variables
//int chk;
int h;  //Stores humidity value
int t; //Stores temperature value


void setup()
{
    Serial.begin(9600);
    dht.begin();
    lcd.begin(16, 2);
    // lcd.init(); //initialize the lcd
    // lcd.backlight(); //open the backlight
    pinMode(6, OUTPUT);
}

void loop()
{
    //Read data and store it to variables h (humidity) and t (temperature)
    // Reading temperature or humidity takes about 250 milliseconds!
    h = dht.readHumidity();
    t = dht.readTemperature();
    // t = 20;
    
    //Print temp and humidity values to serial monitor
    Serial.print(h);
    Serial.print(" ");
    Serial.println(t);
// set the cursor to (0,0):
// print from 0 to 9:

    lcd.setCursor(0, 0);
    lcd.println(" Now Temperature ");
    
    lcd.setCursor(0, 1);
    lcd.print("T:");
    lcd.print(t);
    lcd.print("C");

    lcd.setCursor(6, 1);
    lcd.println("2022 ");
     
    lcd.setCursor(11, 1);
    lcd.print("H:");
    lcd.print(h);
    lcd.print("%");

    if(t > 24) {
      // 24+ Cardiovascular risk of strokes and heart attacks
      lcd.setCursor(0, 0);
      lcd.println(" Inc Discomfort ");
      digitalWrite(6, HIGH);
      delay(10000);
    } else if(t >= 21 && t <= 24) {
      // 21 -24 Increasing discomfort
      lcd.setCursor(0, 0);
      lcd.println(" Cardiovascular Risk ");
      digitalWrite(6, HIGH);
      delay(1000);
      digitalWrite(6, LOW);
      delay(1000);
    } else if(t >= 18 && t < 21) {
      // 18 - 21 Comfortable temperatures
    } else if(t >= 16 && t < 18) {
      // 16 - 18 Discomfort, small health risks
      lcd.setCursor(0, 0);
      lcd.println(" Small Health Risks ");
      digitalWrite(6, HIGH);
      delay(500);
      digitalWrite(6, LOW);
      delay(500);
    } else if(t >= 12 && t < 16) {
      // 12 - 16 Risk of respiratory diseases
      lcd.setCursor(0, 0);
      lcd.println(" Respiratory Diseases ");
      digitalWrite(6, HIGH);
      delay(500);
      digitalWrite(6, LOW);
      delay(500);
    } else if(t >= 9 && t < 12) {
      // 9 - 12 Risk of strokes, heart attacks
      lcd.setCursor(0, 0);
      lcd.println(" Stroke Risk, Heart Attacks ");
      digitalWrite(6, HIGH);
      delay(500);
      digitalWrite(6, LOW);
      delay(500);
    } else {
      // < 9 Risk of hypothermia
      lcd.setCursor(0, 0);
      lcd.println(" Hypothermia Risk");
      digitalWrite(6, HIGH);
      delay(500);
      digitalWrite(6, LOW);
      delay(500);
    }
    digitalWrite(6, LOW);
    
  delay(30000); //Delay 1 sec.
}