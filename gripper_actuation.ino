/* 
 * rosserial Subscriber Example
 * Blinks an LED on callback
 */

#include <ros.h>
#include <std_msgs/Int8.h>

ros::NodeHandle  nh;
int button_pressed = 0;


void messageCb( const std_msgs::Int8& msg){
  button_pressed = msg.data;
  
}

ros::Subscriber<std_msgs::Int8> sub("gripper", &messageCb );

int powerPin = 3;    
bool right = 0;    
int direc = 4;


void setup()
{ 
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(powerPin, OUTPUT);
  pinMode(direc, OUTPUT);

  nh.initNode();
  nh.subscribe(sub);
}

void loop()
{  

  if(button_pressed == 1){
    //Open or close
     analogWrite(powerPin, 100);
     digitalWrite(direc,right);
     delay(2500);
     analogWrite(powerPin, 0);
     button_pressed = 0;
     right =! right;
    }
  
  nh.spinOnce();
  delay(1);
}
