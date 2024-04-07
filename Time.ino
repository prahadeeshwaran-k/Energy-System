//🛎️Run only one time after connected in ntp

void timeavailable(struct timeval *t)
{
  Serial.println("Got time adjustment from NTP!");
  LocalTime();
}

//🚨IT tell the local time run in esp32

void LocalTime()
{
  char buffer[80];
  struct tm time;
  if(!getLocalTime(&time)){
    Serial.println("No time available (yet)");
    return;
  }
  strftime(buffer, sizeof(buffer), "%c", &time);
  Serial.println(buffer);//https://techtutorialsx.com/2021/09/01/esp32-system-time-and-sntp/ 
}