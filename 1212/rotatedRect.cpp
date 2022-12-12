#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main()
{
	Mat image(300, 500, CV_8UC1, Scalar(255)); // 가로 500, 세로 300의 8bit(unsigned char)의 채널 한 개의 그레이스케일 이미지(채널이 한 개니까 Scalar(255)로 인자값 하나만 넣어줘도 뜻하는 바가 ( 255,255,255) => 흰색이 됨, 바탕색은 255로 흰색/ Matrix(행렬)
	Point2f center(250, 150), pts[4];
	Size2f size(300, 100);
	RotatedRect rot_rect(center, size, 20);

	Rect bound_rect = rot_rect.boundingRect();
	rectangle(image, bound_rect, Scalar(0), 1);
	circle(image, rot_rect.center, 1, Scalar(0), 2);

	rot_rect.points(pts);
	for(int i = 0; i<4; i++) {
		circle(image, pts[i], 4, Scalar(0), 1);
		line(image, pts[i], pts[(i+1) % 4], Scalar(0), 2);
	}

	imshow("회전사각형", image);
	waitKey(0);
	return 0;
}
