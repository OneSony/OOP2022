#ifndef __EXAMPLE__
#define __EXAMPLE__
	
class Example {
		
private:
	static int _total_n;
	int _now_n;
	int _data;
	// (1)
			
public:
	
	Example(int data);
	void getData();
	~Example();

};
		
#endif