#ifndef __RESERVATION_FILE
#define __RESERVATION_FILE

#include <map>
#include <string>
using namespace std;

class ReservationFile
{
public:
    ReservationFile();
    ~ReservationFile();
    void LoadReservation();
    void SaveReservation();

    map<int, map<string, string>> reservations_;
};

#endif  // __RESERVATION_FILE
