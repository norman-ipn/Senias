#include <opencv/highgui.h>
#include <opencv/cv.h>

int main(int argc, char** argv) {
   IplImage* img = cvLoadImage(argv[1], CV_LOAD_IMAGE_UNCHANGED);
   cvNamedWindow("Example1", CV_WINDOW_AUTOSIZE);
        cvShowImage("Example1",img);
        cvWaitKey(0);
        cvReleaseImage(&img);
        cvDestroyWindow("Example1");
}
