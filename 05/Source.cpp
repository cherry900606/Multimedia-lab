#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main()
{
	//// 基本題
	//Mat src = imread("image.jpg", cv::IMREAD_GRAYSCALE);	// 灰階圖
	//Mat dst;// = Mat::zeros(src.rows, src.cols, CV_8UC1);
	//// Filling your code here
	//double scale = 0.2;
	//resize(src, src, Size(0, 0), scale, scale);
	//threshold(src, dst, 0, 255, THRESH_BINARY_INV | THRESH_OTSU);

	//Mat mask;

	//mask = cv::getStructuringElement(MORPH_RECT, Size(7, 7));
	//erode(dst, dst, mask, Point(-1, -1), 7);

	//Mat labels;
	//cout << connectedComponents(dst, labels) - 1;

	//imshow("src", src);
	//imshow("dst", dst);
	//imwrite("1.jpg", dst);
	//waitKey();

	// 加分題
	Mat img = imread("image.jpg", 0);
	resize(img, img, Size(img.cols * 0.2, img.rows * 0.2), 0, 0, INTER_LINEAR);
	Mat target;
	threshold(img, target, 127, 255, THRESH_BINARY_INV);
	Mat dst = target.clone();

	//膨脹
	int len = 2;
	for (int times = 0; times < 3; times++) {
		for (int i = len; i < dst.rows-len; i++) {
			for (int j = len; j < dst.cols-len; j++) {
				if (dst.at<uchar>(i, j) == 0) {
					bool valid = false;
					for (int a = i - len; a <= i + len; a++) {
						for (int b = j - len; b <= j + len; b++) {

							if (dst.at<uchar>(a, b) == 255) {
								valid = true;
								break;
							}
						}
						if (valid) {
							dst.at<uchar>(i, j) = 100;
							break;
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < dst.rows; i++) {
		for (int j = 0; j < dst.cols; j++) {
			if (dst.at<uchar>(i, j) == 100)
				dst.at<uchar>(i, j) = 255;
		}
	}
	// 再侵蝕
	len = 27;
	for (int times = 0; times < 5; times++) {
		for (int i = 0; i < dst.rows; i++) {
			for (int j = 0; j < dst.cols; j++) {
				if (dst.at<uchar>(i, j) == 255) {
					bool valid = false;
					for (int a = i - len; a <= i + len; a++) {
						for (int b = j - len; b <= j + len; b++) {
							int x = a, y = b;
							if (x >= dst.rows)  x = dst.rows - 1;
							if (x < 0) x = 0;
							if (y >= dst.cols) y = dst.cols - 1;
							if (y < 0) y = 0;
							
							if (dst.at<uchar>(x, y) == 0) {
								valid = true;
								break;
							}
						}
						if (valid) {
							dst.at<uchar>(i, j) = 100;
							break;
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < dst.rows; i++) {
		for (int j = 0; j < dst.cols; j++) {
			if (dst.at<uchar>(i, j) == 100)
				dst.at<uchar>(i, j) = 0;
		}
	}

	Mat labelImage;
	int nLabels = connectedComponents(dst, labelImage);
	cout << nLabels - 1 << endl;
	imshow("threshBinary", target);
	imshow("numbers:" + to_string(nLabels - 1), dst);
	imwrite("2.jpg", dst);
	waitKey();
}