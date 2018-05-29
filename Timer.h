
#include <time.h>
#include <inttypes.h>



class Timer
{
public:

  void setperiod(unsigned long period);
  void every(unsigned long period, void (*callback)(void),bool start);
   
  void stop();
  void start();
  void update();
    
private:    
  unsigned long period;
  clock_t now, lastEventTime;
  void (*callback)(void);
  bool is_working;
 
};


