class Ssignal{
  public:
  int signal,polarityA,polarityB;
  boolean polarity;
  int change=0;
  short int pwmCount=0;
  boolean up;

  
    void setPolarity(boolean polarity){
      digitalWrite(polarityA,0);
      digitalWrite(polarityB,0); 
      digitalWrite(polarityA,polarity);
      digitalWrite(polarityB,!polarity); 
    }
  
    Ssignal(int _signal,int _polarityA,int _polarityB,boolean _polarity,boolean _up,int initVoltage){
      signal=_signal;
      polarityA=_polarityA;
      polarityB=_polarityB;
      polarity=_polarity;
      up=_up;
      if(up)change=0;
      else change=initVoltage;
      pinMode(polarityA,OUTPUT);
      pinMode(polarityB,OUTPUT);
      pinMode(signal,OUTPUT);
      setPolarity(polarity);
    }

    void generate(){
      if(pwmCount==5){
      pwmCount=0;
      if(up){
         if(change==6){
          up=false;
         }else{
          change++;
        }
      }else{
        if(change==0){
          up=true;
          polarity=!polarity;
          setPolarity(polarity);
         }else{
          change--;
        }
      }
     
    }
    else pwmCount++;
    digitalWrite(signal,(pwmCount<=change));
    }
};


class Interruption{
  public:
    int reference;
    unsigned long int pwmTime=0;
  
    Interruption(int _reference){
      reference=_reference;
    }

    boolean event(unsigned long int myMicros){
      boolean interrupted=myMicros-pwmTime >= reference;
      if(interrupted){
        pwmTime=myMicros;
      }
      return interrupted;
    }
  
};




