/*

/*
************************* video capture *************************
*/
#include "opencv2/opencv.hpp"
#include <stdint.h>

using namespace std;
using namespace cv;

int main() {
	namedWindow("Webcam", WINDOW_KEEPRATIO);
	Mat frame;

	VideoCapture vid(1); // any camera - 0 or file // RTSP TEST ADDRESS: "rtsp://wowzaec2demo.streamlock.net/vod/mp4:BigBuckBunny_115k.mov"
	vid.set(CAP_PROP_FRAME_WIDTH, 320);
	vid.set(CAP_PROP_FRAME_HEIGHT, 240);

	if (!vid.isOpened()) {
		return -1; // exit
	}
/*
	printf("width = %.2f\n", vid.get(CAP_PROP_FRAME_WIDTH));
	printf("height = %.2f\n", vid.get(CAP_PROP_FRAME_HEIGHT));
	printf("fbs = %.2f\n", vid.get(CAP_PROP_FPS));
	printf("brightness = %.2f\n", vid.get(CAP_PROP_BRIGHTNESS));
	printf("contrast = %.2f\n", vid.get(CAP_PROP_CONTRAST));
	printf("saturation = %.2f\n", vid.get(CAP_PROP_SATURATION));
	printf("hue = %.2f\n", vid.get(CAP_PROP_HUE));
	printf("exposure = %.2f\n", vid.get(CAP_PROP_EXPOSURE));
*/
	while (vid.read(frame)) { // or while(true){vid >> frame...}

		printf("width = %.2f, height = %.2f \n", vid.get(CAP_PROP_FRAME_WIDTH), vid.get(CAP_PROP_FRAME_HEIGHT));

		imshow("Webcam", frame);

		if (waitKey(30) >= 0) {
			break;
		}
	}
	return 1;
}

/*
************************* record and display realtime in h264 - 1 *************************
*/

//#include <opencv2\opencv.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include "opencv2/imgproc/imgproc.hpp"
//#include <iostream>
//#include <fstream> 
//#include <iterator> 
//#include <vector>
//#include <stdlib.h>
//
//using namespace cv;
//using namespace std;
//
//void videoRecordAsH264(){
//    namedWindow("VIDEO SAVER", WINDOW_AUTOSIZE);
//    Mat frame;
//    VideoCapture capture(0);
//    int fps = 30;
//    Size size((int)capture.get(CAP_PROP_FRAME_WIDTH), (int)capture.get(cv::CAP_PROP_FRAME_HEIGHT));
//    VideoWriter writer("C:/Users/Administrator/Desktop/NAME/video2.avi", VideoWriter::fourcc('H', '2', '6', '4'), fps, size);
//    int i = 0;
//
//    while (capture.isOpened()) {
//        capture >> frame;
//        if (frame.empty()) { break; }  
//        writer << frame; // OR --> writer.write(frame);
//        imshow("VIDEO SAVER", frame);
//
//        if (waitKey(10) == 27) { break; }
//    }
//
//    // When everything done, release the video capture and write object
//    capture.release();
//    writer.release();
//    //// store Mat data into frame
//    //FileStorage fs("C:/Users/Administrator/Desktop/NAME/" + to_string(i) + ".txt", FileStorage::WRITE);
//    //fs << "video" << frame; //mat_eye;
//    //i++;
//    //fs.release();
//    // Closes all the windows
//    destroyAllWindows();
//}
//
//
//int main()
//{
//    videoRecordAsH264();
//
//    return 0;
//}

/*
************************* record and display realtime in h264 - 2 *************************
*/

//#include <opencv2/opencv.hpp>
//#include <iostream>
//#include <Windows.h>
//using namespace std;
//using namespace cv;
//void videoRecordAsH264() {
//
//	Mat org_frame, gray_frame; // create two Mat to store original frame and grayscale frame
//	const char win1[] = "Original", win2[] = "Grayscale"; // 2 window's name variable
//	int fps = 30;// frame num of each sec
//	char file_path[] = "C:/Users/Administrator/Desktop/NAME/video2.264"; // recorded video save path
//	bool isColor = 1; // save mode is colorful
//	char rtsp_path[] = "rtsp://10.17.20.226:554";
//	Sleep(3000);
//	//open cam, 0 as default cam
//	VideoCapture capture (rtsp_path); // rtsp url here
//	if (!capture.isOpened()) {// check cam is opened or not
//		cout << "Error! Camera is not ready...\n";
//	}
//
//	//Size size((int)capture.get(CAP_PROP_FRAME_WIDTH), (int)capture.get(cv::CAP_PROP_FRAME_HEIGHT)); // get height and width of video
//	//VideoWriter writer(file_path, VideoWriter::fourcc('X', '2', '6', '4'), fps, size, isColor); // create writer to save video
//	namedWindow(win1, WINDOW_KEEPRATIO); // name of two windows
//	//namedWindow(win2, WINDOW_KEEPRATIO);
//
//	while (capture.isOpened()) {
//		capture >> org_frame; // grap frame and decode from cam as flow
//		//cvtColor(org_frame, gray_frame, COLOR_BGR2GRAY); // convert frames into gray scale
//		//writer << org_frame; // save the encoded frame to file as flow
//		imshow(win1, org_frame); // show original and grayscale frame in win1 and win2
//		//imshow(win2, gray_frame);
//
//		if (waitKey(10) == 27) { // press Esc to exit
//			break;
//		}
//	}
//	//writer.release();
//	capture.release();
//	destroyAllWindows();
//}
//
//int main(int, char**) {
//	videoRecordAsH264();
//	return 0;
//}


