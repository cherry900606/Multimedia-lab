//#include <opencv2/opencv.hpp>
//using namespace cv;
//
//int main()
//{
//	Mat img = imread("Lenna.jpg"), grayMat;
//	cvtColor(img, grayMat, COLOR_BGR2GRAY);
//	imshow("Hello World!", grayMat);
//	waitKey();
//}

#include <opencv2/opencv.hpp>
using namespace cv;

int main()
{
	Mat img = imread("Lenna.jpg");
	Mat img_gray = Mat::zeros(img.rows, img.cols, CV_8UC1);

	for (int i = 0; i < img.rows; i++)
	{
		for (int j = 0; j < img.cols; j++)
		{
			int b = img.at<Vec3b>(i, j)[0];
			int g = img.at<Vec3b>(i, j)[1];
			int r = img.at<Vec3b>(i, j)[2];

			img_gray.at<uchar>(i, j) = 0.299 * r + 0.587 * g + 0.114 * b;
		}
	}

	imshow("RGB to gray", img_gray);
	waitKey();
}