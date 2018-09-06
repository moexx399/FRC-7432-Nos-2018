#include <opencv2\videoio.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\opencv.hpp>
#include <ntcore.h>
#include <networktables/NetworkTable.h>

using namespace cv;
using namespace std;
using std::shared_ptr;

void main()
{
	

	// Input Quadilateral or Image plane coordinates
	Point2f inputQuad[4];
	// Output Quadilateral or World plane coordinates
	Point2f outputQuad[4];

	inputQuad[0] = Point2f(0, 100);
	inputQuad[1] = Point2f(640, 100);
	inputQuad[2] = Point2f(640, 480);
	inputQuad[3] = Point2f(0, 480);
	// The 4 points where the mapping is to be done , from top-left in clockwise order
	outputQuad[0] = Point2f(0, 0);
	outputQuad[1] = Point2f(640, 0);
	outputQuad[2] = Point2f(400, 240);
	outputQuad[3] = Point2f(240, 240);

	// Lambda Matrix
	Mat lambda(2, 4, CV_32FC1);

	//Input and Output Image;
	Mat input, output0, output1, output2, output3;

	// Get the Perspective Transform Matrix i.e. lambda 
	lambda = getPerspectiveTransform(inputQuad, outputQuad);

	//The number of connected USB camera(s)
	const uint CAM_NUM = 3;

	//This will hold the VideoCapture objects
	VideoCapture camCaptures[CAM_NUM];

	//This will hold the resulting frames from each camera
	Mat camFrames[CAM_NUM];

	//This will be used for highgui window name
	string labels[CAM_NUM];

	cv::Mat Final(640, 640, CV_8UC3, Scalar(0, 0, 0));
	cv::Mat Left(640, 640, CV_8UC3, Scalar(0, 0, 0));
	cv::Mat Right(640, 640, CV_8UC3, Scalar(0, 0, 0));
	cv::Mat Top(640, 640, CV_8UC3, Scalar(0, 0, 0));
	cv::Mat Bottom(640, 640, CV_8UC3, Scalar(0, 0, 0));
	cv::Mat Temp1(640, 640, CV_8UC3, Scalar(0, 0, 0));
	cv::Mat Temp2(640, 640, CV_8UC3, Scalar(0, 0, 0));

	double angle = -45;

	cv::Point2f center((Final.cols - 1) / 2.0, (Final.rows - 1) / 2.0);
	cv::Mat rot = cv::getRotationMatrix2D(center, angle, 1.0);
	// determine bounding rectangle, center not relevant
	cv::Rect2f bbox = cv::RotatedRect(cv::Point2f(), Final.size(), angle).boundingRect2f();
	// adjust transformation matrix
	rot.at<double>(0, 2) += bbox.width / 2.0 - Final.cols / 2.0;
	rot.at<double>(1, 2) += bbox.height / 2.0 - Final.rows / 2.0;

	cv::Mat dst;

	
	NetworkTable::SetClientMode();
	NetworkTable::SetIPAddress("75.134.142.188");
	NetworkTable::Initialize();
	shared_ptr<NetworkTable> myTable = NetworkTable::GetTable("SmartDashboard");


	//Initialization of VideoCaptures
	for (int i = 0; i < CAM_NUM; i++)
	{
		//Init label for highgui window name
		labels[i] = "Camera " + to_string(i);

		//Opening camera capture stream
		camCaptures[i].open(i);
	}
	//continous loop until 'Esc' key is pressed
	while (waitKey(1) != 27) {

		camCaptures[0] >> camFrames[0];
		input = camFrames[0];
		// Apply the Perspective Transform just found to the src image
		warpPerspective(input, output0, lambda, output0.size());
		camFrames[0] = output0;


		camCaptures[1] >> camFrames[1];
		input = camFrames[1];
		// Apply the Perspective Transform just found to the src image
		warpPerspective(input, output1, lambda, output1.size());
		camFrames[1] = output1;

		camCaptures[2] >> camFrames[2];
		input = camFrames[2];
		// Apply the Perspective Transform just found to the src image
		warpPerspective(input, output2, lambda, output2.size());
		camFrames[2] = output2;

		//camCaptures[3] >> camFrames[3];
		//input = camFrames[3];
		//// Apply the Perspective Transform just found to the src image
		//warpPerspective(input, output3, lambda, output3.size());
		//camFrames[3] = output3;


		cv::rotate(camFrames[1], camFrames[1], ROTATE_90_CLOCKWISE);
		cv::rotate(camFrames[2], camFrames[2], ROTATE_90_COUNTERCLOCKWISE);
		/*cv::rotate(camFrames[3], camFrames[3], ROTATE_180);*/

		


		//Top
		Rect Rec(0, 0, camFrames[0].cols, camFrames[0].rows);
		rectangle(camFrames[0], Rec, Scalar(0), 1, 8, 0);
		Mat Roi = camFrames[0](Rec);
		Rect WhereRec(0, 0, Roi.cols, Roi.rows);
		Roi.copyTo(Top(WhereRec));


		//Right
		Rect Rec1(0, 0, camFrames[1].cols, camFrames[1].rows);
		rectangle(camFrames[1], Rec1, Scalar(0), 1, 8, 0);
		Mat Roi1 = camFrames[1](Rec1);
		Rect WhereRec1(160, 0, Roi1.cols, Roi1.rows);
		Roi1.copyTo(Right(WhereRec1));

		//Left
		Rect Rec2(0, 0, camFrames[2].cols, camFrames[2].rows);
		rectangle(camFrames[2], Rec2, Scalar(0), 1, 8, 0);
		Mat Roi2 = camFrames[2](Rec2);
		Rect WhereRec2(0, 0, Roi2.cols, Roi2.rows);
		Roi2.copyTo(Left(WhereRec2));

		////Bottom
		//Rect Rec3(0, 0, camFrames[3].cols, camFrames[3].rows);
		//rectangle(camFrames[3], Rec3, Scalar(0), 1, 8, 0);
		//Mat Roi3 = camFrames[3](Rec3);
		//Rect WhereRec3(0, 160, Roi3.cols, Roi3.rows);
		//Roi3.copyTo(Bottom(WhereRec3));

		cv::add(Top, Left, Temp1);
		cv::add(Bottom, Right, Temp2);
		cv::add(Temp1, Temp2, Final);

		// get rotation matrix for rotating the image around its center in pixel coordinates
		
		
		//cv::warpAffine(Final, dst, rot, bbox.size());

		imshow("FINAL", dst);

		cv::Size size = dst.size();

		int total = size.width * size.height * dst.channels();
		std::vector<uchar> data(dst.ptr(), dst.ptr() + total);
		std::string s(data.begin(), data.end());
		myTable->PutString("Eagle_Eye", "Sample Text");


		//imshow("1", camFrames[0]);

	}

	//Releasing all VideoCapture resources
	for (int i = 0; i < CAM_NUM; i++)
	{
		camCaptures[i].release();
	}
}