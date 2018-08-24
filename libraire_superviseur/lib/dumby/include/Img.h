//
// Created by senaneuc on 18/07/18.
//

#ifndef LIBRAIRE_SUPERVISEUR_IMAGE_H
#define LIBRAIRE_SUPERVISEUR_IMAGE_H

#include <iostream>
#include <list>
#include <opencv2/aruco/dictionary.hpp>
#include <opencv2/aruco/charuco.hpp>
#include <opencv2/core/mat.hpp>
#include "../include/definition.h"

#define ARENA_NOT_DETECTED -1

class Img {
private:
    cv::Mat img;
    Ptr<std::Dictionary> dictionary;

    float calculAngle(Position robots);
    float calculAngle2(cv::Point2f pt1, cv::Point2f pt2);
    cv::Point2f find_aruco_center(std::vector<cv::Point2f> aruco);
    cv::Point2f find_aruco_direction(std::vector<cv::Point2f> aruco);
    float euclideanDist(cv::Point2f p, cv::Point2f q);
    ImageMat cropArena(Arene arene);

public:
    Img(ImageMat imgMatrice);
    Jpg toJpg();
    std::list<Position> search_aruco(Arene monArene = NULL);
    std::list<Position> search_robot(Arene monArene = NULL);
    Arene search_arena();

    int draw_robot(Position robot);
    int draw_all_robots(std::list<Position> robots);
    int draw_arena(Arene areneToDraw);

};


#endif //LIBRAIRE_SUPERVISEUR_IMAGE_H
