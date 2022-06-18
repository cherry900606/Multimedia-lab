//#include<opencv2/opencv.hpp>
//#include<iostream>
//
//using namespace cv;
//using namespace std;
//
//int main()
//{
//	// 練習二
//	Mat src = imread("dark.jpg", cv::IMREAD_GRAYSCALE);
//	Mat target = imread("target.jpg", cv::IMREAD_GRAYSCALE);
//	Mat dst = Mat::zeros(src.rows, src.cols, CV_8UC1);
//	//Mat sample = Mat::zeros(src.rows, src.cols, CV_8UC1);
//
//	double pSrc[256] = { 0 }, pTarget[256] = { 0 };
//	double cdfSrc[256] = { 0 }, cdfTarget[256] = { 0 };
//	double pixelVal[256] = { 0 };
//	int nSrc = src.rows * src.cols, nTarget = target.rows * target.cols;
//
//	// 先算出每個pixel的出現次數
//	for (int i = 0; i < src.rows; i++)
//		for (int j = 0; j < src.cols; j++)
//			pSrc[src.at<uchar>(i, j)]++;
//	for (int i = 0; i < target.rows; i++)
//		for (int j = 0; j < target.cols; j++)
//			pTarget[target.at<uchar>(i, j)]++;
//
//	for (int i = 0; i < 256; i++)
//	{
//		// 計算出現的機率
//		pSrc[i] /= nSrc;
//		pTarget[i] /= nTarget;
//		// 計算累積機率分布
//		if (i == 0)
//		{
//			cdfSrc[i] = pSrc[i];
//			cdfTarget[i] = pTarget[i];
//		}
//		else
//		{
//			cdfSrc[i] = pSrc[i] + cdfSrc[i - 1];
//			cdfTarget[i] = pTarget[i] + cdfTarget[i - 1];
//		}
//
//	}
//	// 找到對應的值
//	int targetIndex = 0;
//	for (int i = 0; i < 256; i++)
//	{
//		while (cdfSrc[i] > cdfTarget[targetIndex])
//			targetIndex++;
//		pixelVal[i] = targetIndex;
//	}
//	
//	// 每個 pixel 對應到新圖上
//	for (int i = 0; i < src.rows; i++)
//		for (int j = 0; j < src.cols; j++)
//			dst.at<uchar>(i, j) = pixelVal[src.at<uchar>(i, j)];
//	imshow("src", src);
//	imshow("dst", dst);
//	imwrite("2-dark.jpg", dst);
//	waitKey();
//}