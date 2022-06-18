#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main()
{
	// 練習一
	Mat src = imread("bright.jpg", cv::IMREAD_GRAYSCALE);	// 灰階圖
	Mat dst = Mat::zeros(src.rows, src.cols, CV_8UC1);
	Mat sample = Mat::zeros(src.rows, src.cols, CV_8UC1); // 測試用
	equalizeHist(src, sample);
	// Filling your code here
	//int pixelCount[256]
	double p[256] = { 0 };
	double cdf[256] = { 0 };
	double pixelVal[256] = { 0 };
	int n = src.rows * src.cols;

	// 先算出每個pixel的出現次數
	for (int i = 0; i < src.rows; i++)
		for (int j = 0; j < src.cols; j++)
			p[src.at<uchar>(i, j)]++;


	for (int i = 0; i < 256; i++)
	{
		// 計算出現的機率
		p[i] /= n;
		// 計算累積機率分布
		if (i == 0)
			cdf[i] = p[i];
		else
			cdf[i] = p[i] + cdf[i - 1];
		// 轉換成新的數值
		pixelVal[i] = round(cdf[i] * 255);
	}

	// 每個 pixel 對應到新圖上
	for (int i = 0; i < src.rows; i++)
		for (int j = 0; j < src.cols; j++)
			dst.at<uchar>(i, j) = pixelVal[src.at<uchar>(i, j)];
	imshow("src", src);
	imshow("dst", dst);
	imwrite("1-bright.jpg", dst);
	//imshow("sample", sample);
	waitKey();
}