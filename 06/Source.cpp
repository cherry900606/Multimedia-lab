#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat src = imread("pikachu.png", cv::IMREAD_GRAYSCALE);	// ¦Ç¶¥¹Ï
	Mat dst = Mat::zeros(src.rows, src.cols, CV_8UC1);
	// Filling your code here
	for (int i = 0; i < src.rows; i++)
	{
		for (int j = 0; j < src.cols; j++)
		{
			int Gx = 0, Gy = 0;
			

			if (i == 0 || i == src.rows - 1 || j == 0 || j == src.cols - 1) continue;
			Gx = abs(src.at<uchar>(i - 1, j - 1) * -1 + src.at<uchar>(i, j - 1) * -2 + src.at<uchar>(i + 1, j - 1) * -1
				+ src.at<uchar>(i - 1, j + 1) * 1 + src.at<uchar>(i, j + 1) * 2 + src.at<uchar>(i + 1, j + 1) * 1);
			Gy = abs(src.at<uchar>(i - 1, j - 1) * -1 + src.at<uchar>(i - 1, j) * -2 + src.at<uchar>(i - 1, j + 1) * -1
				+ src.at<uchar>(i - 1, j - 1) * 1 + src.at<uchar>(i + 1, j) * 2 + src.at<uchar>(i + 1, j + 1) * 1);

			if (Gx + Gy > 200)
				dst.at<uchar>(i, j) = 255;
		}
	}
	imshow("src", src);
	imshow("dst", dst);
	imwrite("result.png", dst);
	waitKey();
}