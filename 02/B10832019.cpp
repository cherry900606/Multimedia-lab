#include<opencv2/opencv.hpp>
#include<iostream>
#include<algorithm>

using namespace cv;
using namespace std;

int main()
{
	Mat src = imread("lenna_noise.jpg", 0);	// ¦Ç¶¥¹Ï
	Mat dst = Mat::zeros(src.rows, src.cols, CV_8UC1);
	int ksize = 5;	// 5 * 5 ¾B¸n

	// Filling your code here
	// ¥­·Æªk
	/*for (int i = 2; i < src.rows - 2; i++)
	{
		for (int j = 2; j < src.cols - 2; j++)
		{
			int value = 0;
			for (int x = -2; x <= 2; x++)
			{
				for (int y = -2; y <= 2; y++)
				{
					value += src.at<uchar>(i + x, j + y);
				}
			}
			value /= 25;
			dst.at<uchar>(i, j) = value;
		}
	}*/

	// ¤¤­ÈÂoªi
	for (int i = 2; i < src.rows - 2; i++)
	{
		for (int j = 2; j < src.cols - 2; j++)
		{
			int arr[25] = { 0 }, flag = 0;
			for (int x = -2; x <= 2; x++)
			{
				for (int y = -2; y <= 2; y++)
				{
					//cout << flag << endl;
					arr[flag] = src.at<uchar>(i + x, y + j);
					flag++;
				}
			}
			sort(arr, arr + 25);
			dst.at<uchar>(i, j) = arr[13];
		}
	}


	imshow("src", src);
	imshow("dst", dst);
	waitKey();
}