//
// Created by senaneuc on 18/07/18.
//

#ifndef LIBRAIRE_SUPERVISEUR_IMAGE_H
#define LIBRAIRE_SUPERVISEUR_IMAGE_H

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "Img.h"
#include "../include/definition.h"

enum captureSize {xs, sm, md, lg};

class Camera {


private:
    cv::VideoCapture cap;
    int size = sm;
    int width;
    int height;

public:

    Camera(int size);

    int open_camera();

    int getWidth() const;

    int getHeight() const;

    bool isOpen();
    void setSize(int size);

    int close_camera();
    Img grab_image();
};


#endif //LIBRAIRE_SUPERVISEUR_IMAGE_H
