//
// Created by nakakura on 4/3/23.
//

#include "control_service.h"

void ControlService::handleService_(
    const std::shared_ptr<skyway::srv::SkyWayControl::Request>,
    const std::shared_ptr<skyway::srv::SkyWayControl::Response> response) {
  response->response = "あああ";
}

ControlService::ControlService(const std::string &name_space,
                               const rclcpp::NodeOptions &options)
    : Node("minimal_service", name_space, options) {
  using namespace std::placeholders;

  std::vector<rclcpp::Parameter> param = options.parameter_overrides();

  RCLCPP_INFO(this->get_logger(), "param0 %s %s %d",
              param[0].get_type_name().c_str(), param[0].get_name().c_str(),
              param[0].as_int());

  RCLCPP_INFO(this->get_logger(), "param2 %s %s %s",
              param[2].get_type_name().c_str(), param[2].get_name().c_str(),
              param[2].as_string().c_str());

  srv_ = this->create_service<skyway::srv::SkyWayControl>(
      "srv_test", std::bind(&ControlService::handleService_, this, _1, _2));
}
