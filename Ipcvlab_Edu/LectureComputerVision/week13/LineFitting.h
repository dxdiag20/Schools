#pragma once
#include "opencv2\opencv.hpp"
#include <random>
class CRANSAC
{
public:
	cv::Point pt1;	
	cv::Point pt2;
	int pt1Idx;
	int pt2Idx;
	
	double m; //����
	double b; //����

	double opM; // ������ ����
	double opB; // ������ ����
	std::vector<cv::Point> ptVec;   // �������� ������ ������ ������ ����	

	int maxInlier;
public:
	CRANSAC(){maxInlier = 0;}
	void DrawLine(cv::Mat &out);
	void DrawPoint(cv::Mat &out);
	void CalLine();
	void RandomGetPT();
	void MakeRandomPoint();
	void CalInliner();

    // min ~ max ���̿��� �յ��� Ȯ�� ������ ����
    static int getRandomNumber ( int min, int max )
	{		
		std::random_device rn;
		std::mt19937_64 rnd( rn() );
	
		std::uniform_int_distribution<int> range(min, max);

		return range( rnd );
	}
};

class LeastSquare
{
	cv::Point pt1;	
	cv::Point pt2;
	
	double m; //����
	double b; //����

	std::vector<cv::Point> ptVec;   // �������� ������ ������ ������ ����	

public:
	LeastSquare(){}
	void DrawLine(cv::Mat &out);
	void DrawPoint(cv::Mat &out);
	void MakeRandomPoint();
	void CalLine();

    // min ~ max ���̿��� �յ��� Ȯ�� ������ ����
    static int getRandomNumber ( int min, int max )
	{		
		std::random_device rn;
		std::mt19937_64 rnd( rn() );
	
		std::uniform_int_distribution<int> range(min, max);

		return range( rnd );
	}
};