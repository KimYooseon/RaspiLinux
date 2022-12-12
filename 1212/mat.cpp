#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main()
{
	float data[] = {
		1.2f, 2.3f, 3.2f,
		4.5f, 5.f, 6.5f,
	};

	Mat m1(2, 3, CV_8U); 	// 2행 3열
	Mat m2(2, 3, CV_8U, Scalar(300)); 	//2^8 = 256, 0~255까지니까 255이상은 255로 저장
	Mat m3(2, 3, CV_16S, Scalar(300));	//2^16 => 범위가 넓음 => 값이 짤리지 않고 300으로 잘 저장됨
	Mat m4(2, 3, CV_32F, data);

	Size sz(2, 3);
	Mat m5(Size(2, 3), CV_64F); //CV_64F형은 double형과 같음!  /  Size로 지정했으니 3행 2열이 됨
	Mat m6(sz, CV_32F, data); //CV_32F형은 float형

	cout<< "[m1] =" << endl << m1 << endl;
	cout<< "[m2] =" << endl << m2 << endl;
	cout<< "[m3] =" << endl << m3 << endl;
	cout<< "[m4] =" << endl << m4 << endl;
	cout<< "[m5] =" << endl << m5 << endl;
	cout<< "[m6] =" << endl << m6 << endl;
	return 0;
}
