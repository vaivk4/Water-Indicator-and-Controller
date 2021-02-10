#include &lt;LiquidCrystal.h&gt;
#define trigger 10
#define echo 11
#define motor 8
#define buzzer 12
LiquidCrystal lcd(7,6,5,4,3,2);
float time=0,distance=0;
int temp=0;
void setup()
{
lcd.begin(16,2);
pinMode(trigger,OUTPUT);
pinMode(echo,INPUT);
pinMode(motor, OUTPUT);
pinMode(buzzer, OUTPUT);
lcd.print(&quot; Water Level &quot;);
lcd.setCursor(0,1);
lcd.print(&quot; Indicator &quot;);
delay(2000);
}
void loop()
{
lcd.clear();
digitalWrite(trigger,LOW);
delayMicroseconds(2);
digitalWrite(trigger,HIGH);
delayMicroseconds(10);
digitalWrite(trigger,LOW);
delayMicroseconds(2);
time=pulseIn(echo,HIGH);
distance=time*340/200;
lcd.clear();
lcd.print(&quot;Water Space In &quot;);
lcd.setCursor(0,1);
lcd.print(&quot;Tank is: &quot;);
lcd.print(distance);
lcd.print(&quot;Cm&quot;);
delay(2000);
if(distance&lt;12 &amp;&amp; temp==0)
{
digitalWrite(motor, LOW);
digitalWrite(buzzer, HIGH);
lcd.clear();
lcd.print(&quot;Water Tank Full &quot;);
lcd.setCursor(0,1);
lcd.print(&quot;Motor Turned OFF&quot;);
delay(2000);
digitalWrite(buzzer, LOW);
Serial.println(distance);

delay(3000);
temp=1;
}
else if(distance&lt;12 &amp;&amp; temp==1)
{
digitalWrite(motor, LOW);
lcd.clear();
lcd.print(&quot;Water Tank Full &quot;);
lcd.setCursor(0,1);
lcd.print(&quot;Motor Turned OFF&quot;);
Serial.println(distance);
delay(5000);
}
else if(distance&gt;30)
{
digitalWrite(motor, HIGH);
lcd.clear();
lcd.print(&quot;LOW Water Level&quot;);
lcd.setCursor(0,1);
lcd.print(&quot;Motor Turned ON&quot;);
Serial.println(distance);
delay(5000);
temp=0;
}
}
