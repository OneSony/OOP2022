class Move
{
private:
    double x;
    double y;
    double calc(); // calculate x * y
public:
    Move(double a = 0, double b = 0);
    // init x and y to a and b
    void display(); // display the result of calc()
    double get_x(); // return x
    double get_y(); // return y
    void reset(double a = 0, double b = 0);
    // reset x and y to a and b
};