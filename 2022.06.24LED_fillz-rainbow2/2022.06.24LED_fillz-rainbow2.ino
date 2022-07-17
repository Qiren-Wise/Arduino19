#include "FastLED.h"

FASTLED_USING_NAMESPACE

//#if defined(FASTLED_VERSION) && (FASTLED_VERSION<3001000)fine
//#waring "Requires FastLED 3.1 or later;check gihub for latest code"
//#endif

#define DATA_PIN  3
#define LED_TYPE  WS2811    //led灯带型号
#define COLOR_ORDER GRB
#define NUM_LEDS  64   //灯珠
//CRGB leds[NUM_LEDS];

 #define BRIGHTNESS         96
 #define FRAMES_PER_SECOND  120
 #define COLOR_ORDER GRB

 uint8_t max_bright = 128;

 CRGB leds[NUM_LEDS];  //建立光带leds  c=控制  

 CRGB myRGBcolor(50,0,50);  //(rValue,gValue,bValue)  0-255

  CHSV myHSVcolor(80,255,200);//HSV方法定义颜色 ，（色调，饱和度，明亮）

  uint8_t beginHue; //起始色调值
  
 void setup()
 {
   Serial.begin(9600);
   delay(1000);

   LEDS.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds,NUM_LEDS);//初始化光带
   FastLED.setBrightness(max_bright);                        //设置宽带亮度  
  }



void loop() {
  // put your main code here, to run repeatedly:
  fill_gradient_RGB(leds,0,CRGB::Red,29,CRGB::Blue);//(光带名，起始灯珠号，起始RGB色彩，结束灯珠号，结束RGB色彩)
  //fill_gradient_RGB(leds,0,CRGB(50,255,255),29,CRGB::Blue,LONGEST_HUES);
     addGlitter(60);  
  //fill_rainbow(leds,30,beginHue,1);//( , , ,第一个开始)
  FastLED.show();
  delay(50);

}
