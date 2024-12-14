#include <Servo.h>
#include <ArduinoJson.h>
#include <SoftwareSerial.h>

SoftwareSerial BTSerial(2, 3);

Servo servo1;
Servo servo2;

// 모터 센서 연결 (PWM 핀으로 변경)
int motor1 = 4;
int motor2 = 5;

// 모터 초기 각도 90도로 설정
int angle1 = 90;
int angle2 = 90;

// 벌레 검출 개수

void setup() {
  // 서보 모터 연결
  servo1.attach(motor1);
  servo2.attach(motor2);

  // 초기화
  servo1.write(angle1); 
  servo2.write(angle2);

  Serial.begin(9600);
  BTSerial.begin(38400);

  pinMode(7, OUTPUT);
  digitalWrite(7, HIGH);
}

void loop() {
  // Python에서 JSON 데이터 수신
  Serial.println(1);
  if (Serial.available() > 0) {
    String myjson = Serial.readStringUntil('\n');
    if (myjson) {
      BTSerial.write("aaaaa\n");
      for (int i = 0; i < 5; i++) {
        angle1 += 180;
        angle2 -= 180;
        servo1.write(angle1);
        servo2.write(angle2);
        delay(700);

        angle1 -= 180;
        angle2 += 180;
        servo1.write(angle1);
        servo2.write(angle2);
        delay(700);
        }
      }
      
    }
    // DeserializationError error = deserializeJson(doc, myjson);
    // if (error) {
    //   Serial.print(F("deserializeJson() failed: "));
    //   Serial.println(error.f_str());
    //   return;
    // }

    // JSON 데이터 처리
  //   if (doc.containsKey("spiders")) {
  //     spiders = doc["spiders"];
  //     Serial.println("벌레 수: " + String(spiders));
  //   } else {
  //     Serial.println("JSON 데이터에 spiders 키가 없습니다.");
  //     return;
  //   }

  //   // 벌레 검출 시 서보 모터 동작

  // }

  delay(200); // 빠른 반복 방지
}
