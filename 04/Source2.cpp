//#include<opencv2/opencv.hpp>
//#include<iostream>
//
//using namespace cv;
//using namespace std;
//
//int main()
//{
//	// �m�ߤG
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
//	// ����X�C��pixel���X�{����
//	for (int i = 0; i < src.rows; i++)
//		for (int j = 0; j < src.cols; j++)
//			pSrc[src.at<uchar>(i, j)]++;
//	for (int i = 0; i < target.rows; i++)
//		for (int j = 0; j < target.cols; j++)
//			pTarget[target.at<uchar>(i, j)]++;
//
//	for (int i = 0; i < 256; i++)
//	{
//		// �p��X�{�����v
//		pSrc[i] /= nSrc;
//		pTarget[i] /= nTarget;
//		// �p��ֿn���v����
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
//	// ����������
//	int targetIndex = 0;
//	for (int i = 0; i < 256; i++)
//	{
//		while (cdfSrc[i] > cdfTarget[targetIndex])
//			targetIndex++;
//		pixelVal[i] = targetIndex;
//	}
//	
//	// �C�� pixel ������s�ϤW
//	for (int i = 0; i < src.rows; i++)
//		for (int j = 0; j < src.cols; j++)
//			dst.at<uchar>(i, j) = pixelVal[src.at<uchar>(i, j)];
//	imshow("src", src);
//	imshow("dst", dst);
//	imwrite("2-dark.jpg", dst);
//	waitKey();
//}