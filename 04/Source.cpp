//#include<opencv2/opencv.hpp>
//#include<iostream>
//
//using namespace cv;
//using namespace std;
//
//int main()
//{
//	//// �m�ߤ@
//	//Mat src = imread("bright.jpg", cv::IMREAD_GRAYSCALE);	// �Ƕ���
//	//Mat dst = Mat::zeros(src.rows, src.cols, CV_8UC1);
//	//Mat sample = Mat::zeros(src.rows, src.cols, CV_8UC1); // ���ե�
//	//equalizeHist(src, sample);
//	//// Filling your code here
//	////int pixelCount[256]
//	//double p[256] = { 0 };
//	//double cdf[256] = { 0 };
//	//double pixelVal[256] = { 0 };
//	//int n = src.rows * src.cols;
//
//	//// ����X�C��pixel���X�{����
//	//for (int i = 0; i < src.rows; i++)
//	//	for (int j = 0; j < src.cols; j++)
//	//		p[src.at<uchar>(i, j)]++;
//
//
//	//for (int i = 0; i < 256; i++)
//	//{
//	//	// �p��X�{�����v
//	//	p[i] /= n;
//	//	// �p��ֿn���v����
//	//	if (i == 0)
//	//		cdf[i] = p[i];
//	//	else
//	//		cdf[i] = p[i] + cdf[i - 1];
//	//	// �ഫ���s���ƭ�
//	//	pixelVal[i] = round(cdf[i] * 255);
//	//}
//
//	//// �C�� pixel ������s�ϤW
//	//for (int i = 0; i < src.rows; i++)
//	//	for (int j = 0; j < src.cols; j++)
//	//		dst.at<uchar>(i, j) = pixelVal[src.at<uchar>(i, j)];
//	//imshow("src", src);
//	//imshow("dst", dst);
//	//imwrite("1-bright.jpg", dst);
//	////imshow("sample", sample);
//	//waitKey();
//
//	//// �m�ߤG
//	//Mat src = imread("dark.jpg", cv::IMREAD_GRAYSCALE);
//	//Mat target = imread("target.jpg", cv::IMREAD_GRAYSCALE);
//	//Mat dst = Mat::zeros(src.rows, src.cols, CV_8UC1);
//	////Mat sample = Mat::zeros(src.rows, src.cols, CV_8UC1);
//
//	//double pSrc[256] = { 0 }, pTarget[256] = { 0 };
//	//double cdfSrc[256] = { 0 }, cdfTarget[256] = { 0 };
//	//double pixelVal[256] = { 0 };
//	//int nSrc = src.rows * src.cols, nTarget = target.rows * target.cols;
//
//	//// ����X�C��pixel���X�{����
//	//for (int i = 0; i < src.rows; i++)
//	//	for (int j = 0; j < src.cols; j++)
//	//		pSrc[src.at<uchar>(i, j)]++;
//	//for (int i = 0; i < target.rows; i++)
//	//	for (int j = 0; j < target.cols; j++)
//	//		pTarget[target.at<uchar>(i, j)]++;
//
//	//for (int i = 0; i < 256; i++)
//	//{
//	//	// �p��X�{�����v
//	//	pSrc[i] /= nSrc;
//	//	pTarget[i] /= nTarget;
//	//	// �p��ֿn���v����
//	//	if (i == 0)
//	//	{
//	//		cdfSrc[i] = pSrc[i];
//	//		cdfTarget[i] = pTarget[i];
//	//	}
//	//	else
//	//	{
//	//		cdfSrc[i] = pSrc[i] + cdfSrc[i - 1];
//	//		cdfTarget[i] = pTarget[i] + cdfTarget[i - 1];
//	//	}
//
//	//}
//	//// ����������
//	//int targetIndex = 0;
//	//for (int i = 0; i < 256; i++)
//	//{
//	//	while (cdfSrc[i] > cdfTarget[targetIndex])
//	//		targetIndex++;
//	//	pixelVal[i] = targetIndex;
//	//}
//	//
//	//// �C�� pixel ������s�ϤW
//	//for (int i = 0; i < src.rows; i++)
//	//	for (int j = 0; j < src.cols; j++)
//	//		dst.at<uchar>(i, j) = pixelVal[src.at<uchar>(i, j)];
//	//imshow("src", src);
//	//imshow("dst", dst);
//	//imwrite("2-dark.jpg", dst);
//	//waitKey();
//
//	// �[���D ���@
//	//Mat src = imread("bright.jpg");
//	//Mat dst = Mat::zeros(src.rows, src.cols, CV_8UC3);
//	//
//	//// Filling your code here
//	////int pixelCount[256]
//	//double p[3][256] = { 0 };
//	//double cdf[3][256] = { 0 };
//	//double pixelVal[3][256] = { 0 };
//	//int n = src.rows * src.cols;
//
//	//// ����X�C��pixel���X�{����
//	//for (int i = 0; i < src.rows; i++)
//	//	for (int j = 0; j < src.cols; j++)
//	//		for(int k=0;k<3;k++)
//	//			p[k][src.at<Vec3b>(i, j)[k]]++;
//
//	//for (int k = 0; k < 3; k++)
//	//{
//	//	for (int i = 0; i < 256; i++)
//	//	{
//	//		// �p��X�{�����v
//	//		p[k][i] /= n;
//	//		// �p��ֿn���v����
//	//		if (i == 0)
//	//			cdf[k][i] = p[k][i];
//	//		else
//	//			cdf[k][i] = p[k][i] + cdf[k][i - 1];
//	//		// �ഫ���s���ƭ�
//	//		pixelVal[k][i] = round(cdf[k][i] * 255);
//	//	}
//	//}
//	//
//
//	//// �C�� pixel ������s�ϤW
//	//for (int i = 0; i < src.rows; i++)
//	//	for (int j = 0; j < src.cols; j++)
//	//		for(int k=0;k<3;k++)
//	//			dst.at<Vec3b>(i, j)[k] = pixelVal[k][src.at<Vec3b>(i, j)[k]];
//	//imshow("src", src);
//	//imshow("dst", dst);
//	//imwrite("bonus1-bright.jpg", dst);
//	//waitKey();
//
//	//// �[���D ���G
//	Mat src = imread("dark.jpg");
//	Mat target = imread("target.jpg");
//	Mat dst = Mat::zeros(src.rows, src.cols, CV_8UC3);
//	//Mat sample = Mat::zeros(src.rows, src.cols, CV_8UC1);
//
//	double pSrc[3][256] = { 0 }, pTarget[3][256] = { 0 };
//	double cdfSrc[3][256] = { 0 }, cdfTarget[3][256] = { 0 };
//	double pixelVal[3][256] = { 0 };
//	int nSrc = src.rows * src.cols, nTarget = target.rows * target.cols;
//
//	// ����X�C��pixel���X�{����
//	for (int i = 0; i < src.rows; i++)
//		for (int j = 0; j < src.cols; j++)
//			for (int k = 0; k < 3; k++)
//				pSrc[k][src.at<Vec3b>(i, j)[k]]++;
//	for (int i = 0; i < target.rows; i++)
//		for (int j = 0; j < target.cols; j++)
//			for (int k = 0; k < 3; k++)
//			pTarget[k][target.at<Vec3b>(i, j)[k]]++;
//
//	for (int k = 0; k < 3; k++)
//	{
//		for (int i = 0; i < 256; i++)
//		{
//			// �p��X�{�����v
//			pSrc[k][i] /= nSrc;
//			pTarget[k][i] /= nTarget;
//			// �p��ֿn���v����
//			if (i == 0)
//			{
//				cdfSrc[k][i] = pSrc[k][i];
//				cdfTarget[k][i] = pTarget[k][i];
//			}
//			else
//			{
//				cdfSrc[k][i] = pSrc[k][i] + cdfSrc[k][i - 1];
//				cdfTarget[k][i] = pTarget[k][i] + cdfTarget[k][i - 1];
//			}
//
//		}
//	}
//	
//	// ����������
//	for (int k = 0; k < 3; k++)
//	{
//		int targetIndex = 0;
//		for (int i = 0; i < 256; i++)
//		{
//			while (cdfSrc[k][i] > cdfTarget[k][targetIndex])
//				targetIndex++;
//			pixelVal[k][i] = targetIndex;
//		}
//	}
//	
//	
//	// �C�� pixel ������s�ϤW
//	for (int i = 0; i < src.rows; i++)
//		for (int j = 0; j < src.cols; j++)
//			for (int k = 0; k < 3; k++)
//				dst.at<Vec3b>(i, j)[k] = pixelVal[k][src.at<Vec3b>(i, j)[k]];
//	imshow("src", src);
//	imshow("dst", dst);
//	imwrite("bonus2-dark.jpg", dst);
//	waitKey();
//}