#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main()
{
	Mat image(200, 300, CV_8U, Scalar(255));
	namedWindow("KeyBoard Event", WINDOW_AUTOSIZE);
	imshow("KeyBoard Event", image);

	while(1)
	{
		int key = waitKey(100);
		//printf("key: %x\n", key);

		if (key == 27) break;

		switch (key)
		{
			case 'a': cout << "a키 입력" << endl; break;
			case 'b': cout << "b키 입력" << endl; break;
			case 0x41: cout << "A키 입력" << endl; break;
			case 66: cout << "B키 입력" << endl; break;
			
			case 0x51: cout << "왼쪽 화살표 키 입력" <<endl; break;
			case 0x52: cout << "윗쪽 화살표 키 입력" <<endl; break;
			case 0x53: cout << "오른쪽 화살표 키 입력" <<endl; break;
			case 0x54: cout << "아래쪽 화살표 키 입력" <<endl; break;
		}
	}
	return 0;
}
