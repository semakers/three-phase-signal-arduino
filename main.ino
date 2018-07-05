Interruption interruption(96);
Ssignal ssignal(2,3,4,true,true,0);
Ssignal ssignal2(5,6,7,true,false,4);
Ssignal ssignal3(8,9,10,true,false,2);

void setup() {}

void loop() {
  if(interruption.event(micros())){
    ssignal.generate();
    ssignal2.generate();
    ssignal3.generate();
  }
}
