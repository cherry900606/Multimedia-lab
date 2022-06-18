#include <opencv2/opencv.hpp>
using namespace cv;

int main()
{
	// 練習題：LSB watermatk
	/*Mat src = imread("turning_qrcode.png", cv::IMREAD_GRAYSCALE);
	Mat dst = Mat::zeros(src.rows, src.cols, CV_8UC1);

	for (int i = 0; i < src.rows; i++)
	{
		for (int j = 0; j < src.cols; j++)
		{
			if (src.at<uchar>(i, j) & 1 == 1)
				dst.at<uchar>(i, j) = 255;
			else
				dst.at<uchar>(i, j) = 0;
		}
	}
	imshow("src", src);
	imshow("dst", dst);
	waitKey();*/

	// 加分題：圖片縮放
	Mat src = imread("lenna.jpg");

	double resize_size = 1.5;
	Mat dst = Mat::zeros(src.rows * resize_size, src.cols * resize_size, CV_8UC3);

	for (int i = 0; i < dst.rows; i++)
	{
		for (int j = 0; j < dst.cols; j++)
		{
			double nowX = double(i) / resize_size;
			double nowY = double(j) / resize_size;

			int x1 = int(nowX);
			int x2 = int(nowX);
			int y1 = int(nowY);
			int y2 = int(nowY);

			double d1 = nowX - x1;
			double d2 = 1 - d1;
			double d3 = nowY - y1;
			double d4 = 1 - d3;

			dst.at<Vec3b>(i, j) = src.at<Vec3b>(x1, y1) * d2 * d4 + src.at<Vec3b>(x2, y1) * d1 * d4 +
				src.at<Vec3b>(x1, y2) * d2 * d3 + src.at<Vec3b>(x2, y2) * d1 * d3;
		}
	}
	imshow("src", src);
	imshow("dst", dst);
	waitKey();

	return 0;
}