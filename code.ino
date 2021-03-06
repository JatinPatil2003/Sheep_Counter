

int s1trig = 8;
int s1echo = 9;
int s2trig = 12;
int s2echo = 13;
int count = 0;

void setup() {
  pinMode(s1trig, OUTPUT); 
  pinMode(s1echo, INPUT); 
  pinMode(s2trig, OUTPUT); 
  pinMode(s2echo, INPUT); 
  Serial.begin(9600); 
  
}
void loop() {
  int distances1 = distance(s1trig,s1echo);
  int distances2 = distance(s2trig,s2echo);
  
  while(isValid(distances1)){
    Serial.println("e1");
    distances1 = distance(s1trig,s1echo);
    distances2 = distance(s2trig,s2echo);
    while(isValid(distances2) && isValid(distances1)){
      Serial.println("e2");
      distances1 = distance(s1trig,s1echo);
      distances2 = distance(s2trig,s2echo);
      while(isValid(distances2) && !isValid(distances1)){
        Serial.println("e3");
        distances1 = distance(s1trig,s1echo);
        distances2 = distance(s2trig,s2echo);
        while(!isValid(distances2) && !isValid(distances1)){
          Serial.println("e4");
          count++;
          break;
        }
      }
    }
  }
  distances1 = distance(s1trig,s1echo);
  distances2 = distance(s2trig,s2echo);
  while(isValid(distances2)){
    Serial.println("r1");
    distances1 = distance(s1trig,s1echo);
    distances2 = distance(s2trig,s2echo);
    while(isValid(distances2) && isValid(distances1)){
      Serial.println("r2");
      distances1 = distance(s1trig,s1echo);
      distances2 = distance(s2trig,s2echo);
      while(isValid(distances1) && !isValid(distances2)){
        Serial.println("r3");
        distances1 = distance(s1trig,s1echo);
        distances2 = distance(s2trig,s2echo);
        while(!isValid(distances2) && !isValid(distances1)){
          Serial.println("r4");
          count--;
          break;
        }
      }
    }
  }
  
  
  Serial.print("count = ");
  Serial.println(count);
  delay(2000);
}





bool isValid(int distance){
  if(distance >= 50 && distance <= 300){
  	return true;
  }
  else{return false;}
}

int distance(int trig,int echo){
  long duration;
  int distance;
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = duration * 0.034 / 2;
  return distance;
}
