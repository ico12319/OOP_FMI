#include "Date.h"

const int EVENT_NAME_MAX_LEN = 20;

class Event{
    
private:
    char name[EVENT_NAME_MAX_LEN + 1] = "Unknown";
    Date date;
    int startHour = 0;
    int endHour = 0;
    
public:
    Event() = default;
    Event(const char* name,const Date& date,int startHour,int endHour);
    
    const char* getName() const;
    Date getDate() const;
    int getStartHour() const;
    int getEndHor() const;
    
    void setName(const char* name);
    void setDate(const Date& date);
    void setStartHour(int startHour);
    void setEndHour(int endHour);
    
    void printEvent() const;
    
};
