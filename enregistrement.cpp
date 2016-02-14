#include <iostream>
#include <string>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;
using namespace cv;

int main(void)
{
	time_t now = time(NULL);
	cout << ctime(&now) << endl;
	string streamRoom = "Live watching";

	VideoCapture cap(0);
	//namedWindow(streamRoom, WINDOW_NORMAL);

	int frame_width = cap.get(CV_CAP_PROP_FRAME_WIDTH);
	int frame_height = cap.get(CV_CAP_PROP_FRAME_HEIGHT);
	VideoWriter video("surveillance.avi", CV_FOURCC('M','J','P','G'), 20, Size(frame_width, frame_height));

	for(;;)
	{
		Mat frame;
		cap >> frame;
		now = time(NULL);
		putText(frame, string(ctime(&now)), Point(25,25), 1, 0.8, Scalar(255,0,0), 1, CV_AA);
		video.write(frame);
		//imshow(streamRoom, frame);
		if(waitKey(30) >= 0) break;
	}

	return 0;
}

