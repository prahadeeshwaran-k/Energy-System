void TaskRTDBmain(){
 if (Firebase.ready() && (millis() - sendDataPrevMillis > 3000 || sendDataPrevMillis == 0))
    {
        //🕒 no need of time Stupid its realTime only SDlog needed
        sendDataPrevMillis = millis();
        FirebaseJsonArray arr;
        float voltage = random(1,100);//pzem.voltage();
        float current = random(1,100);//pzem.current();
        float power = random(1,100);//pzem.power();
        int frequency = random(1,100);//pzem.frequency();
        float energy = random(1,1100);//pzem.pf();
        arr.add(voltage, current, power, frequency, energy);
        Serial.printf("Set array... %s\n", Firebase.RTDB.setArray(&fbdo, "/PZEM/Info", &arr) ? "ok" : fbdo.errorReason().c_str());
    }
        //int dummyVariable;
        //(void)dummyVariable; // Avoid "unused variable" warning
        // Size of the function in bytes
        //Serial.printf("Size of TaskRTDBmain: %d bytes\n", sizeof(dummyVariable) * __LINE__);
}
    