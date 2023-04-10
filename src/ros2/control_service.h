//
// Created by nakakura on 4/3/23.
//

#ifndef SKYWAY_SERVICE_H
#define SKYWAY_SERVICE_H

#include <chrono>
#include <functional>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "skyway/srv/sky_way_control.hpp"
#include "std_msgs/msg/string.hpp"

class ControlService : public rclcpp::Node {
private:
  rclcpp::Service<skyway::srv::SkyWayControl>::SharedPtr srv_;
  void handleService_(
      const std::shared_ptr<skyway::srv::SkyWayControl::Request> request,
      const std::shared_ptr<skyway::srv::SkyWayControl::Response> response);

public:
  ControlService(const std::string &name_space = "",
                 const rclcpp::NodeOptions &options = rclcpp::NodeOptions());
};

#endif // SKYWAY_SERVICE_H
