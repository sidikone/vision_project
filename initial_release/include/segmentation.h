#ifndef SEGMENTATION_H
#define SEGMENTATION_H

#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

#include "smoothing.h"
#include "image_binary.h"

typedef std::vector<std::vector<cv::Point>> PointVect;

class SegmenTation{

private:

    bool seg_trig = false;
    bool contour_trig = false;
    bool stats_trig = false;

    bool watershed_trig = false;

    cv::Mat _imag;
    cv::Mat _im_remov_back;
    cv::Mat _im_bin;

    cv::Mat _labels;
    cv::Mat _stats;
    cv::Mat _centroids;
    cv::Mat _segment;
    cv::Mat _contours_imag;

    PointVect _contours;
    std::vector<cv::Vec4i> _hierarchy; // for segmentation

    int nb_obj;

    void randomColor(cv::Scalar&);

public:
    SegmenTation(){};
    SegmenTation(cv::Mat&);

// Preprocessing function

    void compute_background_removing(cv::Mat&, std::string);
    void compute_background_removing(std::string, int);
    void compute_image_binerization(std::string typ, double, double);
    void compute_image_cropping(int, int);

// display function
    void display_object_segmenation(bool);
    void display_contour_segmenation(bool);
    void display_object_segmenation();
    void display_contour_segmenation();
    void infos();

// Processing function
    void connected_components_image_segmenation(std::string);
    void find_contour_image_segmentation(std::string);

    void get_image_after_background_removing(cv::Mat&);
    void get_binary_image(cv::Mat&);
    void get_segment_labels(cv::Mat&);
    void get_segmented_image(cv::Mat&);
    void get_labels_centroids(cv::Mat&);
    void get_labels_stats(cv::Mat&);
    void get_contours(PointVect&);
    void get_contour_image(cv::Mat&);

};


#endif // SEGMENTATION_H