#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using std::placeholders::_1;

class MinimalSubscriber: public rclcpp::Node {
    private:
        // attribute
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscriber_;
        // method
        void topic_callback(const std_msgs::msg::String &msg){
            //RCLCPP_INFO for log (output) msg
            RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg.data.c_str());
        }
    public:
        // default constructor
        MinimalSubscriber() : Node("minimal_subscriber"){
            // using callback with std::bind
            this->subscriber_ = this->create_subscription<std_msgs::msg::String>("topic", 10, std::bind(&MinimalSubscriber::topic_callback, this, _1));
        }
};

int main(int argc, char* argv[]){
    // run ROS2 using rclcpp::init
    rclcpp::init(argc, argv);
    // start node using rclcpp::spin
    // use shared pointer with std::make_shared
    rclcpp::spin(std::make_shared<MinimalSubscriber>());
    rclcpp::shutdown();
}
