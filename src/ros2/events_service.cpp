//
// Created by nakakura on 4/10/23.
//

#include "events_service.h"

void EventsService::handleService_(
    const std::shared_ptr<skyway::srv::SkyWayEvents::Request>,
    const std::shared_ptr<skyway::srv::SkyWayEvents::Response> response) {
  response->response = "あああ";
}

EventsService::EventsService(const std::string &name_space,
                             const rclcpp::NodeOptions &options)
    : Node("minimal_service", name_space, options) {
  using namespace std::placeholders;

  srv_ = this->create_service<skyway::srv::SkyWayEvents>(
      "srv_test", std::bind(&EventsService::handleService_, this, _1, _2));
}
