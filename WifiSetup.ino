//📶🛜 wifi function

void WifiSetup(){
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
      Serial.print("Connecting to Wi-Fi");
      while (WiFi.status() != WL_CONNECTED)
      {
          Serial.print(".");
          vTaskDelay(pdMS_TO_TICKS(700));
      }
      Serial.println(" ");
}