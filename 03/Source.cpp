//#include<opencv2/opencv.hpp>
//using namespace cv;
//int main()
//{
//	Mat img = imread("turing.jpg", 0);
//
//	for (int r = 0; r < img.rows; r++)
//	{
//		for (int c = 0; c < img.cols; c++)
//		{
//			if (img.at<uchar>(r, c) & 0b00000001)
//				img.at<uchar>(r, c) = 255;
//			else
//				img.at<uchar>(r, c) = 0;
//		}
//	}
//
//	//Scalar intensity = img.at<uchar>(20, 20);
//	imshow("Hello World!", img);
//	waitKey();
//}
