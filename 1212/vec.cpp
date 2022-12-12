#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	Vec <int, 2> v1(5, 12);
	Vec <double, 3> v2(40, 130.7, 125.6);
	Vec2b v3(10, 10); //인자의 개수가 2개, b는 byte
	Vec6f v4(40.f, 230.25f, 525.6f);//인자의 개수가 6개. 다만 인자를 3개 채워준 것
	Vec3i v5(200, 230, 250);

	Vec3d v6 = v2 + (Vec3d)v5;
	Vec2b v7 = (Vec2b)v1 + v3;
	Vec6f v8 = v4 * 20.0f;

	Point pt1 = v1 + (Vec2i)v7;
	Point3_<double> pt2 = v2;
	//int형으로 형변환하고 싶으면 Point3_<int> pt2 = (Vec3i)v2;

	cout << "[v3] = " << v3 << endl;
	cout << "[v7] = " << v7 << endl;
	cout << "[v3i * v7] = " << v3.mul(v7) << endl;
	cout << "v8[0] = " << v8[0] << endl;
	cout << "v8[1] = " << v8[1] << endl;
	cout << "v8[2] = " << v8[2] << endl;
	cout << "[v2] = " << v2 << endl;
	cout << "[pt2] = " << pt2 << endl;

	return 0;
}
