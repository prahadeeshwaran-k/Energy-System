//🕒connect npt server & get the time

void TimeSetup(){
  sntp_set_time_sync_notification_cb( timeavailable );
  sntp_servermode_dhcp(1);    // (optional)
  configTzTime(time_zone, ntpServer1, ntpServer2);
  struct tm time;
  do {
    Serial.print("-");
    vTaskDelay(pdMS_TO_TICKS(300));
  }
  while (!getLocalTime(&time));
}
 