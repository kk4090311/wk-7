
#include "SSD1306Wire.h"
SSD1306Wire  display(0x3c, 21, 22);

void setup() {
  Serial.begin(115200); //設定傳輸鮑率，跟電腦傳輸資料的頻率
  pinMode(13, INPUT); //設定腳位為輸入用
  display.init();

  display.flipScreenVertically(); //畫面上下顛倒顯示

  ledcSetup(0, 5000, 8);   //頻率5000，頻道0，解析度8;
  ledcAttachPin(14, 0);  //將上述頻道0附加到ledPin腳位14上
}

void loop() {
  int input = analogRead(13);
  int input_map = input;
  String thisString = String(input_map);
  Serial.println(input_map);


  display.clear(); //清空畫面
  display.setFont(ArialMT_Plain_16);   //設定字型與大小
  display.drawString(0, 0,"Value");
  display.drawString(0, 16,thisString );  //(x座標,y座標,"字串")
  display.display(); //顯示畫面
  delay(200);
  
}
