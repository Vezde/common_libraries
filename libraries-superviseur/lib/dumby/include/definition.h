//
// Created by senaneuc on 18/07/18.
//

#ifndef LIBRAIRE_SUPERVISEUR_DEFINITION_H
#define LIBRAIRE_SUPERVISEUR_DEFINITION_H

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core.hpp>

typedef cv::Mat ImageMat;
typedef cv::Rect Arene;
typedef std::vector<unsigned char> Jpg;

struct Position {
    cv::Point2f center;
    cv::Point2f direction;
    float angle;
    int robotId;
};

#endif //LIBRAIRE_SUPERVISEUR_DEFINITION_H
