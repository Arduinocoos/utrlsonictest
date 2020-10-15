
int trigPin=3;
int echoPin=2;
double vspeed;
double old_distance;
int n;
void setup() {
n = 0;
vspeed=0.0;
old_distance=0.0;
Serial.begin(115200);
Serial1.begin(115200);
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);
}

void loop() {
  n++;
  digitalWrite(trigPin, LOW); // 使发出发出超声波信号接口低电平2μs
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); // 使发出发出超声波信号接口高电平10μs，这里是至少10μs
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);    // 保持发出超声波信号接口低电平
  
  double distance = pulseIn(echoPin, HIGH);  // 读出脉冲时间
  double dis= distance * 0.017;   // 将脉冲时间转化为距离（单位：厘米）
    delay(30);
    if(n>=5)
    {
      vspeed = fabs(distance - old_distance) * 170 / (distance + old_distance + 150000); //两次间隔的距离差求速度 （单位：米/秒）
      n=0;
     old_distance= distance;
      }
  
  Serial.println("Distance:" + String(dis) + "#Speed:" + String(vspeed) + "#n:" + String(n));
  Serial1.println("Distance:" + String(dis) + "#Speed:" + String(vspeed) + "#n:" + String(n));


}
