#include "lib.hpp"

void hello() { std::cout << " Hello World" << std::endl; }
void my_img_show() {
  std::cout << "image show!!" << std::endl;
  cv::Mat image(320, 240, CV_8UC3, cv::Scalar(255, 0, 0));
  cv::imshow("hello", image);
}
