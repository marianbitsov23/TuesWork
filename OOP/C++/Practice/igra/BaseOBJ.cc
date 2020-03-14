#include "BaseOBJ.hh"
#include <iostream>
#include <string>
using namespace std;

BaseOBJ::BaseOBJ(int id, double pos[3], double rot[3], double scale[3], string model){
    this->id = id;
    this->position = pos;
    this->rotation = rot;
    this->scale = scale;
    this->model = model;
}

void BaseOBJ::setPosition(double x, double y, double z){
    this->position[0] = x;
    this->position[1] = y;
    this->position[2] = z;
}

void BaseOBJ::setRotation(double x, double y, double z){
    this->rotation[0] = x;
    this->rotation[1] = y;
    this->rotation[2] = z;
}

void BaseOBJ::setScale(double x, double y, double z){
    this->scale[0] = x;
    this->scale[1] = y;
    this->scale[2] = z;
}