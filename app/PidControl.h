

#include "ColorMonitor.h"

class PidControl{
public:
    PidControl(ColorMonitor* colorMonitor);

    double calc_pid_value();
private:
    ColorMonitor* mColorMonitor;
    int mDiff[2] = {0, 0};
    double mIntegral = 0;

    const int target = 21;
    const double kp = 5;
    const double ki = 0;
    const double kd = 15;

};