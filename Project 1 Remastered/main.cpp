#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <random>
#include <functional>
#include "CImg.h"
#include <cmath>
#include <queue>
#include <mutex>



class Worker
{
	public:
		std::thread m_thread;//one thread for one worker
		bool m_terminate;
		bool m_running;
		
		void work(){
			//start the thread
			prepare();
			//a loop for step
			while (!m_terminate) 
				{
					//m_terminate = step();//step return false then while continues
					std::cout << "running loop" << std::endl;
					m_terminate = true;
				}
			std::cout << "Joinable? " << m_thread.joinable() << "yes 1 no 0"<< std::endl;
		};
		
		
	public:
		void start(){
			m_terminate = false;
			m_running = true;
			std::cout << "started" << std::endl;
			m_thread = std::thread(&Worker::work,this);

		};
		void stop(){
			std::cout << "stop called" << std::endl;
			m_terminate = true; //set m_terminiate to true, try to influence the work loop;
		};
		Worker()
		{
			m_terminate = false;
			m_running = false;
		}
		~Worker()
		{
			m_thread.join();
		}
	protected:
		virtual void prepare() {
		}
		virtual bool step() = 0;
};


class Producer : public Worker
{
	public:
	protected:
	void prepare() override {
		std::cout << "overide" << std::endl;
	};
	bool step() override {
		return true;
	};
};

struct Point
{
	float x;
	float y;
};

#define THREAD_NUM 4
#define POINT_NUM 5000000
#define Buffer_Size 1000

const float para[4][6] = {{0,0,0,0.16,0,0},{0.85,0.04, -0.04,0.85,0,1.6},{0.2,-0.26,0.23,0.22,0,1.6},{-0.15,0.28,0.26,0.24,0,0.44}};
const unsigned char bluegreen[] = {0,170,255};

bool doneflag = false;
std::mutex muTex;

template<typename T>
struct circular_buf{
	std::queue<T> buffer_queue;
	const int maximum_size = Buffer_Size;

	
	void Pop(){

		if(buffer_queue.size() != 0)
		{
			buffer_queue.pop();			
		}
	}
	void Push(T element){

		if (buffer_queue.size() == maximum_size){
			buffer_queue.pop();
		};
		buffer_queue.push(element);
	}
	
	int Size(){
		return buffer_queue.size();
	}
	T Front(){
		return buffer_queue.front();
	}
	T Back(){
		return buffer_queue.back();
	}
	bool Empty()
	{
		return buffer_queue.empty();
	}
	T Takefirst(){
		T first_element = buffer_queue.front();
		buffer_queue.pop();

		return first_element;
	}
};

void Drawing(circular_buf<Point>& buf,cimg_library::CImg<unsigned char>& bg){
	Point point_read;
	bool buf_empty;
	
	while(!doneflag){
		muTex.lock();
		//std::cout << "buffer size" <<buf.Size() << std::endl;
		if (!buf.Empty()){
			point_read = buf.Takefirst();
			std::cout << "Processing Buffer" <<buf.Size() << std::endl;
			bg.draw_point(2*(point_read.y*1000),2*(point_read.x*1000+2200),bluegreen);
			//bg.draw_circle((point_read.y*1000),(point_read.x*1000+2200),10,bluegreen);
		}
		muTex.unlock();
		
		}
};


void CalculateNextPoint(circular_buf<Point>& buf) //Array are default passed by pointers
{
	Point old_value = {0,0};
	Point new_value = {0,0};
	std::mt19937 engine(time(0));
	std::uniform_int_distribution<> uniformDist(1,100);
	int j = 5;

	for (int i =1; i < POINT_NUM; i++){
		auto random1_100 = uniformDist(engine);
		
		if (random1_100<=1)
		{
			j = 0;
		};
		
		if (random1_100>=2 && random1_100<=86)
		{
			j = 1;
		};
		
		if (random1_100>=87 && random1_100<=93)
		{
			j = 2;
		};
		
		if (random1_100>93)
		{
			j = 3;
		};

		
		new_value.x = para[j][0]*old_value.x + para[j][1]*old_value.y + para[j][4];
		new_value.y = para[j][2]*old_value.x + para[j][3]*old_value.y + para[j][5];
		old_value = new_value;
		
	  	{
	  		muTex.lock();
			buf.Push(new_value);
			muTex.unlock();
  		}		
	}
	doneflag = true;
};





int main(void)
{

	auto sta = std::chrono::steady_clock::now();
	
	circular_buf<Point>* buf = new circular_buf<Point>;

	unsigned int w = 20000;
	unsigned int h = 10000;
	
	cimg_library::CImg<unsigned char>* bg = new cimg_library::CImg<unsigned char>(w,h,1,3,255);


	std::thread t1;

	t1 = std::thread(CalculateNextPoint,std::ref(*buf));
	std::thread t5(CalculateNextPoint,std::ref(*buf));
	std::thread t6(CalculateNextPoint,std::ref(*buf));


	std::thread t2(Drawing,std::ref(*buf),std::ref(*bg));
	std::thread t3(Drawing,std::ref(*buf),std::ref(*bg));
	std::thread t4(Drawing,std::ref(*buf),std::ref(*bg));

	
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();
	
	std::chrono::duration<double> dur = 
	std::chrono::steady_clock::now() - sta;
	
	std::cout << "Time for 3 Producer/3 Consumer" << dur.count()
		<< "second" << std::endl;
	std::cout << std::endl;
	
 	bg->display();

	delete bg;
	delete buf;

}
