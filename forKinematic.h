
#ifndef FORKINEMATIC_H
#define FORKINEMATIC_H

class ForKinematic{
    private:
        float alpha, v_w1, v_w2, v_w3, v_w4;
        float alpha1, alpha2, alpha3, alpha4;
        const int PWM_max = 255;
        const double omega_max = 62.83; // maximum velocity rad/s
        const double radius = 0.03; // jari-jari roda
    public:
        ForKinematic();

        // float omega (float alpha,float v_w1, float v_w2, float v_w3, float v_w4) {
        //     return (-sin(alpha)*v_w1 - sin(alpha));
        // }

        // ------------ for encoder
        float encVelocityX(float alpha1, float alpha2, float alpha3, float v_w1, float v_w2, float v_w3){
            float x1 = -sin(alpha1)*v_w1;
            float x2 = -sin(alpha2)*v_w2;
            float x3 = -sin(alpha3)*v_w3;
            return (x1 + x2 + x3);
        }
        
        float encVelocityY(float alpha1, float alpha2, float alpha3, float v_w1, float v_w2, float v_w3){
            float y1 = cos(alpha1)*v_w1;
            float y2 = cos(alpha2)*v_w2;
            float y3 = cos(alpha3)*v_w3;
            return (y1 + y2 + y3);;
        }

        float encOmega(int v_w1, int v_w2, int v_w3){
            return v_w1 + v_w1 + v_w3;
        }

        // ------------ for motor
        float velocityX(float alpha1, float alpha2, float alpha3, float alpha4, float v_w1, float v_w2, float v_w3, float v_w4){
            float x1 = -sin(alpha1)*v_w1;
            float x2 = -sin(alpha2)*v_w2;
            float x3 = -sin(alpha3)*v_w3;
            float x4 = -sin(alpha4)*v_w4;
            return (0.03/4)*(x1 + x2 + x3 + x4);
        }

        float velocityY(float alpha1, float alpha2, float alpha3, float alpha4, float v_w1, float v_w2, float v_w3, float v_w4){
            float y1 = cos(alpha1)*v_w1;
            float y2 = cos(alpha2)*v_w2;
            float y3 = cos(alpha3)*v_w3;
            float y4 = cos(alpha4)*v_w4;
            return (0.03/4)*(y1 + y2 + y3 + y4);
        }

        int omega(int v_w1, int v_w2, int v_w3, int v_w4){
            return v_w1 + v_w1 + v_w3 + v_w4;
        }

        // maximum velocity (1.8849 m/s)
        int velocity_to_pwm(double v_w) {
            double omega = v_w / radius;                 // Hitung kecepatan angular motor
            int pwm = static_cast<int>((omega / omega_max) * PWM_max); // Skala ke nilai PWM
            // pwm = max(0, min(pwm, PWM_max));       // Batas nilai PWM [0, PWM_max]
            return pwm;
        }
};

#endif