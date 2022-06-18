#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main()
{
	// �m�ߤ@
	Mat src = imread("bright.jpg", cv::IMREAD_GRAYSCALE);	// �Ƕ���
	Mat dst = Mat::zeros(src.rows, src.cols, CV_8UC1);
	Mat sample = Mat::zeros(src.rows, src.cols, CV_8UC1); // ���ե�
	equalizeHist(src, sample);
	// Filling your code here
	//int pixelCount[256]
	double p[256] = { 0 };
	double cdf[256] = { 0 };
	double pixelVal[256] = { 0 };
	int n = src.rows * src.cols;

	// ����X�C��pixel���X�{����
	for (int i = 0; i < src.rows; i++)
		for (int j = 0; j < src.cols; j++)
			p[src.at<uchar>(i, j)]++;


	for (int i = 0; i < 256; i++)
	{
		// �p��X�{�����v
		p[i] /= n;
		// �p��ֿn���v����
		if (i == 0)
			cdf[i] = p[i];
		else
			cdf[i] = p[i] + cdf[i - 1];
		// �ഫ���s���ƭ�
		pixelVal[i] = round(cdf[i] * 255);
	}

	// �C�� pixel ������s�ϤW
	for (int i = 0; i < src.rows; i++)
		for (int j = 0; j < src.cols; j++)
			dst.at<uchar>(i, j) = pixelVal[src.at<uchar>(i, j)];
	imshow("src", src);
	imshow("dst", dst);
	imwrite("1-bright.jpg", dst);
	//imshow("sample", sample);
	waitKey();
}