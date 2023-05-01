#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include "rclcpp/rclcpp.hpp" // rclcpp library provide Node, Publisher, Subscriber, Services, Client, Timer, Callbacks, etc
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals; // help to specify time, e.g. 5s, 5ms, 5ns

// make class node that inherited from rclcpp::node
class MinimalPublisher: public rclcpp::Node{ // don't forget when inherit class, you chould specify the level of inheritance, maybe public, private, etc
    private:
        // attributes
        // SharedPtr is special pointer that automatically delete an object when the object no longer needed
        rclcpp::TimerBase::SharedPtr timer_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
        size_t count_; // choosing size_t (support any size of unsigned integer) instead of unsigned int

        // methods
        void timer_callback(){
            auto message = std_msgs::msg::String(); // instantiate String std_msg, auto choose any datatype automatically, can be int, string, etc
            message.data = "Hello World! " + std::to_string(count_++);
            RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str()); // output logs
            publisher_->publish(message);
        }
    public:
        // default constructor
        MinimalPublisher() : Node("minimal_publisher"), count_(0){
            this->publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10); // 10 is queue size
            this->timer_ = this->create_wall_timer(500ms, std::bind(&MinimalPublisher::timer_callback, this));
        }
};

int main(int argc, char* argv[]){
    rclcpp::init(argc, argv); // rclcpp::init is for initialize ROS2
    rclcpp::spin(std::make_shared<MinimalPublisher>()); // rclcpp::spin is for starts processing data from node
    // including callbacks from timer
    rclcpp::shutdown();
}

