#ifndef BASEOBJ_HH
#define BASEOBJ_HH
#include <string>

class BaseOBJ{
    private:
        int id;

    public:
        double position[3];
        double rotation[3];
        double scale[3];
        string model;

        BaseOBJ(int id, double pos[3], double rot[3], double scale[3], string model);
        void setPosition(double x, double y, double z);
        void setRotation(double x, double y, double z);
        void setScale(double x, double y, double z);

};
#endif