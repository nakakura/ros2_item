#include "rclcpp/rclcpp.hpp"
#include "ros2/control_service.h"
#include "skyway/srv/sky_way_control.hpp"
#include <boost/bind.hpp>
#include <cstdio>

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);

  auto node2 = rclcpp::Node::make_shared("aaa");
  RCLCPP_INFO(node2->get_logger(), "aaaA");

  /*
  rclcpp::NodeOptions node_options;
  // Create a node named add_two_ints_server
  std::shared_ptr<rclcpp::Node> node =
      rclcpp::Node::make_shared("add_two_ints_server", node_options);
  rclcpp::spin(node);
   */

  std::vector<rclcpp::Parameter> params = {
      rclcpp::Parameter("1つめ", 10), rclcpp::Parameter("counter", 100),
      rclcpp::Parameter("2つめ", "日本語")};
  rclcpp::NodeOptions options;
  options.parameter_overrides(params);
  rclcpp::spin(std::make_shared<ControlService>("hoge", options));

  RCLCPP_INFO(node2->get_logger(), "bbb");
  // Make the service available.
  // rclcpp::spin(node);

  RCLCPP_INFO(node2->get_logger(), "ccc");

  rclcpp::spin(std::shared_ptr<ControlService>());
  rclcpp::shutdown();

  return 0;
}
