// #include <math.h>

#ifndef KINEMATIC_H
#define KINEMATIC_H

class Kinematic{
    private:
        float alpha, v_x, v_y;
    public:
        Kinematic();

        float invKinematic (float alpha, float v_x, float v_y) {
            return (1/0.005)*((-sin(alpha)*v_x) + (cos(alpha)*v_y) + 0.25);
        }
};

#endif