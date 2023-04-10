//
// Created by nakakura on 4/10/23.
//

#ifndef SKYWAY_EVENTS_SERVICE_H
#define SKYWAY_EVENTS_SERVICE_H

#include <chrono>
#include <functional>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "skyway/srv/sky_way_events.hpp"
#include "std_msgs/msg/string.hpp"

class EventsService : public rclcpp::Node {
private:
  rclcpp::Service<skyway::srv::SkyWayEvents>::SharedPtr srv_;

  void handleService_(
      const std::shared_ptr<skyway::srv::SkyWayEvents::Request> request,
      const std::shared_ptr<skyway::srv::SkyWayEvents::Response> response);

public:
  EventsService(const std::string &name_space = "",
                const rclcpp::NodeOptions &options = rclcpp::NodeOptions());
};

#endif // SKYWAY_EVENTS_SERVICE_H
