#include <opencv/highgui.h>
#include <opencv/cv.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv) {
	cvNamedWindow("Original Image", CV_WINDOW_AUTOSIZE);
	CvCapture* capture = cvCreateCameraCapture(-1);
	IplImage* originalImg;

	if(cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH,320))
	
	while(1)
	{
	originalImg = cvQueryFrame(capture);

	if(!originalImg) break;
	cvShowImage("Original Image", originalImg);
	char c = cvWaitKey(10);
	if(c==27) break;
	}

	cvReleaseCapture(&capture);
	cvDestroyWindow("Original Image");	
}
