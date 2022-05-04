#ifndef LIDAR_VEL_H
#define LIDAR_VEL_H

#include <sensor_msgs/msg/laser_scan.hpp>
#include <geometry_msgs/msg/pose.hpp>
#include <geomety_msgs/msg/twist.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <tf2_ros/transform_broadcaster.h>
#include <tf2_ros/transform_listener.h>
#include <tf2_ros/message_filter.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <tf2/utils.h>

#include "rclcpp/rclcpp.hpp"

#include <csm/csm.h>  // csm defines min and max, but Eigen complains
#include <boost/thread.hpp>


namespace lidar_vel
{
class LidarVel: public rclcpp::Node
{
public:
  LidarVel());
  ~LidarVel();

  void scanCallback(const sensor_msgs::msg::LaserScan::SharedPtr scan_msg);

private:
  // Ros handle

  rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr scan_filter_sub_;

  std::shared_ptr<tf2_ros::TransformListener> tf_;
  std::shared_ptr<tf2_ros::TransformBroadcaster> tfB_;
  tf2::Transform base_to_laser_;  // static, cached
  tf2::Transform laser_to_base_; 
  std::shared_ptr<tf2_ros::Buffer> tf_buffer_;
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr vel_publisher_;
  // Coordinate parameters
  std::string map_frame_;
  std::string base_frame_;
  std::string odom_frame_;
  std::string laser_frame_;
  std::string odom_topic_;

  // Keyframe parameters
  double kf_dist_linear_;
  double kf_dist_linear_sq_;
  double kf_dist_angular_;

  bool initialized_;
  bool publish_tf_;

  tf2::Transform f2b_;     // fixed-to-base tf (pose of base frame in fixed frame)
  tf2::Transform prev_f2b_; // previous fixed-to-base tf (for odometry calculation)
  tf2::Transform f2b_kf_;  // pose of the last keyframe scan in fixed frame


  tf2::Transform odom_to_base_tf;

  sm_params input_;
  sm_result output_;
  LDP prev_ldp_scan_;

  // Grid map parameters
  double resolution_;

  std::vector<double> a_cos_;
  std::vector<double> a_sin_;


  rclcpp::Time last_icp_time_;

  bool getBaseToLaserTf (const std::string& frame_id);

  bool processScan(LDP& curr_ldp_scan, const rclcpp::Time& time);
  void laserScanToLDP(const sensor_msgs::msg::LaserScan::SharedPtr& scan, LDP& ldp);
  void createTfFromXYTheta(double x, double y, double theta, tf2::Transform& t);

  bool newKeyframeNeeded(const tf2::Transform& d);

  void add_parameter(
    const std::string & name, const rclcpp::ParameterValue & default_value,
    const std::string & description = "", const std::string & additional_constraints = "",
    bool read_only = false);
  void createCache (const sensor_msgs::msg::LaserScan::SharedPtr& scan_msg);


};  // LidarVel

}  // namespace lidar_vel

#endif  // LIDAR_VEL_H
